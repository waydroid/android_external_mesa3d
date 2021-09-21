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

LOCAL_PATH := $(call my-dir)

include $(LOCAL_PATH)/Makefile.sources

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	$(CPP_SOURCES) \
	$(C_SOURCES)

LOCAL_C_INCLUDES := \
	$(MESA_TOP)/include/wsl/stubs \
	$(call generated-sources-dir-for,STATIC_LIBRARIES,libmesa_nir,,)/nir \
	$(MESA_TOP)/src/compiler/nir \
	$(MESA_TOP)/src/mesa \
	$(MESA_TOP)/src/microsoft/compiler \
	$(MESA_TOP)/src/microsoft/resource_state_manager

# This allows us to have NIR's generated includes.
LOCAL_STATIC_LIBRARIES := libmesa_nir

LOCAL_WHOLE_STATIC_LIBRARIES := \
	libmesa_microsoft_compiler \
	libmesa_microsoft_resource_state

LOCAL_SHARED_LIBRARIES := libsync

LOCAL_MODULE := libmesa_pipe_d3d12

include $(GALLIUM_COMMON_MK)
include $(BUILD_STATIC_LIBRARY)

ifneq ($(HAVE_GALLIUM_NOUVEAU),)
GALLIUM_TARGET_DRIVERS += d3d12
$(eval GALLIUM_LIBS += $(LOCAL_MODULE))
endif
