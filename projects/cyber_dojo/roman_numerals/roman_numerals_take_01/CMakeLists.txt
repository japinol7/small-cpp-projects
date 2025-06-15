cmake_minimum_required(VERSION 3.28)

project(roman_numerals_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_FILES
        src/roman_numerals.hpp
)

set(SOURCE_FILES
        src/roman_numerals.cpp
)

add_library(roman_numerals_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(roman_numerals_run ${SOURCE_FILES} src/main.cpp)
