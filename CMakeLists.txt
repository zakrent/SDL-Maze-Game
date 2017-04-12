cmake_minimum_required(VERSION 3.6)
project(SDL_1)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES src/main.cpp src/Program.cpp src/Program.h src/map/Map.cpp src/map/Map.h src/map/Tile.cpp src/map/Tile.h src/entities/Entity.cpp src/entities/Entity.h src/entities/Player.cpp src/entities/Player.h src/entities/Enemy.cpp src/entities/Enemy.h src/UI/UserInterface.cpp src/UI/UserInterface.h)
add_executable(SDL_1 ${SOURCE_FILES})
target_link_libraries(SDL_1 ${SDL2_LIBRARY})
file(COPY textures/ DESTINATION textures/)