#-------------------------------------------------------------------------------
# Copyright (c) 2024 John D. Haughton
# SPDX-License-Identifier: MIT
#-------------------------------------------------------------------------------

autogen_py(Table_exp_24)

foreach(hw_config ${hw_picoX7_config_list})

   add_executable(pico-106_${hw_config}
                  Table_exp_24.cpp
                  pico-106.cpp)

   target_include_directories(pico-106_${hw_config}
                              PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

   target_compile_definitions(pico-106_${hw_config} PRIVATE HW_${hw_config})

   target_link_libraries(pico-106_${hw_config} PRIVATE HW)

   set_target_properties(pico-106_${hw_config} PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

endforeach()

# add_executable(test_midi_in test_midi_in.cpp)
# target_link_libraries(test_midi_in PRIVATE TNY MTL TNY)
