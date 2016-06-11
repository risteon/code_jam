#
cmake_minimum_required (VERSION 3.1)
project (jam)



add_executable (jam.out template.cpp)
set_property (TARGET jam.out PROPERTY CXX_STANDARD 14)

