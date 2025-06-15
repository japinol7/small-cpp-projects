cmake_minimum_required(VERSION 3.28)

project(filename_range_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_FILES
        src/filename_range.hpp
)

set(SOURCE_FILES
        src/filename_range.cpp
)

add_library(filename_range_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(filename_range_run ${SOURCE_FILES} src/main.cpp)
