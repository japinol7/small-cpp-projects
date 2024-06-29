cmake_minimum_required(VERSION 3.28)
project(small-cpp-projects)

set(CMAKE_CXX_STANDARD 20)

add_executable(hello_world projects/very_small_prjs/hello_world/src/hello_world.cpp)

add_executable(power_01 projects/very_small_prjs/power_01/src/power_01.cpp)
