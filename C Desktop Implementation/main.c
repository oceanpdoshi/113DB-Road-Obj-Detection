//
//  main.c
//  EE113D Project
//
//  Created by Jamie Yang on 2/20/21.
//  Copyright © 2021 Jamie Yang. All rights reserved.
//

#include <stdio.h>
#include "include\cnn.c"
#include <unistd.h>
#include <dirent.h>

int main()
{
    
    //Checks if we are in the right path
    // char path[] = "D:/Desktop/project C files/main.c";
    // if (chdir(path) != 0)
    // {
    //     printf("Failed to change directory.\n");
    // }
    char cwd[500];

    getcwd(cwd, 500);
    printf("Current working dir: %s\n", cwd);
    
    //Load in Input (Image)
    
    FILE * inputFile;
    inputFile = fopen("test_images/test_bin_image0.float32","rb"); //Input file path/name TODO - change img_num
    
    if(inputFile == 0) {
        perror("fopen");
        exit(1);
    }
    
    float * input_flat = calloc(320*320*3, sizeof(float));
    read_float_array(inputFile, input_flat, 320*320*3);
    fclose(inputFile);
    
    float *** input;
    input = allocate_3Darray(320, 320, 3);
    unflatten3D(input_flat, input, 320, 320, 3);
    
    //CONV_2D
    FILE * w_conv2D_file;
    w_conv2D_file = fopen("layer_weights/conv2d.w","rb");
    float * w_conv2d_flattened = calloc(432, sizeof(float));
    read_float_array(w_conv2D_file, w_conv2d_flattened, 432);
    fclose(w_conv2D_file);
    
    float **** w_conv2D;
    w_conv2D = allocate_4Darray(16, 3, 3, 3);
    unflatten4D(w_conv2d_flattened, w_conv2D, 16, 3, 3, 3);
    free(w_conv2d_flattened);
    
    float * b_conv2D = calloc(16, sizeof(float)); //Calloc auto sets memory to 0
    float *** output_conv2D;
    output_conv2D = allocate_3Darray(320, 320, 16);
    conv(input, w_conv2D, b_conv2D, output_conv2D, 320, 320, 3, 3, 16); //kernel size, number of kernels
    deallocate_3Darray(input, 320, 320);
    deallocate_4Darray(w_conv2D, 16, 3, 3);
    free(b_conv2D);
    
    FILE * conv2D_file;
    conv2D_file = fopen("C_outputs/conv2d_output.float32", "wb");
    float * output_conv2D_flat = calloc(320*320*16, sizeof(float));
    flatten3D(output_conv2D, output_conv2D_flat, 320, 320, 16);
    write_float_array(conv2D_file, output_conv2D_flat, 320*320*16);
    free(output_conv2D_flat);
    fclose(conv2D_file);
    
    //Batch_Normalization
    FILE * beta_BN_file;
    beta_BN_file = fopen("layer_weights/batch_normalization.beta", "rb");
    float * beta_BN = calloc(16, sizeof(float));
    read_float_array(beta_BN_file, beta_BN, 16);
    fclose(beta_BN_file);
    
    FILE * gamma_BN_file;
    gamma_BN_file = fopen("layer_weights/batch_normalization.gamma", "rb");
    float * gamma_BN = calloc(16, sizeof(float));
    read_float_array(gamma_BN_file, gamma_BN, 16);
    fclose(gamma_BN_file);
    
    
    FILE * moving_mean_BN_file;
    moving_mean_BN_file = fopen("layer_weights/batch_normalization.moving_mean","rb");
    float * moving_mean_BN = calloc(16, sizeof(float)); //CHECK
    read_float_array(moving_mean_BN_file, moving_mean_BN, 16);
    fclose(moving_mean_BN_file);
    
    FILE * moving_var_BN_file;
    moving_var_BN_file = fopen("layer_weights/batch_normalization.moving_variance", "rb");
    float * moving_var_BN = calloc(16, sizeof(float)); //CHECK
    read_float_array(moving_var_BN_file, moving_var_BN, 16);
    fclose(moving_var_BN_file);
    
    float *** output_BN;
    output_BN = allocate_3Darray(320, 320, 16);
    batch_norm(output_conv2D, 320, 320, 16, moving_mean_BN, moving_var_BN, output_BN, gamma_BN, beta_BN);
    deallocate_3Darray(output_conv2D, 320, 320);
    free(moving_mean_BN);
    free(moving_var_BN);
    free(beta_BN);
    free(gamma_BN);
    
    FILE * batch_normalization_file;
    batch_normalization_file = fopen("C_outputs/batch_normalization_output.float32", "wb");
    float * output_BN_flat = calloc(320*320*16, sizeof(float));
    flatten3D(output_BN, output_BN_flat, 320, 320, 16);
    write_float_array(batch_normalization_file, output_BN_flat, 320*320*16);
    free(output_BN_flat);
    fclose(batch_normalization_file);
    
    //Leaky_RELU
    float *** output_leakyRELU;
    output_leakyRELU = allocate_3Darray(320, 320, 16);
    leakyReLU(output_BN, output_leakyRELU, 320, 320, 16);
    deallocate_3Darray(output_BN, 320, 320);
    
    FILE * leakyRELU_file;
    leakyRELU_file = fopen("C_outputs/leaky_re_lu_output.float32", "wb");
    float * output_leakyRELU_flat = calloc(320*320*16, sizeof(float));
    flatten3D(output_leakyRELU, output_leakyRELU_flat, 320, 320, 16);
    write_float_array(leakyRELU_file, output_leakyRELU_flat, 320*320*16);
    free(output_leakyRELU_flat);
    fclose(leakyRELU_file);
    
    //MaxPooling2D
    float *** output_MaxPooling2D;
    output_MaxPooling2D = allocate_3Darray(160, 160, 16);
    nn_pool(output_leakyRELU, output_MaxPooling2D, 320, 320, 16, 2, 2);
    deallocate_3Darray(output_leakyRELU, 320, 320);
    
    FILE * MaxPooling2D_file;
    MaxPooling2D_file = fopen("C_outputs/max_pooling2d_output.float32", "wb");
    float * output_MaxPooling2D_flat = calloc(160*160*16, sizeof(float));
    flatten3D(output_MaxPooling2D, output_MaxPooling2D_flat, 160, 160, 16);
    write_float_array(MaxPooling2D_file, output_MaxPooling2D_flat, 160*160*16);
    free(output_MaxPooling2D_flat);
    fclose(MaxPooling2D_file);
    
    //CONV2D_1
    FILE * w_conv2D_1_file;
    w_conv2D_1_file = fopen("layer_weights/conv2d_1.w","rb");
    float * w_conv2D_1_flattened = calloc(3*3*16*32, sizeof(float));
    read_float_array(w_conv2D_1_file, w_conv2D_1_flattened, 3*3*16*32);
    fclose(w_conv2D_1_file);
    
    float **** w_conv2D_1;
    w_conv2D_1 = allocate_4Darray(32, 3, 3, 16);
    unflatten4D(w_conv2D_1_flattened, w_conv2D_1, 32, 3, 3, 16);
    free(w_conv2D_1_flattened);
    
    float * b_conv2D_1 = calloc(32, sizeof(float));
    float *** output_conv2D_1;
    output_conv2D_1 = allocate_3Darray(160, 160, 32);
    conv(output_MaxPooling2D, w_conv2D_1, b_conv2D_1, output_conv2D_1, 160, 160, 16, 3, 32); //double
    deallocate_3Darray(output_MaxPooling2D, 160, 160);
    deallocate_4Darray(w_conv2D_1, 32, 3, 3);
    free(b_conv2D_1);
    
    FILE * conv2D_1_file;
    conv2D_1_file = fopen("C_outputs/conv2d_1_output.float32", "wb");
    float * output_conv2D_1_flat = calloc(160*160*32, sizeof(float));
    flatten3D(output_conv2D_1, output_conv2D_1_flat, 160, 160, 32);
    write_float_array(conv2D_1_file, output_conv2D_1_flat, 160*160*32);
    free(output_conv2D_1_flat);
    fclose(conv2D_1_file);
    
    //Batch_Normalization_1
    FILE * beta_BN_1_file;
    beta_BN_1_file = fopen("layer_weights/batch_normalization_1.beta", "rb");
    float * beta_BN_1 = calloc(32, sizeof(float)); //CHECK if nmembs = 32
    read_float_array(beta_BN_1_file, beta_BN_1, 32);
    fclose(beta_BN_1_file);
    
    FILE * gamma_BN_1_file;
    gamma_BN_1_file = fopen("layer_weights/batch_normalization_1.gamma", "rb");
    float * gamma_BN_1 = calloc(32, sizeof(float)); //CHECK
    read_float_array(gamma_BN_1_file, gamma_BN_1, 32);
    fclose(gamma_BN_1_file);
    
    FILE * moving_mean_BN_1_file;
    moving_mean_BN_1_file = fopen("layer_weights/batch_normalization_1.moving_mean","rb");
    float * moving_mean_BN_1= calloc(32, sizeof(float)); //CHECK
    read_float_array(moving_mean_BN_1_file, moving_mean_BN_1, 32);
    fclose(moving_mean_BN_1_file);
    
    FILE * moving_var_BN_1_file;
    moving_var_BN_1_file = fopen("layer_weights/batch_normalization_1.moving_variance", "rb");
    float * moving_var_BN_1 = calloc(32, sizeof(float)); //CHECK
    read_float_array(moving_var_BN_1_file, moving_var_BN_1, 32);
    fclose(moving_var_BN_1_file);
    
    float *** output_BN_1;
    output_BN_1 = allocate_3Darray(160, 160, 32);
    batch_norm(output_conv2D_1, 160, 160, 32, moving_mean_BN_1, moving_var_BN_1, output_BN_1, gamma_BN_1, beta_BN_1);
    deallocate_3Darray(output_conv2D_1, 160, 160);
    free(moving_var_BN_1);
    free(moving_mean_BN_1);
    free(beta_BN_1);
    free(gamma_BN_1);
    
    FILE * batch_normalization_1_file;
    batch_normalization_1_file = fopen("C_outputs/batch_normalization_1_output.float32","wb");
    float * output_BN_1_flat = calloc(160*160*32, sizeof(float));
    flatten3D(output_BN_1, output_BN_1_flat, 160, 160, 32);
    write_float_array(batch_normalization_1_file, output_BN_1_flat, 160*160*32);
    free(output_BN_1_flat);
    fclose(batch_normalization_1_file);
    
    
    //Leaky_RELU_1
    float *** output_leakyRELU_1;
    output_leakyRELU_1 = allocate_3Darray(160, 160, 32);
    leakyReLU(output_BN_1, output_leakyRELU_1, 160, 160, 32);
    deallocate_3Darray(output_BN_1, 160, 160);
    
    FILE * leakyRELU_1_file;
    leakyRELU_1_file = fopen("C_outputs/leaky_re_lu_1_output.float32", "wb");
    float * output_leakyRELU_1_flat = calloc(160*160*32, sizeof(float));
    flatten3D(output_leakyRELU_1, output_leakyRELU_1_flat, 160, 160, 32);
    write_float_array(leakyRELU_1_file, output_leakyRELU_1_flat, 160*160*32);
    free(output_leakyRELU_1_flat);
    fclose(leakyRELU_1_file);
    
    //MaxPooling2D_1
    float *** output_MaxPooling2D_1;
    output_MaxPooling2D_1 = allocate_3Darray(80, 80, 32);
    nn_pool(output_leakyRELU_1, output_MaxPooling2D_1, 160, 160, 32, 2, 2);
    deallocate_3Darray(output_leakyRELU_1, 160, 160);
    
    FILE * MaxPooling2D_1_file;
    MaxPooling2D_1_file = fopen("C_outputs/max_pooling2d_1_output.float32", "wb");
    float * output_MaxPooling2D_1_flat = calloc(80*80*32, sizeof(float));
    flatten3D(output_MaxPooling2D_1, output_MaxPooling2D_1_flat, 80, 80, 32);
    write_float_array(MaxPooling2D_1_file, output_MaxPooling2D_1_flat, 80*80*32);
    free(output_MaxPooling2D_1_flat);
    fclose(MaxPooling2D_1_file);
    
    //CONV2D_2
    FILE * w_conv2D_2_file;
    w_conv2D_2_file = fopen("layer_weights/conv2d_2.w", "rb");
    float * w_conv2D_2_flattened = calloc(3*3*32*64, sizeof(float));
    read_float_array(w_conv2D_2_file, w_conv2D_2_flattened, 3*3*32*64);
    fclose(w_conv2D_2_file);
    
    float **** w_conv2D_2;
    w_conv2D_2 = allocate_4Darray(64, 3, 3, 32);
    unflatten4D(w_conv2D_2_flattened, w_conv2D_2, 64, 3, 3, 32);
    free(w_conv2D_2_flattened);
    
    float * b_conv2D_2 = calloc(64, sizeof(float));
    float *** output_conv2D_2;
    output_conv2D_2 = allocate_3Darray(80, 80, 64);
    conv(output_MaxPooling2D_1, w_conv2D_2, b_conv2D_2, output_conv2D_2, 80, 80, 32, 3, 64);
    deallocate_3Darray(output_MaxPooling2D_1, 80, 80);
    deallocate_4Darray(w_conv2D_2, 64, 3, 3);
    free(b_conv2D_2);
    
    FILE * conv2D_2_file;
    conv2D_2_file = fopen("C_outputs/conv2d_2_output.float32", "wb");
    float * output_conv2D_2_flat = calloc(80*80*64, sizeof(float));
    flatten3D(output_conv2D_2, output_conv2D_2_flat, 80, 80, 64);
    write_float_array(conv2D_2_file, output_conv2D_2_flat, 80*80*64);
    free(output_conv2D_2_flat);
    fclose(conv2D_2_file);
    
    
    //Batch_Normalization_2
    FILE * beta_BN_2_file;
    beta_BN_2_file = fopen("layer_weights/batch_normalization_2.beta", "rb");
    float * beta_BN_2 = calloc(64, sizeof(float)); //CHECK if nmembs = 64
    read_float_array(beta_BN_2_file, beta_BN_2, 64);
    fclose(beta_BN_2_file);
    
    FILE * gamma_BN_2_file;
    gamma_BN_2_file = fopen("layer_weights/batch_normalization_2.gamma", "rb");
    float * gamma_BN_2 = calloc(64, sizeof(float)); //CHECK
    read_float_array(gamma_BN_2_file, gamma_BN_2, 64);
    fclose(gamma_BN_2_file);
    
    FILE * moving_mean_BN_2_file;
    moving_mean_BN_2_file = fopen("layer_weights/batch_normalization_2.moving_mean","rb");
    float * moving_mean_BN_2 = calloc(64, sizeof(float)); //CHECK
    read_float_array(moving_mean_BN_2_file, moving_mean_BN_2, 64);
    fclose(moving_mean_BN_2_file);
    
    FILE * moving_var_BN_2_file;
    moving_var_BN_2_file = fopen("layer_weights/batch_normalization_2.moving_variance", "rb");
    float * moving_var_BN_2 = calloc(64, sizeof(float)); //CHECK
    read_float_array(moving_var_BN_2_file, moving_var_BN_2, 64);
    fclose(moving_var_BN_2_file);
    
    float *** output_BN_2;
    output_BN_2 = allocate_3Darray(80, 80, 64);
    batch_norm(output_conv2D_2, 80, 80, 64, moving_mean_BN_2, moving_var_BN_2, output_BN_2, gamma_BN_2, beta_BN_2);
    deallocate_3Darray(output_conv2D_2, 80, 80);
    free(moving_var_BN_2);
    free(moving_mean_BN_2);
    free(beta_BN_2);
    free(gamma_BN_2);
    
    FILE * batch_normalization_2_file;
    batch_normalization_2_file = fopen("C_outputs/batch_normalization_2_output.float32", "wb");
    float * output_BN_2_flat = calloc(80*80*64, sizeof(float));
    flatten3D(output_BN_2, output_BN_2_flat, 80, 80, 64);
    write_float_array(batch_normalization_2_file, output_BN_2_flat, 80*80*64);
    free(output_BN_2_flat);
    fclose(batch_normalization_2_file);
    
    //Leak_RELU_2
    float *** output_leakyRELU_2;
    output_leakyRELU_2 = allocate_3Darray(80, 80, 64);
    leakyReLU(output_BN_2, output_leakyRELU_2, 80, 80, 64);
    deallocate_3Darray(output_BN_2, 80, 80);
    
    FILE * leakyRELU_2_file;
    leakyRELU_2_file = fopen("C_outputs/leaky_re_lu_2_output.float32", "wb");
    float * output_leakyRELU_2_flat = calloc(80*80*64, sizeof(float));
    flatten3D(output_leakyRELU_2, output_leakyRELU_2_flat, 80, 80, 64);
    write_float_array(leakyRELU_2_file, output_leakyRELU_2_flat, 80*80*64);
    free(output_leakyRELU_2_flat);
    fclose(leakyRELU_2_file);
    
    //MaxPooling2D_2
    float *** output_MaxPooling2D_2;
    output_MaxPooling2D_2 = allocate_3Darray(40, 40, 64);
    nn_pool(output_leakyRELU_2, output_MaxPooling2D_2, 80, 80, 64, 2, 2);
    deallocate_3Darray(output_leakyRELU_2, 80, 80);
    
    FILE * MaxPooling2D_2_file;
    MaxPooling2D_2_file = fopen("C_outputs/max_pooling2d_2_output.float32", "wb");
    float * output_MaxPooling2D_2_flat = calloc(40*40*64, sizeof(float));
    flatten3D(output_MaxPooling2D_2, output_MaxPooling2D_2_flat, 40, 40, 64);
    write_float_array(MaxPooling2D_2_file, output_MaxPooling2D_2_flat, 40*40*64);
    free(output_MaxPooling2D_2_flat);
    fclose(MaxPooling2D_2_file);
    
    //CONV2D_3
    FILE * w_conv2D_3_file;
    w_conv2D_3_file = fopen("layer_weights/conv2d_3.w","rb");
    float * w_conv2D_3_flattened = calloc(3*3*64*128, sizeof(float));
    read_float_array(w_conv2D_3_file, w_conv2D_3_flattened, 3*3*64*128);
    fclose(w_conv2D_3_file);
    
    float **** w_conv2D_3;
    w_conv2D_3 = allocate_4Darray(128, 3, 3, 64);
    unflatten4D(w_conv2D_3_flattened, w_conv2D_3, 128,3, 3, 64);
    free(w_conv2D_3_flattened);
    
    float * b_conv2D_3 = calloc(128, sizeof(float));
    float *** output_conv2D_3;
    output_conv2D_3 = allocate_3Darray(40, 40, 128);
    conv(output_MaxPooling2D_2, w_conv2D_3, b_conv2D_3, output_conv2D_3, 40, 40, 64, 3, 128);
    deallocate_3Darray(output_MaxPooling2D_2, 40, 40);
    deallocate_4Darray(w_conv2D_3, 128, 3, 3);
    free(b_conv2D_3);
    
    FILE * conv2D_3_file;
    conv2D_3_file = fopen("C_outputs/conv2d_3_output.float32", "wb");
    float * output_conv2D_3_flat = calloc(40*40*128, sizeof(float));
    flatten3D(output_conv2D_3, output_conv2D_3_flat, 40, 40, 128);
    write_float_array(conv2D_3_file, output_conv2D_3_flat, 40*40*128);
    free(output_conv2D_3_flat);
    fclose(conv2D_3_file);

    
    //Batch_Normalization_3
    FILE * beta_BN_3_file;
    beta_BN_3_file = fopen("layer_weights/batch_normalization_3.beta", "rb");
    float * beta_BN_3 = calloc(128, sizeof(float)); //CHECK if nmembs = 128
    read_float_array(beta_BN_3_file, beta_BN_3, 128);
    fclose(beta_BN_3_file);
    
    FILE * gamma_BN_3_file;
    gamma_BN_3_file = fopen("layer_weights/batch_normalization_3.gamma", "rb");
    float * gamma_BN_3 = calloc(128, sizeof(float)); //CHECK
    read_float_array(gamma_BN_3_file, gamma_BN_3, 128);
    fclose(gamma_BN_3_file);
    
    FILE * moving_mean_BN_3_file;
    moving_mean_BN_3_file = fopen("layer_weights/batch_normalization_3.moving_mean","rb");
    float * moving_mean_BN_3 = calloc(128, sizeof(float)); //CHECK
    read_float_array(moving_mean_BN_3_file, moving_mean_BN_3, 128);
    fclose(moving_mean_BN_3_file);
    
    FILE * moving_var_BN_3_file;
    moving_var_BN_3_file = fopen("layer_weights/batch_normalization_3.moving_variance", "rb");
    float * moving_var_BN_3 = calloc(128, sizeof(float)); //CHECK
    read_float_array(moving_var_BN_3_file, moving_var_BN_3, 128);
    fclose(moving_var_BN_3_file);
    
    float *** output_BN_3;
    output_BN_3 = allocate_3Darray(40, 40, 128);
    batch_norm(output_conv2D_3, 40, 40, 128, moving_mean_BN_3, moving_var_BN_3, output_BN_3, gamma_BN_3, beta_BN_3);
    deallocate_3Darray(output_conv2D_3, 40, 40);
    free(moving_mean_BN_3);
    free(moving_var_BN_3);
    free(gamma_BN_3);
    free(beta_BN_3);
    
    FILE * batch_normalization_3_file;
    batch_normalization_3_file = fopen("C_outputs/batch_normalization_3_output.float32","wb");
    float * output_BN_3_flat = calloc(40*40*128, sizeof(float));
    flatten3D(output_BN_3, output_BN_3_flat, 40, 40, 128);
    write_float_array(batch_normalization_3_file, output_BN_3_flat, 40*40*128);
    free(output_BN_3_flat);
    fclose(batch_normalization_3_file);
    
    //Leaky_RELU_3
    float *** output_leakyRELU_3;
    output_leakyRELU_3 = allocate_3Darray(40, 40, 128);
    leakyReLU(output_BN_3, output_leakyRELU_3, 40, 40, 128);
    deallocate_3Darray(output_BN_3, 40, 40);
    
    FILE * leakyRELU_3_file;
    leakyRELU_3_file = fopen("C_outputs/leaky_re_lu_3_output.float32", "wb");
    float * output_leakyRELU_3_flat = calloc(40*40*128, sizeof(float));
    flatten3D(output_leakyRELU_3, output_leakyRELU_3_flat, 40, 40, 128);
    write_float_array(leakyRELU_3_file, output_leakyRELU_3_flat, 40*40*128);
    free(output_leakyRELU_3_flat);
    fclose(leakyRELU_3_file);
    
    //MaxPooling2D_3
    float *** output_MaxPooling2D_3;
    output_MaxPooling2D_3 = allocate_3Darray(20, 20, 128);
    nn_pool(output_leakyRELU_3, output_MaxPooling2D_3, 40, 40, 128, 2, 2);
    deallocate_3Darray(output_leakyRELU_3, 40, 40);
    
    FILE * MaxPooling2D_3_file;
    MaxPooling2D_3_file = fopen("C_outputs/max_pooling2d_3_output.float32", "wb");
    float * output_MaxPooling2D_3_flat = calloc(20*20*128, sizeof(float));
    flatten3D(output_MaxPooling2D_3, output_MaxPooling2D_3_flat, 20, 20, 128);
    write_float_array(MaxPooling2D_3_file, output_MaxPooling2D_3_flat, 20*20*128);
    free(output_MaxPooling2D_3_flat);
    fclose(MaxPooling2D_3_file);
    
    //CONV2D_4
    FILE * w_conv2D_4_file;
    w_conv2D_4_file = fopen("layer_weights/conv2d_4.w", "rb");
    float * w_conv2D_4_flattened = calloc(3*3*128*256, sizeof(float));
    read_float_array(w_conv2D_4_file, w_conv2D_4_flattened, 3*3*128*256);
    fclose(w_conv2D_4_file);
    
    float **** w_conv2D_4;
    w_conv2D_4 = allocate_4Darray(256, 3, 3, 128);
    unflatten4D(w_conv2D_4_flattened, w_conv2D_4, 256, 3, 3, 128);
    free(w_conv2D_4_flattened);
    
    float * b_conv2D_4 = calloc(256, sizeof(float));
    float *** output_conv2D_4;
    output_conv2D_4 = allocate_3Darray(20, 20, 256);
    conv(output_MaxPooling2D_3, w_conv2D_4, b_conv2D_4, output_conv2D_4, 20, 20, 128, 3, 256);
    deallocate_3Darray(output_MaxPooling2D_3, 20, 20);
    deallocate_4Darray(w_conv2D_4, 256, 3, 3);
    
    FILE * conv2D_4_file;
    conv2D_4_file = fopen("C_outputs/conv2d_4_output.float32", "wb");
    float * output_conv2D_4_flat = calloc(20*20*256, sizeof(float));
    flatten3D(output_conv2D_4, output_conv2D_4_flat, 20, 20, 256);
    write_float_array(conv2D_4_file, output_conv2D_4_flat, 20*20*256);
    free(output_conv2D_4_flat);
    fclose(conv2D_4_file);

    
    //Batch_Normalization_4
    FILE * beta_BN_4_file;
    beta_BN_4_file = fopen("layer_weights/batch_normalization_4.beta", "rb");
    float * beta_BN_4 = calloc(256, sizeof(float)); //CHECK if nmembs = 256
    read_float_array(beta_BN_4_file, beta_BN_4, 256);
    fclose(beta_BN_4_file);
    
    FILE * gamma_BN_4_file;
    gamma_BN_4_file = fopen("layer_weights/batch_normalization_4.gamma", "rb");
    float * gamma_BN_4 = calloc(256, sizeof(float)); //CHECK
    read_float_array(gamma_BN_4_file, gamma_BN_4, 256);
    fclose(gamma_BN_4_file);
    
    FILE * moving_mean_BN_4_file;
    moving_mean_BN_4_file = fopen("layer_weights/batch_normalization_4.moving_mean","rb");
    float * moving_mean_BN_4 = calloc(256, sizeof(float)); //CHECK
    read_float_array(moving_mean_BN_4_file, moving_mean_BN_4, 256);
    fclose(moving_mean_BN_4_file);
    
    FILE * moving_var_BN_4_file;
    moving_var_BN_4_file = fopen("layer_weights/batch_normalization_4.moving_variance", "rb");
    float * moving_var_BN_4 = calloc(256, sizeof(float)); //CHECK
    read_float_array(moving_var_BN_4_file, moving_var_BN_4, 256);
    fclose(moving_var_BN_4_file);
    
    float *** output_BN_4;
    output_BN_4 = allocate_3Darray(20, 20, 256);
    batch_norm(output_conv2D_4, 20, 20, 256, moving_mean_BN_4, moving_var_BN_4, output_BN_4, gamma_BN_4, beta_BN_4);
    deallocate_3Darray(output_conv2D_4, 20, 20);
    free(moving_var_BN_4);
    free(moving_mean_BN_4);
    free(beta_BN_4);
    free(gamma_BN_4);
    
    FILE * batch_normalization_4_file;
    batch_normalization_4_file = fopen("C_outputs/batch_normalization_4_output.float32","wb");
    float * output_BN_4_flat = calloc(20*20*256, sizeof(float));
    flatten3D(output_BN_4, output_BN_4_flat, 20, 20, 256);
    write_float_array(batch_normalization_4_file, output_BN_4_flat, 20*20*256);
    free(output_BN_4_flat);
    fclose(batch_normalization_4_file);
    
    //Leaky_RELU_4
    float *** output_leakyRELU_4;
    output_leakyRELU_4 = allocate_3Darray(20, 20, 256);
    leakyReLU(output_BN_4, output_leakyRELU_4, 20, 20, 256);
    deallocate_3Darray(output_BN_4, 20, 20);
    
    FILE * leakyRELU_4_file;
    leakyRELU_4_file = fopen("C_outputs/leaky_re_lu_4_output.float32", "wb");
    float * output_leakyRELU_4_flat = calloc(20*20*256, sizeof(float));
    flatten3D(output_leakyRELU_4, output_leakyRELU_4_flat, 20, 20, 256);
    write_float_array(leakyRELU_4_file, output_leakyRELU_4_flat, 20*20*256);
    free(output_leakyRELU_4_flat);
    fclose(leakyRELU_4_file);
    
    //MaxPooling2D_4
    float *** output_MaxPooling2D_4;
    output_MaxPooling2D_4 = allocate_3Darray(10, 10, 256);
    nn_pool(output_leakyRELU_4, output_MaxPooling2D_4, 20, 20, 256, 2, 2);
    
    FILE * MaxPooling2D_4_file;
    MaxPooling2D_4_file = fopen("C_outputs/max_pooling2d_4_output.float32", "wb");
    float * output_MaxPooling2D_4_flat = calloc(10*10*256, sizeof(float));
    flatten3D(output_MaxPooling2D_4, output_MaxPooling2D_4_flat, 10, 10, 256);
    write_float_array(MaxPooling2D_4_file, output_MaxPooling2D_4_flat, 10*10*256);
    free(output_MaxPooling2D_4_flat);
    fclose(MaxPooling2D_4_file);
    
    //CONV2D_5
    FILE * w_conv2D_5_file;
    w_conv2D_5_file = fopen("layer_weights/conv2d_5.w", "rb");
    float * w_conv2D_5_flattened = calloc(3*3*256*512, sizeof(float));
    read_float_array(w_conv2D_5_file, w_conv2D_5_flattened, 3*3*256*512);
    fclose(w_conv2D_5_file);
    
    float **** w_conv2D_5;
    w_conv2D_5 = allocate_4Darray(512, 3, 3, 256);
    unflatten4D(w_conv2D_5_flattened, w_conv2D_5, 512, 3, 3, 256);
    free(w_conv2D_5_flattened);
    
    float * b_conv2D_5 = calloc(512, sizeof(float));
    float *** output_conv2D_5;
    output_conv2D_5 = allocate_3Darray(10, 10, 512);
    conv(output_MaxPooling2D_4, w_conv2D_5, b_conv2D_5, output_conv2D_5, 10, 10, 256, 3, 512);
    deallocate_3Darray(output_MaxPooling2D_4, 10, 10);
    deallocate_4Darray(w_conv2D_5, 512, 3, 3);
    
    FILE * conv2D_5_file;
    conv2D_5_file = fopen("C_outputs/conv2d_5_output.float32", "wb");
    float * output_conv2D_5_flat = calloc(10*10*512, sizeof(float));
    flatten3D(output_conv2D_5, output_conv2D_5_flat, 10, 10, 512);
    write_float_array(conv2D_5_file, output_conv2D_5_flat, 10*10*512);
    free(output_conv2D_5_flat);
    fclose(conv2D_5_file);
    
    //Batch_Normalization_5
    FILE * beta_BN_5_file;
    beta_BN_5_file = fopen("layer_weights/batch_normalization_5.beta", "rb");
    float * beta_BN_5 = calloc(512, sizeof(float));
    read_float_array(beta_BN_5_file, beta_BN_5, 512);
    fclose(beta_BN_5_file);
    
    FILE * gamma_BN_5_file;
    gamma_BN_5_file = fopen("layer_weights/batch_normalization_5.gamma", "rb");
    float * gamma_BN_5 = calloc(512, sizeof(float)); //CHECK
    read_float_array(gamma_BN_5_file, gamma_BN_5, 512);
    fclose(gamma_BN_5_file);
    
    FILE * moving_mean_BN_5_file;
    moving_mean_BN_5_file = fopen("layer_weights/batch_normalization_5.moving_mean","rb");
    float * moving_mean_BN_5 = calloc(512, sizeof(float)); //CHECK
    read_float_array(moving_mean_BN_5_file, moving_mean_BN_5, 512);
    fclose(moving_mean_BN_5_file);
    
    FILE * moving_var_BN_5_file;
    moving_var_BN_5_file = fopen("layer_weights/batch_normalization_5.moving_variance", "rb");
    float * moving_var_BN_5 = calloc(512, sizeof(float)); //CHECK
    read_float_array(moving_var_BN_5_file, moving_var_BN_5, 512);
    fclose(moving_var_BN_5_file);
    
    //Batch_Normalization_5
    float *** output_BN_5;
    output_BN_5 = allocate_3Darray(10, 10, 512);
    batch_norm(output_conv2D_5, 10, 10, 512, moving_mean_BN_5, moving_var_BN_5, output_BN_5, gamma_BN_5, beta_BN_5);
    deallocate_3Darray(output_conv2D_5, 10, 10);
    free(moving_var_BN_5);
    free(moving_mean_BN_5);
    free(gamma_BN_5);
    free(beta_BN_5);
    
    FILE * batch_normalization_5_file;
    batch_normalization_5_file = fopen("C_outputs/batch_normalization_5_output.float32","wb");
    float * output_BN_5_flat = calloc(10*10*512, sizeof(float));
    flatten3D(output_BN_5, output_BN_5_flat, 10, 10, 512);
    write_float_array(batch_normalization_5_file, output_BN_5_flat, 10*10*512);
    free(output_BN_5_flat);
    fclose(batch_normalization_5_file);
    
    //Leaky_RELU_5
    float *** output_leakyRELU_5;
    output_leakyRELU_5 = allocate_3Darray(10, 10, 512);
    leakyReLU(output_BN_5, output_leakyRELU_5, 10, 10, 512);
    deallocate_3Darray(output_BN_5, 10, 10);
    
    FILE * leakyRELU_5_file;
    leakyRELU_5_file = fopen("C_outputs/leaky_re_lu_5_output.float32", "wb");
    float * output_leakyRELU_5_flat = calloc(10*10*512, sizeof(float));
    flatten3D(output_leakyRELU_5, output_leakyRELU_5_flat, 10, 10, 512);
    write_float_array(leakyRELU_5_file, output_leakyRELU_5_flat, 10*10*512);
    free(output_leakyRELU_5_flat);
    fclose(leakyRELU_5_file);
    
    //MaxPooling2D_5
    float *** output_MaxPooling2D_5;
    output_MaxPooling2D_5 = allocate_3Darray(10, 10, 512);
    max_pool2D_same_padded(output_leakyRELU_5, output_MaxPooling2D_5, 10, 10, 512, 2, 1);
    deallocate_3Darray(output_leakyRELU_5, 10, 10);
    
    FILE * MaxPooling2D_5_file;
    MaxPooling2D_5_file = fopen("C_outputs/max_pooling2d_5_output.float32", "wb");
    float * output_MaxPooling2D_5_flat = calloc(10*10*512, sizeof(float));
    flatten3D(output_MaxPooling2D_5, output_MaxPooling2D_5_flat, 10, 10, 512);
    write_float_array(MaxPooling2D_5_file, output_MaxPooling2D_5_flat, 10*10*512);
    free(output_MaxPooling2D_5_flat);
    fclose(MaxPooling2D_5_file);
    
    //CONV2D_6
    FILE * w_conv2D_6_file;
    w_conv2D_6_file = fopen("layer_weights/conv2d_6.w", "rb");
    float * w_conv2D_6_flattened = calloc(3*3*512*1024, sizeof(float));
    read_float_array(w_conv2D_6_file, w_conv2D_6_flattened, 3*3*512*1024);
    fclose(w_conv2D_6_file);
    
    float **** w_conv2D_6;
    w_conv2D_6 = allocate_4Darray(1024, 3, 3, 512);
    unflatten4D(w_conv2D_6_flattened, w_conv2D_6, 1024, 3, 3, 512);
    free(w_conv2D_6_flattened);
    
    float * b_conv2D_6 = calloc(1024, sizeof(float));
    float *** output_conv2D_6;
    output_conv2D_6 = allocate_3Darray(10, 10, 1024);
    conv(output_MaxPooling2D_5, w_conv2D_6, b_conv2D_6, output_conv2D_6, 10, 10, 512, 3, 1024);
    deallocate_3Darray(output_MaxPooling2D_5, 10, 10);
    deallocate_4Darray(w_conv2D_6, 1024, 3, 3);
    free(b_conv2D_6);
    
    FILE * conv2D_6_file;
    conv2D_6_file = fopen("C_outputs/conv2d_6_output.float32", "wb");
    float * output_conv2D_6_flat = calloc(10*10*1024, sizeof(float));
    flatten3D(output_conv2D_6, output_conv2D_6_flat, 10, 10, 1024);
    write_float_array(conv2D_6_file, output_conv2D_6_flat, 10*10*1024);
    free(output_conv2D_6_flat);
    fclose(conv2D_6_file);
    
    //Batch_Normalization_6
    FILE * beta_BN_6_file;
    beta_BN_6_file = fopen("layer_weights/batch_normalization_6.beta", "rb");
    float * beta_BN_6 = calloc(1024, sizeof(float)); //CHECK if nmembs = 512
    read_float_array(beta_BN_6_file, beta_BN_6, 1024);
    fclose(beta_BN_6_file);
    
    FILE * gamma_BN_6_file;
    gamma_BN_6_file = fopen("layer_weights/batch_normalization_6.gamma", "rb");
    float * gamma_BN_6 = calloc(1024, sizeof(float)); //CHECK
    read_float_array(gamma_BN_6_file, gamma_BN_6, 1024);
    fclose(gamma_BN_6_file);
    
    FILE * moving_mean_BN_6_file;
    moving_mean_BN_6_file = fopen("layer_weights/batch_normalization_6.moving_mean","rb");
    float * moving_mean_BN_6 = calloc(1024, sizeof(float)); //CHECK
    read_float_array(moving_mean_BN_6_file, moving_mean_BN_6, 1024);
    fclose(moving_mean_BN_6_file);
    
    FILE * moving_var_BN_6_file;
    moving_var_BN_6_file = fopen("layer_weights/batch_normalization_6.moving_variance", "rb");
    float * moving_var_BN_6 = calloc(1024, sizeof(float)); //CHECK
    read_float_array(moving_var_BN_6_file, moving_var_BN_6, 1024);
    fclose(moving_var_BN_6_file);
    
    float *** output_BN_6;
    output_BN_6 = allocate_3Darray(10, 10, 1024);
    batch_norm(output_conv2D_6, 10, 10, 1024, moving_mean_BN_6, moving_var_BN_6, output_BN_6, gamma_BN_6, beta_BN_6);
    deallocate_3Darray(output_conv2D_6, 10, 10);
    free(moving_mean_BN_6);
    free(moving_var_BN_6);
    free(beta_BN_6);
    free(gamma_BN_6);
    
    FILE * batch_normalization_6_file;
    batch_normalization_6_file = fopen("C_outputs/batch_normalization_6_output.float32","wb");
    float * output_BN_6_flat = calloc(10*10*1024, sizeof(float));
    flatten3D(output_BN_6, output_BN_6_flat, 10, 10, 1024);
    write_float_array(batch_normalization_6_file, output_BN_6_flat, 10*10*1024);
    free(output_BN_6_flat);
    fclose(batch_normalization_6_file);
    
    //Leaky_RELU_6
    float *** output_leakyRELU_6;
    output_leakyRELU_6 = allocate_3Darray(10, 10, 1024);
    leakyReLU(output_BN_6, output_leakyRELU_6, 10, 10, 1024);
    deallocate_3Darray(output_BN_6, 10, 10);
    
    FILE * leakyRELU_6_file;
    leakyRELU_6_file = fopen("C_outputs/leaky_re_lu_6_output.float32", "wb");
    float * output_leakyRELU_6_flat = calloc(10*10*1024, sizeof(float));
    flatten3D(output_leakyRELU_6, output_leakyRELU_6_flat, 10, 10, 1024);
    write_float_array(leakyRELU_6_file, output_leakyRELU_6_flat, 10*10*1024);
    free(output_leakyRELU_6_flat);
    fclose(leakyRELU_6_file);

    
    //CONV2D_7
    FILE * w_conv2D_7_file;
    w_conv2D_7_file = fopen("layer_weights/conv2d_7.w", "rb");
    float * w_conv2D_7_flattened = calloc(1*1*1024*256, sizeof(float));
    read_float_array(w_conv2D_7_file, w_conv2D_7_flattened, 1*1*1024*256);
    fclose(w_conv2D_7_file);
    
    float **** w_conv2D_7;
    w_conv2D_7 = allocate_4Darray(256, 1, 1, 1024);
    unflatten4D(w_conv2D_7_flattened, w_conv2D_7, 256, 1, 1, 1024);
    free(w_conv2D_7_flattened);
    
    float * b_conv2D_7 = calloc(256, sizeof(float));
    float *** output_conv2D_7;
    output_conv2D_7 = allocate_3Darray(10, 10, 256);
    conv(output_leakyRELU_6, w_conv2D_7, b_conv2D_7, output_conv2D_7, 10, 10, 1024, 1, 256);
    deallocate_3Darray(output_leakyRELU_6, 10, 10);
    deallocate_4Darray(w_conv2D_7, 256, 1, 1);
    free(b_conv2D_7);
    
    FILE * conv2D_7_file;
    conv2D_7_file = fopen("C_outputs/conv2d_7_output.float32", "wb");
    float * output_conv2D_7_flat = calloc(10*10*256, sizeof(float));
    flatten3D(output_conv2D_7, output_conv2D_7_flat, 10, 10, 256);
    write_float_array(conv2D_7_file, output_conv2D_7_flat, 10*10*256);
    free(output_conv2D_7_flat);
    fclose(conv2D_7_file);

    
    //Batch_Normalization_7
    FILE * beta_BN_7_file;
    beta_BN_7_file = fopen("layer_weights/batch_normalization_7.beta", "rb");
    float * beta_BN_7 = calloc(256, sizeof(float)); //CHECK if nmembs = 256
    read_float_array(beta_BN_7_file, beta_BN_7, 256);
    fclose(beta_BN_7_file);
    
    FILE * gamma_BN_7_file;
    gamma_BN_7_file = fopen("layer_weights/batch_normalization_7.gamma", "rb");
    float * gamma_BN_7 = calloc(256, sizeof(float)); //CHECK
    read_float_array(gamma_BN_7_file, gamma_BN_7, 256);
    fclose(gamma_BN_7_file);
    
    FILE * moving_mean_BN_7_file;
    moving_mean_BN_7_file = fopen("layer_weights/batch_normalization_7.moving_mean","rb");
    float * moving_mean_BN_7 = calloc(256, sizeof(float)); //CHECK
    read_float_array(moving_mean_BN_7_file, moving_mean_BN_7, 256);
    fclose(moving_mean_BN_7_file);
    
    FILE * moving_var_BN_7_file;
    moving_var_BN_7_file = fopen("layer_weights/batch_normalization_7.moving_variance", "rb");
    float * moving_var_BN_7 = calloc(256, sizeof(float)); //CHECK
    read_float_array(moving_var_BN_7_file, moving_var_BN_7, 256);
    fclose(moving_var_BN_7_file);
    
    float *** output_BN_7;
    output_BN_7 = allocate_3Darray(10, 10, 256);
    batch_norm(output_conv2D_7, 10, 10, 256, moving_mean_BN_7, moving_var_BN_7, output_BN_7, gamma_BN_7, beta_BN_7);
    deallocate_3Darray(output_conv2D_7, 10, 10);
    free(moving_var_BN_7);
    free(moving_mean_BN_7);
    free(beta_BN_7);
    free(gamma_BN_7);
    
    FILE * batch_normalization_7_file;
    batch_normalization_7_file = fopen("C_outputs/batch_normalization_7_output.float32","wb");
    float * output_BN_7_flat = calloc(10*10*256, sizeof(float));
    flatten3D(output_BN_7, output_BN_7_flat, 10, 10, 256);
    write_float_array(batch_normalization_7_file, output_BN_7_flat, 10*10*256);
    free(output_BN_7_flat);
    fclose(batch_normalization_7_file);
    
    //Leaky_RELU_7
    float *** output_leakyRELU_7;
    output_leakyRELU_7 = allocate_3Darray(10, 10, 256);
    leakyReLU(output_BN_7, output_leakyRELU_7, 10, 10, 256);
    deallocate_3Darray(output_BN_7, 10, 10);
    
    FILE * leakyRELU_7_file;
    leakyRELU_7_file = fopen("C_outputs/leaky_re_lu_7_output.float32", "wb");
    float * output_leakyRELU_7_flat = calloc(10*10*256, sizeof(float));
    flatten3D(output_leakyRELU_7, output_leakyRELU_7_flat, 10, 10, 256);
    write_float_array(leakyRELU_7_file, output_leakyRELU_7_flat, 10*10*256);
    free(output_leakyRELU_7_flat);
    fclose(leakyRELU_7_file);

    
    //CONV2D_8
    FILE * w_conv2D_8_file;
    w_conv2D_8_file = fopen("layer_weights/conv2d_8.w", "rb");
    float * w_conv2D_8_flattened = calloc(3*3*256*512, sizeof(float));
    read_float_array(w_conv2D_8_file, w_conv2D_8_flattened, 3*3*256*512);
    fclose(w_conv2D_8_file);
    
    float **** w_conv2D_8;
    w_conv2D_8 = allocate_4Darray(512, 3, 3, 256);
    unflatten4D(w_conv2D_8_flattened, w_conv2D_8, 512, 3, 3, 256);
    free(w_conv2D_8_flattened);
    
    float * b_conv2D_8 = calloc(512, sizeof(float));
    float *** output_conv2D_8;
    output_conv2D_8 = allocate_3Darray(10, 10, 512);
    conv(output_leakyRELU_7, w_conv2D_8, b_conv2D_8, output_conv2D_8, 10, 10, 256, 3, 512);
    free(b_conv2D_8);
    deallocate_4Darray(w_conv2D_8, 512, 3, 3);
    
    FILE * conv2D_8_file;
    conv2D_8_file = fopen("C_outputs/conv2d_8_output.float32", "wb");
    float * output_conv2D_8_flat = calloc(10*10*512, sizeof(float));
    flatten3D(output_conv2D_8, output_conv2D_8_flat, 10, 10, 512);
    write_float_array(conv2D_8_file, output_conv2D_8_flat, 10*10*512);
    free(output_conv2D_8_flat);
    fclose(conv2D_8_file);

    
    //Batch_Normalization_8
    FILE * beta_BN_8_file;
    beta_BN_8_file = fopen("layer_weights/batch_normalization_8.beta", "rb");
    float * beta_BN_8 = calloc(512, sizeof(float)); //CHECK if nmembs = 256
    read_float_array(beta_BN_8_file, beta_BN_8, 512);
    fclose(beta_BN_8_file);
    
    FILE * gamma_BN_8_file;
    gamma_BN_8_file = fopen("layer_weights/batch_normalization_8.gamma", "rb");
    float * gamma_BN_8 = calloc(512, sizeof(float)); //CHECK
    read_float_array(gamma_BN_8_file, gamma_BN_8, 512);
    fclose(gamma_BN_8_file);
    
    FILE * moving_mean_BN_8_file;
    moving_mean_BN_8_file = fopen("layer_weights/batch_normalization_8.moving_mean","rb");
    float * moving_mean_BN_8 = calloc(512, sizeof(float)); //CHECK
    read_float_array(moving_mean_BN_8_file, moving_mean_BN_8, 512);
    fclose(moving_mean_BN_8_file);
    
    FILE * moving_var_BN_8_file;
    moving_var_BN_8_file = fopen("layer_weights/batch_normalization_8.moving_variance", "rb");
    float * moving_var_BN_8 = calloc(512, sizeof(float)); //CHECK
    read_float_array(moving_var_BN_8_file, moving_var_BN_8, 512);
    fclose(moving_var_BN_8_file);
    
    float *** output_BN_8;
    output_BN_8 = allocate_3Darray(10, 10, 512);
    batch_norm(output_conv2D_8, 10, 10, 512, moving_mean_BN_8, moving_var_BN_8, output_BN_8, gamma_BN_8, beta_BN_8);
    deallocate_3Darray(output_conv2D_8, 10, 10);
    free(moving_mean_BN_8);
    free(moving_var_BN_8);
    free(gamma_BN_8);
    free(beta_BN_8);
    
    FILE * batch_normalization_8_file;
    batch_normalization_8_file = fopen("C_outputs/batch_normalization_8_output.float32","wb");
    float * output_BN_8_flat = calloc(10*10*512, sizeof(float));
    flatten3D(output_BN_8, output_BN_8_flat, 10, 10, 512);
    write_float_array(batch_normalization_8_file, output_BN_8_flat, 10*10*512);
    free(output_BN_8_flat);
    fclose(batch_normalization_8_file);

    
    //Leaky_RELU_8;
    float *** output_leakyRELU_8;
    output_leakyRELU_8 = allocate_3Darray(10, 10, 512);
    leakyReLU(output_BN_8, output_leakyRELU_8, 10, 10, 512);
    deallocate_3Darray(output_BN_8, 10, 10);
    
    FILE * leakyRELU_8_file;
    leakyRELU_8_file = fopen("C_outputs/leaky_re_lu_8_output.float32", "wb");
    float * output_leakyRELU_8_flat = calloc(10*10*512, sizeof(float));
    flatten3D(output_leakyRELU_8, output_leakyRELU_8_flat, 10, 10, 512);
    write_float_array(leakyRELU_8_file, output_leakyRELU_8_flat, 10*10*512);
    free(output_leakyRELU_8_flat);
    fclose(leakyRELU_8_file);
    
    //CONV2D_9
    FILE * w_conv2D_9_file;
    w_conv2D_9_file = fopen("layer_weights/conv2d_9.w", "rb");
    float * w_conv2D_9_flattened = calloc(1*1*512*255, sizeof(float));
    read_float_array(w_conv2D_9_file, w_conv2D_9_flattened, 1*1*512*255);
    fclose(w_conv2D_9_file);
    
    float **** w_conv2D_9;
    w_conv2D_9 = allocate_4Darray(255, 1, 1, 512);
    unflatten4D(w_conv2D_9_flattened, w_conv2D_9, 255, 1, 1, 512);
    free(w_conv2D_9_flattened);
    
    FILE * b_conv2D_9_file;
    b_conv2D_9_file = fopen("layer_weights/conv2d_9.b", "rb");
    float * b_conv2D_9 = calloc(255, sizeof(float));
    read_float_array(b_conv2D_9_file, b_conv2D_9, 255);
    fclose(b_conv2D_9_file);
    
    float *** output_conv2D_9;
    output_conv2D_9 = allocate_3Darray(10, 10, 255);
    conv(output_leakyRELU_8, w_conv2D_9, b_conv2D_9, output_conv2D_9, 10, 10, 512, 1, 255);
    deallocate_3Darray(output_leakyRELU_8, 10, 10);
    deallocate_4Darray(w_conv2D_9, 255, 1, 1);
    free(b_conv2D_9);
    
    FILE * conv2D_9_file;
    conv2D_9_file = fopen("C_outputs/conv2d_9_output.float32", "wb");
    float * output_conv2D_9_flat = calloc(10*10*255, sizeof(float));
    flatten3D(output_conv2D_9, output_conv2D_9_flat, 10, 10, 255);
    write_float_array(conv2D_9_file, output_conv2D_9_flat, 10*10*255);
    fclose(conv2D_9_file);
    
    //CONV2D_10
    FILE * w_conv2D_10_file;
    w_conv2D_10_file = fopen("layer_weights/conv2d_10.w", "rb");
    float * w_conv2D_10_flattened = calloc(1*1*256*128, sizeof(float));
    read_float_array(w_conv2D_10_file, w_conv2D_10_flattened, 1*1*256*128);
    fclose(w_conv2D_10_file);
    
    float **** w_conv2D_10;
    w_conv2D_10 = allocate_4Darray(128, 1, 1, 256);
    unflatten4D(w_conv2D_10_flattened, w_conv2D_10, 128, 1, 1, 256);
    free(w_conv2D_10_flattened);
    
    float * b_conv2D_10 = calloc(128, sizeof(float));
    float *** output_conv2D_10;
    output_conv2D_10 = allocate_3Darray(10, 10, 128);
    conv(output_leakyRELU_7, w_conv2D_10, b_conv2D_10, output_conv2D_10, 10, 10, 256, 1, 128);
    deallocate_3Darray(output_leakyRELU_7, 10, 10);
    deallocate_4Darray(w_conv2D_10, 128, 1, 1);
    free(b_conv2D_10);
    
    FILE * conv2D_10_file;
    conv2D_10_file = fopen("C_outputs/conv2d_10_output.float32", "wb");
    float * output_conv2D_10_flat = calloc(10*10*128, sizeof(float));
    flatten3D(output_conv2D_10, output_conv2D_10_flat, 10, 10, 128);
    write_float_array(conv2D_10_file, output_conv2D_10_flat, 10*10*128);
    free(output_conv2D_10_flat);
    fclose(conv2D_10_file);
    
    //Batch_Normalization_9
    FILE * beta_BN_9_file;
    beta_BN_9_file = fopen("layer_weights/batch_normalization_9.beta", "rb");
    float * beta_BN_9 = calloc(128, sizeof(float)); //CHECK if nmembs = 256
    read_float_array(beta_BN_9_file, beta_BN_9, 128);
    fclose(beta_BN_9_file);
    
    FILE * gamma_BN_9_file;
    gamma_BN_9_file = fopen("layer_weights/batch_normalization_9.gamma", "rb");
    float * gamma_BN_9 = calloc(128, sizeof(float)); //CHECK
    read_float_array(gamma_BN_9_file, gamma_BN_9, 128);
    fclose(gamma_BN_9_file);
    
    FILE * moving_mean_BN_9_file;
    moving_mean_BN_9_file = fopen("layer_weights/batch_normalization_9.moving_mean","rb");
    float * moving_mean_BN_9 = calloc(128, sizeof(float)); //CHECK
    read_float_array(moving_mean_BN_9_file, moving_mean_BN_9, 128);
    fclose(moving_mean_BN_9_file);
    
    FILE * moving_var_BN_9_file;
    moving_var_BN_9_file = fopen("layer_weights/batch_normalization_9.moving_variance", "rb");
    float * moving_var_BN_9 = calloc(128, sizeof(float)); //CHECK
    read_float_array(moving_var_BN_9_file, moving_var_BN_9, 128);
    fclose(moving_var_BN_9_file);
    
    float *** output_BN_9;
    output_BN_9 = allocate_3Darray(10, 10, 128);
    batch_norm(output_conv2D_10, 10, 10, 128, moving_mean_BN_9, moving_var_BN_9, output_BN_9, gamma_BN_9, beta_BN_9);
    deallocate_3Darray(output_conv2D_10, 10, 10);
    free(moving_mean_BN_9);
    free(moving_var_BN_9);
    free(beta_BN_9);
    free(gamma_BN_9);
    
    FILE * batch_normalization_9_file;
    batch_normalization_9_file = fopen("C_outputs/batch_normalization_9_output.float32","wb");
    float * output_BN_9_flat = calloc(10*10*128, sizeof(float));
    flatten3D(output_BN_9, output_BN_9_flat, 10, 10, 128);
    write_float_array(batch_normalization_9_file, output_BN_9_flat, 10*10*128);
    free(output_BN_9_flat);
    fclose(batch_normalization_9_file);
    
    //Leaky_RELU_9
    float *** output_leakyRELU_9;
    output_leakyRELU_9 = allocate_3Darray(10, 10, 128);
    leakyReLU(output_BN_9, output_leakyRELU_9, 10, 10, 128);
    deallocate_3Darray(output_BN_9, 10, 10);
    
    FILE * leakyRELU_9_file;
    leakyRELU_9_file = fopen("C_outputs/leaky_re_lu_9_output.float32", "wb");
    float * output_leakyRELU_9_flat = calloc(10*10*128, sizeof(float));
    flatten3D(output_leakyRELU_9, output_leakyRELU_9_flat, 10, 10, 128);
    write_float_array(leakyRELU_9_file, output_leakyRELU_9_flat, 10*10*128);
    free(output_leakyRELU_9_flat);
    fclose(leakyRELU_9_file);
    
    //UpSampling2D
    float *** output_UpSampling;
    output_UpSampling = allocate_3Darray(20, 20, 128);
    upsample2D(output_leakyRELU_9, output_UpSampling, 2, 2, 128, 10, 10);
    deallocate_3Darray(output_leakyRELU_9, 10, 10);
    
    FILE * UpSampling2D_file;
    UpSampling2D_file = fopen("C_outputs/up_sampling2d_output.float32", "wb");
    float * output_UpSampling_flat = calloc(20*20*128, sizeof(float));
    flatten3D(output_UpSampling, output_UpSampling_flat, 20, 20, 128);
    write_float_array(UpSampling2D_file, output_UpSampling_flat, 20*20*128);
    free(output_UpSampling_flat);
    fclose(UpSampling2D_file);
    
    
    //Concatenate
    float *** output_Concatenate;
    output_Concatenate = allocate_3Darray(20, 20, 384);
    concatenate(output_UpSampling, output_leakyRELU_4, output_Concatenate, 2, 128, 20, 20, 256, 20, 20); //Which input is first? What is axis = -1? CHECK
    deallocate_3Darray(output_UpSampling, 20, 20);
    deallocate_3Darray(output_leakyRELU_4, 20, 20);
    
    FILE * concatenate_file;
    concatenate_file = fopen("C_outputs/concatenate_output.float32", "wb");
    float * output_Concatenate_flat = calloc(20*20*384, sizeof(float));
    flatten3D(output_Concatenate, output_Concatenate_flat, 20, 20, 384);
    write_float_array(concatenate_file, output_Concatenate_flat, 20*20*384);
    free(output_Concatenate_flat);
    fclose(concatenate_file);
    
    //CONV2D_11
    FILE * w_conv2D_11_file;
    w_conv2D_11_file = fopen("layer_weights/conv2d_11.w", "rb");
    float * w_conv2D_11_flattened = calloc(3*3*384*256, sizeof(float));
    read_float_array(w_conv2D_11_file, w_conv2D_11_flattened, 3*3*384*256);
    fclose(w_conv2D_11_file);
    
    float **** w_conv2D_11;
    w_conv2D_11 = allocate_4Darray(256, 3, 3, 384);
    unflatten4D(w_conv2D_11_flattened, w_conv2D_11,256, 3, 3, 384);
    free(w_conv2D_11_flattened);
    
    float * b_conv2D_11 = calloc(256, sizeof(float));
    float *** output_conv2D_11;
    output_conv2D_11 = allocate_3Darray(20, 20, 256);
    conv(output_Concatenate, w_conv2D_11, b_conv2D_11, output_conv2D_11, 20, 20, 384, 3, 256);
    deallocate_3Darray(output_Concatenate, 20, 20);
    deallocate_4Darray(w_conv2D_11, 256, 3, 3);
    
    FILE * conv2D_11_file;
    conv2D_11_file = fopen("C_outputs/conv2d_11_output.float32", "wb");
    float * output_conv2D_11_flat = calloc(20*20*256, sizeof(float));
    flatten3D(output_conv2D_11, output_conv2D_11_flat, 20, 20, 256);
    write_float_array(conv2D_11_file, output_conv2D_11_flat, 20*20*256);
    free(output_conv2D_11_flat);
    fclose(conv2D_11_file);
    
    //Batch_Normalization_10
    FILE * beta_BN_10_file;
    beta_BN_10_file = fopen("layer_weights/batch_normalization_10.beta", "rb");
    float * beta_BN_10 = calloc(256, sizeof(float)); //CHECK if nmembs = 256
    read_float_array(beta_BN_10_file, beta_BN_10, 256);
    fclose(beta_BN_10_file);
    
    FILE * gamma_BN_10_file;
    gamma_BN_10_file = fopen("layer_weights/batch_normalization_10.gamma", "rb");
    float * gamma_BN_10 = calloc(256, sizeof(float)); //CHECK
    read_float_array(gamma_BN_10_file, gamma_BN_10, 256);
    fclose(gamma_BN_10_file);
    
    FILE * moving_mean_BN_10_file;
    moving_mean_BN_10_file = fopen("layer_weights/batch_normalization_10.moving_mean","rb");
    float * moving_mean_BN_10 = calloc(256, sizeof(float)); //CHECK
    read_float_array(moving_mean_BN_10_file, moving_mean_BN_10, 256);
    fclose(moving_mean_BN_10_file);
    
    FILE * moving_var_BN_10_file;
    moving_var_BN_10_file = fopen("layer_weights/batch_normalization_10.moving_variance", "rb");
    float * moving_var_BN_10 = calloc(256, sizeof(float)); //CHECK
    read_float_array(moving_var_BN_10_file, moving_var_BN_10, 256);
    fclose(moving_var_BN_10_file);
    
    float *** output_BN_10;
    output_BN_10 = allocate_3Darray(20, 20, 256);
    batch_norm(output_conv2D_11, 20, 20, 256, moving_mean_BN_10, moving_var_BN_10, output_BN_10, gamma_BN_10, beta_BN_10);
    deallocate_3Darray(output_conv2D_11, 20, 20);
    free(moving_var_BN_10);
    free(moving_mean_BN_10);
    free(beta_BN_10);
    free(gamma_BN_10);
    
    FILE * batch_normalization_10_file;
    batch_normalization_10_file = fopen("C_outputs/batch_normalization_10_output.float32","wb");
    float * output_BN_10_flat = calloc(20*20*256, sizeof(float));
    flatten3D(output_BN_10, output_BN_10_flat, 20, 20, 256);
    write_float_array(batch_normalization_10_file, output_BN_10_flat, 20*20*256);
    free(output_BN_10_flat);
    fclose(batch_normalization_10_file);
    
    //Leaky_RELU_10
    float *** output_leakyRELU_10;
    output_leakyRELU_10 = allocate_3Darray(20, 20, 256);
    leakyReLU(output_BN_10, output_leakyRELU_10, 20, 20, 256);
    deallocate_3Darray(output_BN_10, 20, 20);
    
    FILE * leakyRELU_10_file;
    leakyRELU_10_file = fopen("C_outputs/leaky_re_lu_10_output.float32", "wb");
    float * output_leakyRELU_10_flat = calloc(20*20*256, sizeof(float));
    flatten3D(output_leakyRELU_10, output_leakyRELU_10_flat, 20, 20, 256);
    write_float_array(leakyRELU_10_file, output_leakyRELU_10_flat, 20*20*256);
    free(output_leakyRELU_10_flat);
    fclose(leakyRELU_10_file);
    
    //CONV2D_12
    FILE * w_conv2D_12_file;
    w_conv2D_12_file = fopen("layer_weights/conv2d_12.w", "rb");
    float * w_conv2D_12_flattened = calloc(1*1*256*255, sizeof(float));
    read_float_array(w_conv2D_12_file, w_conv2D_12_flattened, 1*1*256*255);
    fclose(w_conv2D_12_file);
    
    float **** w_conv2D_12;
    w_conv2D_12 = allocate_4Darray(255, 1, 1, 256);
    unflatten4D(w_conv2D_12_flattened, w_conv2D_12, 255, 1, 1, 256);
    free(w_conv2D_12_flattened);
    
    FILE * b_conv2D_12_file;
    b_conv2D_12_file = fopen("layer_weights/conv2d_12.b", "rb");
    float * b_conv2D_12 = calloc(255, sizeof(float));
    read_float_array(b_conv2D_12_file, b_conv2D_12, 255);
    fclose(b_conv2D_12_file);
    
    float *** output_conv2D_12;
    output_conv2D_12 = allocate_3Darray(20, 20, 255);
    conv(output_leakyRELU_10, w_conv2D_12, b_conv2D_12, output_conv2D_12, 20, 20, 256, 1, 255);
    deallocate_3Darray(output_leakyRELU_10, 20, 20);
    deallocate_4Darray(w_conv2D_12, 255, 1, 1);
    free(b_conv2D_12);
    
    FILE * conv2D_12_file;
    conv2D_12_file = fopen("C_outputs/conv2d_12_output.float32", "wb");
    float * output_conv2D_12_flat = calloc(20*20*255, sizeof(float));
    flatten3D(output_conv2D_12, output_conv2D_12_flat, 20, 20, 255);
    write_float_array(conv2D_12_file, output_conv2D_12_flat, 20*20*255);
    fclose(conv2D_12_file);

    
    
    //redundant, can just get the output 12 and 9 files
    //Outputting File
    FILE * outputFile1;

    // TODO - change img_num

    outputFile1 = fopen("C_outputs/test_bin_response_image0_10by10by255.float32", "wb"); //Input file path/name
    write_float_array(outputFile1, output_conv2D_9_flat, 10*10*255);
    fclose(outputFile1);
    
    FILE * outputFile2;
    outputFile2 = fopen("C_outputs/test_bin_response_image0_20by20by255.float32", "wb"); //Input file name
    write_float_array(outputFile2, output_conv2D_12_flat, 20*20*255);
    fclose(outputFile2);

}
