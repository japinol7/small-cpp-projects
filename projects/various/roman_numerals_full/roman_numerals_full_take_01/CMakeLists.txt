cmake_minimum_required(VERSION 3.28)

project(roman_numerals_full_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_FILES
        src/roman_numerals_full.hpp
)

set(SOURCE_FILES
        src/roman_numerals_full.cpp
)

add_library(roman_numerals_full_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(roman_numerals_full_run ${SOURCE_FILES} src/main.cpp)
