# Copyright (C) 2014 Emil Velikov <emil.l.velikov@gmail.com>
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

###########################################################
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

include $(LOCAL_PATH)/Makefile.sources

LOCAL_SRC_FILES := \
	$(C_SOURCES)

ifeq ($(ARCH_ARM_HAVE_NEON),true)
LOCAL_SRC_FILES += $(NEON_C_SOURCES)
endif

LOCAL_C_INCLUDES := \
	$(MESA_TOP)/include

LOCAL_MODULE := libmesa_pipe_v3d
LOCAL_MODULE_CLASS := STATIC_LIBRARIES
intermediates := $(call local-generated-sources-dir)

LOCAL_EXPORT_C_INCLUDE_DIRS := $(intermediates)

# We need libmesa_nir to get NIR's generated include directories.
LOCAL_STATIC_LIBRARIES := \
	libmesa_nir \

LOCAL_WHOLE_STATIC_LIBRARIES := \
	libbroadcom-v33 \
	libbroadcom-v41 \
	libbroadcom-v42 \
	libmesa_broadcom_common \
	libmesa_broadcom_compiler \
	libmesa_broadcom_cle \
	libmesa_broadcom_genxml \
	libmesa_broadcom_qpu \
	libmesa_pipe_v3d_v33 \
	libmesa_pipe_v3d_v41 \

include $(GALLIUM_COMMON_MK)
include $(BUILD_STATIC_LIBRARY)

ifneq ($(HAVE_GALLIUM_V3D),)
GALLIUM_TARGET_DRIVERS += v3d
$(eval GALLIUM_LIBS += $(LOCAL_MODULE) libmesa_winsys_v3d)
endif

include $(CLEAR_VARS)
LOCAL_MODULE_CLASS := STATIC_LIBRARIES
LOCAL_SRC_FILES := $(V3D_PER_VERSION_SOURCES)
LOCAL_STATIC_LIBRARIES := libmesa_nir \
	libmesa_broadcom_genxml \
	libmesa_broadcom_cle \

LOCAL_MODULE := libmesa_pipe_v3d_v33
LOCAL_CFLAGS += -DV3D_VERSION=33
include $(GALLIUM_COMMON_MK)
include $(BUILD_STATIC_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE_CLASS := STATIC_LIBRARIES
LOCAL_SRC_FILES := $(V3D_PER_VERSION_SOURCES)
LOCAL_STATIC_LIBRARIES := libmesa_nir \
	libmesa_broadcom_genxml \
	libmesa_broadcom_cle \

LOCAL_MODULE := libmesa_pipe_v3d_v41
LOCAL_CFLAGS += -DV3D_VERSION=41
include $(GALLIUM_COMMON_MK)
include $(BUILD_STATIC_LIBRARY)
