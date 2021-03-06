//
// Created by zakrent on 3/18/17.
//
#include <random>
#include "Map.h"
#include "../entities/Enemy.h"

std::vector < Tile* > Map::generateNodeRow(Tile* firstNode){
    std::vector < Tile* > newRow;
    Tile* currentNode = firstNode;
    while(currentNode && currentNode->type!=2){
        newRow.push_back(currentNode);
        currentNode = getNeighbouringTile(Right, getNeighbouringTile(Right, currentNode));
    }
    return newRow;
};

void Map::generateMap() {

    for (int i = 0; i < MAP_WIDTH; ++i) {
        for (int a = 0; a < MAP_HEIGHT; ++a) {
            tiles.push_back(new Tile(i, a, 1));
            if (a == 0 || i == 0 || i == MAP_WIDTH - 1 || a == MAP_HEIGHT - 1) {
                tiles.back()->type = 2;
            }
        }
    }

    std::vector < std::vector < Tile* >  > nodeRows;
    Tile *firstNode = getNeighbouringTile(Down, getNeighbouringTile(Right, tiles.front()));
    while(firstNode && firstNode->type != 2){
        nodeRows.push_back(generateNodeRow(firstNode));
        firstNode = getNeighbouringTile(Down, getNeighbouringTile(Down, firstNode));
    }
    int group = 0;
    for(auto nodeRow : nodeRows){
        for(auto node : nodeRow){
            node->type=0;
            node->group=group;
            group++;
        }
    }
    int elementsInRow = nodeRows.front().size();
    int numberOfRows = nodeRows.size();

    std::random_device randomGenerator;
    std::uniform_int_distribution<int> elementsInRowDistributionLower(0,elementsInRow-2);
    std::uniform_int_distribution<int> numberOfRowsDistributionLower(0,numberOfRows-2);
    std::uniform_int_distribution<int> elementsInRowDistribution(0,elementsInRow-1);
    std::uniform_int_distribution<int> numberOfRowsDistribution(0,numberOfRows-1);

    Tile* currentNodes[2] = {NULL, NULL};
    bool done = false;
    int nodeCords[2];
    int pass = 0;
    while(!done){
        if(pass % 2 == 0) {
            nodeCords[0] = numberOfRowsDistribution(randomGenerator);
            nodeCords[1] = elementsInRowDistributionLower(randomGenerator);
            currentNodes[0] = nodeRows[nodeCords[0]][nodeCords[1]];
            currentNodes[1] = nodeRows[nodeCords[0]][nodeCords[1]+1];

        }else{
            nodeCords[0] = numberOfRowsDistributionLower(randomGenerator);
            nodeCords[1] = elementsInRowDistribution(randomGenerator);
            currentNodes[0] = nodeRows[nodeCords[0]][nodeCords[1]];
            currentNodes[1] = nodeRows[nodeCords[0]+1][nodeCords[1]];
        }
        if(currentNodes[0]->group != currentNodes[1]->group){
            if(pass % 2 == 0) {
                getNeighbouringTile(Right, currentNodes[0])->type=0;
            }else {
                getNeighbouringTile(Down, currentNodes[0])->type = 0;
            }
            int node1Group = currentNodes[1]->group;
            for(auto nodeRow : nodeRows){
                for(auto node : nodeRow){
                    if(node->group == node1Group){
                        node->group = currentNodes[0]->group;
                    }
                }
            }
        }
        done = true;
        for(auto nodeRow : nodeRows){
            for(auto node : nodeRow){
                if(node->group != nodeRows.front().front()->group){
                    done = false;
                    break;
                }
            }
        }
        pass++;
    }
    nodeRows.back().back()->type = 3;
    for (int j = 0; j < 4; ++j) {
        nodeCords[0] = numberOfRowsDistribution(randomGenerator);
        nodeCords[1] = elementsInRowDistribution(randomGenerator);
        nodeRows[nodeCords[0]][nodeCords[1]]->type = 4;
    }
}

void Map::update() {
    players.front()->handleControll();
    updateEntities();
    checkCollisions();
}

void Map::updateEntities() {
    for (Entity *entity : entities) {
        entity->update(*this);
    }
    for (Player *player : players) {
        player->update(*this);
    }
}

bool isPointInRectangle(SDL_Rect& collider, int pointX, int pointY){
    return bool
            (abs(pointX) >= abs(collider.x)            &&
             abs(pointX) <= abs(collider.x+collider.w) &&
             abs(pointY) >= abs(collider.y)            &&
             abs(pointY) <= abs(collider.y+collider.h));

}

bool Map::checkIfCollidersColide(SDL_Rect& colliderA, SDL_Rect& colliderB) {
    return bool
            (isPointInRectangle(colliderA, colliderB.x+1, colliderB.y+1)             ||
             isPointInRectangle(colliderA, colliderB.x+colliderB.w-1, colliderB.y+1) ||
             isPointInRectangle(colliderA, colliderB.x+1, colliderB.y+colliderB.h-1) ||
             isPointInRectangle(colliderA, colliderB.x+colliderB.w-1, colliderB.y+colliderB.h-1)
            );
}

void Map::checkCollisions() {
    for (Entity *entity : entities) {
        for (Tile *tile : tiles) {
            if (checkIfCollidersColide(tile->collider, entity->collider)) {
                entity->handleTileCollision(*tile);
            }
        }
    }
    for (Entity *player : players) {
        for (Tile *tile : tiles) {
            if (checkIfCollidersColide(tile->collider, player->collider)) {
                player->handleTileCollision(*tile);
            }
        }
    }
}

Tile* Map::getNeighbouringTile(direction directionToNeighbour, Tile* mainTile) {
    if(mainTile == NULL){
        return NULL;
    }
    Tile *neighbourTile = NULL;
    SDL_Rect offsetCollider;
    offsetCollider = mainTile->collider;
    switch(directionToNeighbour){
        case Up:
            offsetCollider.y -= TILE_HEIGHT;
            break;
        case Down:
            offsetCollider.y += TILE_HEIGHT;
            break;
        case Right:
            offsetCollider.x += TILE_WIDTH;
            break;
        case Left:
            offsetCollider.x -= TILE_WIDTH;
        }
    for (Tile *tile : tiles) {
        if (checkIfCollidersColide(offsetCollider, tile->collider)) {
            neighbourTile = tile;
        }
    }
    return neighbourTile;
}


void Map::render(SDL_Renderer& renderer, SDL_Rect& camera, SDL_Texture* TileSheet, SDL_Texture* EntitySheet) {
    for (Tile *tile : tiles) {
        if (checkIfCollidersColide(camera, tile->collider)) {
            tile->render(renderer, camera, TileSheet);
        }
    }
    for (Entity *entity : entities) {
        if (checkIfCollidersColide(camera, entity->collider)) {
            entity->render(renderer, camera, EntitySheet);
        }
    }
    for (Player *player : players) {
        if (checkIfCollidersColide(camera, player->collider)) {
            player->render(renderer, camera, EntitySheet);
        }
    }

}

Map::Map() {
    generateMap();
    players.push_back(new Player(0, 32, 32, 50));
    for (auto tile : tiles) {
        if (tile->type == 4) {
            entities.push_back(new Enemy(1, tile->collider.x, tile->collider.y));
        }
    }
}

void Map::calculateDistancesFromPlayer() {
    for (Tile *tile : tiles) {
        tile->distanceFromPlayer = -1;
    }
    calculateTileDistanceFromPlayer(players.front()->isStandingOn, -1);
}

void Map::calculateTileDistanceFromPlayer(Tile *StartTile, int previousDistance) {
    if (previousDistance > 20 || StartTile == NULL) {
        return;
    } else if ((StartTile->distanceFromPlayer > previousDistance || StartTile->distanceFromPlayer == -1)) {
        StartTile->distanceFromPlayer = previousDistance + 1;
        if (!StartTile->isSolid()) {
            calculateTileDistanceFromPlayer(getNeighbouringTile(Up, StartTile), previousDistance + 1);
            calculateTileDistanceFromPlayer(getNeighbouringTile(Right, StartTile), previousDistance + 1);
            calculateTileDistanceFromPlayer(getNeighbouringTile(Left, StartTile), previousDistance + 1);
            calculateTileDistanceFromPlayer(getNeighbouringTile(Down, StartTile), previousDistance + 1);
        }
    }

}
