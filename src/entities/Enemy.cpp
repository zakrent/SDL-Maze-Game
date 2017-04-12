//
// Created by zakrent on 4/8/17.
//

#include "Enemy.h"

void Enemy::update(Map &mainMap) {
    chasePlayer(mainMap);
    calculateMovementVelocity();
    updatePhysics();
    if (isStandingOn) {
        if (isStandingOn->distanceFromPlayer == 0) {
            if (mainMap.players.front())
                mainMap.players.front()->takeDamage(10);
        }
    }
}


void Enemy::chasePlayer(Map &mainMap) {
    if (isOnMove() || isStandingOn == NULL)
        return;
    bool shouldMove = false;
    int smallestDistanceFromPlayer = 1000;
    direction smallestDistanceFromPlayerDirection;
    Tile *up, *right, *left, *down;
    up = mainMap.getNeighbouringTile(Up, isStandingOn);
    right = mainMap.getNeighbouringTile(Right, isStandingOn);
    left = mainMap.getNeighbouringTile(Left, isStandingOn);
    down = mainMap.getNeighbouringTile(Down, isStandingOn);

    if (isStandingOn != NULL)
        if (!isStandingOn->isSolid() && isStandingOn->distanceFromPlayer != -1 &&
            isStandingOn->distanceFromPlayer < smallestDistanceFromPlayer) {
            smallestDistanceFromPlayer = isStandingOn->distanceFromPlayer;
            shouldMove = false;
        }
    if (up != NULL)
        if (!up->isSolid() && up->distanceFromPlayer != -1 && up->distanceFromPlayer < smallestDistanceFromPlayer) {
            smallestDistanceFromPlayer = up->distanceFromPlayer;
            smallestDistanceFromPlayerDirection = Up;
            shouldMove = true;
        }
    if (down != NULL)
        if (!down->isSolid() && down->distanceFromPlayer != -1 &&
            down->distanceFromPlayer < smallestDistanceFromPlayer) {
            smallestDistanceFromPlayer = down->distanceFromPlayer;
            smallestDistanceFromPlayerDirection = Down;
            shouldMove = true;
        }
    if (right != NULL)
        if (!right->isSolid() && right->distanceFromPlayer != -1 &&
            right->distanceFromPlayer < smallestDistanceFromPlayer) {
            smallestDistanceFromPlayer = right->distanceFromPlayer;
            smallestDistanceFromPlayerDirection = Right;
            shouldMove = true;
        }
    if (left != NULL)
        if (!left->isSolid() && left->distanceFromPlayer != -1 &&
            left->distanceFromPlayer < smallestDistanceFromPlayer) {
            smallestDistanceFromPlayer = left->distanceFromPlayer;
            smallestDistanceFromPlayerDirection = Left;
            shouldMove = true;
        }

    if (shouldMove) {
        moveTo(smallestDistanceFromPlayerDirection);
    }
}

void Enemy::calculateMovementVelocity() {
    velocity[0] = 0;
    velocity[1] = 0;
    int velMul = 2;
    if (moveToCords[0] < collider.x) {
        velocity[0] = -1 * velMul;
    } else if (moveToCords[0] > collider.x) {
        velocity[0] = 1 * velMul;
    }
    if (moveToCords[1] < collider.y) {
        velocity[1] = -1 * velMul;
    } else if (moveToCords[1] > collider.y) {
        velocity[1] = 1 * velMul;
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
