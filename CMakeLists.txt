cmake_minimum_required(VERSION 3.6)
project(SDL_1)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES main.cpp classes/program.cpp classes/program.h classes/Map.cpp classes/Map.h classes/Tile.cpp classes/Tile.h)
add_executable(SDL_1 ${SOURCE_FILES})
target_link_libraries(SDL_1 ${SDL2_LIBRARY})