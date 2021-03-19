import cv2
import matplotlib.pyplot as plt

import tensorflow as tf

def draw_bbox(image_path, bboxes, scores=[]):
    imgcv = cv2.imread(image_path, flags=cv2.IMREAD_COLOR)
    # opencv assumes BGR image rather than RGB -> flip channels
    imgcv = cv2.cvtColor(imgcv, cv2.COLOR_BGR2RGB)
    if scores == []:
        for cat in bboxes.keys():
            for box in bboxes[cat]:
                x, y, w, h = box
                x1 = int(x)
                y1 = int(y)
                x2 = int(x+w)
                y2 = int(y+h)
                cv2.rectangle(imgcv, (x1,y1), (x2,y2), (0,255,0), 2) # add rectangle to image
                
                label = cat
                labelSize=cv2.getTextSize(label,cv2.FONT_HERSHEY_PLAIN,0.5,2)
                _x1 = x1
                _y1 = y1#+int(labelSize[0][1]/2)
                _x2 = _x1+labelSize[0][0]
                _y2 = y1-int(labelSize[0][1])
                cv2.rectangle(imgcv,(_x1,_y1),(_x2,_y2),(0,255,0),cv2.FILLED)
                cv2.putText(imgcv,label,(x1,y1),cv2.FONT_HERSHEY_PLAIN,0.5,(255,255,255),1)
                
                plt.imshow(imgcv)
    else:
        # TODO - write code to also plot scores (in addition to labels)
        print(0)
    plt.show()