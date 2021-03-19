/**
  ******************************************************************************
  * @file    network_1.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Fri Feb 12 16:43:47 2021
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "network_1.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "layers.h"



#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#define AI_TOOLS_VERSION_MAJOR 5
#define AI_TOOLS_VERSION_MINOR 2
#define AI_TOOLS_VERSION_MICRO 0


#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 3
#define AI_TOOLS_API_VERSION_MICRO 0

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network_1
 
#undef AI_NETWORK_1_MODEL_SIGNATURE
#define AI_NETWORK_1_MODEL_SIGNATURE     "2ea594ea4c141df8fc9042bbbe0fba97"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.2.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Fri Feb 12 16:43:47 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_1_N_BATCHES
#define AI_NETWORK_1_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array conv2d_52_bias_array;   /* Array #0 */
AI_STATIC ai_array conv2d_52_weights_array;   /* Array #1 */
AI_STATIC ai_array conv2d_51_bias_array;   /* Array #2 */
AI_STATIC ai_array conv2d_51_weights_array;   /* Array #3 */
AI_STATIC ai_array depthwise_conv2d_25_bias_array;   /* Array #4 */
AI_STATIC ai_array depthwise_conv2d_25_weights_array;   /* Array #5 */
AI_STATIC ai_array conv2d_50_bias_array;   /* Array #6 */
AI_STATIC ai_array conv2d_50_weights_array;   /* Array #7 */
AI_STATIC ai_array depthwise_conv2d_24_bias_array;   /* Array #8 */
AI_STATIC ai_array depthwise_conv2d_24_weights_array;   /* Array #9 */
AI_STATIC ai_array conv2d_49_bias_array;   /* Array #10 */
AI_STATIC ai_array conv2d_49_weights_array;   /* Array #11 */
AI_STATIC ai_array conv2d_48_bias_array;   /* Array #12 */
AI_STATIC ai_array conv2d_48_weights_array;   /* Array #13 */
AI_STATIC ai_array depthwise_conv2d_23_bias_array;   /* Array #14 */
AI_STATIC ai_array depthwise_conv2d_23_weights_array;   /* Array #15 */
AI_STATIC ai_array conv2d_47_bias_array;   /* Array #16 */
AI_STATIC ai_array conv2d_47_weights_array;   /* Array #17 */
AI_STATIC ai_array conv2d_46_bias_array;   /* Array #18 */
AI_STATIC ai_array conv2d_46_weights_array;   /* Array #19 */
AI_STATIC ai_array depthwise_conv2d_22_bias_array;   /* Array #20 */
AI_STATIC ai_array depthwise_conv2d_22_weights_array;   /* Array #21 */
AI_STATIC ai_array conv2d_45_bias_array;   /* Array #22 */
AI_STATIC ai_array conv2d_45_weights_array;   /* Array #23 */
AI_STATIC ai_array conv2d_44_bias_array;   /* Array #24 */
AI_STATIC ai_array conv2d_44_weights_array;   /* Array #25 */
AI_STATIC ai_array depthwise_conv2d_21_bias_array;   /* Array #26 */
AI_STATIC ai_array depthwise_conv2d_21_weights_array;   /* Array #27 */
AI_STATIC ai_array conv2d_43_bias_array;   /* Array #28 */
AI_STATIC ai_array conv2d_43_weights_array;   /* Array #29 */
AI_STATIC ai_array conv2d_42_bias_array;   /* Array #30 */
AI_STATIC ai_array conv2d_42_weights_array;   /* Array #31 */
AI_STATIC ai_array depthwise_conv2d_20_bias_array;   /* Array #32 */
AI_STATIC ai_array depthwise_conv2d_20_weights_array;   /* Array #33 */
AI_STATIC ai_array conv2d_41_bias_array;   /* Array #34 */
AI_STATIC ai_array conv2d_41_weights_array;   /* Array #35 */
AI_STATIC ai_array conv2d_40_bias_array;   /* Array #36 */
AI_STATIC ai_array conv2d_40_weights_array;   /* Array #37 */
AI_STATIC ai_array depthwise_conv2d_19_bias_array;   /* Array #38 */
AI_STATIC ai_array depthwise_conv2d_19_weights_array;   /* Array #39 */
AI_STATIC ai_array conv2d_39_bias_array;   /* Array #40 */
AI_STATIC ai_array conv2d_39_weights_array;   /* Array #41 */
AI_STATIC ai_array conv2d_38_bias_array;   /* Array #42 */
AI_STATIC ai_array conv2d_38_weights_array;   /* Array #43 */
AI_STATIC ai_array depthwise_conv2d_18_bias_array;   /* Array #44 */
AI_STATIC ai_array depthwise_conv2d_18_weights_array;   /* Array #45 */
AI_STATIC ai_array conv2d_37_bias_array;   /* Array #46 */
AI_STATIC ai_array conv2d_37_weights_array;   /* Array #47 */
AI_STATIC ai_array conv2d_36_bias_array;   /* Array #48 */
AI_STATIC ai_array conv2d_36_weights_array;   /* Array #49 */
AI_STATIC ai_array depthwise_conv2d_17_bias_array;   /* Array #50 */
AI_STATIC ai_array depthwise_conv2d_17_weights_array;   /* Array #51 */
AI_STATIC ai_array conv2d_35_bias_array;   /* Array #52 */
AI_STATIC ai_array conv2d_35_weights_array;   /* Array #53 */
AI_STATIC ai_array conv2d_34_bias_array;   /* Array #54 */
AI_STATIC ai_array conv2d_34_weights_array;   /* Array #55 */
AI_STATIC ai_array depthwise_conv2d_16_bias_array;   /* Array #56 */
AI_STATIC ai_array depthwise_conv2d_16_weights_array;   /* Array #57 */
AI_STATIC ai_array conv2d_33_bias_array;   /* Array #58 */
AI_STATIC ai_array conv2d_33_weights_array;   /* Array #59 */
AI_STATIC ai_array conv2d_32_bias_array;   /* Array #60 */
AI_STATIC ai_array conv2d_32_weights_array;   /* Array #61 */
AI_STATIC ai_array depthwise_conv2d_15_bias_array;   /* Array #62 */
AI_STATIC ai_array depthwise_conv2d_15_weights_array;   /* Array #63 */
AI_STATIC ai_array conv2d_31_bias_array;   /* Array #64 */
AI_STATIC ai_array conv2d_31_weights_array;   /* Array #65 */
AI_STATIC ai_array conv2d_30_bias_array;   /* Array #66 */
AI_STATIC ai_array conv2d_30_weights_array;   /* Array #67 */
AI_STATIC ai_array depthwise_conv2d_14_bias_array;   /* Array #68 */
AI_STATIC ai_array depthwise_conv2d_14_weights_array;   /* Array #69 */
AI_STATIC ai_array conv2d_29_bias_array;   /* Array #70 */
AI_STATIC ai_array conv2d_29_weights_array;   /* Array #71 */
AI_STATIC ai_array conv2d_28_bias_array;   /* Array #72 */
AI_STATIC ai_array conv2d_28_weights_array;   /* Array #73 */
AI_STATIC ai_array depthwise_conv2d_13_bias_array;   /* Array #74 */
AI_STATIC ai_array depthwise_conv2d_13_weights_array;   /* Array #75 */
AI_STATIC ai_array conv2d_27_bias_array;   /* Array #76 */
AI_STATIC ai_array conv2d_27_weights_array;   /* Array #77 */
AI_STATIC ai_array conv2d_26_bias_array;   /* Array #78 */
AI_STATIC ai_array conv2d_26_weights_array;   /* Array #79 */
AI_STATIC ai_array depthwise_conv2d_12_bias_array;   /* Array #80 */
AI_STATIC ai_array depthwise_conv2d_12_weights_array;   /* Array #81 */
AI_STATIC ai_array conv2d_25_bias_array;   /* Array #82 */
AI_STATIC ai_array conv2d_25_weights_array;   /* Array #83 */
AI_STATIC ai_array conv2d_24_bias_array;   /* Array #84 */
AI_STATIC ai_array conv2d_24_weights_array;   /* Array #85 */
AI_STATIC ai_array depthwise_conv2d_11_bias_array;   /* Array #86 */
AI_STATIC ai_array depthwise_conv2d_11_weights_array;   /* Array #87 */
AI_STATIC ai_array conv2d_23_bias_array;   /* Array #88 */
AI_STATIC ai_array conv2d_23_weights_array;   /* Array #89 */
AI_STATIC ai_array conv2d_22_bias_array;   /* Array #90 */
AI_STATIC ai_array conv2d_22_weights_array;   /* Array #91 */
AI_STATIC ai_array depthwise_conv2d_10_bias_array;   /* Array #92 */
AI_STATIC ai_array depthwise_conv2d_10_weights_array;   /* Array #93 */
AI_STATIC ai_array conv2d_21_bias_array;   /* Array #94 */
AI_STATIC ai_array conv2d_21_weights_array;   /* Array #95 */
AI_STATIC ai_array conv2d_20_bias_array;   /* Array #96 */
AI_STATIC ai_array conv2d_20_weights_array;   /* Array #97 */
AI_STATIC ai_array depthwise_conv2d_9_bias_array;   /* Array #98 */
AI_STATIC ai_array depthwise_conv2d_9_weights_array;   /* Array #99 */
AI_STATIC ai_array conv2d_19_bias_array;   /* Array #100 */
AI_STATIC ai_array conv2d_19_weights_array;   /* Array #101 */
AI_STATIC ai_array conv2d_18_bias_array;   /* Array #102 */
AI_STATIC ai_array conv2d_18_weights_array;   /* Array #103 */
AI_STATIC ai_array depthwise_conv2d_8_bias_array;   /* Array #104 */
AI_STATIC ai_array depthwise_conv2d_8_weights_array;   /* Array #105 */
AI_STATIC ai_array conv2d_17_bias_array;   /* Array #106 */
AI_STATIC ai_array conv2d_17_weights_array;   /* Array #107 */
AI_STATIC ai_array conv2d_16_bias_array;   /* Array #108 */
AI_STATIC ai_array conv2d_16_weights_array;   /* Array #109 */
AI_STATIC ai_array depthwise_conv2d_7_bias_array;   /* Array #110 */
AI_STATIC ai_array depthwise_conv2d_7_weights_array;   /* Array #111 */
AI_STATIC ai_array conv2d_15_bias_array;   /* Array #112 */
AI_STATIC ai_array conv2d_15_weights_array;   /* Array #113 */
AI_STATIC ai_array conv2d_14_bias_array;   /* Array #114 */
AI_STATIC ai_array conv2d_14_weights_array;   /* Array #115 */
AI_STATIC ai_array depthwise_conv2d_6_bias_array;   /* Array #116 */
AI_STATIC ai_array depthwise_conv2d_6_weights_array;   /* Array #117 */
AI_STATIC ai_array conv2d_13_bias_array;   /* Array #118 */
AI_STATIC ai_array conv2d_13_weights_array;   /* Array #119 */
AI_STATIC ai_array conv2d_12_bias_array;   /* Array #120 */
AI_STATIC ai_array conv2d_12_weights_array;   /* Array #121 */
AI_STATIC ai_array depthwise_conv2d_5_bias_array;   /* Array #122 */
AI_STATIC ai_array depthwise_conv2d_5_weights_array;   /* Array #123 */
AI_STATIC ai_array conv2d_11_bias_array;   /* Array #124 */
AI_STATIC ai_array conv2d_11_weights_array;   /* Array #125 */
AI_STATIC ai_array conv2d_10_bias_array;   /* Array #126 */
AI_STATIC ai_array conv2d_10_weights_array;   /* Array #127 */
AI_STATIC ai_array depthwise_conv2d_4_bias_array;   /* Array #128 */
AI_STATIC ai_array depthwise_conv2d_4_weights_array;   /* Array #129 */
AI_STATIC ai_array conv2d_9_bias_array;   /* Array #130 */
AI_STATIC ai_array conv2d_9_weights_array;   /* Array #131 */
AI_STATIC ai_array conv2d_8_bias_array;   /* Array #132 */
AI_STATIC ai_array conv2d_8_weights_array;   /* Array #133 */
AI_STATIC ai_array depthwise_conv2d_3_bias_array;   /* Array #134 */
AI_STATIC ai_array depthwise_conv2d_3_weights_array;   /* Array #135 */
AI_STATIC ai_array conv2d_7_bias_array;   /* Array #136 */
AI_STATIC ai_array conv2d_7_weights_array;   /* Array #137 */
AI_STATIC ai_array conv2d_6_bias_array;   /* Array #138 */
AI_STATIC ai_array conv2d_6_weights_array;   /* Array #139 */
AI_STATIC ai_array depthwise_conv2d_2_bias_array;   /* Array #140 */
AI_STATIC ai_array depthwise_conv2d_2_weights_array;   /* Array #141 */
AI_STATIC ai_array conv2d_5_bias_array;   /* Array #142 */
AI_STATIC ai_array conv2d_5_weights_array;   /* Array #143 */
AI_STATIC ai_array conv2d_4_bias_array;   /* Array #144 */
AI_STATIC ai_array conv2d_4_weights_array;   /* Array #145 */
AI_STATIC ai_array depthwise_conv2d_1_bias_array;   /* Array #146 */
AI_STATIC ai_array depthwise_conv2d_1_weights_array;   /* Array #147 */
AI_STATIC ai_array conv2d_3_bias_array;   /* Array #148 */
AI_STATIC ai_array conv2d_3_weights_array;   /* Array #149 */
AI_STATIC ai_array conv2d_2_bias_array;   /* Array #150 */
AI_STATIC ai_array conv2d_2_weights_array;   /* Array #151 */
AI_STATIC ai_array depthwise_conv2d_bias_array;   /* Array #152 */
AI_STATIC ai_array depthwise_conv2d_weights_array;   /* Array #153 */
AI_STATIC ai_array conv2d_1_bias_array;   /* Array #154 */
AI_STATIC ai_array conv2d_1_weights_array;   /* Array #155 */
AI_STATIC ai_array conv2d_bias_array;   /* Array #156 */
AI_STATIC ai_array conv2d_weights_array;   /* Array #157 */
AI_STATIC ai_array image_input_output_array;   /* Array #158 */
AI_STATIC ai_array conv2d_output_array;   /* Array #159 */
AI_STATIC ai_array conv2d_1_output_array;   /* Array #160 */
AI_STATIC ai_array depthwise_conv2d_output_array;   /* Array #161 */
AI_STATIC ai_array conv2d_2_output_array;   /* Array #162 */
AI_STATIC ai_array conv2d_3_output_array;   /* Array #163 */
AI_STATIC ai_array depthwise_conv2d_1_output_array;   /* Array #164 */
AI_STATIC ai_array conv2d_4_output_array;   /* Array #165 */
AI_STATIC ai_array add_output_array;   /* Array #166 */
AI_STATIC ai_array conv2d_5_output_array;   /* Array #167 */
AI_STATIC ai_array depthwise_conv2d_2_output_array;   /* Array #168 */
AI_STATIC ai_array conv2d_6_output_array;   /* Array #169 */
AI_STATIC ai_array conv2d_7_output_array;   /* Array #170 */
AI_STATIC ai_array depthwise_conv2d_3_output_array;   /* Array #171 */
AI_STATIC ai_array conv2d_8_output_array;   /* Array #172 */
AI_STATIC ai_array add_1_output_array;   /* Array #173 */
AI_STATIC ai_array conv2d_9_output_array;   /* Array #174 */
AI_STATIC ai_array depthwise_conv2d_4_output_array;   /* Array #175 */
AI_STATIC ai_array conv2d_10_output_array;   /* Array #176 */
AI_STATIC ai_array add_2_output_array;   /* Array #177 */
AI_STATIC ai_array conv2d_11_output_array;   /* Array #178 */
AI_STATIC ai_array depthwise_conv2d_5_output_array;   /* Array #179 */
AI_STATIC ai_array conv2d_12_output_array;   /* Array #180 */
AI_STATIC ai_array conv2d_13_output_array;   /* Array #181 */
AI_STATIC ai_array depthwise_conv2d_6_output_array;   /* Array #182 */
AI_STATIC ai_array conv2d_14_output_array;   /* Array #183 */
AI_STATIC ai_array add_3_output_array;   /* Array #184 */
AI_STATIC ai_array conv2d_15_output_array;   /* Array #185 */
AI_STATIC ai_array depthwise_conv2d_7_output_array;   /* Array #186 */
AI_STATIC ai_array conv2d_16_output_array;   /* Array #187 */
AI_STATIC ai_array add_4_output_array;   /* Array #188 */
AI_STATIC ai_array conv2d_17_output_array;   /* Array #189 */
AI_STATIC ai_array depthwise_conv2d_8_output_array;   /* Array #190 */
AI_STATIC ai_array conv2d_18_output_array;   /* Array #191 */
AI_STATIC ai_array conv2d_19_output_array;   /* Array #192 */
AI_STATIC ai_array depthwise_conv2d_9_output_array;   /* Array #193 */
AI_STATIC ai_array conv2d_20_output_array;   /* Array #194 */
AI_STATIC ai_array add_5_output_array;   /* Array #195 */
AI_STATIC ai_array conv2d_21_output_array;   /* Array #196 */
AI_STATIC ai_array depthwise_conv2d_10_output_array;   /* Array #197 */
AI_STATIC ai_array conv2d_22_output_array;   /* Array #198 */
AI_STATIC ai_array add_6_output_array;   /* Array #199 */
AI_STATIC ai_array conv2d_23_output_array;   /* Array #200 */
AI_STATIC ai_array depthwise_conv2d_11_output_array;   /* Array #201 */
AI_STATIC ai_array conv2d_24_output_array;   /* Array #202 */
AI_STATIC ai_array add_7_output_array;   /* Array #203 */
AI_STATIC ai_array conv2d_25_output_array;   /* Array #204 */
AI_STATIC ai_array depthwise_conv2d_12_output_array;   /* Array #205 */
AI_STATIC ai_array conv2d_26_output_array;   /* Array #206 */
AI_STATIC ai_array add_8_output_array;   /* Array #207 */
AI_STATIC ai_array conv2d_27_output_array;   /* Array #208 */
AI_STATIC ai_array depthwise_conv2d_13_output_array;   /* Array #209 */
AI_STATIC ai_array conv2d_28_output_array;   /* Array #210 */
AI_STATIC ai_array conv2d_29_output_array;   /* Array #211 */
AI_STATIC ai_array depthwise_conv2d_14_output_array;   /* Array #212 */
AI_STATIC ai_array conv2d_30_output_array;   /* Array #213 */
AI_STATIC ai_array add_9_output_array;   /* Array #214 */
AI_STATIC ai_array conv2d_31_output_array;   /* Array #215 */
AI_STATIC ai_array depthwise_conv2d_15_output_array;   /* Array #216 */
AI_STATIC ai_array conv2d_32_output_array;   /* Array #217 */
AI_STATIC ai_array add_10_output_array;   /* Array #218 */
AI_STATIC ai_array conv2d_33_output_array;   /* Array #219 */
AI_STATIC ai_array depthwise_conv2d_16_output_array;   /* Array #220 */
AI_STATIC ai_array conv2d_34_output_array;   /* Array #221 */
AI_STATIC ai_array add_11_output_array;   /* Array #222 */
AI_STATIC ai_array conv2d_35_output_array;   /* Array #223 */
AI_STATIC ai_array depthwise_conv2d_17_output_array;   /* Array #224 */
AI_STATIC ai_array conv2d_36_output_array;   /* Array #225 */
AI_STATIC ai_array add_12_output_array;   /* Array #226 */
AI_STATIC ai_array conv2d_37_output_array;   /* Array #227 */
AI_STATIC ai_array depthwise_conv2d_18_output_array;   /* Array #228 */
AI_STATIC ai_array conv2d_38_output_array;   /* Array #229 */
AI_STATIC ai_array conv2d_39_output_array;   /* Array #230 */
AI_STATIC ai_array depthwise_conv2d_19_output_array;   /* Array #231 */
AI_STATIC ai_array conv2d_40_output_array;   /* Array #232 */
AI_STATIC ai_array add_13_output_array;   /* Array #233 */
AI_STATIC ai_array conv2d_41_output_array;   /* Array #234 */
AI_STATIC ai_array depthwise_conv2d_20_output_array;   /* Array #235 */
AI_STATIC ai_array conv2d_42_output_array;   /* Array #236 */
AI_STATIC ai_array add_14_output_array;   /* Array #237 */
AI_STATIC ai_array conv2d_43_output_array;   /* Array #238 */
AI_STATIC ai_array depthwise_conv2d_21_output_array;   /* Array #239 */
AI_STATIC ai_array conv2d_44_output_array;   /* Array #240 */
AI_STATIC ai_array add_15_output_array;   /* Array #241 */
AI_STATIC ai_array conv2d_45_output_array;   /* Array #242 */
AI_STATIC ai_array depthwise_conv2d_22_output_array;   /* Array #243 */
AI_STATIC ai_array conv2d_46_output_array;   /* Array #244 */
AI_STATIC ai_array add_16_output_array;   /* Array #245 */
AI_STATIC ai_array conv2d_47_output_array;   /* Array #246 */
AI_STATIC ai_array depthwise_conv2d_23_output_array;   /* Array #247 */
AI_STATIC ai_array conv2d_48_output_array;   /* Array #248 */
AI_STATIC ai_array add_17_output_array;   /* Array #249 */
AI_STATIC ai_array conv2d_49_output_array;   /* Array #250 */
AI_STATIC ai_array depthwise_conv2d_24_output_array;   /* Array #251 */
AI_STATIC ai_array conv2d_50_output_array;   /* Array #252 */
AI_STATIC ai_array depthwise_conv2d_25_output_array;   /* Array #253 */
AI_STATIC ai_array conv2d_51_output_array;   /* Array #254 */
AI_STATIC ai_array conv2d_52_output_array;   /* Array #255 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor conv2d_52_bias;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_52_weights;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_51_bias;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_51_weights;   /* Tensor #3 */
AI_STATIC ai_tensor depthwise_conv2d_25_bias;   /* Tensor #4 */
AI_STATIC ai_tensor depthwise_conv2d_25_weights;   /* Tensor #5 */
AI_STATIC ai_tensor conv2d_50_bias;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_50_weights;   /* Tensor #7 */
AI_STATIC ai_tensor depthwise_conv2d_24_bias;   /* Tensor #8 */
AI_STATIC ai_tensor depthwise_conv2d_24_weights;   /* Tensor #9 */
AI_STATIC ai_tensor conv2d_49_bias;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_49_weights;   /* Tensor #11 */
AI_STATIC ai_tensor conv2d_48_bias;   /* Tensor #12 */
AI_STATIC ai_tensor conv2d_48_weights;   /* Tensor #13 */
AI_STATIC ai_tensor depthwise_conv2d_23_bias;   /* Tensor #14 */
AI_STATIC ai_tensor depthwise_conv2d_23_weights;   /* Tensor #15 */
AI_STATIC ai_tensor conv2d_47_bias;   /* Tensor #16 */
AI_STATIC ai_tensor conv2d_47_weights;   /* Tensor #17 */
AI_STATIC ai_tensor conv2d_46_bias;   /* Tensor #18 */
AI_STATIC ai_tensor conv2d_46_weights;   /* Tensor #19 */
AI_STATIC ai_tensor depthwise_conv2d_22_bias;   /* Tensor #20 */
AI_STATIC ai_tensor depthwise_conv2d_22_weights;   /* Tensor #21 */
AI_STATIC ai_tensor conv2d_45_bias;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_45_weights;   /* Tensor #23 */
AI_STATIC ai_tensor conv2d_44_bias;   /* Tensor #24 */
AI_STATIC ai_tensor conv2d_44_weights;   /* Tensor #25 */
AI_STATIC ai_tensor depthwise_conv2d_21_bias;   /* Tensor #26 */
AI_STATIC ai_tensor depthwise_conv2d_21_weights;   /* Tensor #27 */
AI_STATIC ai_tensor conv2d_43_bias;   /* Tensor #28 */
AI_STATIC ai_tensor conv2d_43_weights;   /* Tensor #29 */
AI_STATIC ai_tensor conv2d_42_bias;   /* Tensor #30 */
AI_STATIC ai_tensor conv2d_42_weights;   /* Tensor #31 */
AI_STATIC ai_tensor depthwise_conv2d_20_bias;   /* Tensor #32 */
AI_STATIC ai_tensor depthwise_conv2d_20_weights;   /* Tensor #33 */
AI_STATIC ai_tensor conv2d_41_bias;   /* Tensor #34 */
AI_STATIC ai_tensor conv2d_41_weights;   /* Tensor #35 */
AI_STATIC ai_tensor conv2d_40_bias;   /* Tensor #36 */
AI_STATIC ai_tensor conv2d_40_weights;   /* Tensor #37 */
AI_STATIC ai_tensor depthwise_conv2d_19_bias;   /* Tensor #38 */
AI_STATIC ai_tensor depthwise_conv2d_19_weights;   /* Tensor #39 */
AI_STATIC ai_tensor conv2d_39_bias;   /* Tensor #40 */
AI_STATIC ai_tensor conv2d_39_weights;   /* Tensor #41 */
AI_STATIC ai_tensor conv2d_38_bias;   /* Tensor #42 */
AI_STATIC ai_tensor conv2d_38_weights;   /* Tensor #43 */
AI_STATIC ai_tensor depthwise_conv2d_18_bias;   /* Tensor #44 */
AI_STATIC ai_tensor depthwise_conv2d_18_weights;   /* Tensor #45 */
AI_STATIC ai_tensor conv2d_37_bias;   /* Tensor #46 */
AI_STATIC ai_tensor conv2d_37_weights;   /* Tensor #47 */
AI_STATIC ai_tensor conv2d_36_bias;   /* Tensor #48 */
AI_STATIC ai_tensor conv2d_36_weights;   /* Tensor #49 */
AI_STATIC ai_tensor depthwise_conv2d_17_bias;   /* Tensor #50 */
AI_STATIC ai_tensor depthwise_conv2d_17_weights;   /* Tensor #51 */
AI_STATIC ai_tensor conv2d_35_bias;   /* Tensor #52 */
AI_STATIC ai_tensor conv2d_35_weights;   /* Tensor #53 */
AI_STATIC ai_tensor conv2d_34_bias;   /* Tensor #54 */
AI_STATIC ai_tensor conv2d_34_weights;   /* Tensor #55 */
AI_STATIC ai_tensor depthwise_conv2d_16_bias;   /* Tensor #56 */
AI_STATIC ai_tensor depthwise_conv2d_16_weights;   /* Tensor #57 */
AI_STATIC ai_tensor conv2d_33_bias;   /* Tensor #58 */
AI_STATIC ai_tensor conv2d_33_weights;   /* Tensor #59 */
AI_STATIC ai_tensor conv2d_32_bias;   /* Tensor #60 */
AI_STATIC ai_tensor conv2d_32_weights;   /* Tensor #61 */
AI_STATIC ai_tensor depthwise_conv2d_15_bias;   /* Tensor #62 */
AI_STATIC ai_tensor depthwise_conv2d_15_weights;   /* Tensor #63 */
AI_STATIC ai_tensor conv2d_31_bias;   /* Tensor #64 */
AI_STATIC ai_tensor conv2d_31_weights;   /* Tensor #65 */
AI_STATIC ai_tensor conv2d_30_bias;   /* Tensor #66 */
AI_STATIC ai_tensor conv2d_30_weights;   /* Tensor #67 */
AI_STATIC ai_tensor depthwise_conv2d_14_bias;   /* Tensor #68 */
AI_STATIC ai_tensor depthwise_conv2d_14_weights;   /* Tensor #69 */
AI_STATIC ai_tensor conv2d_29_bias;   /* Tensor #70 */
AI_STATIC ai_tensor conv2d_29_weights;   /* Tensor #71 */
AI_STATIC ai_tensor conv2d_28_bias;   /* Tensor #72 */
AI_STATIC ai_tensor conv2d_28_weights;   /* Tensor #73 */
AI_STATIC ai_tensor depthwise_conv2d_13_bias;   /* Tensor #74 */
AI_STATIC ai_tensor depthwise_conv2d_13_weights;   /* Tensor #75 */
AI_STATIC ai_tensor conv2d_27_bias;   /* Tensor #76 */
AI_STATIC ai_tensor conv2d_27_weights;   /* Tensor #77 */
AI_STATIC ai_tensor conv2d_26_bias;   /* Tensor #78 */
AI_STATIC ai_tensor conv2d_26_weights;   /* Tensor #79 */
AI_STATIC ai_tensor depthwise_conv2d_12_bias;   /* Tensor #80 */
AI_STATIC ai_tensor depthwise_conv2d_12_weights;   /* Tensor #81 */
AI_STATIC ai_tensor conv2d_25_bias;   /* Tensor #82 */
AI_STATIC ai_tensor conv2d_25_weights;   /* Tensor #83 */
AI_STATIC ai_tensor conv2d_24_bias;   /* Tensor #84 */
AI_STATIC ai_tensor conv2d_24_weights;   /* Tensor #85 */
AI_STATIC ai_tensor depthwise_conv2d_11_bias;   /* Tensor #86 */
AI_STATIC ai_tensor depthwise_conv2d_11_weights;   /* Tensor #87 */
AI_STATIC ai_tensor conv2d_23_bias;   /* Tensor #88 */
AI_STATIC ai_tensor conv2d_23_weights;   /* Tensor #89 */
AI_STATIC ai_tensor conv2d_22_bias;   /* Tensor #90 */
AI_STATIC ai_tensor conv2d_22_weights;   /* Tensor #91 */
AI_STATIC ai_tensor depthwise_conv2d_10_bias;   /* Tensor #92 */
AI_STATIC ai_tensor depthwise_conv2d_10_weights;   /* Tensor #93 */
AI_STATIC ai_tensor conv2d_21_bias;   /* Tensor #94 */
AI_STATIC ai_tensor conv2d_21_weights;   /* Tensor #95 */
AI_STATIC ai_tensor conv2d_20_bias;   /* Tensor #96 */
AI_STATIC ai_tensor conv2d_20_weights;   /* Tensor #97 */
AI_STATIC ai_tensor depthwise_conv2d_9_bias;   /* Tensor #98 */
AI_STATIC ai_tensor depthwise_conv2d_9_weights;   /* Tensor #99 */
AI_STATIC ai_tensor conv2d_19_bias;   /* Tensor #100 */
AI_STATIC ai_tensor conv2d_19_weights;   /* Tensor #101 */
AI_STATIC ai_tensor conv2d_18_bias;   /* Tensor #102 */
AI_STATIC ai_tensor conv2d_18_weights;   /* Tensor #103 */
AI_STATIC ai_tensor depthwise_conv2d_8_bias;   /* Tensor #104 */
AI_STATIC ai_tensor depthwise_conv2d_8_weights;   /* Tensor #105 */
AI_STATIC ai_tensor conv2d_17_bias;   /* Tensor #106 */
AI_STATIC ai_tensor conv2d_17_weights;   /* Tensor #107 */
AI_STATIC ai_tensor conv2d_16_bias;   /* Tensor #108 */
AI_STATIC ai_tensor conv2d_16_weights;   /* Tensor #109 */
AI_STATIC ai_tensor depthwise_conv2d_7_bias;   /* Tensor #110 */
AI_STATIC ai_tensor depthwise_conv2d_7_weights;   /* Tensor #111 */
AI_STATIC ai_tensor conv2d_15_bias;   /* Tensor #112 */
AI_STATIC ai_tensor conv2d_15_weights;   /* Tensor #113 */
AI_STATIC ai_tensor conv2d_14_bias;   /* Tensor #114 */
AI_STATIC ai_tensor conv2d_14_weights;   /* Tensor #115 */
AI_STATIC ai_tensor depthwise_conv2d_6_bias;   /* Tensor #116 */
AI_STATIC ai_tensor depthwise_conv2d_6_weights;   /* Tensor #117 */
AI_STATIC ai_tensor conv2d_13_bias;   /* Tensor #118 */
AI_STATIC ai_tensor conv2d_13_weights;   /* Tensor #119 */
AI_STATIC ai_tensor conv2d_12_bias;   /* Tensor #120 */
AI_STATIC ai_tensor conv2d_12_weights;   /* Tensor #121 */
AI_STATIC ai_tensor depthwise_conv2d_5_bias;   /* Tensor #122 */
AI_STATIC ai_tensor depthwise_conv2d_5_weights;   /* Tensor #123 */
AI_STATIC ai_tensor conv2d_11_bias;   /* Tensor #124 */
AI_STATIC ai_tensor conv2d_11_weights;   /* Tensor #125 */
AI_STATIC ai_tensor conv2d_10_bias;   /* Tensor #126 */
AI_STATIC ai_tensor conv2d_10_weights;   /* Tensor #127 */
AI_STATIC ai_tensor depthwise_conv2d_4_bias;   /* Tensor #128 */
AI_STATIC ai_tensor depthwise_conv2d_4_weights;   /* Tensor #129 */
AI_STATIC ai_tensor conv2d_9_bias;   /* Tensor #130 */
AI_STATIC ai_tensor conv2d_9_weights;   /* Tensor #131 */
AI_STATIC ai_tensor conv2d_8_bias;   /* Tensor #132 */
AI_STATIC ai_tensor conv2d_8_weights;   /* Tensor #133 */
AI_STATIC ai_tensor depthwise_conv2d_3_bias;   /* Tensor #134 */
AI_STATIC ai_tensor depthwise_conv2d_3_weights;   /* Tensor #135 */
AI_STATIC ai_tensor conv2d_7_bias;   /* Tensor #136 */
AI_STATIC ai_tensor conv2d_7_weights;   /* Tensor #137 */
AI_STATIC ai_tensor conv2d_6_bias;   /* Tensor #138 */
AI_STATIC ai_tensor conv2d_6_weights;   /* Tensor #139 */
AI_STATIC ai_tensor depthwise_conv2d_2_bias;   /* Tensor #140 */
AI_STATIC ai_tensor depthwise_conv2d_2_weights;   /* Tensor #141 */
AI_STATIC ai_tensor conv2d_5_bias;   /* Tensor #142 */
AI_STATIC ai_tensor conv2d_5_weights;   /* Tensor #143 */
AI_STATIC ai_tensor conv2d_4_bias;   /* Tensor #144 */
AI_STATIC ai_tensor conv2d_4_weights;   /* Tensor #145 */
AI_STATIC ai_tensor depthwise_conv2d_1_bias;   /* Tensor #146 */
AI_STATIC ai_tensor depthwise_conv2d_1_weights;   /* Tensor #147 */
AI_STATIC ai_tensor conv2d_3_bias;   /* Tensor #148 */
AI_STATIC ai_tensor conv2d_3_weights;   /* Tensor #149 */
AI_STATIC ai_tensor conv2d_2_bias;   /* Tensor #150 */
AI_STATIC ai_tensor conv2d_2_weights;   /* Tensor #151 */
AI_STATIC ai_tensor depthwise_conv2d_bias;   /* Tensor #152 */
AI_STATIC ai_tensor depthwise_conv2d_weights;   /* Tensor #153 */
AI_STATIC ai_tensor conv2d_1_bias;   /* Tensor #154 */
AI_STATIC ai_tensor conv2d_1_weights;   /* Tensor #155 */
AI_STATIC ai_tensor conv2d_bias;   /* Tensor #156 */
AI_STATIC ai_tensor conv2d_weights;   /* Tensor #157 */
AI_STATIC ai_tensor image_input_output;   /* Tensor #158 */
AI_STATIC ai_tensor conv2d_output;   /* Tensor #159 */
AI_STATIC ai_tensor conv2d_1_output;   /* Tensor #160 */
AI_STATIC ai_tensor depthwise_conv2d_output;   /* Tensor #161 */
AI_STATIC ai_tensor conv2d_2_output;   /* Tensor #162 */
AI_STATIC ai_tensor conv2d_3_output;   /* Tensor #163 */
AI_STATIC ai_tensor depthwise_conv2d_1_output;   /* Tensor #164 */
AI_STATIC ai_tensor conv2d_4_output;   /* Tensor #165 */
AI_STATIC ai_tensor add_output;   /* Tensor #166 */
AI_STATIC ai_tensor conv2d_5_output;   /* Tensor #167 */
AI_STATIC ai_tensor depthwise_conv2d_2_output;   /* Tensor #168 */
AI_STATIC ai_tensor conv2d_6_output;   /* Tensor #169 */
AI_STATIC ai_tensor conv2d_7_output;   /* Tensor #170 */
AI_STATIC ai_tensor depthwise_conv2d_3_output;   /* Tensor #171 */
AI_STATIC ai_tensor conv2d_8_output;   /* Tensor #172 */
AI_STATIC ai_tensor add_1_output;   /* Tensor #173 */
AI_STATIC ai_tensor conv2d_9_output;   /* Tensor #174 */
AI_STATIC ai_tensor depthwise_conv2d_4_output;   /* Tensor #175 */
AI_STATIC ai_tensor conv2d_10_output;   /* Tensor #176 */
AI_STATIC ai_tensor add_2_output;   /* Tensor #177 */
AI_STATIC ai_tensor conv2d_11_output;   /* Tensor #178 */
AI_STATIC ai_tensor depthwise_conv2d_5_output;   /* Tensor #179 */
AI_STATIC ai_tensor conv2d_12_output;   /* Tensor #180 */
AI_STATIC ai_tensor conv2d_13_output;   /* Tensor #181 */
AI_STATIC ai_tensor depthwise_conv2d_6_output;   /* Tensor #182 */
AI_STATIC ai_tensor conv2d_14_output;   /* Tensor #183 */
AI_STATIC ai_tensor add_3_output;   /* Tensor #184 */
AI_STATIC ai_tensor conv2d_15_output;   /* Tensor #185 */
AI_STATIC ai_tensor depthwise_conv2d_7_output;   /* Tensor #186 */
AI_STATIC ai_tensor conv2d_16_output;   /* Tensor #187 */
AI_STATIC ai_tensor add_4_output;   /* Tensor #188 */
AI_STATIC ai_tensor conv2d_17_output;   /* Tensor #189 */
AI_STATIC ai_tensor depthwise_conv2d_8_output;   /* Tensor #190 */
AI_STATIC ai_tensor conv2d_18_output;   /* Tensor #191 */
AI_STATIC ai_tensor conv2d_19_output;   /* Tensor #192 */
AI_STATIC ai_tensor depthwise_conv2d_9_output;   /* Tensor #193 */
AI_STATIC ai_tensor conv2d_20_output;   /* Tensor #194 */
AI_STATIC ai_tensor add_5_output;   /* Tensor #195 */
AI_STATIC ai_tensor conv2d_21_output;   /* Tensor #196 */
AI_STATIC ai_tensor depthwise_conv2d_10_output;   /* Tensor #197 */
AI_STATIC ai_tensor conv2d_22_output;   /* Tensor #198 */
AI_STATIC ai_tensor add_6_output;   /* Tensor #199 */
AI_STATIC ai_tensor conv2d_23_output;   /* Tensor #200 */
AI_STATIC ai_tensor depthwise_conv2d_11_output;   /* Tensor #201 */
AI_STATIC ai_tensor conv2d_24_output;   /* Tensor #202 */
AI_STATIC ai_tensor add_7_output;   /* Tensor #203 */
AI_STATIC ai_tensor conv2d_25_output;   /* Tensor #204 */
AI_STATIC ai_tensor depthwise_conv2d_12_output;   /* Tensor #205 */
AI_STATIC ai_tensor conv2d_26_output;   /* Tensor #206 */
AI_STATIC ai_tensor add_8_output;   /* Tensor #207 */
AI_STATIC ai_tensor conv2d_27_output;   /* Tensor #208 */
AI_STATIC ai_tensor depthwise_conv2d_13_output;   /* Tensor #209 */
AI_STATIC ai_tensor conv2d_28_output;   /* Tensor #210 */
AI_STATIC ai_tensor conv2d_29_output;   /* Tensor #211 */
AI_STATIC ai_tensor depthwise_conv2d_14_output;   /* Tensor #212 */
AI_STATIC ai_tensor conv2d_30_output;   /* Tensor #213 */
AI_STATIC ai_tensor add_9_output;   /* Tensor #214 */
AI_STATIC ai_tensor conv2d_31_output;   /* Tensor #215 */
AI_STATIC ai_tensor depthwise_conv2d_15_output;   /* Tensor #216 */
AI_STATIC ai_tensor conv2d_32_output;   /* Tensor #217 */
AI_STATIC ai_tensor add_10_output;   /* Tensor #218 */
AI_STATIC ai_tensor conv2d_33_output;   /* Tensor #219 */
AI_STATIC ai_tensor depthwise_conv2d_16_output;   /* Tensor #220 */
AI_STATIC ai_tensor conv2d_34_output;   /* Tensor #221 */
AI_STATIC ai_tensor add_11_output;   /* Tensor #222 */
AI_STATIC ai_tensor conv2d_35_output;   /* Tensor #223 */
AI_STATIC ai_tensor depthwise_conv2d_17_output;   /* Tensor #224 */
AI_STATIC ai_tensor conv2d_36_output;   /* Tensor #225 */
AI_STATIC ai_tensor add_12_output;   /* Tensor #226 */
AI_STATIC ai_tensor conv2d_37_output;   /* Tensor #227 */
AI_STATIC ai_tensor depthwise_conv2d_18_output;   /* Tensor #228 */
AI_STATIC ai_tensor conv2d_38_output;   /* Tensor #229 */
AI_STATIC ai_tensor conv2d_39_output;   /* Tensor #230 */
AI_STATIC ai_tensor depthwise_conv2d_19_output;   /* Tensor #231 */
AI_STATIC ai_tensor conv2d_40_output;   /* Tensor #232 */
AI_STATIC ai_tensor add_13_output;   /* Tensor #233 */
AI_STATIC ai_tensor conv2d_41_output;   /* Tensor #234 */
AI_STATIC ai_tensor depthwise_conv2d_20_output;   /* Tensor #235 */
AI_STATIC ai_tensor conv2d_42_output;   /* Tensor #236 */
AI_STATIC ai_tensor add_14_output;   /* Tensor #237 */
AI_STATIC ai_tensor conv2d_43_output;   /* Tensor #238 */
AI_STATIC ai_tensor depthwise_conv2d_21_output;   /* Tensor #239 */
AI_STATIC ai_tensor conv2d_44_output;   /* Tensor #240 */
AI_STATIC ai_tensor add_15_output;   /* Tensor #241 */
AI_STATIC ai_tensor conv2d_45_output;   /* Tensor #242 */
AI_STATIC ai_tensor depthwise_conv2d_22_output;   /* Tensor #243 */
AI_STATIC ai_tensor conv2d_46_output;   /* Tensor #244 */
AI_STATIC ai_tensor add_16_output;   /* Tensor #245 */
AI_STATIC ai_tensor conv2d_47_output;   /* Tensor #246 */
AI_STATIC ai_tensor depthwise_conv2d_23_output;   /* Tensor #247 */
AI_STATIC ai_tensor conv2d_48_output;   /* Tensor #248 */
AI_STATIC ai_tensor add_17_output;   /* Tensor #249 */
AI_STATIC ai_tensor conv2d_49_output;   /* Tensor #250 */
AI_STATIC ai_tensor depthwise_conv2d_24_output;   /* Tensor #251 */
AI_STATIC ai_tensor conv2d_50_output;   /* Tensor #252 */
AI_STATIC ai_tensor depthwise_conv2d_25_output;   /* Tensor #253 */
AI_STATIC ai_tensor conv2d_51_output;   /* Tensor #254 */
AI_STATIC ai_tensor conv2d_52_output;   /* Tensor #255 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv2d_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_1_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain conv2d_2_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain conv2d_3_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_1_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain conv2d_4_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain add_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain conv2d_5_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_2_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain conv2d_6_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain conv2d_7_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_3_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain conv2d_8_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain add_1_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain conv2d_9_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_4_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain conv2d_10_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain add_2_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain conv2d_11_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_5_chain;   /* Chain #20 */
AI_STATIC_CONST ai_tensor_chain conv2d_12_chain;   /* Chain #21 */
AI_STATIC_CONST ai_tensor_chain conv2d_13_chain;   /* Chain #22 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_6_chain;   /* Chain #23 */
AI_STATIC_CONST ai_tensor_chain conv2d_14_chain;   /* Chain #24 */
AI_STATIC_CONST ai_tensor_chain add_3_chain;   /* Chain #25 */
AI_STATIC_CONST ai_tensor_chain conv2d_15_chain;   /* Chain #26 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_7_chain;   /* Chain #27 */
AI_STATIC_CONST ai_tensor_chain conv2d_16_chain;   /* Chain #28 */
AI_STATIC_CONST ai_tensor_chain add_4_chain;   /* Chain #29 */
AI_STATIC_CONST ai_tensor_chain conv2d_17_chain;   /* Chain #30 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_8_chain;   /* Chain #31 */
AI_STATIC_CONST ai_tensor_chain conv2d_18_chain;   /* Chain #32 */
AI_STATIC_CONST ai_tensor_chain conv2d_19_chain;   /* Chain #33 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_9_chain;   /* Chain #34 */
AI_STATIC_CONST ai_tensor_chain conv2d_20_chain;   /* Chain #35 */
AI_STATIC_CONST ai_tensor_chain add_5_chain;   /* Chain #36 */
AI_STATIC_CONST ai_tensor_chain conv2d_21_chain;   /* Chain #37 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_10_chain;   /* Chain #38 */
AI_STATIC_CONST ai_tensor_chain conv2d_22_chain;   /* Chain #39 */
AI_STATIC_CONST ai_tensor_chain add_6_chain;   /* Chain #40 */
AI_STATIC_CONST ai_tensor_chain conv2d_23_chain;   /* Chain #41 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_11_chain;   /* Chain #42 */
AI_STATIC_CONST ai_tensor_chain conv2d_24_chain;   /* Chain #43 */
AI_STATIC_CONST ai_tensor_chain add_7_chain;   /* Chain #44 */
AI_STATIC_CONST ai_tensor_chain conv2d_25_chain;   /* Chain #45 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_12_chain;   /* Chain #46 */
AI_STATIC_CONST ai_tensor_chain conv2d_26_chain;   /* Chain #47 */
AI_STATIC_CONST ai_tensor_chain add_8_chain;   /* Chain #48 */
AI_STATIC_CONST ai_tensor_chain conv2d_27_chain;   /* Chain #49 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_13_chain;   /* Chain #50 */
AI_STATIC_CONST ai_tensor_chain conv2d_28_chain;   /* Chain #51 */
AI_STATIC_CONST ai_tensor_chain conv2d_29_chain;   /* Chain #52 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_14_chain;   /* Chain #53 */
AI_STATIC_CONST ai_tensor_chain conv2d_30_chain;   /* Chain #54 */
AI_STATIC_CONST ai_tensor_chain add_9_chain;   /* Chain #55 */
AI_STATIC_CONST ai_tensor_chain conv2d_31_chain;   /* Chain #56 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_15_chain;   /* Chain #57 */
AI_STATIC_CONST ai_tensor_chain conv2d_32_chain;   /* Chain #58 */
AI_STATIC_CONST ai_tensor_chain add_10_chain;   /* Chain #59 */
AI_STATIC_CONST ai_tensor_chain conv2d_33_chain;   /* Chain #60 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_16_chain;   /* Chain #61 */
AI_STATIC_CONST ai_tensor_chain conv2d_34_chain;   /* Chain #62 */
AI_STATIC_CONST ai_tensor_chain add_11_chain;   /* Chain #63 */
AI_STATIC_CONST ai_tensor_chain conv2d_35_chain;   /* Chain #64 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_17_chain;   /* Chain #65 */
AI_STATIC_CONST ai_tensor_chain conv2d_36_chain;   /* Chain #66 */
AI_STATIC_CONST ai_tensor_chain add_12_chain;   /* Chain #67 */
AI_STATIC_CONST ai_tensor_chain conv2d_37_chain;   /* Chain #68 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_18_chain;   /* Chain #69 */
AI_STATIC_CONST ai_tensor_chain conv2d_38_chain;   /* Chain #70 */
AI_STATIC_CONST ai_tensor_chain conv2d_39_chain;   /* Chain #71 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_19_chain;   /* Chain #72 */
AI_STATIC_CONST ai_tensor_chain conv2d_40_chain;   /* Chain #73 */
AI_STATIC_CONST ai_tensor_chain add_13_chain;   /* Chain #74 */
AI_STATIC_CONST ai_tensor_chain conv2d_41_chain;   /* Chain #75 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_20_chain;   /* Chain #76 */
AI_STATIC_CONST ai_tensor_chain conv2d_42_chain;   /* Chain #77 */
AI_STATIC_CONST ai_tensor_chain add_14_chain;   /* Chain #78 */
AI_STATIC_CONST ai_tensor_chain conv2d_43_chain;   /* Chain #79 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_21_chain;   /* Chain #80 */
AI_STATIC_CONST ai_tensor_chain conv2d_44_chain;   /* Chain #81 */
AI_STATIC_CONST ai_tensor_chain add_15_chain;   /* Chain #82 */
AI_STATIC_CONST ai_tensor_chain conv2d_45_chain;   /* Chain #83 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_22_chain;   /* Chain #84 */
AI_STATIC_CONST ai_tensor_chain conv2d_46_chain;   /* Chain #85 */
AI_STATIC_CONST ai_tensor_chain add_16_chain;   /* Chain #86 */
AI_STATIC_CONST ai_tensor_chain conv2d_47_chain;   /* Chain #87 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_23_chain;   /* Chain #88 */
AI_STATIC_CONST ai_tensor_chain conv2d_48_chain;   /* Chain #89 */
AI_STATIC_CONST ai_tensor_chain add_17_chain;   /* Chain #90 */
AI_STATIC_CONST ai_tensor_chain conv2d_49_chain;   /* Chain #91 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_24_chain;   /* Chain #92 */
AI_STATIC_CONST ai_tensor_chain conv2d_50_chain;   /* Chain #93 */
AI_STATIC_CONST ai_tensor_chain depthwise_conv2d_25_chain;   /* Chain #94 */
AI_STATIC_CONST ai_tensor_chain conv2d_51_chain;   /* Chain #95 */
AI_STATIC_CONST ai_tensor_chain conv2d_52_chain;   /* Chain #96 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d conv2d_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d conv2d_1_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_layer; /* Layer #2 */
AI_STATIC ai_layer_conv2d conv2d_2_layer; /* Layer #3 */
AI_STATIC ai_layer_conv2d conv2d_3_layer; /* Layer #4 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_1_layer; /* Layer #5 */
AI_STATIC ai_layer_conv2d conv2d_4_layer; /* Layer #6 */
AI_STATIC ai_layer_eltwise add_layer; /* Layer #7 */
AI_STATIC ai_layer_conv2d conv2d_5_layer; /* Layer #8 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_2_layer; /* Layer #9 */
AI_STATIC ai_layer_conv2d conv2d_6_layer; /* Layer #10 */
AI_STATIC ai_layer_conv2d conv2d_7_layer; /* Layer #11 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_3_layer; /* Layer #12 */
AI_STATIC ai_layer_conv2d conv2d_8_layer; /* Layer #13 */
AI_STATIC ai_layer_eltwise add_1_layer; /* Layer #14 */
AI_STATIC ai_layer_conv2d conv2d_9_layer; /* Layer #15 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_4_layer; /* Layer #16 */
AI_STATIC ai_layer_conv2d conv2d_10_layer; /* Layer #17 */
AI_STATIC ai_layer_eltwise add_2_layer; /* Layer #18 */
AI_STATIC ai_layer_conv2d conv2d_11_layer; /* Layer #19 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_5_layer; /* Layer #20 */
AI_STATIC ai_layer_conv2d conv2d_12_layer; /* Layer #21 */
AI_STATIC ai_layer_conv2d conv2d_13_layer; /* Layer #22 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_6_layer; /* Layer #23 */
AI_STATIC ai_layer_conv2d conv2d_14_layer; /* Layer #24 */
AI_STATIC ai_layer_eltwise add_3_layer; /* Layer #25 */
AI_STATIC ai_layer_conv2d conv2d_15_layer; /* Layer #26 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_7_layer; /* Layer #27 */
AI_STATIC ai_layer_conv2d conv2d_16_layer; /* Layer #28 */
AI_STATIC ai_layer_eltwise add_4_layer; /* Layer #29 */
AI_STATIC ai_layer_conv2d conv2d_17_layer; /* Layer #30 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_8_layer; /* Layer #31 */
AI_STATIC ai_layer_conv2d conv2d_18_layer; /* Layer #32 */
AI_STATIC ai_layer_conv2d conv2d_19_layer; /* Layer #33 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_9_layer; /* Layer #34 */
AI_STATIC ai_layer_conv2d conv2d_20_layer; /* Layer #35 */
AI_STATIC ai_layer_eltwise add_5_layer; /* Layer #36 */
AI_STATIC ai_layer_conv2d conv2d_21_layer; /* Layer #37 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_10_layer; /* Layer #38 */
AI_STATIC ai_layer_conv2d conv2d_22_layer; /* Layer #39 */
AI_STATIC ai_layer_eltwise add_6_layer; /* Layer #40 */
AI_STATIC ai_layer_conv2d conv2d_23_layer; /* Layer #41 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_11_layer; /* Layer #42 */
AI_STATIC ai_layer_conv2d conv2d_24_layer; /* Layer #43 */
AI_STATIC ai_layer_eltwise add_7_layer; /* Layer #44 */
AI_STATIC ai_layer_conv2d conv2d_25_layer; /* Layer #45 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_12_layer; /* Layer #46 */
AI_STATIC ai_layer_conv2d conv2d_26_layer; /* Layer #47 */
AI_STATIC ai_layer_eltwise add_8_layer; /* Layer #48 */
AI_STATIC ai_layer_conv2d conv2d_27_layer; /* Layer #49 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_13_layer; /* Layer #50 */
AI_STATIC ai_layer_conv2d conv2d_28_layer; /* Layer #51 */
AI_STATIC ai_layer_conv2d conv2d_29_layer; /* Layer #52 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_14_layer; /* Layer #53 */
AI_STATIC ai_layer_conv2d conv2d_30_layer; /* Layer #54 */
AI_STATIC ai_layer_eltwise add_9_layer; /* Layer #55 */
AI_STATIC ai_layer_conv2d conv2d_31_layer; /* Layer #56 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_15_layer; /* Layer #57 */
AI_STATIC ai_layer_conv2d conv2d_32_layer; /* Layer #58 */
AI_STATIC ai_layer_eltwise add_10_layer; /* Layer #59 */
AI_STATIC ai_layer_conv2d conv2d_33_layer; /* Layer #60 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_16_layer; /* Layer #61 */
AI_STATIC ai_layer_conv2d conv2d_34_layer; /* Layer #62 */
AI_STATIC ai_layer_eltwise add_11_layer; /* Layer #63 */
AI_STATIC ai_layer_conv2d conv2d_35_layer; /* Layer #64 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_17_layer; /* Layer #65 */
AI_STATIC ai_layer_conv2d conv2d_36_layer; /* Layer #66 */
AI_STATIC ai_layer_eltwise add_12_layer; /* Layer #67 */
AI_STATIC ai_layer_conv2d conv2d_37_layer; /* Layer #68 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_18_layer; /* Layer #69 */
AI_STATIC ai_layer_conv2d conv2d_38_layer; /* Layer #70 */
AI_STATIC ai_layer_conv2d conv2d_39_layer; /* Layer #71 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_19_layer; /* Layer #72 */
AI_STATIC ai_layer_conv2d conv2d_40_layer; /* Layer #73 */
AI_STATIC ai_layer_eltwise add_13_layer; /* Layer #74 */
AI_STATIC ai_layer_conv2d conv2d_41_layer; /* Layer #75 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_20_layer; /* Layer #76 */
AI_STATIC ai_layer_conv2d conv2d_42_layer; /* Layer #77 */
AI_STATIC ai_layer_eltwise add_14_layer; /* Layer #78 */
AI_STATIC ai_layer_conv2d conv2d_43_layer; /* Layer #79 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_21_layer; /* Layer #80 */
AI_STATIC ai_layer_conv2d conv2d_44_layer; /* Layer #81 */
AI_STATIC ai_layer_eltwise add_15_layer; /* Layer #82 */
AI_STATIC ai_layer_conv2d conv2d_45_layer; /* Layer #83 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_22_layer; /* Layer #84 */
AI_STATIC ai_layer_conv2d conv2d_46_layer; /* Layer #85 */
AI_STATIC ai_layer_eltwise add_16_layer; /* Layer #86 */
AI_STATIC ai_layer_conv2d conv2d_47_layer; /* Layer #87 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_23_layer; /* Layer #88 */
AI_STATIC ai_layer_conv2d conv2d_48_layer; /* Layer #89 */
AI_STATIC ai_layer_eltwise add_17_layer; /* Layer #90 */
AI_STATIC ai_layer_conv2d conv2d_49_layer; /* Layer #91 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_24_layer; /* Layer #92 */
AI_STATIC ai_layer_conv2d conv2d_50_layer; /* Layer #93 */
AI_STATIC ai_layer_conv2d depthwise_conv2d_25_layer; /* Layer #94 */
AI_STATIC ai_layer_conv2d conv2d_51_layer; /* Layer #95 */
AI_STATIC ai_layer_conv2d conv2d_52_layer; /* Layer #96 */


/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 255, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32640, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_25_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_25_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3200, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 12288, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_24_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_24_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2400, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4608, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10752, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_23_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 224, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_23_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_47_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 224, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_47_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10752, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10752, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_22_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 224, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_22_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 224, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10752, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10752, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_21_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 224, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_21_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 224, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10752, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10752, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_20_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 224, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_20_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 224, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10752, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_40_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_40_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10752, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_19_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 224, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_19_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2016, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 224, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10752, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6528, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_18_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 136, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_18_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1224, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 136, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3264, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3264, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_17_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 136, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_17_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1224, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 136, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3264, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3264, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_16_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 136, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_16_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1224, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 136, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3264, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3264, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_15_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 136, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_15_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1224, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 136, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3264, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3264, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_14_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 136, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_14_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1224, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 136, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3264, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2304, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_13_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_13_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 864, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_12_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_12_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 864, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_11_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_11_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 864, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_10_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_10_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 864, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_9_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_9_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 864, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_8_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_8_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 432, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)

/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)

/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_7_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_7_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 432, AI_STATIC)

/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)

/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)

/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_6_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_6_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 432, AI_STATIC)

/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)

/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)

/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#122 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_5_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#123 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_5_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 288, AI_STATIC)

/* Array#124 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#125 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#126 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#127 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#128 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_4_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#129 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_4_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 288, AI_STATIC)

/* Array#130 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#131 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#132 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#133 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#134 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_3_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#135 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_3_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 288, AI_STATIC)

/* Array#136 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#137 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#138 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#139 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)

/* Array#140 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)

/* Array#141 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 216, AI_STATIC)

/* Array#142 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)

/* Array#143 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#144 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4, AI_STATIC)

/* Array#145 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#146 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#147 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_1_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 72, AI_STATIC)

/* Array#148 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#149 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#150 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4, AI_STATIC)

/* Array#151 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#152 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#153 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 72, AI_STATIC)

/* Array#154 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#155 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#156 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#157 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 216, AI_STATIC)

/* Array#158 */
AI_ARRAY_OBJ_DECLARE(
  image_input_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 49152, AI_STATIC)

/* Array#159 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#160 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#161 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#162 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)

/* Array#163 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#164 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#165 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)

/* Array#166 */
AI_ARRAY_OBJ_DECLARE(
  add_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)

/* Array#167 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 98304, AI_STATIC)

/* Array#168 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24576, AI_STATIC)

/* Array#169 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192, AI_STATIC)

/* Array#170 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#171 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_3_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#172 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192, AI_STATIC)

/* Array#173 */
AI_ARRAY_OBJ_DECLARE(
  add_1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192, AI_STATIC)

/* Array#174 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#175 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_4_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#176 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192, AI_STATIC)

/* Array#177 */
AI_ARRAY_OBJ_DECLARE(
  add_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192, AI_STATIC)

/* Array#178 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#179 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_5_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192, AI_STATIC)

/* Array#180 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)

/* Array#181 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 12288, AI_STATIC)

/* Array#182 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_6_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 12288, AI_STATIC)

/* Array#183 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)

/* Array#184 */
AI_ARRAY_OBJ_DECLARE(
  add_3_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)

/* Array#185 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 12288, AI_STATIC)

/* Array#186 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_7_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 12288, AI_STATIC)

/* Array#187 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)

/* Array#188 */
AI_ARRAY_OBJ_DECLARE(
  add_4_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)

/* Array#189 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 12288, AI_STATIC)

/* Array#190 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_8_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 12288, AI_STATIC)

/* Array#191 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#192 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24576, AI_STATIC)

/* Array#193 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_9_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24576, AI_STATIC)

/* Array#194 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#195 */
AI_ARRAY_OBJ_DECLARE(
  add_5_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#196 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24576, AI_STATIC)

/* Array#197 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_10_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24576, AI_STATIC)

/* Array#198 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#199 */
AI_ARRAY_OBJ_DECLARE(
  add_6_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#200 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24576, AI_STATIC)

/* Array#201 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_11_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24576, AI_STATIC)

/* Array#202 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#203 */
AI_ARRAY_OBJ_DECLARE(
  add_7_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#204 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24576, AI_STATIC)

/* Array#205 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_12_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24576, AI_STATIC)

/* Array#206 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#207 */
AI_ARRAY_OBJ_DECLARE(
  add_8_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#208 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24576, AI_STATIC)

/* Array#209 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_13_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6144, AI_STATIC)

/* Array#210 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#211 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8704, AI_STATIC)

/* Array#212 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_14_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8704, AI_STATIC)

/* Array#213 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#214 */
AI_ARRAY_OBJ_DECLARE(
  add_9_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#215 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8704, AI_STATIC)

/* Array#216 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_15_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8704, AI_STATIC)

/* Array#217 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_32_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#218 */
AI_ARRAY_OBJ_DECLARE(
  add_10_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#219 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8704, AI_STATIC)

/* Array#220 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_16_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8704, AI_STATIC)

/* Array#221 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#222 */
AI_ARRAY_OBJ_DECLARE(
  add_11_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#223 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8704, AI_STATIC)

/* Array#224 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_17_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8704, AI_STATIC)

/* Array#225 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_36_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#226 */
AI_ARRAY_OBJ_DECLARE(
  add_12_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#227 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8704, AI_STATIC)

/* Array#228 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_18_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2176, AI_STATIC)

/* Array#229 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)

/* Array#230 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3584, AI_STATIC)

/* Array#231 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_19_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3584, AI_STATIC)

/* Array#232 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_40_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)

/* Array#233 */
AI_ARRAY_OBJ_DECLARE(
  add_13_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)

/* Array#234 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3584, AI_STATIC)

/* Array#235 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_20_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3584, AI_STATIC)

/* Array#236 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)

/* Array#237 */
AI_ARRAY_OBJ_DECLARE(
  add_14_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)

/* Array#238 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3584, AI_STATIC)

/* Array#239 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_21_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3584, AI_STATIC)

/* Array#240 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)

/* Array#241 */
AI_ARRAY_OBJ_DECLARE(
  add_15_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)

/* Array#242 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3584, AI_STATIC)

/* Array#243 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_22_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3584, AI_STATIC)

/* Array#244 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)

/* Array#245 */
AI_ARRAY_OBJ_DECLARE(
  add_16_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)

/* Array#246 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_47_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3584, AI_STATIC)

/* Array#247 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_23_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3584, AI_STATIC)

/* Array#248 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)

/* Array#249 */
AI_ARRAY_OBJ_DECLARE(
  add_17_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)

/* Array#250 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#251 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_24_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)

/* Array#252 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)

/* Array#253 */
AI_ARRAY_OBJ_DECLARE(
  depthwise_conv2d_25_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)

/* Array#254 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_51_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)

/* Array#255 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 4080, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 255, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1020, 1020),
  1, &conv2d_52_bias_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 255), AI_STRIDE_INIT(4, 4, 512, 512, 512),
  1, &conv2d_52_weights_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_51_bias_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 4, 512, 512, 512),
  1, &conv2d_51_weights_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_25_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &depthwise_conv2d_25_bias_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_25_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 5, 128), AI_STRIDE_INIT(4, 4, 4, 20, 100),
  1, &depthwise_conv2d_25_weights_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_50_bias_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 128), AI_STRIDE_INIT(4, 4, 384, 384, 384),
  1, &conv2d_50_weights_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_24_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &depthwise_conv2d_24_bias_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_24_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 5, 96), AI_STRIDE_INIT(4, 4, 4, 20, 100),
  1, &depthwise_conv2d_24_weights_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_49_bias_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 96), AI_STRIDE_INIT(4, 4, 192, 192, 192),
  1, &conv2d_49_weights_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_48_bias_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 224, 1, 1, 48), AI_STRIDE_INIT(4, 4, 896, 896, 896),
  1, &conv2d_48_weights_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_23_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 1, 1), AI_STRIDE_INIT(4, 4, 4, 896, 896),
  1, &depthwise_conv2d_23_bias_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_23_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 224), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_23_weights_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_47_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 1, 1), AI_STRIDE_INIT(4, 4, 4, 896, 896),
  1, &conv2d_47_bias_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_47_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 224), AI_STRIDE_INIT(4, 4, 192, 192, 192),
  1, &conv2d_47_weights_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_46_bias_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 224, 1, 1, 48), AI_STRIDE_INIT(4, 4, 896, 896, 896),
  1, &conv2d_46_weights_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_22_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 1, 1), AI_STRIDE_INIT(4, 4, 4, 896, 896),
  1, &depthwise_conv2d_22_bias_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_22_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 224), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_22_weights_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 1, 1), AI_STRIDE_INIT(4, 4, 4, 896, 896),
  1, &conv2d_45_bias_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 224), AI_STRIDE_INIT(4, 4, 192, 192, 192),
  1, &conv2d_45_weights_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_44_bias_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 224, 1, 1, 48), AI_STRIDE_INIT(4, 4, 896, 896, 896),
  1, &conv2d_44_weights_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_21_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 1, 1), AI_STRIDE_INIT(4, 4, 4, 896, 896),
  1, &depthwise_conv2d_21_bias_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_21_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 224), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_21_weights_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 1, 1), AI_STRIDE_INIT(4, 4, 4, 896, 896),
  1, &conv2d_43_bias_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 224), AI_STRIDE_INIT(4, 4, 192, 192, 192),
  1, &conv2d_43_weights_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_42_bias_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 224, 1, 1, 48), AI_STRIDE_INIT(4, 4, 896, 896, 896),
  1, &conv2d_42_weights_array, NULL)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_20_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 1, 1), AI_STRIDE_INIT(4, 4, 4, 896, 896),
  1, &depthwise_conv2d_20_bias_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_20_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 224), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_20_weights_array, NULL)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 1, 1), AI_STRIDE_INIT(4, 4, 4, 896, 896),
  1, &conv2d_41_bias_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 224), AI_STRIDE_INIT(4, 4, 192, 192, 192),
  1, &conv2d_41_weights_array, NULL)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_40_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_40_bias_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_40_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 224, 1, 1, 48), AI_STRIDE_INIT(4, 4, 896, 896, 896),
  1, &conv2d_40_weights_array, NULL)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_19_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 1, 1), AI_STRIDE_INIT(4, 4, 4, 896, 896),
  1, &depthwise_conv2d_19_bias_array, NULL)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_19_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 224), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_19_weights_array, NULL)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 1, 1), AI_STRIDE_INIT(4, 4, 4, 896, 896),
  1, &conv2d_39_bias_array, NULL)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 224), AI_STRIDE_INIT(4, 4, 192, 192, 192),
  1, &conv2d_39_weights_array, NULL)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_38_bias_array, NULL)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 136, 1, 1, 48), AI_STRIDE_INIT(4, 4, 544, 544, 544),
  1, &conv2d_38_weights_array, NULL)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_18_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 1, 1), AI_STRIDE_INIT(4, 4, 4, 544, 544),
  1, &depthwise_conv2d_18_bias_array, NULL)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_18_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 136), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_18_weights_array, NULL)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 1, 1), AI_STRIDE_INIT(4, 4, 4, 544, 544),
  1, &conv2d_37_bias_array, NULL)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 136), AI_STRIDE_INIT(4, 4, 96, 96, 96),
  1, &conv2d_37_weights_array, NULL)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_36_bias_array, NULL)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 136, 1, 1, 24), AI_STRIDE_INIT(4, 4, 544, 544, 544),
  1, &conv2d_36_weights_array, NULL)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_17_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 1, 1), AI_STRIDE_INIT(4, 4, 4, 544, 544),
  1, &depthwise_conv2d_17_bias_array, NULL)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_17_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 136), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_17_weights_array, NULL)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 1, 1), AI_STRIDE_INIT(4, 4, 4, 544, 544),
  1, &conv2d_35_bias_array, NULL)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 136), AI_STRIDE_INIT(4, 4, 96, 96, 96),
  1, &conv2d_35_weights_array, NULL)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_34_bias_array, NULL)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 136, 1, 1, 24), AI_STRIDE_INIT(4, 4, 544, 544, 544),
  1, &conv2d_34_weights_array, NULL)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_16_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 1, 1), AI_STRIDE_INIT(4, 4, 4, 544, 544),
  1, &depthwise_conv2d_16_bias_array, NULL)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_16_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 136), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_16_weights_array, NULL)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 1, 1), AI_STRIDE_INIT(4, 4, 4, 544, 544),
  1, &conv2d_33_bias_array, NULL)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 136), AI_STRIDE_INIT(4, 4, 96, 96, 96),
  1, &conv2d_33_weights_array, NULL)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_32_bias_array, NULL)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 136, 1, 1, 24), AI_STRIDE_INIT(4, 4, 544, 544, 544),
  1, &conv2d_32_weights_array, NULL)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_15_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 1, 1), AI_STRIDE_INIT(4, 4, 4, 544, 544),
  1, &depthwise_conv2d_15_bias_array, NULL)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_15_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 136), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_15_weights_array, NULL)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 1, 1), AI_STRIDE_INIT(4, 4, 4, 544, 544),
  1, &conv2d_31_bias_array, NULL)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 136), AI_STRIDE_INIT(4, 4, 96, 96, 96),
  1, &conv2d_31_weights_array, NULL)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_30_bias_array, NULL)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 136, 1, 1, 24), AI_STRIDE_INIT(4, 4, 544, 544, 544),
  1, &conv2d_30_weights_array, NULL)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_14_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 1, 1), AI_STRIDE_INIT(4, 4, 4, 544, 544),
  1, &depthwise_conv2d_14_bias_array, NULL)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_14_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 136), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_14_weights_array, NULL)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 1, 1), AI_STRIDE_INIT(4, 4, 4, 544, 544),
  1, &conv2d_29_bias_array, NULL)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 136), AI_STRIDE_INIT(4, 4, 96, 96, 96),
  1, &conv2d_29_weights_array, NULL)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_28_bias_array, NULL)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 4, 384, 384, 384),
  1, &conv2d_28_weights_array, NULL)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_13_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &depthwise_conv2d_13_bias_array, NULL)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_13_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 96), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_13_weights_array, NULL)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_27_bias_array, NULL)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 4, 64, 64, 64),
  1, &conv2d_27_weights_array, NULL)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_26_bias_array, NULL)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 4, 384, 384, 384),
  1, &conv2d_26_weights_array, NULL)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_12_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &depthwise_conv2d_12_bias_array, NULL)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_12_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 96), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_12_weights_array, NULL)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_25_bias_array, NULL)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 4, 64, 64, 64),
  1, &conv2d_25_weights_array, NULL)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_24_bias_array, NULL)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 4, 384, 384, 384),
  1, &conv2d_24_weights_array, NULL)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_11_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &depthwise_conv2d_11_bias_array, NULL)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_11_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 96), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_11_weights_array, NULL)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_23_bias_array, NULL)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 4, 64, 64, 64),
  1, &conv2d_23_weights_array, NULL)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_22_bias_array, NULL)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 4, 384, 384, 384),
  1, &conv2d_22_weights_array, NULL)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_10_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &depthwise_conv2d_10_bias_array, NULL)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_10_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 96), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_10_weights_array, NULL)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_21_bias_array, NULL)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 4, 64, 64, 64),
  1, &conv2d_21_weights_array, NULL)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_20_bias_array, NULL)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 4, 384, 384, 384),
  1, &conv2d_20_weights_array, NULL)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_9_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &depthwise_conv2d_9_bias_array, NULL)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_9_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 96), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_9_weights_array, NULL)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_19_bias_array, NULL)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 4, 64, 64, 64),
  1, &conv2d_19_weights_array, NULL)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_18_bias_array, NULL)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 16), AI_STRIDE_INIT(4, 4, 192, 192, 192),
  1, &conv2d_18_weights_array, NULL)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_8_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &depthwise_conv2d_8_bias_array, NULL)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_8_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 48), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_8_weights_array, NULL)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_17_bias_array, NULL)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 4, 32, 32, 32),
  1, &conv2d_17_weights_array, NULL)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_16_bias_array, NULL)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 8), AI_STRIDE_INIT(4, 4, 192, 192, 192),
  1, &conv2d_16_weights_array, NULL)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_7_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &depthwise_conv2d_7_bias_array, NULL)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_7_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 48), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_7_weights_array, NULL)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_15_bias_array, NULL)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 4, 32, 32, 32),
  1, &conv2d_15_weights_array, NULL)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_14_bias_array, NULL)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 8), AI_STRIDE_INIT(4, 4, 192, 192, 192),
  1, &conv2d_14_weights_array, NULL)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_6_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &depthwise_conv2d_6_bias_array, NULL)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_6_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 48), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_6_weights_array, NULL)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_13_bias_array, NULL)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 4, 32, 32, 32),
  1, &conv2d_13_weights_array, NULL)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_12_bias_array, NULL)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 8), AI_STRIDE_INIT(4, 4, 128, 128, 128),
  1, &conv2d_12_weights_array, NULL)

/* Tensor #122 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_5_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &depthwise_conv2d_5_bias_array, NULL)

/* Tensor #123 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_5_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 32), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_5_weights_array, NULL)

/* Tensor #124 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_11_bias_array, NULL)

/* Tensor #125 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 32), AI_STRIDE_INIT(4, 4, 32, 32, 32),
  1, &conv2d_11_weights_array, NULL)

/* Tensor #126 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_10_bias_array, NULL)

/* Tensor #127 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 8), AI_STRIDE_INIT(4, 4, 128, 128, 128),
  1, &conv2d_10_weights_array, NULL)

/* Tensor #128 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_4_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &depthwise_conv2d_4_bias_array, NULL)

/* Tensor #129 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_4_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 32), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_4_weights_array, NULL)

/* Tensor #130 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_9_bias_array, NULL)

/* Tensor #131 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 32), AI_STRIDE_INIT(4, 4, 32, 32, 32),
  1, &conv2d_9_weights_array, NULL)

/* Tensor #132 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_8_bias_array, NULL)

/* Tensor #133 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 8), AI_STRIDE_INIT(4, 4, 128, 128, 128),
  1, &conv2d_8_weights_array, NULL)

/* Tensor #134 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_3_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &depthwise_conv2d_3_bias_array, NULL)

/* Tensor #135 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_3_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 32), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_3_weights_array, NULL)

/* Tensor #136 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_7_bias_array, NULL)

/* Tensor #137 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 32), AI_STRIDE_INIT(4, 4, 32, 32, 32),
  1, &conv2d_7_weights_array, NULL)

/* Tensor #138 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_6_bias_array, NULL)

/* Tensor #139 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 8), AI_STRIDE_INIT(4, 4, 96, 96, 96),
  1, &conv2d_6_weights_array, NULL)

/* Tensor #140 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_2_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &depthwise_conv2d_2_bias_array, NULL)

/* Tensor #141 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_2_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 24), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_2_weights_array, NULL)

/* Tensor #142 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_5_bias_array, NULL)

/* Tensor #143 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 4, 1, 1, 24), AI_STRIDE_INIT(4, 4, 16, 16, 16),
  1, &conv2d_5_weights_array, NULL)

/* Tensor #144 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 1, 1), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &conv2d_4_bias_array, NULL)

/* Tensor #145 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 4), AI_STRIDE_INIT(4, 4, 32, 32, 32),
  1, &conv2d_4_weights_array, NULL)

/* Tensor #146 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_1_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &depthwise_conv2d_1_bias_array, NULL)

/* Tensor #147 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_1_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 8), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_1_weights_array, NULL)

/* Tensor #148 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_3_bias_array, NULL)

/* Tensor #149 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 4, 1, 1, 8), AI_STRIDE_INIT(4, 4, 16, 16, 16),
  1, &conv2d_3_weights_array, NULL)

/* Tensor #150 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 1, 1), AI_STRIDE_INIT(4, 4, 4, 16, 16),
  1, &conv2d_2_bias_array, NULL)

/* Tensor #151 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 4), AI_STRIDE_INIT(4, 4, 32, 32, 32),
  1, &conv2d_2_weights_array, NULL)

/* Tensor #152 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &depthwise_conv2d_bias_array, NULL)

/* Tensor #153 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 8), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &depthwise_conv2d_weights_array, NULL)

/* Tensor #154 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_1_bias_array, NULL)

/* Tensor #155 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 8), AI_STRIDE_INIT(4, 4, 32, 32, 32),
  1, &conv2d_1_weights_array, NULL)

/* Tensor #156 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_bias_array, NULL)

/* Tensor #157 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 3, 3, 3, 8), AI_STRIDE_INIT(4, 4, 12, 36, 108),
  1, &conv2d_weights_array, NULL)

/* Tensor #158 */
AI_TENSOR_OBJ_DECLARE(
  image_input_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 128, 128), AI_STRIDE_INIT(4, 4, 4, 12, 1536),
  1, &image_input_output_array, NULL)

/* Tensor #159 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 64, 64), AI_STRIDE_INIT(4, 4, 4, 32, 2048),
  1, &conv2d_output_array, NULL)

/* Tensor #160 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 64, 64), AI_STRIDE_INIT(4, 4, 4, 32, 2048),
  1, &conv2d_1_output_array, NULL)

/* Tensor #161 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 64, 64), AI_STRIDE_INIT(4, 4, 4, 32, 2048),
  1, &depthwise_conv2d_output_array, NULL)

/* Tensor #162 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 64, 64), AI_STRIDE_INIT(4, 4, 4, 16, 1024),
  1, &conv2d_2_output_array, NULL)

/* Tensor #163 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 64, 64), AI_STRIDE_INIT(4, 4, 4, 32, 2048),
  1, &conv2d_3_output_array, NULL)

/* Tensor #164 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_1_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 64, 64), AI_STRIDE_INIT(4, 4, 4, 32, 2048),
  1, &depthwise_conv2d_1_output_array, NULL)

/* Tensor #165 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 64, 64), AI_STRIDE_INIT(4, 4, 4, 16, 1024),
  1, &conv2d_4_output_array, NULL)

/* Tensor #166 */
AI_TENSOR_OBJ_DECLARE(
  add_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 4, 64, 64), AI_STRIDE_INIT(4, 4, 4, 16, 1024),
  1, &add_output_array, NULL)

/* Tensor #167 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 64, 64), AI_STRIDE_INIT(4, 4, 4, 96, 6144),
  1, &conv2d_5_output_array, NULL)

/* Tensor #168 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_2_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 32, 32), AI_STRIDE_INIT(4, 4, 4, 96, 3072),
  1, &depthwise_conv2d_2_output_array, NULL)

/* Tensor #169 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 32, 32), AI_STRIDE_INIT(4, 4, 4, 32, 1024),
  1, &conv2d_6_output_array, NULL)

/* Tensor #170 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 4, 4, 128, 4096),
  1, &conv2d_7_output_array, NULL)

/* Tensor #171 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_3_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 4, 4, 128, 4096),
  1, &depthwise_conv2d_3_output_array, NULL)

/* Tensor #172 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 32, 32), AI_STRIDE_INIT(4, 4, 4, 32, 1024),
  1, &conv2d_8_output_array, NULL)

/* Tensor #173 */
AI_TENSOR_OBJ_DECLARE(
  add_1_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 32, 32), AI_STRIDE_INIT(4, 4, 4, 32, 1024),
  1, &add_1_output_array, NULL)

/* Tensor #174 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 4, 4, 128, 4096),
  1, &conv2d_9_output_array, NULL)

/* Tensor #175 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_4_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 4, 4, 128, 4096),
  1, &depthwise_conv2d_4_output_array, NULL)

/* Tensor #176 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 32, 32), AI_STRIDE_INIT(4, 4, 4, 32, 1024),
  1, &conv2d_10_output_array, NULL)

/* Tensor #177 */
AI_TENSOR_OBJ_DECLARE(
  add_2_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 32, 32), AI_STRIDE_INIT(4, 4, 4, 32, 1024),
  1, &add_2_output_array, NULL)

/* Tensor #178 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 32, 32), AI_STRIDE_INIT(4, 4, 4, 128, 4096),
  1, &conv2d_11_output_array, NULL)

/* Tensor #179 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_5_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 16, 16), AI_STRIDE_INIT(4, 4, 4, 128, 2048),
  1, &depthwise_conv2d_5_output_array, NULL)

/* Tensor #180 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 16, 16), AI_STRIDE_INIT(4, 4, 4, 32, 512),
  1, &conv2d_12_output_array, NULL)

/* Tensor #181 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 16, 16), AI_STRIDE_INIT(4, 4, 4, 192, 3072),
  1, &conv2d_13_output_array, NULL)

/* Tensor #182 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_6_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 16, 16), AI_STRIDE_INIT(4, 4, 4, 192, 3072),
  1, &depthwise_conv2d_6_output_array, NULL)

/* Tensor #183 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 16, 16), AI_STRIDE_INIT(4, 4, 4, 32, 512),
  1, &conv2d_14_output_array, NULL)

/* Tensor #184 */
AI_TENSOR_OBJ_DECLARE(
  add_3_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 16, 16), AI_STRIDE_INIT(4, 4, 4, 32, 512),
  1, &add_3_output_array, NULL)

/* Tensor #185 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 16, 16), AI_STRIDE_INIT(4, 4, 4, 192, 3072),
  1, &conv2d_15_output_array, NULL)

/* Tensor #186 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_7_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 16, 16), AI_STRIDE_INIT(4, 4, 4, 192, 3072),
  1, &depthwise_conv2d_7_output_array, NULL)

/* Tensor #187 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 16, 16), AI_STRIDE_INIT(4, 4, 4, 32, 512),
  1, &conv2d_16_output_array, NULL)

/* Tensor #188 */
AI_TENSOR_OBJ_DECLARE(
  add_4_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 16, 16), AI_STRIDE_INIT(4, 4, 4, 32, 512),
  1, &add_4_output_array, NULL)

/* Tensor #189 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 16, 16), AI_STRIDE_INIT(4, 4, 4, 192, 3072),
  1, &conv2d_17_output_array, NULL)

/* Tensor #190 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_8_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 16, 16), AI_STRIDE_INIT(4, 4, 4, 192, 3072),
  1, &depthwise_conv2d_8_output_array, NULL)

/* Tensor #191 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 4, 4, 64, 1024),
  1, &conv2d_18_output_array, NULL)

/* Tensor #192 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 4, 4, 384, 6144),
  1, &conv2d_19_output_array, NULL)

/* Tensor #193 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_9_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 4, 4, 384, 6144),
  1, &depthwise_conv2d_9_output_array, NULL)

/* Tensor #194 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 4, 4, 64, 1024),
  1, &conv2d_20_output_array, NULL)

/* Tensor #195 */
AI_TENSOR_OBJ_DECLARE(
  add_5_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 4, 4, 64, 1024),
  1, &add_5_output_array, NULL)

/* Tensor #196 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 4, 4, 384, 6144),
  1, &conv2d_21_output_array, NULL)

/* Tensor #197 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_10_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 4, 4, 384, 6144),
  1, &depthwise_conv2d_10_output_array, NULL)

/* Tensor #198 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 4, 4, 64, 1024),
  1, &conv2d_22_output_array, NULL)

/* Tensor #199 */
AI_TENSOR_OBJ_DECLARE(
  add_6_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 4, 4, 64, 1024),
  1, &add_6_output_array, NULL)

/* Tensor #200 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 4, 4, 384, 6144),
  1, &conv2d_23_output_array, NULL)

/* Tensor #201 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_11_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 4, 4, 384, 6144),
  1, &depthwise_conv2d_11_output_array, NULL)

/* Tensor #202 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 4, 4, 64, 1024),
  1, &conv2d_24_output_array, NULL)

/* Tensor #203 */
AI_TENSOR_OBJ_DECLARE(
  add_7_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 4, 4, 64, 1024),
  1, &add_7_output_array, NULL)

/* Tensor #204 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 4, 4, 384, 6144),
  1, &conv2d_25_output_array, NULL)

/* Tensor #205 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_12_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 4, 4, 384, 6144),
  1, &depthwise_conv2d_12_output_array, NULL)

/* Tensor #206 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 4, 4, 64, 1024),
  1, &conv2d_26_output_array, NULL)

/* Tensor #207 */
AI_TENSOR_OBJ_DECLARE(
  add_8_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 4, 4, 64, 1024),
  1, &add_8_output_array, NULL)

/* Tensor #208 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 4, 4, 384, 6144),
  1, &conv2d_27_output_array, NULL)

/* Tensor #209 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_13_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 8, 8), AI_STRIDE_INIT(4, 4, 4, 384, 3072),
  1, &depthwise_conv2d_13_output_array, NULL)

/* Tensor #210 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 4, 4, 96, 768),
  1, &conv2d_28_output_array, NULL)

/* Tensor #211 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 8, 8), AI_STRIDE_INIT(4, 4, 4, 544, 4352),
  1, &conv2d_29_output_array, NULL)

/* Tensor #212 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_14_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 8, 8), AI_STRIDE_INIT(4, 4, 4, 544, 4352),
  1, &depthwise_conv2d_14_output_array, NULL)

/* Tensor #213 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 4, 4, 96, 768),
  1, &conv2d_30_output_array, NULL)

/* Tensor #214 */
AI_TENSOR_OBJ_DECLARE(
  add_9_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 4, 4, 96, 768),
  1, &add_9_output_array, NULL)

/* Tensor #215 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 8, 8), AI_STRIDE_INIT(4, 4, 4, 544, 4352),
  1, &conv2d_31_output_array, NULL)

/* Tensor #216 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_15_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 8, 8), AI_STRIDE_INIT(4, 4, 4, 544, 4352),
  1, &depthwise_conv2d_15_output_array, NULL)

/* Tensor #217 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_32_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 4, 4, 96, 768),
  1, &conv2d_32_output_array, NULL)

/* Tensor #218 */
AI_TENSOR_OBJ_DECLARE(
  add_10_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 4, 4, 96, 768),
  1, &add_10_output_array, NULL)

/* Tensor #219 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 8, 8), AI_STRIDE_INIT(4, 4, 4, 544, 4352),
  1, &conv2d_33_output_array, NULL)

/* Tensor #220 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_16_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 8, 8), AI_STRIDE_INIT(4, 4, 4, 544, 4352),
  1, &depthwise_conv2d_16_output_array, NULL)

/* Tensor #221 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 4, 4, 96, 768),
  1, &conv2d_34_output_array, NULL)

/* Tensor #222 */
AI_TENSOR_OBJ_DECLARE(
  add_11_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 4, 4, 96, 768),
  1, &add_11_output_array, NULL)

/* Tensor #223 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 8, 8), AI_STRIDE_INIT(4, 4, 4, 544, 4352),
  1, &conv2d_35_output_array, NULL)

/* Tensor #224 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_17_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 8, 8), AI_STRIDE_INIT(4, 4, 4, 544, 4352),
  1, &depthwise_conv2d_17_output_array, NULL)

/* Tensor #225 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_36_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 4, 4, 96, 768),
  1, &conv2d_36_output_array, NULL)

/* Tensor #226 */
AI_TENSOR_OBJ_DECLARE(
  add_12_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 4, 4, 96, 768),
  1, &add_12_output_array, NULL)

/* Tensor #227 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 8, 8), AI_STRIDE_INIT(4, 4, 4, 544, 4352),
  1, &conv2d_37_output_array, NULL)

/* Tensor #228 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_18_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 136, 4, 4), AI_STRIDE_INIT(4, 4, 4, 544, 2176),
  1, &depthwise_conv2d_18_output_array, NULL)

/* Tensor #229 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 4, 4), AI_STRIDE_INIT(4, 4, 4, 192, 768),
  1, &conv2d_38_output_array, NULL)

/* Tensor #230 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 4, 4), AI_STRIDE_INIT(4, 4, 4, 896, 3584),
  1, &conv2d_39_output_array, NULL)

/* Tensor #231 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_19_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 4, 4), AI_STRIDE_INIT(4, 4, 4, 896, 3584),
  1, &depthwise_conv2d_19_output_array, NULL)

/* Tensor #232 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_40_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 4, 4), AI_STRIDE_INIT(4, 4, 4, 192, 768),
  1, &conv2d_40_output_array, NULL)

/* Tensor #233 */
AI_TENSOR_OBJ_DECLARE(
  add_13_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 4, 4), AI_STRIDE_INIT(4, 4, 4, 192, 768),
  1, &add_13_output_array, NULL)

/* Tensor #234 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 4, 4), AI_STRIDE_INIT(4, 4, 4, 896, 3584),
  1, &conv2d_41_output_array, NULL)

/* Tensor #235 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_20_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 4, 4), AI_STRIDE_INIT(4, 4, 4, 896, 3584),
  1, &depthwise_conv2d_20_output_array, NULL)

/* Tensor #236 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 4, 4), AI_STRIDE_INIT(4, 4, 4, 192, 768),
  1, &conv2d_42_output_array, NULL)

/* Tensor #237 */
AI_TENSOR_OBJ_DECLARE(
  add_14_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 4, 4), AI_STRIDE_INIT(4, 4, 4, 192, 768),
  1, &add_14_output_array, NULL)

/* Tensor #238 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 4, 4), AI_STRIDE_INIT(4, 4, 4, 896, 3584),
  1, &conv2d_43_output_array, NULL)

/* Tensor #239 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_21_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 4, 4), AI_STRIDE_INIT(4, 4, 4, 896, 3584),
  1, &depthwise_conv2d_21_output_array, NULL)

/* Tensor #240 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 4, 4), AI_STRIDE_INIT(4, 4, 4, 192, 768),
  1, &conv2d_44_output_array, NULL)

/* Tensor #241 */
AI_TENSOR_OBJ_DECLARE(
  add_15_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 4, 4), AI_STRIDE_INIT(4, 4, 4, 192, 768),
  1, &add_15_output_array, NULL)

/* Tensor #242 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 4, 4), AI_STRIDE_INIT(4, 4, 4, 896, 3584),
  1, &conv2d_45_output_array, NULL)

/* Tensor #243 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_22_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 4, 4), AI_STRIDE_INIT(4, 4, 4, 896, 3584),
  1, &depthwise_conv2d_22_output_array, NULL)

/* Tensor #244 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 4, 4), AI_STRIDE_INIT(4, 4, 4, 192, 768),
  1, &conv2d_46_output_array, NULL)

/* Tensor #245 */
AI_TENSOR_OBJ_DECLARE(
  add_16_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 4, 4), AI_STRIDE_INIT(4, 4, 4, 192, 768),
  1, &add_16_output_array, NULL)

/* Tensor #246 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_47_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 4, 4), AI_STRIDE_INIT(4, 4, 4, 896, 3584),
  1, &conv2d_47_output_array, NULL)

/* Tensor #247 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_23_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 224, 4, 4), AI_STRIDE_INIT(4, 4, 4, 896, 3584),
  1, &depthwise_conv2d_23_output_array, NULL)

/* Tensor #248 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 4, 4), AI_STRIDE_INIT(4, 4, 4, 192, 768),
  1, &conv2d_48_output_array, NULL)

/* Tensor #249 */
AI_TENSOR_OBJ_DECLARE(
  add_17_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 4, 4), AI_STRIDE_INIT(4, 4, 4, 192, 768),
  1, &add_17_output_array, NULL)

/* Tensor #250 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 4, 4), AI_STRIDE_INIT(4, 4, 4, 384, 1536),
  1, &conv2d_49_output_array, NULL)

/* Tensor #251 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_24_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 4, 4), AI_STRIDE_INIT(4, 4, 4, 384, 1536),
  1, &depthwise_conv2d_24_output_array, NULL)

/* Tensor #252 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 4, 4), AI_STRIDE_INIT(4, 4, 4, 512, 2048),
  1, &conv2d_50_output_array, NULL)

/* Tensor #253 */
AI_TENSOR_OBJ_DECLARE(
  depthwise_conv2d_25_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 4, 4), AI_STRIDE_INIT(4, 4, 4, 512, 2048),
  1, &depthwise_conv2d_25_output_array, NULL)

/* Tensor #254 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_51_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 4, 4), AI_STRIDE_INIT(4, 4, 4, 512, 2048),
  1, &conv2d_51_output_array, NULL)

/* Tensor #255 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 255, 4, 4), AI_STRIDE_INIT(4, 4, 4, 1020, 4080),
  1, &conv2d_52_output_array, NULL)



/**  Layer declarations section  **********************************************/



AI_STATIC_CONST ai_float conv2d_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_nl_params_data, conv2d_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &image_input_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_weights, &conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_layer, 2,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_1_layer, AI_STATIC,
  .tensors = &conv2d_chain, 
  .groups = 1, 
  .nl_params = &conv2d_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)


AI_STATIC_CONST ai_float conv2d_1_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_1_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_1_nl_params_data, conv2d_1_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_weights, &conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_1_layer, 5,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_layer, AI_STATIC,
  .tensors = &conv2d_1_chain, 
  .groups = 1, 
  .nl_params = &conv2d_1_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_nl_params_data, depthwise_conv2d_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_weights, &depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_layer, 8,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_2_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_chain, 
  .groups = 8, 
  .nl_params = &depthwise_conv2d_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 11,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_3_layer, AI_STATIC,
  .tensors = &conv2d_2_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float conv2d_3_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_3_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_3_nl_params_data, conv2d_3_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 13,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_1_layer, AI_STATIC,
  .tensors = &conv2d_3_chain, 
  .groups = 1, 
  .nl_params = &conv2d_3_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_1_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_1_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_1_nl_params_data, depthwise_conv2d_1_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_1_weights, &depthwise_conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_1_layer, 16,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_4_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_1_chain, 
  .groups = 8, 
  .nl_params = &depthwise_conv2d_1_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_4_weights, &conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_4_layer, 19,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_layer, AI_STATIC,
  .tensors = &conv2d_4_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_2_output, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_layer, 22,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_5_layer, AI_STATIC,
  .tensors = &add_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_5_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_5_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_5_nl_params_data, conv2d_5_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_5_weights, &conv2d_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_5_layer, 23,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_2_layer, AI_STATIC,
  .tensors = &conv2d_5_chain, 
  .groups = 1, 
  .nl_params = &conv2d_5_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_2_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_2_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_2_nl_params_data, depthwise_conv2d_2_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_2_weights, &depthwise_conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_2_layer, 27,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_6_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_2_chain, 
  .groups = 24, 
  .nl_params = &depthwise_conv2d_2_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_6_weights, &conv2d_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_layer, 30,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_7_layer, AI_STATIC,
  .tensors = &conv2d_6_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float conv2d_7_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_7_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_7_nl_params_data, conv2d_7_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_7_weights, &conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_7_layer, 32,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_3_layer, AI_STATIC,
  .tensors = &conv2d_7_chain, 
  .groups = 1, 
  .nl_params = &conv2d_7_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_3_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_3_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_3_nl_params_data, depthwise_conv2d_3_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_3_weights, &depthwise_conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_3_layer, 35,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_8_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_3_chain, 
  .groups = 32, 
  .nl_params = &depthwise_conv2d_3_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_8_weights, &conv2d_8_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_8_layer, 38,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_1_layer, AI_STATIC,
  .tensors = &conv2d_8_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_6_output, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_1_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_1_layer, 41,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_9_layer, AI_STATIC,
  .tensors = &add_1_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_9_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_9_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_9_nl_params_data, conv2d_9_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 42,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_4_layer, AI_STATIC,
  .tensors = &conv2d_9_chain, 
  .groups = 1, 
  .nl_params = &conv2d_9_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_4_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_4_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_4_nl_params_data, depthwise_conv2d_4_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_4_weights, &depthwise_conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_4_layer, 45,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_10_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_4_chain, 
  .groups = 32, 
  .nl_params = &depthwise_conv2d_4_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_10_weights, &conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_10_layer, 48,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_2_layer, AI_STATIC,
  .tensors = &conv2d_10_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_1_output, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_2_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_2_layer, 51,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_11_layer, AI_STATIC,
  .tensors = &add_2_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_11_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_11_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_11_nl_params_data, conv2d_11_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_11_weights, &conv2d_11_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_11_layer, 52,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_5_layer, AI_STATIC,
  .tensors = &conv2d_11_chain, 
  .groups = 1, 
  .nl_params = &conv2d_11_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_5_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_5_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_5_nl_params_data, depthwise_conv2d_5_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_5_weights, &depthwise_conv2d_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_5_layer, 56,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_12_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_5_chain, 
  .groups = 32, 
  .nl_params = &depthwise_conv2d_5_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_12_weights, &conv2d_12_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_12_layer, 59,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_13_layer, AI_STATIC,
  .tensors = &conv2d_12_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float conv2d_13_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_13_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_13_nl_params_data, conv2d_13_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_13_weights, &conv2d_13_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_13_layer, 61,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_6_layer, AI_STATIC,
  .tensors = &conv2d_13_chain, 
  .groups = 1, 
  .nl_params = &conv2d_13_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_6_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_6_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_6_nl_params_data, depthwise_conv2d_6_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_6_weights, &depthwise_conv2d_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_6_layer, 64,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_14_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_6_chain, 
  .groups = 48, 
  .nl_params = &depthwise_conv2d_6_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_14_weights, &conv2d_14_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_14_layer, 67,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_3_layer, AI_STATIC,
  .tensors = &conv2d_14_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_12_output, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_3_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_3_layer, 70,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_15_layer, AI_STATIC,
  .tensors = &add_3_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_15_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_15_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_15_nl_params_data, conv2d_15_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_15_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_layer, 71,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_7_layer, AI_STATIC,
  .tensors = &conv2d_15_chain, 
  .groups = 1, 
  .nl_params = &conv2d_15_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_7_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_7_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_7_nl_params_data, depthwise_conv2d_7_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_7_weights, &depthwise_conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_7_layer, 74,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_16_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_7_chain, 
  .groups = 48, 
  .nl_params = &depthwise_conv2d_7_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_16_weights, &conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_16_layer, 77,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_4_layer, AI_STATIC,
  .tensors = &conv2d_16_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_3_output, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_4_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_4_layer, 80,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_17_layer, AI_STATIC,
  .tensors = &add_4_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_17_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_17_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_17_nl_params_data, conv2d_17_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_17_weights, &conv2d_17_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_layer, 81,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_8_layer, AI_STATIC,
  .tensors = &conv2d_17_chain, 
  .groups = 1, 
  .nl_params = &conv2d_17_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_8_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_8_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_8_nl_params_data, depthwise_conv2d_8_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_8_weights, &depthwise_conv2d_8_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_8_layer, 84,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_18_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_8_chain, 
  .groups = 48, 
  .nl_params = &depthwise_conv2d_8_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_18_weights, &conv2d_18_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_18_layer, 87,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_19_layer, AI_STATIC,
  .tensors = &conv2d_18_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float conv2d_19_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_19_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_19_nl_params_data, conv2d_19_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_19_weights, &conv2d_19_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_19_layer, 89,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_9_layer, AI_STATIC,
  .tensors = &conv2d_19_chain, 
  .groups = 1, 
  .nl_params = &conv2d_19_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_9_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_9_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_9_nl_params_data, depthwise_conv2d_9_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_9_weights, &depthwise_conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_9_layer, 92,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_20_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_9_chain, 
  .groups = 96, 
  .nl_params = &depthwise_conv2d_9_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_20_weights, &conv2d_20_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_20_layer, 95,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_5_layer, AI_STATIC,
  .tensors = &conv2d_20_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_18_output, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_5_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_5_layer, 98,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_21_layer, AI_STATIC,
  .tensors = &add_5_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_21_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_21_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_21_nl_params_data, conv2d_21_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_21_weights, &conv2d_21_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_21_layer, 99,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_10_layer, AI_STATIC,
  .tensors = &conv2d_21_chain, 
  .groups = 1, 
  .nl_params = &conv2d_21_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_10_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_10_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_10_nl_params_data, depthwise_conv2d_10_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_10_weights, &depthwise_conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_10_layer, 102,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_22_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_10_chain, 
  .groups = 96, 
  .nl_params = &depthwise_conv2d_10_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_22_weights, &conv2d_22_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_22_layer, 105,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_6_layer, AI_STATIC,
  .tensors = &conv2d_22_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_5_output, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_6_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_6_layer, 108,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_23_layer, AI_STATIC,
  .tensors = &add_6_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_23_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_23_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_23_nl_params_data, conv2d_23_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_23_weights, &conv2d_23_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_23_layer, 109,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_11_layer, AI_STATIC,
  .tensors = &conv2d_23_chain, 
  .groups = 1, 
  .nl_params = &conv2d_23_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_11_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_11_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_11_nl_params_data, depthwise_conv2d_11_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_11_weights, &depthwise_conv2d_11_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_11_layer, 112,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_24_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_11_chain, 
  .groups = 96, 
  .nl_params = &depthwise_conv2d_11_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_24_weights, &conv2d_24_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_24_layer, 115,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_7_layer, AI_STATIC,
  .tensors = &conv2d_24_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_6_output, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_7_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_7_layer, 118,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_25_layer, AI_STATIC,
  .tensors = &add_7_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_25_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_25_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_25_nl_params_data, conv2d_25_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_25_weights, &conv2d_25_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_25_layer, 119,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_12_layer, AI_STATIC,
  .tensors = &conv2d_25_chain, 
  .groups = 1, 
  .nl_params = &conv2d_25_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_12_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_12_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_12_nl_params_data, depthwise_conv2d_12_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_12_weights, &depthwise_conv2d_12_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_12_layer, 122,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_26_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_12_chain, 
  .groups = 96, 
  .nl_params = &depthwise_conv2d_12_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_26_weights, &conv2d_26_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_26_layer, 125,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_8_layer, AI_STATIC,
  .tensors = &conv2d_26_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_7_output, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_8_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_8_layer, 128,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_27_layer, AI_STATIC,
  .tensors = &add_8_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_27_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_27_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_27_nl_params_data, conv2d_27_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_27_weights, &conv2d_27_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_27_layer, 129,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_13_layer, AI_STATIC,
  .tensors = &conv2d_27_chain, 
  .groups = 1, 
  .nl_params = &conv2d_27_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_13_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_13_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_13_nl_params_data, depthwise_conv2d_13_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_13_weights, &depthwise_conv2d_13_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_13_layer, 133,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_28_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_13_chain, 
  .groups = 96, 
  .nl_params = &depthwise_conv2d_13_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_28_weights, &conv2d_28_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_28_layer, 136,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_29_layer, AI_STATIC,
  .tensors = &conv2d_28_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float conv2d_29_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_29_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_29_nl_params_data, conv2d_29_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_29_weights, &conv2d_29_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_29_layer, 138,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_14_layer, AI_STATIC,
  .tensors = &conv2d_29_chain, 
  .groups = 1, 
  .nl_params = &conv2d_29_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_14_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_14_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_14_nl_params_data, depthwise_conv2d_14_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_14_weights, &depthwise_conv2d_14_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_14_layer, 141,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_30_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_14_chain, 
  .groups = 136, 
  .nl_params = &depthwise_conv2d_14_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_30_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_30_weights, &conv2d_30_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_30_layer, 144,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_9_layer, AI_STATIC,
  .tensors = &conv2d_30_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_28_output, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_9_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_9_layer, 147,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_31_layer, AI_STATIC,
  .tensors = &add_9_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_31_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_31_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_31_nl_params_data, conv2d_31_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_31_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_31_weights, &conv2d_31_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_31_layer, 148,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_15_layer, AI_STATIC,
  .tensors = &conv2d_31_chain, 
  .groups = 1, 
  .nl_params = &conv2d_31_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_15_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_15_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_15_nl_params_data, depthwise_conv2d_15_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_15_weights, &depthwise_conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_15_layer, 151,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_32_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_15_chain, 
  .groups = 136, 
  .nl_params = &depthwise_conv2d_15_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_32_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_32_weights, &conv2d_32_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_32_layer, 154,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_10_layer, AI_STATIC,
  .tensors = &conv2d_32_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_9_output, &conv2d_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_10_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_10_layer, 157,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_33_layer, AI_STATIC,
  .tensors = &add_10_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_33_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_33_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_33_nl_params_data, conv2d_33_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_33_weights, &conv2d_33_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_33_layer, 158,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_16_layer, AI_STATIC,
  .tensors = &conv2d_33_chain, 
  .groups = 1, 
  .nl_params = &conv2d_33_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_16_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_16_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_16_nl_params_data, depthwise_conv2d_16_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_16_weights, &depthwise_conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_16_layer, 161,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_34_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_16_chain, 
  .groups = 136, 
  .nl_params = &depthwise_conv2d_16_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_34_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_34_weights, &conv2d_34_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_34_layer, 164,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_11_layer, AI_STATIC,
  .tensors = &conv2d_34_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_10_output, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_11_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_11_layer, 167,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_35_layer, AI_STATIC,
  .tensors = &add_11_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_35_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_35_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_35_nl_params_data, conv2d_35_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_35_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_35_weights, &conv2d_35_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_35_layer, 168,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_17_layer, AI_STATIC,
  .tensors = &conv2d_35_chain, 
  .groups = 1, 
  .nl_params = &conv2d_35_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_17_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_17_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_17_nl_params_data, depthwise_conv2d_17_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_17_weights, &depthwise_conv2d_17_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_17_layer, 171,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_36_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_17_chain, 
  .groups = 136, 
  .nl_params = &depthwise_conv2d_17_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_36_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_36_weights, &conv2d_36_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_36_layer, 174,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_12_layer, AI_STATIC,
  .tensors = &conv2d_36_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_11_output, &conv2d_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_12_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_12_layer, 177,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_37_layer, AI_STATIC,
  .tensors = &add_12_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_37_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_37_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_37_nl_params_data, conv2d_37_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_37_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_37_weights, &conv2d_37_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_37_layer, 178,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_18_layer, AI_STATIC,
  .tensors = &conv2d_37_chain, 
  .groups = 1, 
  .nl_params = &conv2d_37_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_18_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_18_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_18_nl_params_data, depthwise_conv2d_18_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_18_weights, &depthwise_conv2d_18_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_18_layer, 182,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_38_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_18_chain, 
  .groups = 136, 
  .nl_params = &depthwise_conv2d_18_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_38_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_38_weights, &conv2d_38_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_38_layer, 185,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_39_layer, AI_STATIC,
  .tensors = &conv2d_38_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float conv2d_39_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_39_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_39_nl_params_data, conv2d_39_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_39_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_39_weights, &conv2d_39_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_39_layer, 187,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_19_layer, AI_STATIC,
  .tensors = &conv2d_39_chain, 
  .groups = 1, 
  .nl_params = &conv2d_39_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_19_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_19_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_19_nl_params_data, depthwise_conv2d_19_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_19_weights, &depthwise_conv2d_19_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_19_layer, 190,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_40_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_19_chain, 
  .groups = 224, 
  .nl_params = &depthwise_conv2d_19_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_40_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_40_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_40_weights, &conv2d_40_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_40_layer, 193,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_13_layer, AI_STATIC,
  .tensors = &conv2d_40_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_38_output, &conv2d_40_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_13_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_13_layer, 196,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_41_layer, AI_STATIC,
  .tensors = &add_13_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_41_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_41_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_41_nl_params_data, conv2d_41_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_41_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_41_weights, &conv2d_41_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_41_layer, 197,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_20_layer, AI_STATIC,
  .tensors = &conv2d_41_chain, 
  .groups = 1, 
  .nl_params = &conv2d_41_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_20_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_20_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_20_nl_params_data, depthwise_conv2d_20_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_20_weights, &depthwise_conv2d_20_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_20_layer, 200,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_42_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_20_chain, 
  .groups = 224, 
  .nl_params = &depthwise_conv2d_20_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_42_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_42_weights, &conv2d_42_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_42_layer, 203,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_14_layer, AI_STATIC,
  .tensors = &conv2d_42_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_13_output, &conv2d_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_14_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_14_layer, 206,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_43_layer, AI_STATIC,
  .tensors = &add_14_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_43_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_43_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_43_nl_params_data, conv2d_43_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_43_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_43_weights, &conv2d_43_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_43_layer, 207,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_21_layer, AI_STATIC,
  .tensors = &conv2d_43_chain, 
  .groups = 1, 
  .nl_params = &conv2d_43_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_21_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_21_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_21_nl_params_data, depthwise_conv2d_21_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_21_weights, &depthwise_conv2d_21_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_21_layer, 210,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_44_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_21_chain, 
  .groups = 224, 
  .nl_params = &depthwise_conv2d_21_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_44_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_44_weights, &conv2d_44_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_44_layer, 213,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_15_layer, AI_STATIC,
  .tensors = &conv2d_44_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_14_output, &conv2d_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_15_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_15_layer, 216,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_45_layer, AI_STATIC,
  .tensors = &add_15_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_45_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_45_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_45_nl_params_data, conv2d_45_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_45_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_45_weights, &conv2d_45_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_45_layer, 217,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_22_layer, AI_STATIC,
  .tensors = &conv2d_45_chain, 
  .groups = 1, 
  .nl_params = &conv2d_45_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_22_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_22_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_22_nl_params_data, depthwise_conv2d_22_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_22_weights, &depthwise_conv2d_22_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_22_layer, 220,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_46_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_22_chain, 
  .groups = 224, 
  .nl_params = &depthwise_conv2d_22_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_46_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_46_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_46_weights, &conv2d_46_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_46_layer, 223,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_16_layer, AI_STATIC,
  .tensors = &conv2d_46_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_15_output, &conv2d_46_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_16_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_16_layer, 226,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_47_layer, AI_STATIC,
  .tensors = &add_16_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_47_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_47_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_47_nl_params_data, conv2d_47_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_47_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_47_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_47_weights, &conv2d_47_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_47_layer, 227,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_23_layer, AI_STATIC,
  .tensors = &conv2d_47_chain, 
  .groups = 1, 
  .nl_params = &conv2d_47_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_23_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_23_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_23_nl_params_data, depthwise_conv2d_23_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_47_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_23_weights, &depthwise_conv2d_23_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_23_layer, 230,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_48_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_23_chain, 
  .groups = 224, 
  .nl_params = &depthwise_conv2d_23_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_48_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_48_weights, &conv2d_48_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_48_layer, 233,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &add_17_layer, AI_STATIC,
  .tensors = &conv2d_48_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  add_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &add_16_output, &conv2d_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_17_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  add_17_layer, 236,
  ELTWISE_TYPE,
  eltwise, forward_eltwise,
  &AI_NET_OBJ_INSTANCE, &conv2d_49_layer, AI_STATIC,
  .tensors = &add_17_chain, 
  .operation = ai_sum, 
)


AI_STATIC_CONST ai_float conv2d_49_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_49_nl_params, AI_ARRAY_FORMAT_FLOAT,
    conv2d_49_nl_params_data, conv2d_49_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_49_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &add_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_49_weights, &conv2d_49_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_49_layer, 237,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_24_layer, AI_STATIC,
  .tensors = &conv2d_49_chain, 
  .groups = 1, 
  .nl_params = &conv2d_49_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_24_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_24_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_24_nl_params_data, depthwise_conv2d_24_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_24_weights, &depthwise_conv2d_24_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_24_layer, 240,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_50_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_24_chain, 
  .groups = 96, 
  .nl_params = &depthwise_conv2d_24_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 2, 2, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_50_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_50_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_50_weights, &conv2d_50_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_50_layer, 243,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &depthwise_conv2d_25_layer, AI_STATIC,
  .tensors = &conv2d_50_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float depthwise_conv2d_25_nl_params_data[] = { 0.0, 0.10000000149011612, -1 };
AI_ARRAY_OBJ_DECLARE(
    depthwise_conv2d_25_nl_params, AI_ARRAY_FORMAT_FLOAT,
    depthwise_conv2d_25_nl_params_data, depthwise_conv2d_25_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  depthwise_conv2d_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_50_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &depthwise_conv2d_25_weights, &depthwise_conv2d_25_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  depthwise_conv2d_25_layer, 245,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_51_layer, AI_STATIC,
  .tensors = &depthwise_conv2d_25_chain, 
  .groups = 128, 
  .nl_params = &depthwise_conv2d_25_nl_params, 
  .nl_func = nl_func_relu_generic_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 2, 2, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_51_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &depthwise_conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_51_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_51_weights, &conv2d_51_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_51_layer, 248,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_52_layer, AI_STATIC,
  .tensors = &conv2d_51_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_52_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_51_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_52_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_52_weights, &conv2d_52_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_52_layer, 250,
  CONV2D_TYPE,
  conv2d, forward_conv2d,
  &AI_NET_OBJ_INSTANCE, &conv2d_52_layer, AI_STATIC,
  .tensors = &conv2d_52_chain, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 1062012, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 402624, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_1_IN_NUM, &image_input_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_1_OUT_NUM, &conv2d_52_output),
  &conv2d_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool network_1_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, AI_NETWORK_1_ACTIVATIONS_ALIGNMENT));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    image_input_output_array.data = AI_PTR(NULL);
    image_input_output_array.data_start = AI_PTR(NULL);
    conv2d_output_array.data = AI_PTR(activations + 140480);
    conv2d_output_array.data_start = AI_PTR(activations + 140480);
    conv2d_1_output_array.data = AI_PTR(activations + 138400);
    conv2d_1_output_array.data_start = AI_PTR(activations + 138400);
    depthwise_conv2d_output_array.data = AI_PTR(activations + 7328);
    depthwise_conv2d_output_array.data_start = AI_PTR(activations + 7328);
    conv2d_2_output_array.data = AI_PTR(activations + 206016);
    conv2d_2_output_array.data_start = AI_PTR(activations + 206016);
    conv2d_3_output_array.data = AI_PTR(activations + 7328);
    conv2d_3_output_array.data_start = AI_PTR(activations + 7328);
    depthwise_conv2d_1_output_array.data = AI_PTR(activations + 3168);
    depthwise_conv2d_1_output_array.data_start = AI_PTR(activations + 3168);
    conv2d_4_output_array.data = AI_PTR(activations + 271552);
    conv2d_4_output_array.data_start = AI_PTR(activations + 271552);
    add_output_array.data = AI_PTR(activations + 337088);
    add_output_array.data_start = AI_PTR(activations + 337088);
    conv2d_5_output_array.data = AI_PTR(activations + 3168);
    conv2d_5_output_array.data_start = AI_PTR(activations + 3168);
    depthwise_conv2d_2_output_array.data = AI_PTR(activations + 0);
    depthwise_conv2d_2_output_array.data_start = AI_PTR(activations + 0);
    conv2d_6_output_array.data = AI_PTR(activations + 98304);
    conv2d_6_output_array.data_start = AI_PTR(activations + 98304);
    conv2d_7_output_array.data = AI_PTR(activations + 131072);
    conv2d_7_output_array.data_start = AI_PTR(activations + 131072);
    depthwise_conv2d_3_output_array.data = AI_PTR(activations + 262144);
    depthwise_conv2d_3_output_array.data_start = AI_PTR(activations + 262144);
    conv2d_8_output_array.data = AI_PTR(activations + 0);
    conv2d_8_output_array.data_start = AI_PTR(activations + 0);
    add_1_output_array.data = AI_PTR(activations + 32768);
    add_1_output_array.data_start = AI_PTR(activations + 32768);
    conv2d_9_output_array.data = AI_PTR(activations + 65536);
    conv2d_9_output_array.data_start = AI_PTR(activations + 65536);
    depthwise_conv2d_4_output_array.data = AI_PTR(activations + 196608);
    depthwise_conv2d_4_output_array.data_start = AI_PTR(activations + 196608);
    conv2d_10_output_array.data = AI_PTR(activations + 0);
    conv2d_10_output_array.data_start = AI_PTR(activations + 0);
    add_2_output_array.data = AI_PTR(activations + 65536);
    add_2_output_array.data_start = AI_PTR(activations + 65536);
    conv2d_11_output_array.data = AI_PTR(activations + 98304);
    conv2d_11_output_array.data_start = AI_PTR(activations + 98304);
    depthwise_conv2d_5_output_array.data = AI_PTR(activations + 0);
    depthwise_conv2d_5_output_array.data_start = AI_PTR(activations + 0);
    conv2d_12_output_array.data = AI_PTR(activations + 32768);
    conv2d_12_output_array.data_start = AI_PTR(activations + 32768);
    conv2d_13_output_array.data = AI_PTR(activations + 40960);
    conv2d_13_output_array.data_start = AI_PTR(activations + 40960);
    depthwise_conv2d_6_output_array.data = AI_PTR(activations + 90112);
    depthwise_conv2d_6_output_array.data_start = AI_PTR(activations + 90112);
    conv2d_14_output_array.data = AI_PTR(activations + 0);
    conv2d_14_output_array.data_start = AI_PTR(activations + 0);
    add_3_output_array.data = AI_PTR(activations + 8192);
    add_3_output_array.data_start = AI_PTR(activations + 8192);
    conv2d_15_output_array.data = AI_PTR(activations + 16384);
    conv2d_15_output_array.data_start = AI_PTR(activations + 16384);
    depthwise_conv2d_7_output_array.data = AI_PTR(activations + 65536);
    depthwise_conv2d_7_output_array.data_start = AI_PTR(activations + 65536);
    conv2d_16_output_array.data = AI_PTR(activations + 0);
    conv2d_16_output_array.data_start = AI_PTR(activations + 0);
    add_4_output_array.data = AI_PTR(activations + 16384);
    add_4_output_array.data_start = AI_PTR(activations + 16384);
    conv2d_17_output_array.data = AI_PTR(activations + 24576);
    conv2d_17_output_array.data_start = AI_PTR(activations + 24576);
    depthwise_conv2d_8_output_array.data = AI_PTR(activations + 73728);
    depthwise_conv2d_8_output_array.data_start = AI_PTR(activations + 73728);
    conv2d_18_output_array.data = AI_PTR(activations + 0);
    conv2d_18_output_array.data_start = AI_PTR(activations + 0);
    conv2d_19_output_array.data = AI_PTR(activations + 16384);
    conv2d_19_output_array.data_start = AI_PTR(activations + 16384);
    depthwise_conv2d_9_output_array.data = AI_PTR(activations + 114688);
    depthwise_conv2d_9_output_array.data_start = AI_PTR(activations + 114688);
    conv2d_20_output_array.data = AI_PTR(activations + 16384);
    conv2d_20_output_array.data_start = AI_PTR(activations + 16384);
    add_5_output_array.data = AI_PTR(activations + 32768);
    add_5_output_array.data_start = AI_PTR(activations + 32768);
    conv2d_21_output_array.data = AI_PTR(activations + 49152);
    conv2d_21_output_array.data_start = AI_PTR(activations + 49152);
    depthwise_conv2d_10_output_array.data = AI_PTR(activations + 147456);
    depthwise_conv2d_10_output_array.data_start = AI_PTR(activations + 147456);
    conv2d_22_output_array.data = AI_PTR(activations + 0);
    conv2d_22_output_array.data_start = AI_PTR(activations + 0);
    add_6_output_array.data = AI_PTR(activations + 16384);
    add_6_output_array.data_start = AI_PTR(activations + 16384);
    conv2d_23_output_array.data = AI_PTR(activations + 32768);
    conv2d_23_output_array.data_start = AI_PTR(activations + 32768);
    depthwise_conv2d_11_output_array.data = AI_PTR(activations + 131072);
    depthwise_conv2d_11_output_array.data_start = AI_PTR(activations + 131072);
    conv2d_24_output_array.data = AI_PTR(activations + 0);
    conv2d_24_output_array.data_start = AI_PTR(activations + 0);
    add_7_output_array.data = AI_PTR(activations + 32768);
    add_7_output_array.data_start = AI_PTR(activations + 32768);
    conv2d_25_output_array.data = AI_PTR(activations + 49152);
    conv2d_25_output_array.data_start = AI_PTR(activations + 49152);
    depthwise_conv2d_12_output_array.data = AI_PTR(activations + 147456);
    depthwise_conv2d_12_output_array.data_start = AI_PTR(activations + 147456);
    conv2d_26_output_array.data = AI_PTR(activations + 0);
    conv2d_26_output_array.data_start = AI_PTR(activations + 0);
    add_8_output_array.data = AI_PTR(activations + 16384);
    add_8_output_array.data_start = AI_PTR(activations + 16384);
    conv2d_27_output_array.data = AI_PTR(activations + 32768);
    conv2d_27_output_array.data_start = AI_PTR(activations + 32768);
    depthwise_conv2d_13_output_array.data = AI_PTR(activations + 0);
    depthwise_conv2d_13_output_array.data_start = AI_PTR(activations + 0);
    conv2d_28_output_array.data = AI_PTR(activations + 24576);
    conv2d_28_output_array.data_start = AI_PTR(activations + 24576);
    conv2d_29_output_array.data = AI_PTR(activations + 30720);
    conv2d_29_output_array.data_start = AI_PTR(activations + 30720);
    depthwise_conv2d_14_output_array.data = AI_PTR(activations + 65536);
    depthwise_conv2d_14_output_array.data_start = AI_PTR(activations + 65536);
    conv2d_30_output_array.data = AI_PTR(activations + 0);
    conv2d_30_output_array.data_start = AI_PTR(activations + 0);
    add_9_output_array.data = AI_PTR(activations + 6144);
    add_9_output_array.data_start = AI_PTR(activations + 6144);
    conv2d_31_output_array.data = AI_PTR(activations + 12288);
    conv2d_31_output_array.data_start = AI_PTR(activations + 12288);
    depthwise_conv2d_15_output_array.data = AI_PTR(activations + 47104);
    depthwise_conv2d_15_output_array.data_start = AI_PTR(activations + 47104);
    conv2d_32_output_array.data = AI_PTR(activations + 0);
    conv2d_32_output_array.data_start = AI_PTR(activations + 0);
    add_10_output_array.data = AI_PTR(activations + 12288);
    add_10_output_array.data_start = AI_PTR(activations + 12288);
    conv2d_33_output_array.data = AI_PTR(activations + 18432);
    conv2d_33_output_array.data_start = AI_PTR(activations + 18432);
    depthwise_conv2d_16_output_array.data = AI_PTR(activations + 53248);
    depthwise_conv2d_16_output_array.data_start = AI_PTR(activations + 53248);
    conv2d_34_output_array.data = AI_PTR(activations + 0);
    conv2d_34_output_array.data_start = AI_PTR(activations + 0);
    add_11_output_array.data = AI_PTR(activations + 6144);
    add_11_output_array.data_start = AI_PTR(activations + 6144);
    conv2d_35_output_array.data = AI_PTR(activations + 12288);
    conv2d_35_output_array.data_start = AI_PTR(activations + 12288);
    depthwise_conv2d_17_output_array.data = AI_PTR(activations + 47104);
    depthwise_conv2d_17_output_array.data_start = AI_PTR(activations + 47104);
    conv2d_36_output_array.data = AI_PTR(activations + 0);
    conv2d_36_output_array.data_start = AI_PTR(activations + 0);
    add_12_output_array.data = AI_PTR(activations + 12288);
    add_12_output_array.data_start = AI_PTR(activations + 12288);
    conv2d_37_output_array.data = AI_PTR(activations + 18432);
    conv2d_37_output_array.data_start = AI_PTR(activations + 18432);
    depthwise_conv2d_18_output_array.data = AI_PTR(activations + 0);
    depthwise_conv2d_18_output_array.data_start = AI_PTR(activations + 0);
    conv2d_38_output_array.data = AI_PTR(activations + 8704);
    conv2d_38_output_array.data_start = AI_PTR(activations + 8704);
    conv2d_39_output_array.data = AI_PTR(activations + 11776);
    conv2d_39_output_array.data_start = AI_PTR(activations + 11776);
    depthwise_conv2d_19_output_array.data = AI_PTR(activations + 26112);
    depthwise_conv2d_19_output_array.data_start = AI_PTR(activations + 26112);
    conv2d_40_output_array.data = AI_PTR(activations + 0);
    conv2d_40_output_array.data_start = AI_PTR(activations + 0);
    add_13_output_array.data = AI_PTR(activations + 3072);
    add_13_output_array.data_start = AI_PTR(activations + 3072);
    conv2d_41_output_array.data = AI_PTR(activations + 6144);
    conv2d_41_output_array.data_start = AI_PTR(activations + 6144);
    depthwise_conv2d_20_output_array.data = AI_PTR(activations + 20480);
    depthwise_conv2d_20_output_array.data_start = AI_PTR(activations + 20480);
    conv2d_42_output_array.data = AI_PTR(activations + 0);
    conv2d_42_output_array.data_start = AI_PTR(activations + 0);
    add_14_output_array.data = AI_PTR(activations + 6144);
    add_14_output_array.data_start = AI_PTR(activations + 6144);
    conv2d_43_output_array.data = AI_PTR(activations + 9216);
    conv2d_43_output_array.data_start = AI_PTR(activations + 9216);
    depthwise_conv2d_21_output_array.data = AI_PTR(activations + 23552);
    depthwise_conv2d_21_output_array.data_start = AI_PTR(activations + 23552);
    conv2d_44_output_array.data = AI_PTR(activations + 0);
    conv2d_44_output_array.data_start = AI_PTR(activations + 0);
    add_15_output_array.data = AI_PTR(activations + 3072);
    add_15_output_array.data_start = AI_PTR(activations + 3072);
    conv2d_45_output_array.data = AI_PTR(activations + 6144);
    conv2d_45_output_array.data_start = AI_PTR(activations + 6144);
    depthwise_conv2d_22_output_array.data = AI_PTR(activations + 20480);
    depthwise_conv2d_22_output_array.data_start = AI_PTR(activations + 20480);
    conv2d_46_output_array.data = AI_PTR(activations + 0);
    conv2d_46_output_array.data_start = AI_PTR(activations + 0);
    add_16_output_array.data = AI_PTR(activations + 6144);
    add_16_output_array.data_start = AI_PTR(activations + 6144);
    conv2d_47_output_array.data = AI_PTR(activations + 9216);
    conv2d_47_output_array.data_start = AI_PTR(activations + 9216);
    depthwise_conv2d_23_output_array.data = AI_PTR(activations + 23552);
    depthwise_conv2d_23_output_array.data_start = AI_PTR(activations + 23552);
    conv2d_48_output_array.data = AI_PTR(activations + 0);
    conv2d_48_output_array.data_start = AI_PTR(activations + 0);
    add_17_output_array.data = AI_PTR(activations + 3072);
    add_17_output_array.data_start = AI_PTR(activations + 3072);
    conv2d_49_output_array.data = AI_PTR(activations + 6144);
    conv2d_49_output_array.data_start = AI_PTR(activations + 6144);
    depthwise_conv2d_24_output_array.data = AI_PTR(activations + 0);
    depthwise_conv2d_24_output_array.data_start = AI_PTR(activations + 0);
    conv2d_50_output_array.data = AI_PTR(activations + 6144);
    conv2d_50_output_array.data_start = AI_PTR(activations + 6144);
    depthwise_conv2d_25_output_array.data = AI_PTR(activations + 14336);
    depthwise_conv2d_25_output_array.data_start = AI_PTR(activations + 14336);
    conv2d_51_output_array.data = AI_PTR(activations + 0);
    conv2d_51_output_array.data_start = AI_PTR(activations + 0);
    conv2d_52_output_array.data = AI_PTR(NULL);
    conv2d_52_output_array.data_start = AI_PTR(NULL);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool network_1_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    conv2d_52_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_52_bias_array.data = AI_PTR(weights + 1060992);
    conv2d_52_bias_array.data_start = AI_PTR(weights + 1060992);
    conv2d_52_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_52_weights_array.data = AI_PTR(weights + 930432);
    conv2d_52_weights_array.data_start = AI_PTR(weights + 930432);
    conv2d_51_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_51_bias_array.data = AI_PTR(weights + 929920);
    conv2d_51_bias_array.data_start = AI_PTR(weights + 929920);
    conv2d_51_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_51_weights_array.data = AI_PTR(weights + 864384);
    conv2d_51_weights_array.data_start = AI_PTR(weights + 864384);
    depthwise_conv2d_25_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_25_bias_array.data = AI_PTR(weights + 863872);
    depthwise_conv2d_25_bias_array.data_start = AI_PTR(weights + 863872);
    depthwise_conv2d_25_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_25_weights_array.data = AI_PTR(weights + 851072);
    depthwise_conv2d_25_weights_array.data_start = AI_PTR(weights + 851072);
    conv2d_50_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_50_bias_array.data = AI_PTR(weights + 850560);
    conv2d_50_bias_array.data_start = AI_PTR(weights + 850560);
    conv2d_50_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_50_weights_array.data = AI_PTR(weights + 801408);
    conv2d_50_weights_array.data_start = AI_PTR(weights + 801408);
    depthwise_conv2d_24_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_24_bias_array.data = AI_PTR(weights + 801024);
    depthwise_conv2d_24_bias_array.data_start = AI_PTR(weights + 801024);
    depthwise_conv2d_24_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_24_weights_array.data = AI_PTR(weights + 791424);
    depthwise_conv2d_24_weights_array.data_start = AI_PTR(weights + 791424);
    conv2d_49_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_49_bias_array.data = AI_PTR(weights + 791040);
    conv2d_49_bias_array.data_start = AI_PTR(weights + 791040);
    conv2d_49_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_49_weights_array.data = AI_PTR(weights + 772608);
    conv2d_49_weights_array.data_start = AI_PTR(weights + 772608);
    conv2d_48_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_48_bias_array.data = AI_PTR(weights + 772416);
    conv2d_48_bias_array.data_start = AI_PTR(weights + 772416);
    conv2d_48_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_48_weights_array.data = AI_PTR(weights + 729408);
    conv2d_48_weights_array.data_start = AI_PTR(weights + 729408);
    depthwise_conv2d_23_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_23_bias_array.data = AI_PTR(weights + 728512);
    depthwise_conv2d_23_bias_array.data_start = AI_PTR(weights + 728512);
    depthwise_conv2d_23_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_23_weights_array.data = AI_PTR(weights + 720448);
    depthwise_conv2d_23_weights_array.data_start = AI_PTR(weights + 720448);
    conv2d_47_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_47_bias_array.data = AI_PTR(weights + 719552);
    conv2d_47_bias_array.data_start = AI_PTR(weights + 719552);
    conv2d_47_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_47_weights_array.data = AI_PTR(weights + 676544);
    conv2d_47_weights_array.data_start = AI_PTR(weights + 676544);
    conv2d_46_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_46_bias_array.data = AI_PTR(weights + 676352);
    conv2d_46_bias_array.data_start = AI_PTR(weights + 676352);
    conv2d_46_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_46_weights_array.data = AI_PTR(weights + 633344);
    conv2d_46_weights_array.data_start = AI_PTR(weights + 633344);
    depthwise_conv2d_22_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_22_bias_array.data = AI_PTR(weights + 632448);
    depthwise_conv2d_22_bias_array.data_start = AI_PTR(weights + 632448);
    depthwise_conv2d_22_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_22_weights_array.data = AI_PTR(weights + 624384);
    depthwise_conv2d_22_weights_array.data_start = AI_PTR(weights + 624384);
    conv2d_45_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_45_bias_array.data = AI_PTR(weights + 623488);
    conv2d_45_bias_array.data_start = AI_PTR(weights + 623488);
    conv2d_45_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_45_weights_array.data = AI_PTR(weights + 580480);
    conv2d_45_weights_array.data_start = AI_PTR(weights + 580480);
    conv2d_44_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_44_bias_array.data = AI_PTR(weights + 580288);
    conv2d_44_bias_array.data_start = AI_PTR(weights + 580288);
    conv2d_44_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_44_weights_array.data = AI_PTR(weights + 537280);
    conv2d_44_weights_array.data_start = AI_PTR(weights + 537280);
    depthwise_conv2d_21_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_21_bias_array.data = AI_PTR(weights + 536384);
    depthwise_conv2d_21_bias_array.data_start = AI_PTR(weights + 536384);
    depthwise_conv2d_21_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_21_weights_array.data = AI_PTR(weights + 528320);
    depthwise_conv2d_21_weights_array.data_start = AI_PTR(weights + 528320);
    conv2d_43_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_43_bias_array.data = AI_PTR(weights + 527424);
    conv2d_43_bias_array.data_start = AI_PTR(weights + 527424);
    conv2d_43_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_43_weights_array.data = AI_PTR(weights + 484416);
    conv2d_43_weights_array.data_start = AI_PTR(weights + 484416);
    conv2d_42_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_42_bias_array.data = AI_PTR(weights + 484224);
    conv2d_42_bias_array.data_start = AI_PTR(weights + 484224);
    conv2d_42_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_42_weights_array.data = AI_PTR(weights + 441216);
    conv2d_42_weights_array.data_start = AI_PTR(weights + 441216);
    depthwise_conv2d_20_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_20_bias_array.data = AI_PTR(weights + 440320);
    depthwise_conv2d_20_bias_array.data_start = AI_PTR(weights + 440320);
    depthwise_conv2d_20_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_20_weights_array.data = AI_PTR(weights + 432256);
    depthwise_conv2d_20_weights_array.data_start = AI_PTR(weights + 432256);
    conv2d_41_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_41_bias_array.data = AI_PTR(weights + 431360);
    conv2d_41_bias_array.data_start = AI_PTR(weights + 431360);
    conv2d_41_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_41_weights_array.data = AI_PTR(weights + 388352);
    conv2d_41_weights_array.data_start = AI_PTR(weights + 388352);
    conv2d_40_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_40_bias_array.data = AI_PTR(weights + 388160);
    conv2d_40_bias_array.data_start = AI_PTR(weights + 388160);
    conv2d_40_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_40_weights_array.data = AI_PTR(weights + 345152);
    conv2d_40_weights_array.data_start = AI_PTR(weights + 345152);
    depthwise_conv2d_19_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_19_bias_array.data = AI_PTR(weights + 344256);
    depthwise_conv2d_19_bias_array.data_start = AI_PTR(weights + 344256);
    depthwise_conv2d_19_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_19_weights_array.data = AI_PTR(weights + 336192);
    depthwise_conv2d_19_weights_array.data_start = AI_PTR(weights + 336192);
    conv2d_39_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_39_bias_array.data = AI_PTR(weights + 335296);
    conv2d_39_bias_array.data_start = AI_PTR(weights + 335296);
    conv2d_39_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_39_weights_array.data = AI_PTR(weights + 292288);
    conv2d_39_weights_array.data_start = AI_PTR(weights + 292288);
    conv2d_38_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_bias_array.data = AI_PTR(weights + 292096);
    conv2d_38_bias_array.data_start = AI_PTR(weights + 292096);
    conv2d_38_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_weights_array.data = AI_PTR(weights + 265984);
    conv2d_38_weights_array.data_start = AI_PTR(weights + 265984);
    depthwise_conv2d_18_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_18_bias_array.data = AI_PTR(weights + 265440);
    depthwise_conv2d_18_bias_array.data_start = AI_PTR(weights + 265440);
    depthwise_conv2d_18_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_18_weights_array.data = AI_PTR(weights + 260544);
    depthwise_conv2d_18_weights_array.data_start = AI_PTR(weights + 260544);
    conv2d_37_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_bias_array.data = AI_PTR(weights + 260000);
    conv2d_37_bias_array.data_start = AI_PTR(weights + 260000);
    conv2d_37_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_weights_array.data = AI_PTR(weights + 246944);
    conv2d_37_weights_array.data_start = AI_PTR(weights + 246944);
    conv2d_36_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_bias_array.data = AI_PTR(weights + 246848);
    conv2d_36_bias_array.data_start = AI_PTR(weights + 246848);
    conv2d_36_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_36_weights_array.data = AI_PTR(weights + 233792);
    conv2d_36_weights_array.data_start = AI_PTR(weights + 233792);
    depthwise_conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_17_bias_array.data = AI_PTR(weights + 233248);
    depthwise_conv2d_17_bias_array.data_start = AI_PTR(weights + 233248);
    depthwise_conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_17_weights_array.data = AI_PTR(weights + 228352);
    depthwise_conv2d_17_weights_array.data_start = AI_PTR(weights + 228352);
    conv2d_35_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_35_bias_array.data = AI_PTR(weights + 227808);
    conv2d_35_bias_array.data_start = AI_PTR(weights + 227808);
    conv2d_35_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_35_weights_array.data = AI_PTR(weights + 214752);
    conv2d_35_weights_array.data_start = AI_PTR(weights + 214752);
    conv2d_34_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_bias_array.data = AI_PTR(weights + 214656);
    conv2d_34_bias_array.data_start = AI_PTR(weights + 214656);
    conv2d_34_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_weights_array.data = AI_PTR(weights + 201600);
    conv2d_34_weights_array.data_start = AI_PTR(weights + 201600);
    depthwise_conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_16_bias_array.data = AI_PTR(weights + 201056);
    depthwise_conv2d_16_bias_array.data_start = AI_PTR(weights + 201056);
    depthwise_conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_16_weights_array.data = AI_PTR(weights + 196160);
    depthwise_conv2d_16_weights_array.data_start = AI_PTR(weights + 196160);
    conv2d_33_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_bias_array.data = AI_PTR(weights + 195616);
    conv2d_33_bias_array.data_start = AI_PTR(weights + 195616);
    conv2d_33_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_weights_array.data = AI_PTR(weights + 182560);
    conv2d_33_weights_array.data_start = AI_PTR(weights + 182560);
    conv2d_32_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_32_bias_array.data = AI_PTR(weights + 182464);
    conv2d_32_bias_array.data_start = AI_PTR(weights + 182464);
    conv2d_32_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_32_weights_array.data = AI_PTR(weights + 169408);
    conv2d_32_weights_array.data_start = AI_PTR(weights + 169408);
    depthwise_conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_15_bias_array.data = AI_PTR(weights + 168864);
    depthwise_conv2d_15_bias_array.data_start = AI_PTR(weights + 168864);
    depthwise_conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_15_weights_array.data = AI_PTR(weights + 163968);
    depthwise_conv2d_15_weights_array.data_start = AI_PTR(weights + 163968);
    conv2d_31_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_31_bias_array.data = AI_PTR(weights + 163424);
    conv2d_31_bias_array.data_start = AI_PTR(weights + 163424);
    conv2d_31_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_31_weights_array.data = AI_PTR(weights + 150368);
    conv2d_31_weights_array.data_start = AI_PTR(weights + 150368);
    conv2d_30_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_bias_array.data = AI_PTR(weights + 150272);
    conv2d_30_bias_array.data_start = AI_PTR(weights + 150272);
    conv2d_30_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_weights_array.data = AI_PTR(weights + 137216);
    conv2d_30_weights_array.data_start = AI_PTR(weights + 137216);
    depthwise_conv2d_14_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_14_bias_array.data = AI_PTR(weights + 136672);
    depthwise_conv2d_14_bias_array.data_start = AI_PTR(weights + 136672);
    depthwise_conv2d_14_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_14_weights_array.data = AI_PTR(weights + 131776);
    depthwise_conv2d_14_weights_array.data_start = AI_PTR(weights + 131776);
    conv2d_29_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_bias_array.data = AI_PTR(weights + 131232);
    conv2d_29_bias_array.data_start = AI_PTR(weights + 131232);
    conv2d_29_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_weights_array.data = AI_PTR(weights + 118176);
    conv2d_29_weights_array.data_start = AI_PTR(weights + 118176);
    conv2d_28_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_bias_array.data = AI_PTR(weights + 118080);
    conv2d_28_bias_array.data_start = AI_PTR(weights + 118080);
    conv2d_28_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_weights_array.data = AI_PTR(weights + 108864);
    conv2d_28_weights_array.data_start = AI_PTR(weights + 108864);
    depthwise_conv2d_13_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_13_bias_array.data = AI_PTR(weights + 108480);
    depthwise_conv2d_13_bias_array.data_start = AI_PTR(weights + 108480);
    depthwise_conv2d_13_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_13_weights_array.data = AI_PTR(weights + 105024);
    depthwise_conv2d_13_weights_array.data_start = AI_PTR(weights + 105024);
    conv2d_27_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_bias_array.data = AI_PTR(weights + 104640);
    conv2d_27_bias_array.data_start = AI_PTR(weights + 104640);
    conv2d_27_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_weights_array.data = AI_PTR(weights + 98496);
    conv2d_27_weights_array.data_start = AI_PTR(weights + 98496);
    conv2d_26_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_bias_array.data = AI_PTR(weights + 98432);
    conv2d_26_bias_array.data_start = AI_PTR(weights + 98432);
    conv2d_26_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_weights_array.data = AI_PTR(weights + 92288);
    conv2d_26_weights_array.data_start = AI_PTR(weights + 92288);
    depthwise_conv2d_12_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_12_bias_array.data = AI_PTR(weights + 91904);
    depthwise_conv2d_12_bias_array.data_start = AI_PTR(weights + 91904);
    depthwise_conv2d_12_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_12_weights_array.data = AI_PTR(weights + 88448);
    depthwise_conv2d_12_weights_array.data_start = AI_PTR(weights + 88448);
    conv2d_25_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_bias_array.data = AI_PTR(weights + 88064);
    conv2d_25_bias_array.data_start = AI_PTR(weights + 88064);
    conv2d_25_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_weights_array.data = AI_PTR(weights + 81920);
    conv2d_25_weights_array.data_start = AI_PTR(weights + 81920);
    conv2d_24_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_bias_array.data = AI_PTR(weights + 81856);
    conv2d_24_bias_array.data_start = AI_PTR(weights + 81856);
    conv2d_24_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_weights_array.data = AI_PTR(weights + 75712);
    conv2d_24_weights_array.data_start = AI_PTR(weights + 75712);
    depthwise_conv2d_11_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_11_bias_array.data = AI_PTR(weights + 75328);
    depthwise_conv2d_11_bias_array.data_start = AI_PTR(weights + 75328);
    depthwise_conv2d_11_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_11_weights_array.data = AI_PTR(weights + 71872);
    depthwise_conv2d_11_weights_array.data_start = AI_PTR(weights + 71872);
    conv2d_23_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_bias_array.data = AI_PTR(weights + 71488);
    conv2d_23_bias_array.data_start = AI_PTR(weights + 71488);
    conv2d_23_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_weights_array.data = AI_PTR(weights + 65344);
    conv2d_23_weights_array.data_start = AI_PTR(weights + 65344);
    conv2d_22_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_bias_array.data = AI_PTR(weights + 65280);
    conv2d_22_bias_array.data_start = AI_PTR(weights + 65280);
    conv2d_22_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_weights_array.data = AI_PTR(weights + 59136);
    conv2d_22_weights_array.data_start = AI_PTR(weights + 59136);
    depthwise_conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_10_bias_array.data = AI_PTR(weights + 58752);
    depthwise_conv2d_10_bias_array.data_start = AI_PTR(weights + 58752);
    depthwise_conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_10_weights_array.data = AI_PTR(weights + 55296);
    depthwise_conv2d_10_weights_array.data_start = AI_PTR(weights + 55296);
    conv2d_21_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_bias_array.data = AI_PTR(weights + 54912);
    conv2d_21_bias_array.data_start = AI_PTR(weights + 54912);
    conv2d_21_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_weights_array.data = AI_PTR(weights + 48768);
    conv2d_21_weights_array.data_start = AI_PTR(weights + 48768);
    conv2d_20_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_bias_array.data = AI_PTR(weights + 48704);
    conv2d_20_bias_array.data_start = AI_PTR(weights + 48704);
    conv2d_20_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_weights_array.data = AI_PTR(weights + 42560);
    conv2d_20_weights_array.data_start = AI_PTR(weights + 42560);
    depthwise_conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_9_bias_array.data = AI_PTR(weights + 42176);
    depthwise_conv2d_9_bias_array.data_start = AI_PTR(weights + 42176);
    depthwise_conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_9_weights_array.data = AI_PTR(weights + 38720);
    depthwise_conv2d_9_weights_array.data_start = AI_PTR(weights + 38720);
    conv2d_19_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_bias_array.data = AI_PTR(weights + 38336);
    conv2d_19_bias_array.data_start = AI_PTR(weights + 38336);
    conv2d_19_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_weights_array.data = AI_PTR(weights + 32192);
    conv2d_19_weights_array.data_start = AI_PTR(weights + 32192);
    conv2d_18_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_bias_array.data = AI_PTR(weights + 32128);
    conv2d_18_bias_array.data_start = AI_PTR(weights + 32128);
    conv2d_18_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_weights_array.data = AI_PTR(weights + 29056);
    conv2d_18_weights_array.data_start = AI_PTR(weights + 29056);
    depthwise_conv2d_8_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_8_bias_array.data = AI_PTR(weights + 28864);
    depthwise_conv2d_8_bias_array.data_start = AI_PTR(weights + 28864);
    depthwise_conv2d_8_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_8_weights_array.data = AI_PTR(weights + 27136);
    depthwise_conv2d_8_weights_array.data_start = AI_PTR(weights + 27136);
    conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_bias_array.data = AI_PTR(weights + 26944);
    conv2d_17_bias_array.data_start = AI_PTR(weights + 26944);
    conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_weights_array.data = AI_PTR(weights + 25408);
    conv2d_17_weights_array.data_start = AI_PTR(weights + 25408);
    conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_bias_array.data = AI_PTR(weights + 25376);
    conv2d_16_bias_array.data_start = AI_PTR(weights + 25376);
    conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_weights_array.data = AI_PTR(weights + 23840);
    conv2d_16_weights_array.data_start = AI_PTR(weights + 23840);
    depthwise_conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_7_bias_array.data = AI_PTR(weights + 23648);
    depthwise_conv2d_7_bias_array.data_start = AI_PTR(weights + 23648);
    depthwise_conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_7_weights_array.data = AI_PTR(weights + 21920);
    depthwise_conv2d_7_weights_array.data_start = AI_PTR(weights + 21920);
    conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_bias_array.data = AI_PTR(weights + 21728);
    conv2d_15_bias_array.data_start = AI_PTR(weights + 21728);
    conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_weights_array.data = AI_PTR(weights + 20192);
    conv2d_15_weights_array.data_start = AI_PTR(weights + 20192);
    conv2d_14_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_bias_array.data = AI_PTR(weights + 20160);
    conv2d_14_bias_array.data_start = AI_PTR(weights + 20160);
    conv2d_14_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_weights_array.data = AI_PTR(weights + 18624);
    conv2d_14_weights_array.data_start = AI_PTR(weights + 18624);
    depthwise_conv2d_6_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_6_bias_array.data = AI_PTR(weights + 18432);
    depthwise_conv2d_6_bias_array.data_start = AI_PTR(weights + 18432);
    depthwise_conv2d_6_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_6_weights_array.data = AI_PTR(weights + 16704);
    depthwise_conv2d_6_weights_array.data_start = AI_PTR(weights + 16704);
    conv2d_13_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_bias_array.data = AI_PTR(weights + 16512);
    conv2d_13_bias_array.data_start = AI_PTR(weights + 16512);
    conv2d_13_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_weights_array.data = AI_PTR(weights + 14976);
    conv2d_13_weights_array.data_start = AI_PTR(weights + 14976);
    conv2d_12_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_bias_array.data = AI_PTR(weights + 14944);
    conv2d_12_bias_array.data_start = AI_PTR(weights + 14944);
    conv2d_12_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_weights_array.data = AI_PTR(weights + 13920);
    conv2d_12_weights_array.data_start = AI_PTR(weights + 13920);
    depthwise_conv2d_5_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_5_bias_array.data = AI_PTR(weights + 13792);
    depthwise_conv2d_5_bias_array.data_start = AI_PTR(weights + 13792);
    depthwise_conv2d_5_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_5_weights_array.data = AI_PTR(weights + 12640);
    depthwise_conv2d_5_weights_array.data_start = AI_PTR(weights + 12640);
    conv2d_11_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_bias_array.data = AI_PTR(weights + 12512);
    conv2d_11_bias_array.data_start = AI_PTR(weights + 12512);
    conv2d_11_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_weights_array.data = AI_PTR(weights + 11488);
    conv2d_11_weights_array.data_start = AI_PTR(weights + 11488);
    conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_bias_array.data = AI_PTR(weights + 11456);
    conv2d_10_bias_array.data_start = AI_PTR(weights + 11456);
    conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_weights_array.data = AI_PTR(weights + 10432);
    conv2d_10_weights_array.data_start = AI_PTR(weights + 10432);
    depthwise_conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_4_bias_array.data = AI_PTR(weights + 10304);
    depthwise_conv2d_4_bias_array.data_start = AI_PTR(weights + 10304);
    depthwise_conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_4_weights_array.data = AI_PTR(weights + 9152);
    depthwise_conv2d_4_weights_array.data_start = AI_PTR(weights + 9152);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(weights + 9024);
    conv2d_9_bias_array.data_start = AI_PTR(weights + 9024);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(weights + 8000);
    conv2d_9_weights_array.data_start = AI_PTR(weights + 8000);
    conv2d_8_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_bias_array.data = AI_PTR(weights + 7968);
    conv2d_8_bias_array.data_start = AI_PTR(weights + 7968);
    conv2d_8_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_weights_array.data = AI_PTR(weights + 6944);
    conv2d_8_weights_array.data_start = AI_PTR(weights + 6944);
    depthwise_conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_3_bias_array.data = AI_PTR(weights + 6816);
    depthwise_conv2d_3_bias_array.data_start = AI_PTR(weights + 6816);
    depthwise_conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_3_weights_array.data = AI_PTR(weights + 5664);
    depthwise_conv2d_3_weights_array.data_start = AI_PTR(weights + 5664);
    conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_bias_array.data = AI_PTR(weights + 5536);
    conv2d_7_bias_array.data_start = AI_PTR(weights + 5536);
    conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_weights_array.data = AI_PTR(weights + 4512);
    conv2d_7_weights_array.data_start = AI_PTR(weights + 4512);
    conv2d_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_bias_array.data = AI_PTR(weights + 4480);
    conv2d_6_bias_array.data_start = AI_PTR(weights + 4480);
    conv2d_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_weights_array.data = AI_PTR(weights + 3712);
    conv2d_6_weights_array.data_start = AI_PTR(weights + 3712);
    depthwise_conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_2_bias_array.data = AI_PTR(weights + 3616);
    depthwise_conv2d_2_bias_array.data_start = AI_PTR(weights + 3616);
    depthwise_conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_2_weights_array.data = AI_PTR(weights + 2752);
    depthwise_conv2d_2_weights_array.data_start = AI_PTR(weights + 2752);
    conv2d_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_bias_array.data = AI_PTR(weights + 2656);
    conv2d_5_bias_array.data_start = AI_PTR(weights + 2656);
    conv2d_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_weights_array.data = AI_PTR(weights + 2272);
    conv2d_5_weights_array.data_start = AI_PTR(weights + 2272);
    conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_bias_array.data = AI_PTR(weights + 2256);
    conv2d_4_bias_array.data_start = AI_PTR(weights + 2256);
    conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_weights_array.data = AI_PTR(weights + 2128);
    conv2d_4_weights_array.data_start = AI_PTR(weights + 2128);
    depthwise_conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_1_bias_array.data = AI_PTR(weights + 2096);
    depthwise_conv2d_1_bias_array.data_start = AI_PTR(weights + 2096);
    depthwise_conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_1_weights_array.data = AI_PTR(weights + 1808);
    depthwise_conv2d_1_weights_array.data_start = AI_PTR(weights + 1808);
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(weights + 1776);
    conv2d_3_bias_array.data_start = AI_PTR(weights + 1776);
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(weights + 1648);
    conv2d_3_weights_array.data_start = AI_PTR(weights + 1648);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(weights + 1632);
    conv2d_2_bias_array.data_start = AI_PTR(weights + 1632);
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(weights + 1504);
    conv2d_2_weights_array.data_start = AI_PTR(weights + 1504);
    depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_bias_array.data = AI_PTR(weights + 1472);
    depthwise_conv2d_bias_array.data_start = AI_PTR(weights + 1472);
    depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    depthwise_conv2d_weights_array.data = AI_PTR(weights + 1184);
    depthwise_conv2d_weights_array.data_start = AI_PTR(weights + 1184);
    conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_bias_array.data = AI_PTR(weights + 1152);
    conv2d_1_bias_array.data_start = AI_PTR(weights + 1152);
    conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_weights_array.data = AI_PTR(weights + 896);
    conv2d_1_weights_array.data_start = AI_PTR(weights + 896);
    conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_bias_array.data = AI_PTR(weights + 864);
    conv2d_bias_array.data_start = AI_PTR(weights + 864);
    conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_weights_array.data = AI_PTR(weights + 0);
    conv2d_weights_array.data_start = AI_PTR(weights + 0);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_network_1_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_1_MODEL_NAME,
      .model_signature   = AI_NETWORK_1_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = {AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR,
                            AI_TOOLS_API_VERSION_MICRO, 0x0},

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 18684007,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if ( !ai_platform_api_get_network_report(network, &r) ) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_network_1_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_1_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_network_1_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_1_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= network_1_configure_weights(net_ctx, &params->params);
  ok &= network_1_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_1_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_1_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}




#undef AI_NETWORK_1_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

