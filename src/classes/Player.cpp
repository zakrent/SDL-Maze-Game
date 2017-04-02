//
// Created by zakrent on 3/25/17.
//

#include "Player.h"


void Player::handleControll() {
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if(currentKeyStates[SDL_SCANCODE_A]){
        this->velocity[0] = -1;
    }else if(currentKeyStates[SDL_SCANCODE_D]){
        this->velocity[0] = 1;
    }else{
        this->velocity[0] = 0;
    }
    if(currentKeyStates[SDL_SCANCODE_S]){
        this->velocity[1] = 1;
    }else if(currentKeyStates[SDL_SCANCODE_W]){
        this->velocity[1] = -1;
    }else{
        this->velocity[1] = 0;
    }

}

Player::Player(int type, int xInPixels, int yInPixels, int health)
        : Entity(type, xInPixels, yInPixels, health)
{
    return ;
}
