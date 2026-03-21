#-------------------------------------------------------------------------------
# Copyright (c) 2024 John D. Haughton
# SPDX-License-Identifier: MIT
#-------------------------------------------------------------------------------

autogen_py(Table_exp_24)

add_picoX7_executable(pico-106
                         pico-106.cpp
                         Table_exp_24.cpp)

# add_executable(test_midi_in test_midi_in.cpp)
# target_link_libraries(test_midi_in PRIVATE TNY MTL TNY)
