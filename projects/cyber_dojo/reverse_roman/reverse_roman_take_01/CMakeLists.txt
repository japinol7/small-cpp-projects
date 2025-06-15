cmake_minimum_required(VERSION 3.28)

project(reverse_roman_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_FILES
        src/reverse_roman.hpp
)

set(SOURCE_FILES
        src/reverse_roman.cpp
)

add_library(reverse_roman_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(reverse_roman_run ${SOURCE_FILES} src/main.cpp)
