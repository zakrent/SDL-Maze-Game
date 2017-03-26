//
// Created by zakrent on 3/18/17.
//

#include "Map.h"


void Map::generateMap() {
    //temp
    for (int i = 0; i < 10; ++i) {
        for (int a = 0; a < 10; ++a) {
            tiles.push_back(Tile(i, a, 0));
        }
    }
    tiles[10].type = 1;// debug
    entities.push_back(Entity(0,32,32));
    //TODO: Remove debug
}

void Map::updateEntities() {
    for(Entity &entity : entities){
        entity.update();
    }
}

void Map::render(SDL_Renderer& renderer, SDL_Rect& camera, SDL_Texture* TileSheet, SDL_Texture* EntitySheet) {
    for (Tile &tile : tiles) {
        //TODO: Check if tile is in camera view then render
        tile.render(renderer, camera, TileSheet);
    }
    for(Entity &entity : entities){
        entity.render(renderer, camera, EntitySheet);
    }

}

Map::Map() {
    generateMap();
}

