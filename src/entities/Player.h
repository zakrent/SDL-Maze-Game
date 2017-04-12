//
// Created by zakrent on 3/25/17.
//

#ifndef SDL_1_PLAYER_H
#define SDL_1_PLAYER_H

#include "Entity.h"
#include <SDL_events.h>

class Player : public Entity{
public:
    void update(Map &mainMap);
    void handleControll();
    Player(int type, int xInPixels, int yInPixels, int health = -1);
};

#endif //SDL_1_PLAYER_H
