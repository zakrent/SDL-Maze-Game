//
// Created by zakrent on 3/18/17.
//

#ifndef SDL_1_MAP_H
#define SDL_1_MAP_H

#include <vector>
#include "Tile.h"

class Map {
public:
    std::vector < Tile > tiles;
    //std::vector < Entity > entities;
    //Player player;
    void generateMap();
    void render(SDL_Renderer& renderer, SDL_Rect& camera, SDL_Texture* TileSheet);
    Map();
};


#endif //SDL_1_MAP_H
