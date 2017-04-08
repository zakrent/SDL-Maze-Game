//
// Created by zakrent on 4/8/17.
//

#include "Enemy.h"

void Enemy::update() {
    calculateMovementVelocity();
    updatePhysics();
}

void Enemy::calculateMovementVelocity() {
    velocity[0] = 0;
    velocity[1] = 0;
    if (moveToCords[0] < collider.x) {
        velocity[0] = -1;
    } else if (moveToCords[0] > collider.x) {
        velocity[0] = 1;
    }
    if (moveToCords[1] < collider.y) {
        velocity[1] = -1;
    } else if (moveToCords[1] > collider.y) {
        velocity[1] = 1;
    }

};

void Enemy::moveTo(direction moveDirection) {
    switch (moveDirection) {
        case Up:
            moveToCords[0] = collider.x;
            moveToCords[1] = collider.y - TILE_HEIGHT;
            break;
        case Down:
            moveToCords[0] = collider.x;
            moveToCords[1] = collider.y + TILE_HEIGHT;
            break;
        case Left:
            moveToCords[0] = collider.x - TILE_WIDTH;
            moveToCords[1] = collider.y;
            break;
        case Right:
            moveToCords[0] = collider.x + TILE_WIDTH;
            moveToCords[1] = collider.y;
    }
}

bool Enemy::isOnMove() {
    return !(moveToCords[0] == collider.x && moveToCords[1] == collider.y);
}

Enemy::Enemy(int type, int xInPixels, int yInPixels, int health) : Entity(type, xInPixels, yInPixels, health) {
    moveToCords[0] = collider.x;
    moveToCords[1] = collider.y;
}
