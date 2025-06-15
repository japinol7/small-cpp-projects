cmake_minimum_required(VERSION 3.28)

project(balanced_parentheses_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_FILES
        src/balanced_parentheses.hpp
)

set(SOURCE_FILES
        src/balanced_parentheses.cpp
)

add_library(balanced_parentheses_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(balanced_parentheses_run ${SOURCE_FILES} src/main.cpp)
