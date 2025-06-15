cmake_minimum_required(VERSION 3.28)

project(print_diamond_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_FILES
        src/print_diamond.hpp
)

set(SOURCE_FILES
        src/print_diamond.cpp
)

add_library(print_diamond_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(print_diamond_run ${SOURCE_FILES} src/main.cpp)
