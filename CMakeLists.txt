#-------------------------------------------------------------------------------
# Copyright (c) 2024 John D. Haughton
# SPDX-License-Identifier: MIT
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.20)

project(pico106
        LANGUAGES CXX C ASM
        VERSION 0.03)

if(NOT DEFINED BUILD_TESTING)
    set(BUILD_TESTING OFF CACHE BOOL "Build unit tests")
endif()
include(CTest)

set(HWR_CONFIG picoX7)

add_subdirectory(PDK)
add_subdirectory(Source)
