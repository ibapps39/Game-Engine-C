#ifndef ENGINE_GRAPHICS_H
#define ENGINE_GRAPHICS_H
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "../include/SDL2/SDL.h"
/*
Defining a SDL Window, SDL init function, and SDL_free function
*/

/*
Dimensional struct for a SDL Window
*/
typedef struct {
  int width;
  int height;
  SDL_Window *window;
} Graphics;
/*
Initializes an SDL Window to the Graphics pointer variable 
and returns 0 if successful. 
*/
int GRAPHIC_init(Graphics *graphics);
/*
Frees allocated memory for a SDL Window that was assigned 
to the Graphics pointer.
*/
void GRAPHICS_free(Graphics *graphics);
#endif //ENGINE_GRAPHICS_H