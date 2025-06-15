cmake_minimum_required(VERSION 3.28)
project(hello_world)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello_world projects/very_small_prjs/hello_world/src/hello_world.cpp)
