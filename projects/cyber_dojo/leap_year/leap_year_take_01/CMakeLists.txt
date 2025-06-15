cmake_minimum_required(VERSION 3.28)

project(leap_year_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_FILES
        src/leap_year.hpp
)

set(SOURCE_FILES
        src/leap_year.cpp
)

add_library(leap_year_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(leap_year_run ${SOURCE_FILES} src/main.cpp)
