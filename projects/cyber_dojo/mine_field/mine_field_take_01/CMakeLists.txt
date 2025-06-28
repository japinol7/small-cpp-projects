cmake_minimum_required(VERSION 3.28)

project(mine_field_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_FILES
        src/mine_field.hpp
)

set(SOURCE_FILES
        src/mine_field.cpp
)

add_library(mine_field_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(mine_field_run ${SOURCE_FILES} src/main.cpp)
