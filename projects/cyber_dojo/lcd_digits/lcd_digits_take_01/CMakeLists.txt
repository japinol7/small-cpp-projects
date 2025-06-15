cmake_minimum_required(VERSION 3.28)

project(lcd_digits_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_FILES
        src/lcd_digits.hpp
        src/lcd_digit_cell.hpp
)

set(SOURCE_FILES
        src/lcd_digits.cpp
        src/lcd_digit_cell.cpp
)

add_library(lcd_digits_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(lcd_digits_run ${SOURCE_FILES} src/main.cpp)
