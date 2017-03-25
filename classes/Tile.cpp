//
// Created by zakrent on 3/18/17.
//

#include "Tile.h"

Tile::Tile(int x, int y, int type) {
    collider = {x*TILE_WIDTH, y*TILE_HEIGHT ,TILE_WIDTH, TILE_HEIGHT};
    this->type = type;
}

void Tile::render(SDL_Renderer& renderer, SDL_Rect& camera, SDL_Texture* texture[]) {
    SDL_Rect dstrect = {collider.x - camera.x, collider.y - camera.y, TILE_WIDTH, TILE_HEIGHT};
    SDL_RenderCopyEx(&renderer, texture[0], NULL, &dstrect, 0, NULL, SDL_FLIP_NONE);
}
