#include "../include/main.h"

int main(void) {
    StateManager statemanager;
    STATEMANAGER_init(&statemanager);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
        STATEMANAGER_free(&statemanager);
        return 1;
    }

    Graphics graphics;
    if (Graphics_init(&graphics) != 0) {
        STATEMANAGER_free(&statemanager);
        SDL_Quit();
        return 1;
    }
    return 0;
}