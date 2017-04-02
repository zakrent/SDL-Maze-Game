//
// Created by zakrent on 3/25/17.
//

#ifndef SDL_1_ENTITY_H
#define SDL_1_ENTITY_H

#include <SDL_rect.h>
#include <SDL_render.h>
#include "Tile.h"

class Entity {
protected:
    float velocity[2]; //velocity[0] is x and [1] is y, unit = 1px/0.01s
    void updatePhysics();
public:
    const int ENTITY_WIDTH = 32;
    const int ENTITY_HEIGHT = 32;
    SDL_Rect collider;
    int type;
    void render(SDL_Renderer& renderer, SDL_Rect& camera, SDL_Texture* EntitySheet);
    void update();
    void handleTileCollision(Tile& tile);
    Entity(int type, int xInPixels, int yInPixels);
    ~Entity();

};


#endif //SDL_1_ENTITY_H
