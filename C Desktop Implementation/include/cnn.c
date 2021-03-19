/*
 * cnn.c
 *
 *  Created on: Oct 21, 2020
 *      Author: ocean
 */
# include "cnn.h"


// Padding will always be 'same', all filters are 3x3xc and all layer outputs are 28x28xc
//(W−F+2P)/S+1 = Output size
// Padding = 1, Stride = 1

//TO CHECK/CHANGE
//CHECK ALL LAYERS USING PYTHON - tf.keras.whatever
//add - checked
//ZeroPadding2D - checked
//batch norm - checked
//upsample2D - checked
//concatenate - checked
//leakyReLU - 

/*void depthwise_conv2d(float *** input, float *** kernel, float * bias, float *** result, int input_height, int input_width, int input_channels, int kernel_size, int num_kernels)
{
    for (int c = 0; c < input_channels; c++)
    {
        for (int i = 0; i < input_height; i++)
        {
            for (int j = 0; j < input_width; j++)
            {
                for (int i_k = 0; i_k < kernel_size; i_k++)
                {
                    for (int j_k = 0; j_k < kernel_size; j_k++)
                    {
                        result[i][j][c] += input[i+i_k][j+j_k][c] * kernel[i_k][j_k][c];
                    }
                }
            }
        }
    }
} */

void leakyReLU(float *** input, float *** output, int input_height, int input_width, int input_channels)
{
    for (int i = 0; i < input_height; i++)
    {
        for (int j = 0; j < input_width; j++)
        {
            for (int c = 0; c < input_channels; c++)
            {
                if (input[i][j][c] >= 0.1*input[i][j][c])
                {
                    output[i][j][c] = input[i][j][c];
                } else {
                    output[i][j][c] = 0.1*input[i][j][c];
                }
            }
        }
    }
  
}

//result = (input - moving_mean)/sqrt(moving_var + eps) * gamma + beta;
void batch_norm(float *** input, int input_height, int input_width, int input_channels, float * moving_mean, float * moving_var, float *** result, float * gamma, float * beta)
{
    float eps = .001;
    
    for (int i = 0; i < input_height; i++)
    {
        for (int j = 0; j < input_width; j++)
        {
            for (int k = 0; k < input_channels; k++)
            {
                result[i][j][k] = (input[i][j][k] - moving_mean[k]) /sqrt(moving_var[k] + eps) * gamma[k] + beta[k];
            }
        }
    }
}

void add(float *** input1, float *** input2, int input_width, int input_height, int input_channels, float *** output)
{
    //float output[input_height][input_width][input_channels];
    for (int c = 0; c < input_channels; c++)
    {
        for (int i = 0; i < input_height; i++)
        {
            for (int j = 0; j < input_width; j++)
            {
                output[i][j][c] = input1[i][j][c] + input2[i][j][c];
            }
        }
    }
}

//Should be 4D tensor - batch size, rows, cols, channels
void zero_padding2D(float *** input, int input_height, int input_width, int input_channels, int top, int bottom, int left, int right, float *** result)
{
    int padded_height = input_height + top + bottom;
    int padded_width = input_width + left + right;
    //float padded_input[padded_height][padded_width][input_channels];
    
    for (int i = 0; i < padded_height; i++)
    {
        for (int j = 0; j < padded_width; j++)
        {
            for (int k = 0; k < input_channels; k++)
            {
                if (i >= top && j >= left && i <= (padded_height - bottom - 1)  && j <= (padded_width - right - 1))
                {
                    result[i][j][k] = input[i-top][j-left][k];
                }
                else
                {
                    result[i][j][k] = 0.0;
                }
            }
        }
    }
}

void upsample2D(float *** input, float *** result, int row_factor, int col_factor, int input_channels, int input_height, int input_width)
{
    for (int i = 0; i < input_height; i++)
    {
        for (int i_rep = 0; i_rep < row_factor; i_rep++)
        {
            for (int j = 0; j < input_width; j++)
            {
                for (int j_rep = 0; j_rep < col_factor; j_rep++)
                {
                    for (int c = 0; c < input_channels; c++){
                        result[row_factor * i + i_rep][col_factor * j + j_rep][c] = input[i][j][c];
                    }
                    
                }
            }
        }
    }
}

     
void concatenate(float *** input1, float *** input2, float *** result, int axis, int input1_channels, int input1_height,int input1_width, int input2_channels, int input2_height,int input2_width)
{
    if (axis == 0)
    {
        for (int i = 0; i < input1_height; i++)
        {
            for (int j = 0; j < input1_width; j++)
            {
                for (int k = 0; k < input1_channels; k++)
                {
                    result[j][i][k] = input1[j][i][k];
                    
                }
            }
        }
        
        for (int i = 0; i < input2_height; i++)
        {
            for (int j = 0; j < input2_width; j++)
            {
                for (int k = 0; k < input2_channels; k++)
                {
                    result[i+input1_height][j][k] = input2[i][j][k];
                }
            }
        }
    } else if (axis == 1) {
        for (int i = 0; i < input1_width; i++)
        {
            for (int j = 0; j < input1_height; j++)
            {
                for (int k = 0; k < input1_channels; k++)
                {
                    result[j][i][k] = input1[j][i][k];
                    
                }
            }
        }
        
        for (int i = 0; i < input2_width; i++)
        {
            for (int j = 0; j < input2_height; j++)
            {
                for (int k = 0; k < input2_channels; k++)
                {
                    result[j][i+input1_width][k] = input2[j][i][k];
                }
            }
        }
    } else {
        for (int i = 0; i < input1_channels; i++)
        {
            for (int j = 0; j < input2_height; j++)
            {
                for (int k = 0; k < input2_width; k++)
                {
                    result[j][k][i] = input1[j][k][i];
                    
                }
            }
        }
        
        for (int i = 0; i < input2_channels; i++)
        {
            for (int j = 0; j < input2_height; j++)
            {
                for (int k = 0; k < input2_width; k++)
                {
                    result[j][k][i+input1_channels] = input2[j][k][i];
                }
            }
        }
    }
    
}

void conv(float *** input, float **** kernel, float * bias, float *** result, int input_height, int input_width, int input_channels, int kernel_size, int num_kernels)
{

    // Create padded array
    int p = (0.5)*(- 1 + kernel_size); // will always be even IF FILTER SIZE IS ODD, so do not have to worry about "floor" operation
    int padded_height = input_height + 2*p;
    int padded_width = input_width + 2*p;
    int padded_channels = input_channels;
    float padded_input[padded_height][padded_width][padded_channels];

    for (int i = 0; i < padded_height; i++)
    {
        for (int j = 0; j < padded_width; j++)
        {
            for (int k = 0; k < padded_channels; k++)
            {
                if (i >= p && j >= p && i <= (padded_height - p - 1)  && j <= (padded_width - p - 1))
                {
                    padded_input[i][j][k] = input[i-p][j-p][k];
                }
                else
                {
                    padded_input[i][j][k] = 0.0;
                }
            }
        }
    }

    // print the padded arrays
//    for (int k = 0; k < padded_channels; k++)
//        {
//            for (int i = 0; i < padded_height; i++)
//            {
//               for (int j = 0; j < padded_width; j++)
//               {
//                   printf("%.0f ", padded_input[i][j][k]);
//               }
//               printf("\n");
//            }
//            printf("\n\n");
//        }

    //  compute the convolution
    float sum;
    for (int kernel_num = 0; kernel_num < num_kernels; kernel_num++)
    {
        for (int i = 0; i <= padded_height - kernel_size; i++)
        {
            for (int j = 0; j <= padded_width - kernel_size; j++)
            {
                sum = 0.0;
                for (int i_k = 0; i_k < kernel_size; i_k++)
                {
                    for (int j_k = 0; j_k < kernel_size; j_k++)
                    {
                        for (int c = 0; c < padded_channels; c++)
                        {
                            sum +=  kernel[kernel_num][i_k][j_k][c]*padded_input[i+i_k][j+j_k][c];
                        }
                    }
                }
                sum += bias[kernel_num];
                result[i][j][kernel_num] = sum;
                /*// ReLU = max(0, x)
                if (sum >= 0) {
                    result[i][j][kernel_num] = sum;
                }
                else
                {
                    result[i][j][kernel_num] = 0;
                } */
            }
        }
    }



}

// Implements 'valid' padding = 'same' padding when P = 0
// This function has been tested, don't touch!
void nn_pool(float *** input, float *** output, int input_height, int input_width, int input_channels, int pool_size, int stride)
{

    float max_list[pool_size*pool_size];

    float k_max;
    for (int c = 0; c < input_channels; c++)
    {
        int o_i = 0;
        int o_j = 0;
        //stride = pool_size (generally)
        for (int i = 0; i < input_height; i += stride, o_i +=1, o_j = 0)
        {
            for (int j = 0; j < input_width; j+= stride, o_j += 1)
            {
                int count = 0;
                for (int ii = 0; ii < pool_size; ii++)
                {
                    for (int jj = 0; jj < pool_size; jj++)
                    {
                        max_list[count] = input[i+ii][j+jj][c];
                        count += 1;
                    }
                }
                k_max = max_array(max_list, pool_size*pool_size);
                output[o_i][o_j][c] = k_max;
            }
        }
    }

}

// Implements 'same' padding max pooling as prescribed by:
// https://stackoverflow.com/questions/37674306/what-is-the-difference-between-same-and-valid-padding-in-tf-nn-max-pool-of-t
void max_pool2D_same_padded(float *** input, float *** output, int input_height, int input_width, int input_channels, int pool_size, int stride)
{

    // For S = 1:
    // P = ceil((F-1)/2) = 1 for our case
    int p = 1;// (int) ceil((0.5)*(- 1 + pool_size));
    int padded_height = input_height + 2*p;
    int padded_width = input_width + 2*p;
    int padded_channels = input_channels;
    float padded_input[padded_height][padded_width][padded_channels];

    for (int i = 0; i < padded_height; i++)
    {
        for (int j = 0; j < padded_width; j++)
        {
            for (int k = 0; k < padded_channels; k++)
            {
                if (i >= p && j >= p && i <= (padded_height - p - 1)  && j <= (padded_width - p - 1))
                {
                    padded_input[i][j][k] = input[i-p][j-p][k];
                }
                else
                {
                    padded_input[i][j][k] = -100000000000.0;
                }
            }
        }
    }
    
    float max_list[pool_size*pool_size];

    float k_max;
    for (int c = 0; c < input_channels; c++)
    {
        int o_i = 0;
        int o_j = 0;
        // we start at p=1 becaus when number of columns to be added is odd -> it's added to just
        // right and bottom of array (so only consider padding on right/bottom of array)
        for (int i = p; i < padded_height-p; i += stride, o_i +=1, o_j = 0) // 1 <= i <= 10, 1<=j<=10
        {
            for (int j = p; j < padded_width-p; j+= stride, o_j += 1)
            {
                int count = 0;
                for (int ii = 0; ii < pool_size; ii++)
                {
                    for (int jj = 0; jj < pool_size; jj++)
                    {
                        // TODO
                        max_list[count] = padded_input[i+ii][j+jj][c];
                        count += 1;
                    }
                }
                k_max = max_array(max_list, pool_size*pool_size);
                output[o_i][o_j][c] = k_max;
            }
        }
    }

}

// kernel: (output_size x input_size)
void dense(float * input, float ** kernel, float * bias, double * output, int input_size, int output_size)
{
    float sum;
    for (int i = 0; i < output_size; i++)
    {
        sum = 0;
        for (int j = 0; j < input_size; j++)
        {
            sum += input[j]*kernel[j][i];
        }
        output[i] =  (double) (sum + bias[i]);
    }

    double softmax_sum = 0.0;
    for (int i = 0; i < output_size; i++)
    {
        softmax_sum += exp(output[i]);
    }
    for (int i = 0; i < output_size; i++)
    {
        output[i] = exp(output[i])/softmax_sum;
    }

}

void flatten3D(float *** input, float * result, int input_height, int input_width, int input_channels)
{
    int t = 0;
    for (int i = 0; i < input_height; i++)
    {
        for (int j = 0; j < input_width; j++)
        {
            for (int k = 0; k < input_channels; k++)
            {
                result[t] = input[i][j][k];
                t += 1;
            }
        }
    }

}

void unflatten2D(float * input, float ** result, int output_height, int output_width)
{
    int i_o = 0;
    int j_o = 0;
    int input_length = output_height * output_width;

    for (int i = 0; i < input_length; i++)
    {
        result[i_o][j_o] = input[i];
        j_o += 1;
        if (j_o == output_width)
        {
            i_o += 1;
            j_o = 0;
        }
    }
}

void unflatten3D(float * input, float *** result, int output_height, int output_width, int output_channels)
{
    int i_o = 0;
    int j_o = 0;
    int c_o = 0;

    int input_length = output_height*output_width*output_channels;

    for (int i = 0; i < input_length; i++)
    {
        result[i_o][j_o][c_o] = input[i];
        c_o += 1;
        if (c_o == output_channels)
        {
            c_o = 0;
            j_o += 1;
            if (j_o == output_width)
            {
                j_o = 0;
                i_o += 1;
            }
        }
    }
}

void unflatten4D(float * input, float **** result, int num_kernels, int output_height, int output_width, int output_channels)
{
    int kernel_num = 0;
    int i_o = 0;
    int j_o = 0;
    int c_o = 0;

    int input_length = num_kernels*output_height*output_width*output_channels;

    for (int i = 0; i < input_length; i++)
    {
        result[kernel_num][i_o][j_o][c_o] = input[i];
        kernel_num += 1;
        if (kernel_num == num_kernels)
        {
            kernel_num = 0;
            c_o += 1;
            if (c_o == output_channels)
            {
                c_o = 0;
                j_o += 1;
                if (j_o == output_width)
                {
                    j_o = 0;
                    i_o += 1;
                }
            }
        }

    }
}

float max_array(float input[], int input_length)
{
    float curr_max = input[0];
    for (int i = 0; i < input_length; i++)
    {
        if (input[i] > curr_max)
            curr_max = input[i];
    }
    return curr_max;
}

float ** allocate_2Darray(int row_size, int col_size)
{
    float ** array = (float**)calloc(row_size, sizeof(float*));
    for (int i = 0; i < row_size; i++)
        array[i] = (float*)calloc(col_size, sizeof(float));
    return array;
}

void deallocate_2Darray(float** array, int row_size)
{
    for (int i = 0; i < row_size; i++)
        free(array[i]);
    free(array);
}

float *** allocate_3Darray(int row_size, int col_size, int depth_size)
{
    float *** array = (float***)calloc(row_size, sizeof(float**));
    for (int i = 0; i < row_size; i++)
        array[i] = (float**)calloc(col_size, sizeof(float*));
    for (int i = 0; i < row_size; i++)
        for (int j = 0; j < col_size; j++)
            array[i][j] = (float*)calloc(depth_size, sizeof(float));

    return array;
//     float *** array = (float***)malloc(row_size * sizeof(float**));
//     for (int i = 0; i < row_size; i++)
//         array[i] = (float**)malloc(col_size * sizeof(float*));
//     for (int i = 0; i < row_size; i++)
//         for (int j = 0; j < col_size; j++)
//             array[i][j] = (float*)malloc(depth_size);
//
//     return array;
}

void deallocate_3Darray(float *** a, int row_size, int col_size)
{
    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            free(a[i][j]);
        }
    }
    for (int i = 0; i < row_size; i++) {
        free(a[i]);
    }
    free(a);
}

float **** allocate_4Darray(int num_blocks, int row_size, int col_size, int depth_size)
{
    float**** array;
    array = (float****)calloc(num_blocks, sizeof(float***));
    for (int i = 0; i < num_blocks; i++)
        array[i] = (float***)calloc(row_size, sizeof(float**));

    for (int i = 0; i < num_blocks; i++)
        for (int j = 0; j < row_size; j++)
            array[i][j] = (float**)calloc(col_size, sizeof(float*));

    for (int i = 0; i < num_blocks; i++)
        for (int j = 0; j < row_size; j++)
            for (int k = 0; k < col_size; k++)
                array[i][j][k] = (float*)calloc(depth_size, sizeof(float));

    return array;
//    float**** array;
//    array = (float****)malloc(num_blocks * sizeof(float***));
//    for (int i = 0; i < num_blocks; i++)
//        array[i] = (float***)malloc(row_size * sizeof(float**));
//
//    for (int i = 0; i < num_blocks; i++)
//        for (int j = 0; j < row_size; j++)
//            array[i][j] = (float**)malloc(col_size*sizeof(float*));
//
//    for (int i = 0; i < num_blocks; i++)
//        for (int j = 0; j < row_size; j++)
//            for (int k = 0; k < col_size; k++)
//                array[i][j][k] = (float*)malloc(depth_size);
//
//    return array;
}

void deallocate_4Darray(float **** a, int num_blocks, int row_size, int col_size)
{
    for (int i = 0; i < num_blocks; i++)
        for (int j = 0; j < row_size; j++)
            for (int k = 0; k < col_size; k++)
                free(a[i][j][k]);

    for (int i = 0; i < num_blocks; i++)
        for (int j = 0; j < row_size; j++)
            free(a[i][j]);

    for (int i = 0; i < num_blocks; i++)
        free(a[i]);

    free(a);

}

void write_float_array(FILE *f, float * v,  int nmemb) {
  fwrite(v, sizeof(float), nmemb, f);
}

void read_float_array(FILE *f, float *v, int nmemb) {
    fread(v, sizeof(float), nmemb, f);
}