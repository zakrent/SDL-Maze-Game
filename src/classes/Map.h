//
// Created by zakrent on 3/18/17.
//

#ifndef SDL_1_MAP_H
#define SDL_1_MAP_H

#include <vector>
#include "Tile.h"
#include "Entity.h"
#include "Player.h"

enum direction {
    Up,
    Down,
    Left,
    Right
};

static const int MAP_HEIGHT = 10;
static const int MAP_WIDTH = 20;

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
    int getNeighbouringTileIndex(direction directionToNeighbour, Tile mainTile);
    Map();
};


#endif //SDL_1_MAP_H
