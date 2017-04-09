//
// Created by zakrent on 4/8/17.
//

#ifndef SDL_1_ENEMY_H
#define SDL_1_ENEMY_H

#include "Entity.h"
#include "../map/Map.h"

class Enemy : public Entity {
private:
    int moveToCords[2];
    void calculateMovementVelocity();

    void chasePlayer(Map &mainMap);
public:
    void moveTo(direction moveDirection);
    bool isOnMove();

    void update(Map &mainMap);

    Enemy(int type, int xInPixels, int yInPixels, int health = -1);
};


#endif //SDL_1_ENEMY_H
