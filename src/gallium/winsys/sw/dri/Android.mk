# Mesa 3-D graphics library
#
# Copyright (C) 2015 Chih-Wei Huang <cwhuang@linux.org.tw>
# Copyright (C) 2015 Android-x86 Open Source Project
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

LOCAL_SRC_FILES := $(C_SOURCES)

LOCAL_MODULE := libmesa_winsys_sw_dri

ifeq ($(shell test $(PLATFORM_SDK_VERSION) -ge 27; echo $$?), 0)
LOCAL_C_INCLUDES += \
	frameworks/native/libs/nativebase/include \
	frameworks/native/libs/nativewindow/include \
	frameworks/native/libs/arect/include \
	system/core/libsystem/include

LOCAL_HEADER_LIBRARIES += \
	libcutils_headers \
	libsystem_headers \
	libnativebase_headers \
	libhardware_headers
endif

ifeq ($(filter $(MESA_ANDROID_MAJOR_VERSION), 4 5 6 7),)
LOCAL_SHARED_LIBRARIES += libnativewindow
endif

include $(GALLIUM_COMMON_MK)
include $(BUILD_STATIC_LIBRARY)
