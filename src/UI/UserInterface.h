//
// Created by zakrent on 4/12/17.
//

#ifndef SDL_1_USERINTERFACE_H
#define SDL_1_USERINTERFACE_H


#include <SDL_system.h>
#include "../entities/Player.h"

class UserInterface {
private:
    void drawHealthBar(SDL_Renderer *renderer, Player *mainPlayer);

public:
    void draw(SDL_Renderer *renderer, Player *mainPlayer);
};


#endif //SDL_1_USERINTERFACE_H
