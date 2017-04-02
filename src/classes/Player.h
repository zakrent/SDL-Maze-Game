//
// Created by zakrent on 3/25/17.
//

#ifndef SDL_1_PLAYER_H
#define SDL_1_PLAYER_H

#include "Entity.h"

class Player : public Entity{
public:
    void handleControllEvent();
    using Entity::Entity;
};

#endif //SDL_1_PLAYER_H
