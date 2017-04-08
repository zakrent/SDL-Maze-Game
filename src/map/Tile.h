//
// Created by zakrent on 3/18/17.
//

#ifndef SDL_1_TILE_H
#define SDL_1_TILE_H

#include <SDL_rect.h>
#include <SDL_render.h>

static const int TILE_WIDTH = 32;
static const int TILE_HEIGHT = 32;

class Tile {
public:
    SDL_Rect collider;
    int type;
    int distanceFromPlayer;
    int group;
    void render(SDL_Renderer& renderer, SDL_Rect& camera, SDL_Texture* TileSheet);
    bool isSolid();
    Tile(int x, int y, int type);
};


#endif //SDL_1_TILE_H
