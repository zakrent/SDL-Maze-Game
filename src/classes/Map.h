//
// Created by zakrent on 3/18/17.
//

#ifndef SDL_1_MAP_H
#define SDL_1_MAP_H

#include <vector>
#include "Tile.h"
#include "Entity.h"
#include "Player.h"

class Map {
public:
    std::vector < Tile > tiles;
    std::vector < Entity > entities;
    std::vector < Player > players;
    void generateMap();
    void render(SDL_Renderer& renderer, SDL_Rect& camera, SDL_Texture* TileSheet, SDL_Texture* EntitySheet);
    void updateEntities();
    void checkCollisions();
    bool checkIfCollidersColide(SDL_Rect& colliderA, SDL_Rect& colliderB);
    Map();
};


#endif //SDL_1_MAP_H
