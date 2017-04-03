//
// Created by zakrent on 3/25/17.
//

#include <SDL_render.h>
#include "Entity.h"

void Entity::update() {

    updatePhysics();
}

void Entity::updatePhysics() {
    collider.x += velocity[0];
    collider.y += velocity[1];
}

void Entity::handleTileCollision(Tile& tile) {
    if(tile.isSolid()){
        collider.x -= velocity[0];
        collider.y -= velocity[1];
    }else{
        isStandingOn = &tile;
    }
}

void Entity::render(SDL_Renderer& renderer, SDL_Rect& camera, SDL_Texture* EntitySheet) {
    SDL_Rect dstrect = {collider.x - camera.x, collider.y - camera.y, ENTITY_WIDTH, ENTITY_HEIGHT};
    SDL_Rect srcrect = {type*ENTITY_WIDTH, 0, ENTITY_WIDTH, ENTITY_HEIGHT};
    SDL_RenderCopyEx(&renderer, EntitySheet, &srcrect, &dstrect, 0, NULL, SDL_FLIP_NONE);
}

Entity::Entity(int type, int xInPixels, int yInPixels, int health) {
    //this->velocity[0]=1; //TODO: Remove debugging
    this->isStandingOn = NULL;
    this->type = type;
    this->health = health;
    collider = {xInPixels, yInPixels, ENTITY_WIDTH, ENTITY_HEIGHT};
}

Entity::~Entity() {

}



