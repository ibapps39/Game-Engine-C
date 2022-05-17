#ifndef ENGINE_GRAPHICS_H
#define ENGINE_GRAPHICS_H
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "../include/SDL2/SDL.h"
/*
Defining a SDL Window, SDL init function, and SDL_free function
*/
typedef struct {
  int width;
  int height;
  SDL_Window *window;
} Graphics;

int GRAPHIC_init(Graphics *graphics);
void GRAPHICS_free(Graphics *graphics);
#endif //ENGINE_GRAPHICS_H