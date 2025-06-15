cmake_minimum_required(VERSION 3.28)

project(game_of_life_lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER_FILES
        src/game_of_life.hpp
)

set(SOURCE_FILES
        src/game_of_life.cpp
)

add_library(game_of_life_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

add_executable(game_of_life_run ${SOURCE_FILES} src/main.cpp)
