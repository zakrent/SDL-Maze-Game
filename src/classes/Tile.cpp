//
// Created by zakrent on 3/18/17.
//

#include "Tile.h"

bool Tile::isSolid() {
    return type == 1 || type == 2;
}


void Tile::render(SDL_Renderer& renderer, SDL_Rect& camera, SDL_Texture* TileSheet) {
    SDL_Rect dstrect = {collider.x - camera.x, collider.y - camera.y, TILE_WIDTH, TILE_HEIGHT};
    SDL_Rect srcrect = {type*TILE_WIDTH, 0, TILE_WIDTH, TILE_HEIGHT};
    SDL_RenderCopyEx(&renderer, TileSheet, &srcrect, &dstrect, 0, NULL, SDL_FLIP_NONE);
}

Tile::Tile(int x, int y, int type) {
    collider = {x*TILE_WIDTH, y*TILE_HEIGHT ,TILE_WIDTH, TILE_HEIGHT};
    this->type = type;
}
