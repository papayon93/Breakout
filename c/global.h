#include "struct.h"

#ifndef GLOBAL_H
#define GLOBAL_H

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern const int false;
extern const int true;

extern const int IMAGE_WIDTH;
extern const int IMAGE_HEIGHT;

extern SDL_Window* gWindow;

extern Ball ball;
  
extern SDL_Surface* gScreenSurface;

extern SDL_Surface* gJPGSurface;

extern SDL_Renderer* gRenderer;

extern SDL_Texture* gTexture;

extern Mix_Chunk *gSonidoMoneda;
extern Mix_Chunk *gSonidoSalto;
extern Mix_Chunk *gSonidoVida;

extern int Move_Right;
extern int Move_Left;

#endif