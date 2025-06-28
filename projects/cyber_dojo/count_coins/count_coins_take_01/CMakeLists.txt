cmake_minimum_required(VERSION 3.28)

project(count_coins_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_FILES
        src/count_coins.hpp
)

set(SOURCE_FILES
        src/count_coins.cpp
)

add_library(count_coins_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(count_coins_run ${SOURCE_FILES} src/main.cpp)
