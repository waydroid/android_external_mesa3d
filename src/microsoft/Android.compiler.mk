#
# Copyright (C) 2021 Erfan Abdi <erfangplus@gmail.com>
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
#

# ---------------------------------------
# Build libmesa_microsoft_compiler
# ---------------------------------------

include $(CLEAR_VARS)

LOCAL_MODULE := libmesa_microsoft_compiler
LOCAL_MODULE_CLASS := STATIC_LIBRARIES

LOCAL_SRC_FILES := \
	$(COMPILER_FILES)

LOCAL_C_INCLUDES := \
	$(MESA_TOP)/src/mapi \
	$(MESA_TOP)/src/mesa \
	$(MESA_TOP)/src/microsoft/compiler \
	$(MESA_TOP)/src/gallium/auxiliary \
	$(MESA_TOP)/src/gallium/include \
	$(call generated-sources-dir-for,STATIC_LIBRARIES,libmesa_glsl,,)/glsl \
	$(call generated-sources-dir-for,STATIC_LIBRARIES,libmesa_nir,,)/nir \
	$(MESA_TOP)/src/compiler/nir

dxil_nir_algebraic_deps := \
	$(LOCAL_PATH)/compiler/dxil_nir_algebraic.py \
	$(MESA_TOP)/src/compiler/nir/nir_algebraic.py

intermediates := $(call local-generated-sources-dir)

$(intermediates)/compiler/dxil_nir_algebraic.c: $(dxil_nir_algebraic_deps)
	@mkdir -p $(dir $@)
	$(hide) $(MESA_PYTHON2) $< -p $(MESA_TOP)/src/compiler/nir > $@

LOCAL_STATIC_LIBRARIES := \
	libmesa_git_sha1 \
	libmesa_glsl \
	libmesa_nir \

LOCAL_GENERATED_SOURCES += $(addprefix $(intermediates)/, \
	$(COMPILER_GENERATED_FILES))

include $(MESA_COMMON_MK)
include $(BUILD_STATIC_LIBRARY)
