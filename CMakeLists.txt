#-------------------------------------------------------------------------------
# Copyright (c) 2024 John D. Haughton
# SPDX-License-Identifier: MIT
#-------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.20)

project(pico106
        LANGUAGES CXX C ASM
        VERSION 0.03)

include(CTest)

set(HARDWARE picoX7)

add_subdirectory(Platform/Hardware)
add_subdirectory(Source)
