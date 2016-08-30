#
cmake_minimum_required (VERSION 3.1)
project (jam)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable (jam.out template.cpp io_redirect.cpp)
set_property (TARGET jam.out PROPERTY CXX_STANDARD 14)

