cmake_minimum_required(VERSION 3.6)
project(SDL_1)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES src/main.cpp src/classes/program.cpp src/classes/program.h src/classes/Map.cpp src/classes/Map.h src/classes/Tile.cpp src/classes/Tile.h src/classes/Entity.cpp src/classes/Entity.h src/classes/Player.cpp src/classes/Player.h)
add_executable(SDL_1 ${SOURCE_FILES})
target_link_libraries(SDL_1 ${SDL2_LIBRARY})