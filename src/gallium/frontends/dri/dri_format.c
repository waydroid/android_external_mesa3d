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

#include "dri_format.h"

const struct dri2_format_mapping *
dri2_get_mapping_by_fourcc(int fourcc)
{
   for (unsigned i = 0; i < ARRAY_SIZE(dri2_format_table); i++) {
      if (dri2_format_table[i].dri_fourcc == fourcc)
         return &dri2_format_table[i];
   }

   return NULL;
}

const struct dri2_format_mapping *
dri2_get_mapping_by_format(int format)
{
   if (format == __DRI_IMAGE_FORMAT_NONE)
      return NULL;

   for (unsigned i = 0; i < ARRAY_SIZE(dri2_format_table); i++) {
      if (dri2_format_table[i].dri_format == format)
         return &dri2_format_table[i];
   }

   return NULL;
}

/* vim: set sw=3 ts=8 sts=3 expandtab: */
