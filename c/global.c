#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h> 
#include "global.h"
#include "struct.h"

/*Screen dimension constants*/
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int false = 0;
const int true = 1;

const int IMAGE_WIDTH = 61;
const int IMAGE_HEIGHT = 61;

/*The window we'll be rendering to*/
SDL_Window* gWindow = NULL;

/*The imagem character*/
Ball ball;
  
/*The surface contained by the window*/
SDL_Surface* gScreenSurface = NULL;

/*Current displayed PNG image*/
SDL_Surface* gJPGSurface = NULL;

/*The sound effects that will be used*/
Mix_Chunk *gSonidoMoneda = NULL;
Mix_Chunk *gSonidoSalto = NULL;
Mix_Chunk *gSonidoVida = NULL;