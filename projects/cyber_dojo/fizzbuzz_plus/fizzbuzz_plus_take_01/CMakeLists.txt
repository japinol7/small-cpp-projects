cmake_minimum_required(VERSION 3.28)

project(fizzbuzz_plus_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_FILES
        src/fizzbuzz_plus.hpp
        src/utils/utils.hpp
)

set(SOURCE_FILES
        src/fizzbuzz_plus.cpp
        src/utils/utils.cpp
)

add_library(fizzbuzz_plus_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(fizzbuzz_plus_run ${SOURCE_FILES} src/main.cpp)
