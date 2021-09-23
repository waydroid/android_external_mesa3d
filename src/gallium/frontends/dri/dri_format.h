/*
 * Copyright (C) 1999-2007  Brian Paul   All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef DRI_FORMAT_H
#define DRI_FORMAT_H

#include "drm-uapi/drm_fourcc.h"
#include "dri_util.h"

struct dri2_format_mapping {
   int dri_fourcc;
   int dri_format; /* image format */
   int dri_components;
   enum pipe_format pipe_format;
   int nplanes;
   struct {
      int buffer_index;
      int width_shift;
      int height_shift;
      uint32_t dri_format; /* plane format */
   } planes[3];
};

static const struct dri2_format_mapping dri2_format_table[] = {
      { DRM_FORMAT_ABGR16161616F, __DRI_IMAGE_FORMAT_ABGR16161616F,
        __DRI_IMAGE_COMPONENTS_RGBA,      PIPE_FORMAT_R16G16B16A16_FLOAT, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_ABGR16161616F } } },
      { DRM_FORMAT_XBGR16161616F, __DRI_IMAGE_FORMAT_XBGR16161616F,
        __DRI_IMAGE_COMPONENTS_RGB,       PIPE_FORMAT_R16G16B16X16_FLOAT, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_XBGR16161616F } } },
      { DRM_FORMAT_ARGB2101010,   __DRI_IMAGE_FORMAT_ARGB2101010,
        __DRI_IMAGE_COMPONENTS_RGBA,      PIPE_FORMAT_B10G10R10A2_UNORM, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_ARGB2101010 } } },
      { DRM_FORMAT_XRGB2101010,   __DRI_IMAGE_FORMAT_XRGB2101010,
        __DRI_IMAGE_COMPONENTS_RGB,       PIPE_FORMAT_B10G10R10X2_UNORM, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_XRGB2101010 } } },
      { DRM_FORMAT_ABGR2101010,   __DRI_IMAGE_FORMAT_ABGR2101010,
        __DRI_IMAGE_COMPONENTS_RGBA,      PIPE_FORMAT_R10G10B10A2_UNORM, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_ABGR2101010 } } },
      { DRM_FORMAT_XBGR2101010,   __DRI_IMAGE_FORMAT_XBGR2101010,
        __DRI_IMAGE_COMPONENTS_RGB,       PIPE_FORMAT_R10G10B10X2_UNORM, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_XBGR2101010 } } },
      { DRM_FORMAT_ARGB8888,      __DRI_IMAGE_FORMAT_ARGB8888,
        __DRI_IMAGE_COMPONENTS_RGBA,      PIPE_FORMAT_BGRA8888_UNORM, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_ARGB8888 } } },
      { DRM_FORMAT_ABGR8888,      __DRI_IMAGE_FORMAT_ABGR8888,
        __DRI_IMAGE_COMPONENTS_RGBA,      PIPE_FORMAT_RGBA8888_UNORM, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_ABGR8888 } } },
      { __DRI_IMAGE_FOURCC_SARGB8888,     __DRI_IMAGE_FORMAT_SARGB8,
        __DRI_IMAGE_COMPONENTS_RGBA,      PIPE_FORMAT_BGRA8888_SRGB, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_SARGB8 } } },
      { DRM_FORMAT_XRGB8888,      __DRI_IMAGE_FORMAT_XRGB8888,
        __DRI_IMAGE_COMPONENTS_RGB,       PIPE_FORMAT_BGRX8888_UNORM, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_XRGB8888 } } },
      { DRM_FORMAT_XBGR8888,      __DRI_IMAGE_FORMAT_XBGR8888,
        __DRI_IMAGE_COMPONENTS_RGB,       PIPE_FORMAT_RGBX8888_UNORM, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_XBGR8888 } } },
      { DRM_FORMAT_ARGB1555,      __DRI_IMAGE_FORMAT_ARGB1555,
        __DRI_IMAGE_COMPONENTS_RGBA,      PIPE_FORMAT_B5G5R5A1_UNORM, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_ARGB1555 } } },
      { DRM_FORMAT_RGB565,        __DRI_IMAGE_FORMAT_RGB565,
        __DRI_IMAGE_COMPONENTS_RGB,       PIPE_FORMAT_B5G6R5_UNORM, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_RGB565 } } },
      { DRM_FORMAT_R8,            __DRI_IMAGE_FORMAT_R8,
        __DRI_IMAGE_COMPONENTS_R,         PIPE_FORMAT_R8_UNORM, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R8 } } },
      { DRM_FORMAT_R16,           __DRI_IMAGE_FORMAT_R16,
        __DRI_IMAGE_COMPONENTS_R,         PIPE_FORMAT_R16_UNORM, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R16 } } },
      { DRM_FORMAT_GR88,          __DRI_IMAGE_FORMAT_GR88,
        __DRI_IMAGE_COMPONENTS_RG,        PIPE_FORMAT_RG88_UNORM, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_GR88 } } },
      { DRM_FORMAT_GR1616,        __DRI_IMAGE_FORMAT_GR1616,
        __DRI_IMAGE_COMPONENTS_RG,        PIPE_FORMAT_RG1616_UNORM, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_GR1616 } } },

      { DRM_FORMAT_YUV410, __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_U_V,     PIPE_FORMAT_IYUV, 3,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R8 },
          { 1, 2, 2, __DRI_IMAGE_FORMAT_R8 },
          { 2, 2, 2, __DRI_IMAGE_FORMAT_R8 } } },
      { DRM_FORMAT_YUV411, __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_U_V,     PIPE_FORMAT_IYUV, 3,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R8 },
          { 1, 2, 0, __DRI_IMAGE_FORMAT_R8 },
          { 2, 2, 0, __DRI_IMAGE_FORMAT_R8 } } },
      { DRM_FORMAT_YUV420,        __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_U_V,     PIPE_FORMAT_IYUV, 3,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R8 },
          { 1, 1, 1, __DRI_IMAGE_FORMAT_R8 },
          { 2, 1, 1, __DRI_IMAGE_FORMAT_R8 } } },
      { DRM_FORMAT_YUV422,        __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_U_V,     PIPE_FORMAT_IYUV, 3,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R8 },
          { 1, 1, 0, __DRI_IMAGE_FORMAT_R8 },
          { 2, 1, 0, __DRI_IMAGE_FORMAT_R8 } } },
      { DRM_FORMAT_YUV444,        __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_U_V,     PIPE_FORMAT_IYUV, 3,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R8 },
          { 1, 0, 0, __DRI_IMAGE_FORMAT_R8 },
          { 2, 0, 0, __DRI_IMAGE_FORMAT_R8 } } },

      { DRM_FORMAT_YVU410,        __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_U_V,     PIPE_FORMAT_IYUV, 3,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R8 },
          { 2, 2, 2, __DRI_IMAGE_FORMAT_R8 },
          { 1, 2, 2, __DRI_IMAGE_FORMAT_R8 } } },
      { DRM_FORMAT_YVU411,        __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_U_V,     PIPE_FORMAT_IYUV, 3,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R8 },
          { 2, 2, 0, __DRI_IMAGE_FORMAT_R8 },
          { 1, 2, 0, __DRI_IMAGE_FORMAT_R8 } } },
      { DRM_FORMAT_YVU420,        __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_U_V,     PIPE_FORMAT_IYUV, 3,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R8 },
          { 2, 1, 1, __DRI_IMAGE_FORMAT_R8 },
          { 1, 1, 1, __DRI_IMAGE_FORMAT_R8 } } },
      { DRM_FORMAT_YVU422,        __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_U_V,     PIPE_FORMAT_IYUV, 3,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R8 },
          { 2, 1, 0, __DRI_IMAGE_FORMAT_R8 },
          { 1, 1, 0, __DRI_IMAGE_FORMAT_R8 } } },
      { DRM_FORMAT_YVU444,        __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_U_V,     PIPE_FORMAT_IYUV, 3,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R8 },
          { 2, 0, 0, __DRI_IMAGE_FORMAT_R8 },
          { 1, 0, 0, __DRI_IMAGE_FORMAT_R8 } } },

      { DRM_FORMAT_NV12,          __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_UV,      PIPE_FORMAT_NV12, 2,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R8 },
          { 1, 1, 1, __DRI_IMAGE_FORMAT_GR88 } } },

      { DRM_FORMAT_P010,          __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_UV,      PIPE_FORMAT_P010, 2,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R16 },
          { 1, 1, 1, __DRI_IMAGE_FORMAT_GR1616 } } },
      { DRM_FORMAT_P012,          __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_UV,      PIPE_FORMAT_P012, 2,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R16 },
          { 1, 1, 1, __DRI_IMAGE_FORMAT_GR1616 } } },
      { DRM_FORMAT_P016,          __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_UV,      PIPE_FORMAT_P016, 2,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R16 },
          { 1, 1, 1, __DRI_IMAGE_FORMAT_GR1616 } } },

      { DRM_FORMAT_NV16,          __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_UV,      PIPE_FORMAT_NV12, 2,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_R8 },
          { 1, 1, 0, __DRI_IMAGE_FORMAT_GR88 } } },

      { DRM_FORMAT_AYUV,      __DRI_IMAGE_FORMAT_ABGR8888,
        __DRI_IMAGE_COMPONENTS_AYUV,      PIPE_FORMAT_AYUV, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_ABGR8888 } } },
      { DRM_FORMAT_XYUV8888,      __DRI_IMAGE_FORMAT_XBGR8888,
        __DRI_IMAGE_COMPONENTS_XYUV,      PIPE_FORMAT_XYUV, 1,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_XBGR8888 } } },

      /* For YUYV and UYVY buffers, we set up two overlapping DRI images
       * and treat them as planar buffers in the compositors.
       * Plane 0 is GR88 and samples YU or YV pairs and places Y into
       * the R component, while plane 1 is ARGB/ABGR and samples YUYV/UYVY
       * clusters and places pairs and places U into the G component and
       * V into A.  This lets the texture sampler interpolate the Y
       * components correctly when sampling from plane 0, and interpolate
       * U and V correctly when sampling from plane 1. */
      { DRM_FORMAT_YUYV,          __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_XUXV,    PIPE_FORMAT_YUYV, 2,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_GR88 },
          { 0, 1, 0, __DRI_IMAGE_FORMAT_ARGB8888 } } },
      { DRM_FORMAT_UYVY,          __DRI_IMAGE_FORMAT_NONE,
        __DRI_IMAGE_COMPONENTS_Y_UXVX,    PIPE_FORMAT_UYVY, 2,
        { { 0, 0, 0, __DRI_IMAGE_FORMAT_GR88 },
          { 0, 1, 0, __DRI_IMAGE_FORMAT_ABGR8888 } } }
};

const struct dri2_format_mapping *
dri2_get_mapping_by_fourcc(int fourcc);

const struct dri2_format_mapping *
dri2_get_mapping_by_format(int format);
#endif

/* vim: set sw=3 ts=8 sts=3 expandtab: */
