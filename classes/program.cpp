//
// Created by zakrent on 3/18/17.
//
#include "program.h"

void Program::startMainLoop() {
    running = true;
    while(running){
        handleEvents();
        render();
    }
    return;
}

void Program::render() {
    SDL_RenderClear(renderer);
    map.render(*renderer, camera, texture);
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

void Program::loadTextures(SDL_Renderer& renderer) {
    //temp
    SDL_Texture* tempTexture = NULL;
    SDL_Surface* tempSurface = NULL;
    tempSurface = SDL_LoadBMP("tex.bmp");
    tempTexture = SDL_CreateTextureFromSurface(&renderer, tempSurface);
    texture[0] = tempTexture;
    SDL_FreeSurface(tempSurface);
    tempSurface = NULL;
}

Program::Program() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    loadTextures(*renderer);
}

Program::~Program() {
    for (auto tex : texture) {
        SDL_DestroyTexture(tex);
    }
    SDL_Quit();
}



