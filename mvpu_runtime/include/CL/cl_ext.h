// SPDX-License-Identifier: MediaTekProprietary
/*******************************************************************************
 * Copyright (c) 2008-2015 The Khronos Group Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and/or associated documentation files (the
 * "Materials"), to deal in the Materials without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Materials, and to
 * permit persons to whom the Materials are furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Materials.
 *
 * MODIFICATIONS TO THIS FILE MAY MEAN IT NO LONGER ACCURATELY REFLECTS
 * KHRONOS STANDARDS. THE UNMODIFIED, NORMATIVE VERSIONS OF KHRONOS
 * SPECIFICATIONS AND HEADER INFORMATION ARE LOCATED AT
 *    https://www.khronos.org/registry/
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
 ******************************************************************************/

/* cl_ext.h contains OpenCL extensions which don't have external */
/* (OpenGL, D3D) dependencies.                                   */

#ifndef __CL_EXT_H
#define __CL_EXT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <CL/cl.h>

/************************
* cl_mtk_batch extension *
************************/
#ifndef cl_mtk_batch
#define cl_mtk_batch 1

typedef struct _cl_batch_mtk*             cl_batch_mtk;             // batch = a group of events with dependencies
typedef struct _cl_batch_event_mtk*       cl_batch_event_mtk;       // for event_wait_list within batch

typedef struct _cl_batch_group_mtk*       cl_batch_group_mtk;       // batch group = a group of batches with dependencies
typedef struct _cl_batch_group_event_mtk* cl_batch_group_event_mtk; // for event_wait_list within batch_group

typedef cl_uint                         cl_batch_info_mtk;
typedef cl_bitfield                     cl_batch_flags_mtk;
typedef cl_uint                         cl_batch_property_type;
typedef cl_uint                         cl_batch_group_info_mtk;
typedef cl_bitfield                     cl_batch_group_flags_mtk;
typedef cl_uint                         cl_batch_group_property_type;
typedef cl_uint                         cl_copy_cmd_desc_type_mtk;
typedef cl_uint                         cl_event_property_type;
typedef cl_uint                         cl_ring_buf_type_mtk;
typedef cl_uint                         cl_ring_buf_info_mtk;

/* error codes */
// SW-related -500 ~ -519
#define CL_INVALID_BATCH_OBJECT_MTK                     -500
#define CL_INVALID_SCHEDULER_MTK                        -501
#define CL_INVALID_MEM_AUTO_ALLOC_FAIL_MTK              -502
#define CL_INVALID_BATCH_GROUP_OBJECT_MTK               -504
#define CL_WARNING_LARGE_KERNEL_SIZE_MTK                -505
#define CL_INVALID_SYNC_PROPERTY_MTK                    -506
#define CL_INVALID_HSE_SETTING_MTK                      -507
#define CL_INVALID_CL_BINARY_VERSION                    -508
#define CL_OUT_OF_CPOOL_RING_BUFFER_RESOURCES_MTK       -509
#define CL_OUT_OF_ARGTBL_RING_BUFFER_RESOURCES_MTK      -510
#define CL_OUT_OF_PRIVATE_RING_BUFFER_RESOURCES_MTK     -511
#define CL_PREPARE_DEV_MEM_FAIL_MTK                     -516

// HW-related -520 ~ -539
#define CL_INVALID_DMA_TYPE_MTK                         -520
#define CL_INVALID_BUFFER_OUT_OF_RANGE_MTK              -521
#define CL_INVALID_BUFFERS_OVERLAP_MTK                  -522
#define CL_MVPU_ENGINE_ERROR_MTK                        -530
#define CL_EDMA_ENGINE_ERROR_MTK                        -531
#define CL_APUSYS_ERROR_MTK                             -532
// Pattern-related -540 ~ -559
#define CL_INVALID_BATCH_BINARY_MTK                     -540
#define CL_INVALID_BATCH_ARG_MTK                        -541
#define CL_INVALID_BATCH_ARG_ID_MTK                     -542
#define CL_INVALID_BATCH_ARG_SIZE_MTK                   -543
#define CL_INVALID_BATCH_ARG_VALUE_MTK                  -544
// quality-related -560 ~ -600
#define CL_INVALID_MODE_MTK                             -560
#define CL_INVALID_SHAPE_PITCH_LESS_THAN_REGION_MTK     -561
#define CL_INVALID_SHAPE_COLOR_PACKAGE_MTK              -562
#define CL_INVALID_SHAPE_COLOR_Y_UV_REGION_MTK          -563
#define CL_INVALID_SHAPE_COLOR_Y_U_V_WIDTH_MTK          -564
#define CL_INVALID_SHAPE_COLOR_Y_U_V_HEIGHT_MTK         -565
#define CL_INVALID_PIXEL_SIZE_NOT_SUPPORTED_MTK         -566
#define CL_INVALID_COLOR_FMT_MTK                        -570
#define CL_INVALID_COLOR_CVT_NOT_SUPPORTED_MTK          -571

// mutex-related -720 ~
#define CL_MUTEX_LOCK_FAIL                              -720
#define CL_MUTEX_UNLOCK_FAIL                            -721

// Runtime-internal: re-direct to CL_INVALID_VALUE
#define MTK_INVALID_BUF_OPERATION_NOT_SUPPORTED         -750


/* cl_device_info  */
#define CL_DEVICE_MAX_GLOBAL_WORK_IDS_MTK           0x2080
#define CL_PATTERN_VERSION_MTK                      0x2081  // get pattern version


/* cl_command_queue_properties */
#define CL_QUEUE_ASYNC_AVALIABLE_MTK                (1 << 8)
#define CL_QUEUE_DEVICE_POWER_SAVE_MTK              (1 << 9)

/* cl_batch_info_mtk  */
#define CL_BATCH_NAME_MTK                           0x2100
#define CL_BATCH_CONTEXT_MTK                        0x2101
#define CL_BATCH_REFERENCE_COUNT_MTK                0x2102
#define CL_BATCH_DEVICE_MTK                         0x2103
#define CL_BATCH_NUM_CMDS_MTK                       0x2104
#define CL_BATCH_VALIDATION_STATUS_MTK              0x2105
#define CL_BATCH_FLAGS_MTK                          0x2108
#define CL_BATCH_PEAK_USER_L1_SIZE_MTK              0x2109  // These 4 PEAK macros show the breakdown of peak memory usage.
#define CL_BATCH_PEAK_KERNEL_L1_SIZE_MTK            0x210a  // Definition of peak memory usage: max(USER_L1_SIZE + KERNEL_L1_SIZE + SYSTEM_L1_SIZE)
#define CL_BATCH_PEAK_SYSTEM_L1_SIZE_MTK            0x210b  //
#define CL_BATCH_PEAK_FREE_L1_SIZE_MTK              0x210c  // Sum of all is L1 size. (FAST_GLOBAL_SIZE = USER_L1_SIZE + KERNEL_L1_SIZE + SYSTEM_L1_SIZE + FREE_L1_SIZE)
#define CL_BATCH_BINARY_MTK                         0x210d  // get batch binary
#define CL_BATCH_NUM_ARGS_MTK                       0x210e  // get num of batch arguments
#define CL_BATCH_ARG_NAMES_MTK                      0x210f  // get name list(semi-colon separated list) of batch arguments
#define CL_BATCH_ARG_TYPES_MTK                      0x2110  // get type list of batch arguments
#define CL_BATCH_ARG_IDS_MTK                        0x2111  // get id list of batch arguments
#define CL_BATCH_ARG_SIZES_MTK                      0x2112  // get size list of batch arguments
#define CL_BATCH_COMMANDS_MAPPING_TABLE_MTK         0x2113  // get user set kernel/copy name -> kid, jid mapping table
#define CL_BATCH_CPOOL_RINGBUF_SIZE_MTK             0x2114  // get batch const pool size
#define CL_BATCH_ARGTBL_RINGBUF_SIZE_MTK            0x2115  // get batch argument table size
#define CL_BATCH_PRIVATE_RINGBUF_SIZE_MTK           0x2116  // get batch private memory size

/* cl_batch_group_info_mtk */
// TBA

/* cl_command_type */
#define CL_COMMAND_BATCH_GROUP_MTK                          0x2140
#define CL_COMMAND_BATCH_MTK                                0x2141
#define CL_COMMAND_PATTERN_MTK                              0x2142
#define CL_COMMAND_COPY_BUFFER_4D_MTK                       0x214e
#define CL_COMMAND_FILL_BUFFER_4D_MTK                       0x214f
#define CL_COMMAND_COPY_BUFFER_COLORCVT_MTK                 0x2150
#define CL_COMMAND_COPY_BUFFER_ROTATE_MTK                   0x2151
#define CL_COMMAND_COPY_BUFFER_SPLIT_MTK                    0x2152
#define CL_COMMAND_COPY_BUFFER_MERGE_MTK                    0x2153
#define CL_COMMAND_COPY_BUFFER_FMTCVT_MTK                   0x2154
#define CL_COMMAND_COPY_BUFFER_SWAP_MTK                     0x2155
#define CL_COMMAND_COPY_BUFFER_FLIP_MTK                     0x2156
#define CL_COMMAND_COPY_BUFFER_COLORCVT_ADV_MTK             0x2157
#define CL_COMMAND_COPY_BUFFER_PAD_MTK                      0x2158
#define CL_COMMAND_COPY_BUFFER_TRANSPOSE_MTK                0x2159
#define CL_COMMAND_COPY_BUFFER_USERDEF_MTK                  0x215a

/* cl_batch_flags_mtk */
#define CL_BATCH_OUT_OF_ORDER_EXEC_MTK                     (1 << 0)
#define CL_BATCH_SYNC_EXEC_MTK                             (1 << 2)
#define CL_BATCH_CACHEABLE_MTK                             (1 << 3)
#define CL_BATCH_SECURITY_LV0_MTK                          (1 << 4)
#define CL_BATCH_SECURITY_LV1_MTK                          (1 << 5)
#define CL_BATCH_SECURITY_LV2_MTK                          (1 << 6)

/* cl_batch_group_flags_mtk */
#define CL_BATCH_GROUP_SYNC_EXEC_MTK                        (1 << 2)

/* cl_copy_cmd_desc_type_mtk */
#define CL_COPY_CMD_DESC_COPY_BUF_MTK                       0x2170
#define CL_COPY_CMD_DESC_COPY_BUF_RECT_MTK                  0x2171
#define CL_COPY_CMD_DESC_COPY_BUF_4D_MTK                    0x2172
#define CL_COPY_CMD_DESC_FILL_MTK                           0x2173
#define CL_COPY_CMD_DESC_FILL_4D_MTK                        0x2174
#define CL_COPY_CMD_DESC_COLORCVT_MTK                       0x217c
#define CL_COPY_CMD_DESC_ROTATE_MTK                         0x2180
#define CL_COPY_CMD_DESC_SPLIT_MTK                          0x2181
#define CL_COPY_CMD_DESC_MERGE_MTK                          0x2182
#define CL_COPY_CMD_DESC_FMTCVT_MTK                         0x2183
#define CL_COPY_CMD_DESC_SWAP_MTK                           0x2184
#define CL_COPY_CMD_DESC_FLIP_MTK                           0x2185
#define CL_COPY_CMD_DESC_COLORCVT_ADV_MTK                   0x2186
#define CL_COPY_CMD_DESC_PAD_MTK                            0x2187
#define CL_COPY_CMD_DESC_TRANSPOSE_MTK                      0x2188
#define CL_COPY_CMD_DESC_USERDEF_MTK                        0x2189

/* cl_event_property_type */
#define CL_EVENT_WAIT_PROPERTY_MTK                          0x2200
#define CL_EVENT_WAKE_PROPERTY_MTK                          0x2201
#define CL_EVENT_CLEAR_PROPERTY_MTK                         0x2210

/* cl_batch_property_type */
#define CL_BATCH_BOOST_VALUE_MTK                            0x2220 // performance value(0~100, default=100), will be interpolated and mapping to current platform frequency.
#define CL_BATCH_EXPECTED_MS_MTK                            0x2221 // execution time user expected, usually get from previous cmd.
#define CL_BATCH_SUGGEST_MS_MTK                             0x2222 // not used.
#define CL_BATCH_VLM_FORCE_MTK                              0x2223 // force subcmd allocate real local memory before execution, bubble maybe appear caused by wait local memory release from other subcmd.
#define CL_BATCH_BINARY_DISABLE_SET_ARG_MTK                 0x2225 // bitfield mask(default=0)
                                                                   // bit 0 disable ndr update
                                                                   // bit 1 disable dma update
#define CL_BATCH_PRIORITY_MTK                               0x2240
#define CL_BATCH_DELAY_POWER_OFF                            0x2244


/* cl_batch_group_property_type */
#define CL_BATCH_GROUP_PRIORITY_MTK                         0x2240 // Cmd priority(0~31, default=20), Lower number means higher priority, only valid without softlimit setting.
#define CL_BATCH_GROUP_HARDLIMIT_MTK                        0x2241 // Hard limit, cmd will be timeout if this cmd not completed with time expired.
#define CL_BATCH_GROUP_SOFTLIMIT_MTK                        0x2242 // Soft limit, cmd execution time user expected and scheduler will refers to.
#define CL_BATCH_GROUP_POWERSAVE_MTK                        0x2243 // Allow scheduler shut off power between cmd execution without any delay timer.
#define CL_BATCH_GROUP_DELAY_POWER_OFF                      0x2244

#define CL_PROGRAM_THIN_BINARY_SIZES_MTK                    0x2260
#define CL_PROGRAM_THIN_BINARIES_MTK                        0x2261

/* cl_ring_buf_type_mtk */
#define CL_RING_BUFFER_TYPE_CPOOL_MTK                       0x2280
#define CL_RING_BUFFER_TYPE_ARGTBL_MTK                      0x2281
#define CL_RING_BUFFER_TYPE_PRIVATE_MTK                     0x2282

/* cl_ring_buf_info_mtk */
#define CL_CPOOL_SIZE_MTK                                   0x2284
#define CL_ARGTBL_SIZE_MTK                                  0x2285
#define CL_PRIVATE_SIZE_MTK                                 0x2286
#define CL_CPOOL_USED_SIZE_MTK                              0x2287
#define CL_ARGTBL_USED_SIZE_MTK                             0x2288
#define CL_PRIVATE_USED_SIZE_MTK                            0x2289

typedef enum {
    CL_DMA_UNKNOWN = 0,
    CL_DMA_EDMA,
    CL_DMA_GLSU,
} DMAType;

#define RT_HSE_INVALID_ID   0xFFFF
// 4:4:4 (32 bpp):AYUV, I444
    // 131: yuv444_8_to_yuv420_8
// 4:2:2 (16 bpp):YUY2,UYVY, YVYU
    // 9:   yuv422_8_to_rgba_8
// 4:2:0 (16 bpp):IMC1,IMC3
// 4:2:0 (12 bpp):IMC2,IMC4,YV12,NV12
    // 8:   yuv420_8_to_rgba_8
    // 10:  rgb_8_to_yuv420_8
    // 11:  rgba_8_to_yuv420_8
    // 129: yuv420_8_to_rgb_8
    // 130: yuv420_8_to_yuv444_8
// others
    // 128: rgb_8_to_gray_8
#define CL_PIXELFMT_INTERLEAVE          CL_PIXELFMT_ITLV_RGB
#define CL_PIXELFMT_INTERLEAVE_3CH_END  CL_PIXELFMT_ITLV_BGR
#define CL_PIXELFMT_INTERLEAVE_4CH_END  CL_PIXELFMT_ITLV_YUV444_AYUV
#define CL_PIXELFMT_INTERLEAVE_END      CL_PIXELFMT_ITLV_YUV444_AYUV
#define CL_PIXELFMT_SEMIPLANAR          CL_PIXELFMT_SEMI_YUV420_NV12
#define CL_PIXELFMT_SEMIPLANAR_END      CL_PIXELFMT_SEMI_YUV420_NV21
#define CL_PIXELFMT_PLANAR              CL_PIXELFMT_PLAN_YUV420
#define CL_PIXELFMT_PLANAR_3PLANAR_END  CL_PIXELFMT_PLAN_RGB
#define CL_PIXELFMT_PLANAR_END          CL_PIXELFMT_PLAN_RGB

#define NUM_CL_PIXEL_TYPE               (CL_PIXELFMT_PLANAR_END + 1)

typedef enum {
    CL_USER0_MODE0 = 0,
    CL_USER0_MODE1,
    CL_USER0_MODE2,
    CL_USER0_MODE3,

    CL_USER1_MODE0 = 32,
    CL_USER1_MODE1,
    CL_USER1_MODE2,
    CL_USER1_MODE3,

    CL_USER2_MODE0 = 64,
    CL_USER2_MODE1,
    CL_USER2_MODE2,
    CL_USER2_MODE3,

    CL_USER3_MODE0 = 96,
    CL_USER3_MODE1,
    CL_USER3_MODE2,
    CL_USER3_MODE3,
} UserDefMode;

typedef enum {
    // Interleave
    CL_PIXELFMT_ITLV_RGB = 0,
    CL_PIXELFMT_ITLV_BGR,
    CL_PIXELFMT_ITLV_RGBA,
    CL_PIXELFMT_ITLV_ARGB,
    CL_PIXELFMT_ITLV_BGRA,
    CL_PIXELFMT_ITLV_ABGR,
    CL_PIXELFMT_ITLV_YUV422_YUYV,
    CL_PIXELFMT_ITLV_YUV422_UYVY,
    CL_PIXELFMT_ITLV_YUV422_YVYU,
    CL_PIXELFMT_ITLV_YUV444_AYUV,
    // Semi-Planar
    CL_PIXELFMT_SEMI_YUV420_NV12,       // 12bits per pixel; 2 Planars: Y, UV.
    CL_PIXELFMT_SEMI_YUV420_NV21,       // 12bits per pixel; 2 Planars: Y, VU.
    CL_PIXELFMT_SEMI_YUV444_UV_ONLY_MTK,
    CL_PIXELFMT_SEMI_YUV444_MTK,
    // Planar
    CL_PIXELFMT_PLAN_YUV420,            // 12bits per pixel; 3 Planars: Y, U, V. same as I420
    CL_PIXELFMT_PLAN_YUV422,
    CL_PIXELFMT_PLAN_YUV444,
    CL_PIXELFMT_PLAN_RGB,
    // Isomerism
    CL_PIXELFMT_PLAN_YUV420_IMC1 = 64,  // 16bits per pixel; 3 Planars: Y, V, U.
    CL_PIXELFMT_PLAN_YUV420_IMC3,       // 16bits per pixel; 3 Planars: Y, U, V.
    CL_PIXELFMT_PLAN_YUV420_IMC2,       // 12bits per pixel; 3 Planars: Y, V, U.
    CL_PIXELFMT_PLAN_YUV420_IMC4,       // 12bits per pixel; 3 Planars: Y, U, V.
    CL_PIXELFMT_PLAN_YUV420_YV12,       // 12bits per pixel; 3 Planars: Y, V, U.
} CL_PixelFmt;

#define CL_COLORFMT_RGB CL_COLORFMT_RGB888
#define CL_COLORFMT_EXCLUDE_FMTS    (CL_COLORFMT_RGB565 + 1)
#define CL_COLORFMT_TRANS_SIZE (CL_COLORFMT_END - CL_COLORFMT_EXCLUDE_FMTS)
typedef enum {
    CL_COLORFMT_GRAY = 0,
    CL_COLORFMT_RGB565,
    CL_COLORFMT_RGB888,
    CL_COLORFMT_RGBA,
    CL_COLORFMT_YUV420,
    CL_COLORFMT_YUV422,
    CL_COLORFMT_YUV444,
    CL_COLORFMT_YUV444_16,
    CL_COLORFMT_RGB_16,
    CL_COLORFMT_END
} CL_ColorFmt;

typedef enum {
    ROTATE_90_CLOCKWISE = 0, //rotate angle 90
    ROTATE_180 = 1, //rotate angle 180
    ROTATE_90_COUNTERCLOCKWISE = 2 //rotate angle 270
} RotateFlags;

#define SPLIT_MODE_TO_CHANNEL(x)   (x + 2)
typedef enum {
    SPLIT_2_CHANNELS = 0,
    SPLIT_3_CHANNELS = 1,
    SPLIT_4_CHANNELS = 2
} SplitMode;

#define MERGE_MODE_TO_CHANNEL(x)   (x + 2)
typedef enum {
    MERGE_2_CHANNELS = 0,
    MERGE_3_CHANNELS = 1,
    MERGE_4_CHANNELS = 2
} MergeMode;

#define CL_FLAG_HIGH_POSITION_MTK    CL_TRUE
#define CL_FLAG_LOW_POSITION_MTK     CL_FALSE
typedef enum {
    FMTCVT_U8_TO_U16 = 0,
    FMTCVT_U10_TO_U16 = 1,
    FMTCVT_U12_TO_U16 = 2,
    FMTCVT_U14_TO_U16 = 3,
    FMTCVT_U16_TO_U10 = 4,
    FMTCVT_U16_TO_U12 = 5
} FmtCVTMode;

typedef enum {
    FLIP_HORIZONTAL = 0,
    FLIP_VERTICAL   = 1
} FlipMode;

#define GLSU_PAD_MAX_BOUNDARY_SIZE 63
typedef enum {
    CL_BORDER_CONSTANT = 0,
    CL_BORDER_REPLICATE = 1
} PadMode;

typedef struct _cl_batch_desc_mtk {
    cl_batch_flags_mtk          flags;
    cl_uint                     compute_device_index; /**< no effect, will be deprecated in SW1.1 */
    cl_uint                     compute_unit_index;   /**< no effect, will be deprecated in SW1.1 */
} cl_batch_desc_mtk;

typedef struct _cl_batch_group_desc_mtk {
    cl_batch_group_flags_mtk          flags;
} cl_batch_group_desc_mtk;

/**
 * 1D copy
 */
typedef struct _cl_copy_buffer_desc_mtk {
    cl_copy_cmd_desc_type_mtk cmd_desc_type; /**< support: CL_COPY_CMD_DESC_COPY_BUF_MTK */
    DMAType dma_type; /**< support: CL_DMA_EDMA, CL_DMA_GLSU */
    cl_mem src_buffer;
    cl_mem dst_buffer;
    size_t src_offset;
    size_t dst_offset;
    size_t size;
} cl_copy_buffer_desc_mtk;

/**
 * 2D/3D copy
 */
typedef struct _cl_copy_buffer_rect_desc_mtk {
    cl_copy_cmd_desc_type_mtk cmd_desc_type; /**< support: CL_COPY_CMD_DESC_COPY_BUF_RECT_MTK */
    DMAType dma_type; /**< support: CL_DMA_EDMA, CL_DMA_GLSU */
    cl_mem src_buffer;
    cl_mem dst_buffer;
    const size_t *src_origin; /**< need to be size_t[4] */
    const size_t *dst_origin; /**< need to be size_t[4] */
    const size_t *region;     /**< need to be size_t[4] */
    size_t src_row_pitch;
    size_t src_slice_pitch;
    size_t dst_row_pitch;
    size_t dst_slice_pitch;
} cl_copy_buffer_rect_desc_mtk;

/**
 * 4D copy
 */
typedef struct _cl_copy_buffer_4D_desc_mtk {
    cl_copy_cmd_desc_type_mtk cmd_desc_type; /**< support: CL_COPY_CMD_DESC_COPY_BUF_4D_MTK */
    DMAType dma_type; /**< support: CL_DMA_EDMA, CL_DMA_GLSU */
    cl_mem src_buffer;
    cl_mem dst_buffer;
    const size_t *src_origin; /**< need to be size_t[4] */
    const size_t *dst_origin; /**< need to be size_t[4] */
    const size_t *region;     /**< need to be size_t[4] */
    size_t src_row_pitch;
    size_t src_slice_pitch;
    size_t dst_row_pitch;
    size_t dst_slice_pitch;
    size_t src_cube_pitch;
    size_t dst_cube_pitch;
} cl_copy_buffer_4D_desc_mtk;

typedef struct _cl_fill_buffer_desc_mtk {
    cl_copy_cmd_desc_type_mtk cmd_desc_type; /**< support: CL_COPY_CMD_DESC_FILL_MTK */
    DMAType dma_type; /**< support: CL_DMA_EDMA, CL_DMA_GLSU */
    cl_mem buffer;
    size_t offset;
    size_t size;

    const void *pattern;
    size_t pattern_size; /**< supported size: EDMA=4 ; GLSU=1,2,4 */
} cl_fill_buffer_desc_mtk;

typedef struct _cl_fill_buffer_4D_desc_mtk {
    cl_copy_cmd_desc_type_mtk cmd_desc_type; /**< support: CL_COPY_CMD_DESC_FILL_4D_MTK */
    DMAType dma_type; /**< support: CL_DMA_EDMA, CL_DMA_GLSU */
    cl_mem buffer;
    const size_t *origin; /**< describes 4D buffer offset of x,y,z,w; need to be size_t[4] */
    const size_t *region; /**< describes 4D buffer size of x,y,z,w; need to be size_t[4] */
    size_t row_pitch;
    size_t slice_pitch;
    size_t cube_pitch;

    const void *pattern;
    size_t pattern_size; /**< supported size: EDMA=4 ; GLSU=1,2,4 */
} cl_fill_buffer_4D_desc_mtk;

/**
 * @brief This structure is used to describe conversion between color format and for interleave and planar mode both.
 * supported conversion: 2-way: yuv444<->yuv420, rgb<->yuv420;
 *                       1-way: rgba2yuv, rgb2gray.
 * Setting of buffer 1, 2, 3 is created for planar mode.
 */
typedef struct _cl_buf_info {
    cl_mem cl_buffer;
    /**< origin & region need to be size_t[4] and pitch needs to be size_t[3]*/
    const size_t * origin;  /**< It indicates the offset between start address of source buffer and the start address of our interesting data on each dimension.*/
    const size_t * region;  /**< It indicates the size of source data on each dimension.*/
    const size_t * pitch;   /**< It indicates the pitch or stride size of [0]: row; [1]:slice; [2]: cube.*/
} cl_buf_info;

typedef struct _cl_colorcvt_matrix{
    cl_short clrcvt_mtrx[3][3];                 /**< Color conversion matrix*/
    cl_short clrcvt_mtrx_shift[3];              /**< RGB shift after color conversion*/
} cl_colorcvt_matrix;

typedef struct _cl_copy_buffer_userdef_desc_mtk {
    cl_copy_cmd_desc_type_mtk cmd_desc_type; /**< support: CL_COPY_CMD_DESC_USERDEF_MTK */
    UserDefMode mode;
    cl_uint user_key;
    DMAType dma_type;
    cl_uint num_src_buffer;
    cl_uint num_dst_buffer;

    cl_buf_info * src_buffer;
    cl_buf_info * dst_buffer;

    cl_uint num_para;
    cl_uint * para;
} cl_copy_buffer_userdef_desc_mtk;

typedef struct _cl_copy_buffer_pad_desc_mtk {
    cl_copy_cmd_desc_type_mtk cmd_desc_type; /**< support: CL_COPY_CMD_DESC_PAD_MTK */
    DMAType dma_type;
    PadMode mode;           /**< need to be the macro we provide*/
    cl_int const_value;
    size_t pixel_size;      /**< the pixel size means how many bytes of 1 pixel*/
    size_t num_dim;
    size_t top;
    size_t bottom;
    size_t left;
    size_t right;
    cl_buf_info src_buffer;
    cl_buf_info dst_buffer;
} cl_copy_buffer_pad_desc_mtk;

typedef struct _cl_copy_buffer_transpose_desc_mtk {
    cl_copy_cmd_desc_type_mtk cmd_desc_type; /**< support: CL_COPY_CMD_DESC_TRANSPOSE_MTK */
    DMAType dma_type;
    size_t pixel_size;      /**< the pixel size means how many bytes of 1 pixel*/
    size_t num_dim;
    cl_buf_info src_buffer;
    cl_buf_info dst_buffer;
} cl_copy_buffer_transpose_desc_mtk;

typedef struct _cl_copy_buffer_color_cvt_adv_desc_mtk{
    cl_copy_cmd_desc_type_mtk cmd_desc_type;    /**< This type indicate the color format conversion is applied.*/
    DMAType       dma_type;                     /**< It indicates what DMA unit is used.*/
    CL_ColorFmt   src_color_fmt;
    CL_ColorFmt   dst_color_fmt;
    CL_PixelFmt   src_pixel_fmt;
    CL_PixelFmt   dst_pixel_fmt;
    cl_short      alpha_value;
    size_t        num_dim;                      /**< It indicates number of dimension of source data, we use it to parse information from origin, region and pitch.*/

    union {
        cl_buf_info src_buffer_r;
        cl_buf_info src_buffer_y;
        cl_buf_info src_buffer_yuv;
        cl_buf_info src_buffer_rgba;
        cl_buf_info src_buffer_rgb;
        /* user interface is above.*/
        cl_buf_info src_buffer_0;
    };
    union {
        cl_buf_info src_buffer_g;
        cl_buf_info src_buffer_u;
        cl_buf_info src_buffer_uv;
        /* user interface is above.*/
        cl_buf_info src_buffer_1;
    };
    union {
        cl_buf_info src_buffer_b;
        cl_buf_info src_buffer_v;
        /* user interface is above.*/
        cl_buf_info src_buffer_2;
    };
    union {
        cl_buf_info src_buffer_a;
        /* user interface is above.*/
        cl_buf_info src_buffer_3;
    };
    union {
        cl_buf_info dst_buffer_r;
        cl_buf_info dst_buffer_y;
        cl_buf_info dst_buffer_yuv;
        cl_buf_info dst_buffer_rgba;
        cl_buf_info dst_buffer_rgb;
        /* user interface is above.*/
        cl_buf_info dst_buffer_0;
    };
    union {
        cl_buf_info dst_buffer_g;
        cl_buf_info dst_buffer_u;
        cl_buf_info dst_buffer_uv;
        /* user interface is above.*/
        cl_buf_info dst_buffer_1;
    };
    union {
        cl_buf_info dst_buffer_b;
        cl_buf_info dst_buffer_v;
        /* user interface is above.*/
        cl_buf_info dst_buffer_2;
    };
    union {
        cl_buf_info dst_buffer_a;
        /* user interface is above.*/
        cl_buf_info dst_buffer_3;
    };
    union{
        cl_colorcvt_matrix clrcvt_matrix;
    };
} cl_copy_buffer_colorcvt_adv_desc_mtk;

typedef struct _cl_copy_buffer_color_cvt_desc_mtk {
    cl_copy_cmd_desc_type_mtk cmd_desc_type;    /**< This type indicate the color format conversion is applied.*/
    DMAType       dma_type;                     /**< It indicates what DMA unit is used.*/
    CL_ColorFmt   src_color_fmt;
    CL_ColorFmt   dst_color_fmt;
    CL_PixelFmt   src_pixel_fmt;
    CL_PixelFmt   dst_pixel_fmt;
    cl_short      alpha_value;
    size_t        num_dim;                      /**< It indicates number of dimension of source data, we use it to parse information from origin, region and pitch.*/

    union {
        cl_buf_info src_buffer_r;
        cl_buf_info src_buffer_y;
        cl_buf_info src_buffer_yuv;
        cl_buf_info src_buffer_rgba;
        cl_buf_info src_buffer_rgb;
        /* user interface is above.*/
        cl_buf_info src_buffer_0;
    };
    union {
        cl_buf_info src_buffer_g;
        cl_buf_info src_buffer_u;
        cl_buf_info src_buffer_uv;
        /* user interface is above.*/
        cl_buf_info src_buffer_1;
    };
    union {
        cl_buf_info src_buffer_b;
        cl_buf_info src_buffer_v;
        /* user interface is above.*/
        cl_buf_info src_buffer_2;
    };
    union {
        cl_buf_info src_buffer_a;
        /* user interface is above.*/
        cl_buf_info src_buffer_3;
    };
    union {
        cl_buf_info dst_buffer_r;
        cl_buf_info dst_buffer_y;
        cl_buf_info dst_buffer_yuv;
        cl_buf_info dst_buffer_rgba;
        cl_buf_info dst_buffer_rgb;
        /* user interface is above.*/
        cl_buf_info dst_buffer_0;
    };
    union {
        cl_buf_info dst_buffer_g;
        cl_buf_info dst_buffer_u;
        cl_buf_info dst_buffer_uv;
        /* user interface is above.*/
        cl_buf_info dst_buffer_1;
    };
    union {
        cl_buf_info dst_buffer_b;
        cl_buf_info dst_buffer_v;
        /* user interface is above.*/
        cl_buf_info dst_buffer_2;
    };
    union {
        cl_buf_info dst_buffer_a;
        /* user interface is above.*/
        cl_buf_info dst_buffer_3;
    };
} cl_copy_buffer_colorcvt_desc_mtk;

typedef struct _cl_copy_buffer_rotate_desc_mtk {
    cl_copy_cmd_desc_type_mtk cmd_desc_type; /**< support: CL_COPY_CMD_DESC_ROTATE_MTK */
    DMAType dma_type;
    RotateFlags mode;           /**< need to be the macro we provide*/
    size_t pixel_size;    /**< the pixel size means how many bytes of 1 pixel*/
    size_t num_dim;
    cl_buf_info src_buffer;
    cl_buf_info dst_buffer;
} cl_copy_buffer_rotate_desc_mtk;

typedef struct _cl_copy_buffer_split_desc_mtk {
    cl_copy_cmd_desc_type_mtk cmd_desc_type; /**< support: CL_COPY_CMD_DESC_SPLIT_MTK */
    DMAType dma_type;
    SplitMode mode;              /**< need to be the macro we provide*/
    size_t pixel_size;     /**< the pixel size means how many bytes of 1 pixel*/
    size_t num_dim;
    cl_uchar dst_ch_en_bitmap;
    cl_buf_info src_buffer;
    cl_buf_info dst_buffer[4];
} cl_copy_buffer_split_desc_mtk;

typedef struct _cl_copy_buffer_merge_desc_mtk {
    cl_copy_cmd_desc_type_mtk cmd_desc_type; /**< support: CL_COPY_CMD_DESC_MERGE_MTK */
    DMAType dma_type;
    MergeMode mode;              /**< need to be the macro we provide*/
    size_t pixel_size;     /**< the pixel size means how many bytes of 1 pixel*/
    size_t num_dim;
    cl_buf_info src_buffer[4];
    cl_buf_info dst_buffer;
} cl_copy_buffer_merge_desc_mtk;

typedef struct _cl_copy_buffer_fmtcvt_desc_mtk {
    cl_copy_cmd_desc_type_mtk cmd_desc_type; /**< support: CL_COPY_CMD_DESC_FMTCVT_MTK */
    DMAType dma_type;
    FmtCVTMode mode;        /**< need to be the macro we provide*/
    cl_bool pos_flag;          /**<flag CL_PAD_FLAG_HIGH_MTK: zero padded on MSB; CL_PAD_FLAG_LOW_MTK on LSB*/
    size_t num_dim;
    cl_buf_info src_buffer;
    cl_buf_info dst_buffer;
} cl_copy_buffer_fmtcvt_desc_mtk;

typedef struct _cl_copy_buffer_swap_desc_mtk {
    cl_copy_cmd_desc_type_mtk cmd_desc_type; /**< support: CL_COPY_CMD_DESC_SWAP_MTK */
    DMAType dma_type;
    size_t swap_size;
    size_t num_dim;
    cl_buf_info src_buffer;
    cl_buf_info dst_buffer;
} cl_copy_buffer_swap_desc_mtk;

typedef struct _cl_copy_buffer_flip_desc_mtk {
    cl_copy_cmd_desc_type_mtk cmd_desc_type; /**< support: CL_COPY_CMD_DESC_FLIP_MTK */
    DMAType dma_type;
    FlipMode mode;
    size_t pixel_size;
    size_t num_dim;
    cl_buf_info src_buffer;
    cl_buf_info dst_buffer;
} cl_copy_buffer_flip_desc_mtk;

typedef struct _cl_event_wait_properties_mtk {
    cl_uint num_wait;
    cl_bool * wait_id_ready;
    cl_uint * wait_id;
} cl_event_wait_properties_mtk;

typedef struct _cl_event_wake_properties_mtk {
    cl_uint num_wake;
    cl_bool * wake_id_ready;
    cl_uint * wake_id;
} cl_event_wake_properties_mtk;

// batch argument type
typedef enum {
    BATCH_ARG_TYPE_MEMORY_MTK = 0,      /**< supprot cl_mem */
    BATCH_ARG_TYPE_NDR_ARGUMENT_MTK,    /**< support kernel argument */
    BATCH_ARG_TYPE_EDMA_FIELD_MTK,      /**< support edma field */
    BATCH_ARG_TYPE_GLSU_FIELD_MTK,      /**< support glsu field */
    BATCH_ARG_TYPE_UNKNOWN_MTK,         /**< only for check, should not appear */
} cl_batch_arg_type_mtk;

#define ciSetKernelArgMTK(...)          clSetKernelArg(__VA_ARGS__)

//Function definitions
extern void clVersionMTK(void);

extern CL_API_ENTRY cl_int CL_API_CALL
clSetRingBufferSizeMTK(cl_device_id device,
                       cl_ring_buf_type_mtk ring_buffer_type,
                       cl_uint size) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clGetRingBufferInfoMTK(cl_device_id device,
                       cl_ring_buf_info_mtk param_name,
                       size_t param_value_size,
                       void *param_value,
                       size_t *param_value_size_ret) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_batch_mtk CL_API_CALL
clCreateBatchMTK(cl_context context,
                 cl_device_id device,
                 const char *name,
                 const cl_batch_desc_mtk *batch_desc,
                 cl_int *errcode_ret) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_batch_mtk CL_API_CALL
clCreateBatchWithBinaryMTK(cl_context context,
                           const size_t size,
                           const char *binary,
                           const char *name,
                           cl_int *errcode_ret) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_batch_mtk CL_API_CALL
clCreateBatchWithBinaryCacheMTK(cl_context context,
                                const size_t size,
                                const char *binary,
                                const char *name,
                                cl_int *errcode_ret) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_batch_mtk CL_API_CALL
clCreateBatchWithSecureBinaryMTK(cl_context context,
                           cl_device_id device,
                           const cl_batch_desc_mtk *batch_desc,
                           const size_t size,
                           const char *binary,
                           const char *name,
                           cl_int *errcode_ret) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clSetBatchPropertyMTK(const cl_batch_mtk batch,
                      const cl_batch_property_type type,
                      const cl_ulong property) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_batch_group_mtk CL_API_CALL
clCreateBatchGroupMTK(cl_context context,
                      const char *name,
                      const cl_batch_group_desc_mtk *batch_group_desc,
                      cl_int *errcode_ret) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clSetBatchGroupPropertyMTK(const cl_batch_group_mtk batch_group,
                           const cl_batch_group_property_type type,
                           const cl_ulong property) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clAddBatchToBatchGroupMTK(cl_batch_group_mtk batch_group,
                          const cl_batch_mtk batch,
                          cl_uint num_events_in_wait_list,
                          const cl_batch_group_event_mtk *event_wait_list,
                          cl_batch_group_event_mtk *event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
ciBatchNDRangeKernelMTK(cl_batch_mtk batch,
                        cl_kernel kernel,
                        cl_uint work_dim,
                        const size_t *work_group_size,
                        cl_uint num_events_in_wait_list,
                        const cl_batch_event_mtk *event_wait_list,
                        cl_batch_event_mtk *event,
                        const char *suffix) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clBatchNDRangeKernelMTK(cl_batch_mtk batch,
                        cl_kernel kernel,
                        cl_uint work_dim,
                        const size_t *global_work_offset,
                        const size_t *global_work_size,
                        const size_t *local_work_size,
                        cl_uint num_events_in_wait_list,
                        const cl_batch_event_mtk *event_wait_list,
                        cl_batch_event_mtk *event,
                        const char *suffix) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clBatchCopyBufferMTK(cl_batch_mtk batch,
                     cl_mem src_buffer,
                     cl_mem dst_buffer,
                     size_t src_offset,
                     size_t dst_offset,
                     size_t cb,
                     cl_uint num_events_in_wait_list,
                     const cl_batch_event_mtk *event_wait_list,
                     cl_batch_event_mtk *event,
                     const char *cmd_name) CL_EXT_SUFFIX__VERSION_1_2;


extern CL_API_ENTRY cl_int CL_API_CALL
clBatchCopyBufferRectMTK(cl_batch_mtk batch,
                         cl_mem src_buffer,
                         cl_mem dst_buffer,
                         const size_t *src_origin,
                         const size_t *dst_origin,
                         const size_t *region,
                         size_t src_row_pitch,
                         size_t src_slice_pitch,
                         size_t dst_row_pitch,
                         size_t dst_slice_pitch,
                         cl_uint num_events_in_wait_list,
                         const cl_batch_event_mtk *event_wait_list,
                         cl_batch_event_mtk *event,
                         const char *cmd_name) CL_EXT_SUFFIX__VERSION_1_2;



extern CL_API_ENTRY cl_int CL_API_CALL
clBatchFillBufferMTK(cl_batch_mtk batch,
                     cl_mem buffer,
                     const void *pattern,
                     size_t pattern_size,
                     size_t offset,
                     size_t size,
                     cl_uint num_events_in_wait_list,
                     const cl_batch_event_mtk *event_wait_list,
                     cl_batch_event_mtk *event,
                     const char *cmd_name) CL_EXT_SUFFIX__VERSION_1_2;


extern CL_API_ENTRY cl_int CL_API_CALL
clBatchCopyBufferAdvanceMTK(cl_batch_mtk batch,
                            cl_command_type cmd_type, /**< cl_command_type section in cl.h (0x11xx) & cl_ext.h (0x21xx) */
                            const void *cmd_desc,
                            cl_uint num_events_in_wait_list,
                            const cl_batch_event_mtk *event_wait_list,
                            cl_batch_event_mtk *event,
                            const char *cmd_name) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clFinalizeBatchMTK(cl_batch_mtk batch) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clFinalizeBatchGroupMTK(cl_batch_group_mtk batch_group) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueBatchMTK(cl_command_queue command_queue,
                  cl_batch_mtk batch,
                  cl_uint num_events_in_wait_list,
                  const cl_event *event_wait_list,
                  cl_event *event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueBatchGroupMTK(cl_command_queue command_queue,
                       cl_batch_group_mtk batch_group,
                       cl_uint num_events_in_wait_list,
                       const cl_event *event_wait_list,
                       cl_event *event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clGetBatchInfoMTK(cl_batch_mtk batch,
                  cl_batch_info_mtk param_name,
                  size_t param_value_size,
                  void *param_value,
                  size_t *param_value_size_ret) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clSetBatchArgMTK(cl_batch_mtk batch,
                 cl_uint arg_id,
                 size_t arg_size,
                 const void *arg_value) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clGetBatchEventInfoMTK(cl_batch_event_mtk batch_event,
                       cl_event_info param_name,
                       size_t param_value_size,
                       void *param_value,
                       size_t *param_value_size_ret) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clRetainBatchMTK(cl_batch_mtk batch) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clReleaseBatchMTK(cl_batch_mtk batch) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clRetainBatchGroupMTK(cl_batch_group_mtk batch_group) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clReleaseBatchGroupMTK(cl_batch_group_mtk batch_group) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clRetainBatchEventMTK(cl_batch_event_mtk batch_event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clReleaseBatchGroupEventMTK(cl_batch_group_event_mtk batch_group_event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clRetainBatchGroupEventMTK(cl_batch_group_event_mtk batch_group_event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clReleaseBatchEventMTK(cl_batch_event_mtk batch_event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clSetEventPropertyMTK(cl_context context, cl_event * event,
                      cl_event_property_type type,
                      void * property) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clSetBatchEventPropertyMTK(cl_context context, cl_batch_mtk batch,
                           cl_batch_event_mtk * batch_event,
                           cl_event_property_type type,
                           void * property) CL_EXT_SUFFIX__VERSION_1_2;

#endif  //#ifndef cl_mtk_batch

/*******************************
* cl_mtk_enqueue_ndr extension *
********************************/
extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyBufferColorCVTMTK(cl_command_queue command_queue,
                               cl_copy_buffer_colorcvt_desc_mtk * cl_desc,
                               cl_uint num_events_in_wait_list,
                               const cl_event *event_wait_list,
                               cl_event *event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyBufferColorCVTAdvanceMTK(cl_command_queue command_queue,
                                      cl_copy_buffer_colorcvt_adv_desc_mtk * cl_desc,
                                      cl_uint num_events_in_wait_list,
                                      const cl_event *event_wait_list,
                                      cl_event *event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyBufferFlipMTK(cl_command_queue command_queue,
                           cl_copy_buffer_flip_desc_mtk * cl_desc,
                           cl_uint num_events_in_wait_list,
                           const cl_event *event_wait_list,
                           cl_event *event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyBufferFmtCVTMTK(cl_command_queue command_queue,
                             cl_copy_buffer_fmtcvt_desc_mtk * cl_desc,
                             cl_uint num_events_in_wait_list,
                             const cl_event *event_wait_list,
                             cl_event *event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyBufferMergeMTK(cl_command_queue command_queue,
                            cl_copy_buffer_merge_desc_mtk * cl_desc,
                            cl_uint num_events_in_wait_list,
                            const cl_event *event_wait_list,
                            cl_event *event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyBufferRotateMTK(cl_command_queue command_queue,
                             cl_copy_buffer_rotate_desc_mtk * cl_desc,
                             cl_uint num_events_in_wait_list,
                             const cl_event *event_wait_list,
                             cl_event *event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyBufferSplitMTK(cl_command_queue command_queue,
                            cl_copy_buffer_split_desc_mtk * cl_desc,
                            cl_uint num_events_in_wait_list,
                            const cl_event *event_wait_list,
                            cl_event *event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyBufferSwapMTK(cl_command_queue command_queue,
                           cl_copy_buffer_swap_desc_mtk * cl_desc,
                           cl_uint num_events_in_wait_list,
                           const cl_event *event_wait_list,
                           cl_event *event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyBufferPadMTK(cl_command_queue command_queue,
                          cl_copy_buffer_pad_desc_mtk * cl_desc,
                          cl_uint num_events_in_wait_list,
                          const cl_event *event_wait_list,
                          cl_event *event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyBufferTransposeMTK(cl_command_queue command_queue,
                                cl_copy_buffer_transpose_desc_mtk * cl_desc,
                                cl_uint num_events_in_wait_list,
                                const cl_event *event_wait_list,
                                cl_event *event) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyBufferUserDefMTK(cl_command_queue command_queue,
                                cl_copy_buffer_userdef_desc_mtk * cl_desc,
                                cl_uint num_events_in_wait_list,
                                const cl_event *event_wait_list,
                                cl_event *event) CL_EXT_SUFFIX__VERSION_1_2;


#ifndef cl_mtk_enqueue_ndr
#define cl_mtk_enqueue_ndr 1

extern CL_API_ENTRY cl_int CL_API_CALL
ciEnqueueNDRangeKernelMTK(cl_command_queue command_queue,/* command_queue */
                          cl_kernel kernel,                 /* kernel */
                          cl_uint work_dim,
                          const size_t *work_group_size,    /* global_work_size */
                          cl_uint num_events_in_wait_list,  /* num_events_in_wait_list */
                          const cl_event *event_wait_list,  /* event_wait_list */
                          cl_event *event       /* event */) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueNDRangeKernelWithSuffixMTK(cl_command_queue command_queue, cl_kernel kernel,
                                    cl_uint work_dim, const size_t *global_work_offset,
                                    const size_t *global_work_size,
                                    const size_t *local_work_size,
                                    cl_uint num_events_in_wait_list,
                                    const cl_event *event_wait_list,
                                    cl_event *event, const char *suffix) CL_EXT_SUFFIX__VERSION_1_2;
#endif //#ifndef cl_mtk_enqueue_ndr

extern CL_API_ENTRY cl_int CL_API_CALL
clTest() CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_kernel CL_API_CALL
ciCreateKernelWithBinaryMTK(cl_context context ,
                            cl_device_id device_id,
                            const char* kernel_name,
                            const unsigned char* binary,
                            size_t binary_size,
                            cl_int * errcode_ret) CL_EXT_SUFFIX__VERSION_1_2;

#define ciReleaseKernelMTK(...)          clReleaseKernel(__VA_ARGS__)

extern CL_API_ENTRY cl_int CL_API_CALL
clGetProgramThinBinariesMTK(cl_program program, size_t param_value_size, void *param_value,
                 size_t *param_value_size_ret)  CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clGetProgramThinBinarySizesMTK(cl_program program, size_t param_value_size, void *param_value,
                 size_t *param_value_size_ret) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clCheckLibMTK() CL_EXT_SUFFIX__VERSION_1_2;

/*******************************
* cl_mtk_mem extension         *
********************************/
#ifndef cl_mtk_mem
#define cl_mtk_mem 1

/******************************************************************************/

/* error codes */
#define CL_INVALID_MEM_MODE_MTK                     -701
#define CL_MISALIGNED_MEM_OBJECT_OFFSET_MTK         -702

/* cl_mem_info  */
//#define CL_MEM_TYPE                               0x1100
//#define CL_MEM_FLAGS                              0x1101
//#define CL_MEM_SIZE                               0x1102
//#define CL_MEM_HOST_PTR                           0x1103
//#define CL_MEM_MAP_COUNT                          0x1104
//#define CL_MEM_REFERENCE_COUNT                    0x1105
//#define CL_MEM_CONTEXT                            0x1106
//#define CL_MEM_ASSOCIATED_MEMOBJECT               0x1107
//#define CL_MEM_OFFSET                             0x1108
#define   CL_MEM_NAME_MTK                           0x2200
#define   CL_MEM_DEVICE_MTK                         0x2201

/* cl_mem_flags - bitfield */
//#define CL_MEM_READ_WRITE                         (1 << 0)
//#define CL_MEM_WRITE_ONLY                         (1 << 1)
//#define CL_MEM_READ_ONLY                          (1 << 2)
//#define CL_MEM_USE_HOST_PTR                       (1 << 3)
//#define CL_MEM_ALLOC_HOST_PTR                     (1 << 4)
//#define CL_MEM_COPY_HOST_PTR                      (1 << 5)
///* reserved                                       (1 << 6)    */
//#define CL_MEM_HOST_WRITE_ONLY                    (1 << 7)
//#define CL_MEM_HOST_READ_ONLY                     (1 << 8)
//#define CL_MEM_HOST_NO_ACCESS                     (1 << 9)
/* cl_device_info */
#define CL_DEVICE_FAST_GLOBAL_SIZE_MTK              0x2230
#define CL_DEVICE_FAST_GLOBAL_BASE_ADDR_ALIGN_MTK   0x2231

#endif //#ifndef cl_mtk_mem

/**************************
* cl_mtk_buffer extension *
***************************/
#ifndef cl_mtk_buffer
#define cl_mtk_buffer 1  //use TCM


/* cl_device_info */
#define CL_DEVICE_TCM_SIZE_MTK                      0x2310
#define CL_DEVICE_NUM_MVPU_MTK                      0x2311
#define CL_DEVICE_NUM_EDMA_MTK                      0x2312

/* cl_mem_flags - bitfield */
#define CL_MEM_BATCH_INPUT_OUTPUT_MTK               (1UL << 11)  // marking a buffer as an input/output buffer, which won't be recorded in pattern, and need setup to pattern
#define CL_MEM_BATCH_MALLOC_ONLY_MTK                (1UL << 12)  // marking a buffer as an malloc only buffer, which won't be recorded in pattern
#define CL_IMPORT_DMA_BUF_MTK                       (1UL << 16)
#define CL_IMPORT_AHARDWARE_BUF_MTK                 (1UL << 17)
#define CL_MEM_ALLOC_ON_APU_TCM_MTK                 (1UL << 20)
#define CL_MEM_ALLOC_ON_MVPU_L1_MTK                 (1UL << 21)
/* For batch create from binary update TCM use only */
#define CL_MEM_BATCH_BINARY_USE_TCM_MTK             (1UL << 24)
/* For APU TCM use only */
#define CL_MEM_ATTR_SHARED_MTK                      (1UL << 25)
/* For MVPU L1 use only */
#define CL_MEM_BYPASS_ALIGN_CHECK_MTK               (1UL << 30)
#define CL_MEM_ALIGN_2_MTK                          (1UL << 31)
#define CL_MEM_ALIGN_4_MTK                          (1UL << 32)
#define CL_MEM_ALIGN_8_MTK                          (1UL << 33)
#define CL_MEM_ALIGN_16_MTK                         (1UL << 34)
#define CL_MEM_ALIGN_32_MTK                         (1UL << 35)
#define CL_MEM_ALIGN_64_MTK                         (1UL << 36)
#define CL_MEM_ALIGN_128_MTK                        (1UL << 37)
#define CL_MEM_ALIGN_256_MTK                        (1UL << 38)
#define CL_MEM_ALIGN_512_MTK                        (1UL << 39)
#define CL_MEM_ALIGN_1024_MTK                       (1UL << 40)

extern CL_API_ENTRY cl_mem CL_API_CALL
clCreateBufferMTK(cl_context   context,
                  cl_mem_flags flags,
                  size_t       size,
                  void *       host_ptr,
                  cl_int *     errcode_ret,
                  const char * name) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_mem CL_API_CALL
clCreateSubBufferMTK(cl_mem                buffer,
                     cl_mem_flags          flags,
                     cl_buffer_create_type buffer_create_type,
                     const void *          buffer_create_info,
                     cl_int *              errcode_ret,
                     const char *          name) CL_EXT_SUFFIX__VERSION_1_2;
#endif //#ifdef cl_mtk_buffer

/*******************************
* cl_mtk_query_kernel extension *
********************************/
#ifndef cl_mtk_query_kernel_work_group
#define cl_mtk_query_kernel_work_group 1

/* cl_kernel_work_group_info */
#define CL_KERNEL_ARG_BUF_SIZE_MTK                  0x2500
#define CL_KERNEL_CONST_POOL_SIZE_MTK               0x2501

#endif //#ifndef cl_mtk_query_kernel

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
inline CL_API_ENTRY cl_int CL_API_CALL
clBatchCopyBufferMTK(cl_batch_mtk batch, // this API will be deprecated in SW1.1
                     cl_mem src_buffer,
                     cl_mem dst_buffer,
                     size_t src_offset,
                     size_t dst_offset,
                     size_t cb,
                     cl_uint num_events_in_wait_list,
                     const cl_batch_event_mtk *event_wait_list,
                     cl_batch_event_mtk *event) CL_EXT_SUFFIX__VERSION_1_2
{
    return clBatchCopyBufferMTK(batch, src_buffer, dst_buffer, src_offset, dst_offset, cb, num_events_in_wait_list, event_wait_list, event, NULL);
}

inline CL_API_ENTRY cl_int CL_API_CALL
clBatchCopyBufferRectMTK(cl_batch_mtk batch, // this API will be deprecated in SW1.1
                         cl_mem src_buffer,
                         cl_mem dst_buffer,
                         const size_t *src_origin,
                         const size_t *dst_origin,
                         const size_t *region,
                         size_t src_row_pitch,
                         size_t src_slice_pitch,
                         size_t dst_row_pitch,
                         size_t dst_slice_pitch,
                         cl_uint num_events_in_wait_list,
                         const cl_batch_event_mtk *event_wait_list,
                         cl_batch_event_mtk *event) CL_EXT_SUFFIX__VERSION_1_2
{
    return clBatchCopyBufferRectMTK(batch, src_buffer, dst_buffer, src_origin, dst_origin, region, src_row_pitch, src_slice_pitch, dst_row_pitch, dst_slice_pitch, num_events_in_wait_list, event_wait_list, event, NULL);
}

inline CL_API_ENTRY cl_int CL_API_CALL
clBatchFillBufferMTK(cl_batch_mtk batch, // this API will be deprecated in SW1.1
                     cl_mem buffer,
                     const void *pattern,
                     size_t pattern_size,
                     size_t offset,
                     size_t size,
                     cl_uint num_events_in_wait_list,
                     const cl_batch_event_mtk *event_wait_list,
                     cl_batch_event_mtk *event) CL_EXT_SUFFIX__VERSION_1_2
{
    return clBatchFillBufferMTK(batch, buffer, pattern, pattern_size, offset, size, num_events_in_wait_list, event_wait_list, event, NULL);
}

inline CL_API_ENTRY cl_int CL_API_CALL
clBatchCopyBufferWithNameMTK(cl_batch_mtk batch, // this API will be deprecated in SW1.1
                             cl_mem src_buffer,
                             cl_mem dst_buffer,
                             size_t src_offset,
                             size_t dst_offset,
                             size_t cb,
                             cl_uint num_events_in_wait_list,
                             const cl_batch_event_mtk *event_wait_list,
                             cl_batch_event_mtk *event,
                             const char *cmd_name) CL_EXT_SUFFIX__VERSION_1_2
{
    return clBatchCopyBufferMTK(batch, src_buffer, dst_buffer, src_offset, dst_offset, cb, num_events_in_wait_list, event_wait_list, event, cmd_name);
}

inline CL_API_ENTRY cl_int CL_API_CALL
clBatchCopyBufferRectWithNameMTK(cl_batch_mtk batch, // this API will be deprecated in SW1.1
                                 cl_mem src_buffer,
                                 cl_mem dst_buffer,
                                 const size_t *src_origin,
                                 const size_t *dst_origin,
                                 const size_t *region,
                                 size_t src_row_pitch,
                                 size_t src_slice_pitch,
                                 size_t dst_row_pitch,
                                 size_t dst_slice_pitch,
                                 cl_uint num_events_in_wait_list,
                                 const cl_batch_event_mtk *event_wait_list,
                                 cl_batch_event_mtk *event,
                                 const char *cmd_name) CL_EXT_SUFFIX__VERSION_1_2
{
    return clBatchCopyBufferRectMTK(batch, src_buffer, dst_buffer, src_origin, dst_origin, region, src_row_pitch, src_slice_pitch, dst_row_pitch, dst_slice_pitch, num_events_in_wait_list, event_wait_list, event, cmd_name);
}

inline CL_API_ENTRY cl_int CL_API_CALL
clBatchFillBufferWithNameMTK(cl_batch_mtk batch, // this API will be deprecated in SW1.1
                             cl_mem buffer,
                             const void *pattern,
                             size_t pattern_size,
                             size_t offset,
                             size_t size,
                             cl_uint num_events_in_wait_list,
                             const cl_batch_event_mtk *event_wait_list,
                             cl_batch_event_mtk *event,
                             const char *cmd_name) CL_EXT_SUFFIX__VERSION_1_2
{
    return clBatchFillBufferMTK(batch, buffer, pattern, pattern_size, offset, size, num_events_in_wait_list, event_wait_list, event, cmd_name);
}


#endif // #ifdef __cplusplus

#endif /* __CL_EXT_H */
