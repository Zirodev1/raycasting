#include <stdio.h>
#include <SDL2/SDL.h>
#include "constants.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
int isGameRunning = FALSE;

int initializeWindow(){
    if (SDL_INIT(SDL_INIT_EVERYTHING) != 0){
        fprintf(stderr, "Eror initializing SDL.\n");
        return FALSE;
    }
    window = SDL_CreateWIndow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGTH,
        SDL_WINDOW_FULLSCREEN
    );
    if(!window) {
        fprintf(stderr, "Error creating SDL window.\n");
        return FALSE;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer) {
        fprintf(stderr, "Error creating SDL renderer.\n");
        return FALSE;
    }
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    
    return TRUE;
}

void destroyWindow(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char *argv[]) {
    isGameRunning = initializeWindow();

    setup();

    while (isGameRunning) {

    }

    destroyWindow();

    return 0;
}
