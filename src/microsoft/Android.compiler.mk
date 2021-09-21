# Mesa 3-D graphics library
#
# Copyright (C) 2021 Diab Neiroukh <lazerl0rd@thezest.dev>
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.

include $(CLEAR_VARS)

LOCAL_MODULE := libdxil_compiler
LOCAL_MODULE_CLASS := STATIC_LIBRARIES
intermediates := $(call local-generated-sources-dir)

LOCAL_SRC_FILES := \
	$(compiler_FILES)

LOCAL_C_INCLUDES := \
	$(MESA_TOP)/src/compiler/nir \
	$(MESA_TOP)/src/gallium/auxiliary \
	$(MESA_TOP)/src/gallium/include \
	$(MESA_TOP)/src/mapi \
	$(MESA_TOP)/src/mesa \
	$(MESA_TOP)/src/microsoft/compiler

LOCAL_STATIC_LIBRARIES := libmesa_nir

LOCAL_GENERATED_SOURCES := \
	$(intermediates)/dxil_nir_algebraic.c \
	$(MESA_GEN_GLSL_H)

dxil_nir_algebraic_gen := $(LOCAL_PATH)/bifrost/dxil_nir_algebraic.py
dxil_nir_algebraic_deps := \
	$(MESA_TOP)/src/compiler/nir

$(intermediates)/dxil_nir_algebraic.c: $(dxil_nir_algebraic_deps)
	@mkdir -p $(dir $@)
	$(hide) $(MESA_PYTHON3) $(dxil_nir_algebraic_gen) -p $< > $@

LOCAL_EXPORT_C_INCLUDE_DIRS := \
	$(MESA_TOP)/src/microsoft/compiler

include $(MESA_COMMON_MK)
include $(BUILD_STATIC_LIBRARY)
