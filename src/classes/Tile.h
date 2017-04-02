//
// Created by zakrent on 3/18/17.
//

#ifndef SDL_1_TILE_H
#define SDL_1_TILE_H

#include <SDL_rect.h>
#include <SDL_render.h>

class Tile {
public:
    const int TILE_WIDTH = 32;
    const int TILE_HEIGHT = 32;
    SDL_Rect collider;
    int type;
    void render(SDL_Renderer& renderer, SDL_Rect& camera, SDL_Texture* TileSheet);
    bool isSolid();
    Tile(int x, int y, int type);
};


#endif //SDL_1_TILE_H
