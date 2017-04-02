//
// Created by zakrent on 3/18/17.
//
#include "program.h"

void Program::startMainLoop() {
    running = true;
    Uint32 minUpdateTime = 10;
    Uint32 updateStartedAt;
    while(running){
        updateStartedAt = SDL_GetTicks();
        map.players.front().handleControll();
        map.updateEntities();
        map.checkCollisions();
        handleEvents();
        render();
        if(!SDL_TICKS_PASSED(SDL_GetTicks()+1, updateStartedAt+minUpdateTime)){
            SDL_Delay((updateStartedAt+minUpdateTime)-SDL_GetTicks());
        }
    }
}

void Program::render() {
    SDL_RenderClear(renderer);
    map.render(*renderer, camera, TileSheet, EntitySheet);
    SDL_RenderPresent(renderer);
}

void Program::handleEvents() {
    SDL_Event event;
    while( SDL_PollEvent( &event) != 0 ) {
        switch(event.type){
            case SDL_QUIT:
                running = false;
                break;
            default:
                break;
        }
    }
}

SDL_Texture* loadTexture(SDL_Renderer& renderer, char fileName[]){
    SDL_Texture* tempTexture = NULL;
    SDL_Surface* tempSurface = NULL;
    tempSurface = SDL_LoadBMP(fileName);
    tempTexture = SDL_CreateTextureFromSurface(&renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    tempSurface = NULL;
    return tempTexture;
}

void Program::loadTextures(SDL_Renderer& renderer) {
    TileSheet = loadTexture(renderer, "textures/TileSheet.bmp");
    EntitySheet = loadTexture(renderer, "textures/EntitySheet.bmp");
}

Program::Program() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    loadTextures(*renderer);
}

Program::~Program() {
    SDL_DestroyTexture(TileSheet);
    SDL_Quit();
}




