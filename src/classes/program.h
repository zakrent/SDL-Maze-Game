//
// Created by zakrent on 3/18/17.
//

#ifndef SDL_1_PROGRAM_H
#define SDL_1_PROGRAM_H

#include <SDL2/SDL.h>
#include "Map.h"

class Program {
private:
    Map map;
    SDL_Window *window;
    bool running = false;
    void render();
    void handleEvents();
public:
    const int SCREEN_WIDTH  = 640;
    const int SCREEN_HEIGHT = 480;
    SDL_Renderer *renderer;
    SDL_Texture *TileSheet;
    SDL_Texture *EntitySheet;
    SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    void loadTextures(SDL_Renderer& renderer);
    void startMainLoop();
    Program();
    ~Program();

    void calculateCameraPos();
};


#endif //SDL_1_PROGRAM_H
