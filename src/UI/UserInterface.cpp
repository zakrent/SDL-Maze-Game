//
// Created by zakrent on 4/12/17.
//

#include "UserInterface.h"
#include "../Program.h"

void UserInterface::draw(SDL_Renderer *renderer, Player *mainPlayer) {
    drawHealthBar(renderer, mainPlayer);
}

void UserInterface::drawHealthBar(SDL_Renderer *renderer, Player *mainPlayer) {
    SDL_Rect fillRect = {10, 10, mainPlayer->health * 3, 16};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x30, 0x30, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect);
}


