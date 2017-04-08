//
// Created by zakrent on 3/18/17.
//

#ifndef SDL_1_MAP_H
#define SDL_1_MAP_H

#include <vector>
#include "Tile.h"
#include "../entities/Entity.h"
#include "../entities/Player.h"

enum direction {
    Up,
    Down,
    Left,
    Right
};

static const int MAP_HEIGHT = 50;
static const int MAP_WIDTH = 50;

class Map {
private:
    std::vector<Tile *> tiles;
    std::vector<Entity *> entities;
    std::vector < Tile* > generateNodeRow(Tile* firstNode);
    void updateEntities();
    void checkCollisions();
public:
    std::vector<Player *> players;
    void generateMap();
    void render(SDL_Renderer& renderer, SDL_Rect& camera, SDL_Texture* TileSheet, SDL_Texture* EntitySheet);
    void update();
    bool checkIfCollidersColide(SDL_Rect& colliderA, SDL_Rect& colliderB);
    Tile* getNeighbouringTile(direction directionToNeighbour, Tile* mainTile);
    Map();
};


#endif //SDL_1_MAP_H
