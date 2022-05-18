#include "../include/Graphics.h"
/*
Initializes a SDL Window and handles null/error windows.
*/
int GRAPHICS_init(Graphics *graphics){
    graphics->window = SDL_CreateWindow(
        "C Engine With SDL2",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_SHOWN
    );
/*
Error Handling
*/
    if(graphics->window == NULL){
        printf("Error: %s\n", SDL_GetError());
        SDL_Log("Unable to create window: %s\n", SDL_GetError());
        return 1;
    }

    return 0;
}
void GRAPHICS_free(Graphics *graphics){
    SDL_DestroyWindow(graphics->window);
}