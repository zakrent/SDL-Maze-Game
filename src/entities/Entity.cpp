//
// Created by zakrent on 3/25/17.
//

#include <SDL_render.h>
#include <SDL_timer.h>
#include "Entity.h"

void Entity::update(Map &mainMap) {

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
    if (isStandingOn) {
        int distanceFromPlayer = isStandingOn->distanceFromPlayer;
        if (125 - distanceFromPlayer * 5 <= 0 || distanceFromPlayer == -1) {
            SDL_SetTextureColorMod(EntitySheet, 0, 0, 0);
        } else {
            SDL_SetTextureColorMod(EntitySheet, 125 - distanceFromPlayer * 5, 125 - distanceFromPlayer * 5,
                                   125 - distanceFromPlayer * 5);
        }
    }
    SDL_RenderCopyEx(&renderer, EntitySheet, &srcrect, &dstrect, 0, NULL, SDL_FLIP_NONE);
}

void Entity::takeDamage(int damage) {
    if (SDL_GetTicks() - lastDamageTime < 250) {
        return;
    }
    health -= damage;
    lastDamageTime = SDL_GetTicks();
}


Entity::Entity(int type, int xInPixels, int yInPixels, int health) {
    this->isStandingOn = NULL;
    this->type = type;
    this->health = health;
    lastDamageTime = SDL_GetTicks();
    collider = {xInPixels, yInPixels, ENTITY_WIDTH, ENTITY_HEIGHT};
}

Entity::~Entity() {

}
