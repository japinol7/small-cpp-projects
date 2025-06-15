cmake_minimum_required(VERSION 3.28)

project(isbn_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_FILES
        src/isbn.hpp
)

set(SOURCE_FILES
        src/isbn.cpp
)

add_library(isbn_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(isbn_run ${SOURCE_FILES} src/main.cpp)
