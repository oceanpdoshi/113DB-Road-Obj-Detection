//
//  cnn.h
//  EE113D Project
//
//  Created by Jamie Yang on 2/20/21.
//  Copyright © 2021 Jamie Yang. All rights reserved.
//

#ifndef cnn_h
#define cnn_h
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>


// Padding will always be 'same', all filters are 3x3xc and all layer outputs are 28x28xc
//(W−F+2P)/S+1 = Output size
//void depthwise_conv2d(float ***input, float *** kernel, float * bias, float *** result, int input_height, int input_width, int input_channels, int kernel_size, int num_kernels);
void leakyReLU(float *** input, float *** output, int input_height, int input_width, int input_channels);
void batch_norm(float *** input, int input_height, int input_width, int input_channels, float * moving_mean, float * moving_var, float *** result, float * gamma, float * beta);
void add(float *** input1, float *** input2, int input_width, int input_height, int input_channels, float *** result);
//void zero_padding2D(float *** input, int input_height, int input_width, int input_channels, int top, int bottom, int left, int right, float *** result);
void upsample2D(float *** input, float *** result, int row_factor, int col_factor, int input_channels, int input_height, int input_width);
void concatenate(float *** input1, float *** input2, float *** result, int axis, int input1_channels, int input1_height,int input1_width, int input2_channels, int input2_height,int input2_width);
void conv(float *** input, float **** kernel, float * bias, float *** result, int input_height, int input_width, int input_channel, int kernel_size, int num_kernels);
void nn_pool(float *** input, float *** output, int input_height, int input_width, int input_channels, int pool_size, int stride);
void max_pool2D_same_padded(float *** input, float *** output, int input_height, int input_width, int input_channels, int pool_size, int strides);
void dense(float * input, float ** kernel, float * bias, double * output, int input_size, int output_size);

void flatten3D(float *** input, float * result, int input_height, int input_width, int input_channels);

void unflatten2D(float * input, float ** result, int output_height, int output_width);
void unflatten3D(float * input, float *** result, int output_height, int output_width, int output_channels);
void unflatten4D(float * input, float **** result, int num_kernels, int output_height, int output_width, int output_channels);

float max_array(float input[], int input_length);

float ** allocate_2Darray(int row_size, int col_size);
void deallocate_2Darray(float** array, int row_size);

float *** allocate_3Darray(int row_size, int col_size, int depth_size);
void deallocate_3Darray(float *** a, int row_size, int col_size);

float **** allocate_4Darray(int num_blocks, int row_size, int col_size, int depth_size);
void deallocate_4Darray(float **** a, int num_blocks, int row_size, int col_size);

void write_float_array(FILE *f, float * v,  int nmemb);
void read_float_array(FILE *f, float *v, int nmemb);


#endif /* cnn_h */


