import math
from natsort import os_sorted
import os
from skimage.io import imread

import tensorflow as tf
import tensorflow.keras.utils.Sequence as Sequence

'''
img_id
    cat
        bbox1
        bbox2
        bbox3
        ...
    cat 
        bbox1
        bbox2
        bbox3
        ...
'''


class COCO128Sequence(Sequence):
    
    def __init__(self, dataDir, dataType, anchors_wh, batch_size):
        
        self.img_path = os.path.join(dataDir, 'images', dataType)
        self.ann_path = os.path.join(dataDir, 'annotations', '{}bboxes.json'.format(dataType) )

        self.batch_size = batch_size        
        self.anchors_wh = anchors_wh
        self.num_classes = len(classes)
        self.classes = classes # ordered list of category names for training

        self.img_filenames = os_sorted(os.listdir(img_path))
        self.img_ids = [os.path.splitext(f)[0] for f in img_filenames]

        # Create dictionary with all the bboxes
        with open(ann_path, 'r') as json_file:
            self.img_bboxes_json = json.load(json_file)
            json_file.close()
        

    def __len__(self):
        return math.ceil(len(self.image_filenames) / self.batch_size) # total number of batches

    def __getitem__(self, idx):
        batch_x_filenames = self.img_filenames[idx*self.batch_size : (idx + 1)*self.batch_size]
        batch_y_ids = self.img_ids[idx*self.batch_size : (idx + 1)*self.batch_size]

        batch_x = np.array([imread(os.path.join(img_path, f)) for f in batch_x_filenames])
        batch_y = []
        for id in batch_y_ids:
            d = self.img_bboxes[id]
            classes_one_hot = np.zeros(num_classes)
            for cat in d.keys():
                batch_y.append(self.preprocess_label_for_one_scale())
        batch_y = np.asarray(batch_y)

        return batch_x, batch_y

    
    # TODO - have to figure this function out if you want to convert y-values into somethign compatibile with YOLO Loss
    def preprocess_label_for_one_scale(self, classes, bboxes, grid_size=13, valid_anchors=None):
            """
            preprocess the class and bounding boxes annotations into model desired format for one scale
            (grid, grid, anchor, (centroid x, centroid y, width, height, objectness, ...one-hot classes...))
            inputs:
            grid_size: a scalar grid size to use
            outputs:
            y: the desired label format to calcualte loss
            """
            # construct an empty placeholder for the final output y first
            y = tf.zeros((grid_size, grid_size, 3, 5 + self.num_classes))

            # find the best anchor indices for each ground truth box
            anchor_indices = self.find_best_anchor(bboxes)

            # necessary assertion, otherwise the steps later would fail
            tf.Assert(classes.shape[0] == bboxes.shape[0], [classes])
            tf.Assert(anchor_indices.shape[0] == bboxes.shape[0], [anchor_indices])

            # this has to be tf.shape instead of classes.shape, otherwise would be None
            num_boxes = tf.shape(classes)[0]

            indices = tf.TensorArray(tf.int32, 1, dynamic_size=True)
            updates = tf.TensorArray(tf.float32, 1, dynamic_size=True)

            valid_count = 0
            for i in tf.range(num_boxes):
                curr_class = tf.cast(classes[i], tf.float32)
                curr_box = bboxes[i]
                curr_anchor = anchor_indices[i]

                # only use the anchor when it belongs to current scale (grid_size)
                # for example, when grid size is 13, only anchor 6, 7, 8 (big anchors) are valid
                # because the reception field of this grid size is the biggest
                # however, if grid size is 52, the finest grained grid, we can only use anchor
                # 0, 1, 2 (small anchors)
                anchor_found = tf.reduce_any(curr_anchor == valid_anchors)
                if anchor_found:
                    # now that we found the anchor, we need to set it in our final output y
                    # we only have three anchor boxes in y, so we need to mod by 3 first to get
                    # adjusted index. eg. anchor 7 will have index 1
                    # we need to reshape here so that adjusted_anchor_index is a vector
                    adjusted_anchor_index = tf.math.floormod(curr_anchor, 3)

                    # we need to turn (xmin, ymin, xmax, ymax) box format into
                    # (centeroid x, centroid y, width, height) to be able to
                    # calculate yolo loss later
                    curr_box_xy = (curr_box[..., 0:2] + curr_box[..., 2:4]) / 2
                    curr_box_wh = curr_box[..., 2:4] - curr_box[..., 0:2]

                    # calculate which grid cell should we use
                    # eg. when curr_box_xy = [0.25, 0.25], and grid size = 26, which is a quarter of the image
                    # the index of grid cell is floor(0.25 * 26) = 6
                    grid_cell_xy = tf.cast(
                        curr_box_xy // tf.cast((1 / grid_size), dtype=tf.float32),
                        tf.int32)

                    # for this box, we need to update y at location (grid_size, grid_size, adjusted_anchor_index)
                    # eg. shape in (13, 13, 1)
                    # grid[y][x][anchor] = (tx, ty, bw, bh, obj, class)
                    # note that it's not grid[x][y]
                    index = tf.stack(
                        [grid_cell_xy[1], grid_cell_xy[0], adjusted_anchor_index])

                    # this is the value we use to update the above location
                    # eg. shape in (7)
                    # note that we need to make this one-hot classes in order to use categorical crossentropy later
                    update = tf.concat(
                        values=[
                            curr_box_xy, curr_box_wh,
                            tf.constant([1.0]), curr_class
                        ],
                        axis=0)
                    # add to final indices and updates to be written into y
                    indices = indices.write(valid_count, index)
                    updates = updates.write(valid_count, update)
                    # tf.print(indices.stack())
                    # tf.print(updates.stack())
                    valid_count = 1 + valid_count

            y = tf.tensor_scatter_nd_update(y, indices.stack(), updates.stack())
            return y
        
