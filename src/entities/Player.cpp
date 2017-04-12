//
// Created by zakrent on 3/25/17.
//

#include "Player.h"

void Player::update(Map &mainMap) {
    updatePhysics();
    if (health <= 0 || (isStandingOn != NULL && isStandingOn->type == 3)) {
        SDL_Event event;
        event.type = SDL_QUIT;
        SDL_PushEvent(&event);
    }
}

void Player::handleControll() {
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    int velocityMultiplier = 4;
    if(currentKeyStates[SDL_SCANCODE_A]){
        this->velocity[0] = -1 * velocityMultiplier;
    }else if(currentKeyStates[SDL_SCANCODE_D]){
        this->velocity[0] = 1 * velocityMultiplier;
    }else{
        this->velocity[0] = 0 * velocityMultiplier;
    }
    if(currentKeyStates[SDL_SCANCODE_S]){
        this->velocity[1] = 1 * velocityMultiplier;
    }else if(currentKeyStates[SDL_SCANCODE_W]){
        this->velocity[1] = -1 * velocityMultiplier;
    }else{
        this->velocity[1] = 0 * velocityMultiplier;
    }
}

Player::Player(int type, int xInPixels, int yInPixels, int health)
        : Entity(type, xInPixels, yInPixels, health)
{
    return ;
}
