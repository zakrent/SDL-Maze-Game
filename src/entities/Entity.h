//
// Created by zakrent on 3/25/17.
//

#ifndef SDL_1_ENTITY_H
#define SDL_1_ENTITY_H

#include <SDL_rect.h>
#include <SDL_render.h>
#include "../map/Tile.h"

class Map;

class Entity {
protected:
    float velocity[2]; //velocity[0] is x and [1] is y, unit = 1px/0.01s
    void updatePhysics();
    int health; //-1 for indestructible
public:
    const int ENTITY_WIDTH = 24;
    const int ENTITY_HEIGHT = 24;
    SDL_Rect collider;
    Tile* isStandingOn;
    int type;
    void render(SDL_Renderer& renderer, SDL_Rect& camera, SDL_Texture* EntitySheet);

    virtual void update(Map &mainMap);
    void handleTileCollision(Tile& tile);
    Entity(int type, int xInPixels, int yInPixels, int health = -1);
    virtual ~Entity();

};


#endif //SDL_1_ENTITY_H
