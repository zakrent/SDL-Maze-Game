//
// Created by zakrent on 3/18/17.
//

#ifndef SDL_1_MAP_H
#define SDL_1_MAP_H

#include <vector>
#include "Tile.h"
#include "Entity.h"

class Map {
public:
    std::vector < Tile > tiles;
    std::vector < Entity > entities;
    //Player player;
    void generateMap();
    void render(SDL_Renderer& renderer, SDL_Rect& camera, SDL_Texture* TileSheet, SDL_Texture* EntitySheet);
    void updateEntities();
    Map();
};


#endif //SDL_1_MAP_H
