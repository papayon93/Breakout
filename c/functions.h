/*
 * funcoes.h
 * 
 * Copyright 2016 Adriano Cruz <adriano@nce.ufrj.br>
 * 
 */

#ifndef Functions_H
#define Functions_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h> 
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "struct.h"
#include "global.h"

void moveBall(Ball *p);
Ball createBall( int posX, int posY, int stepX, int stepY, SDL_Surface *image);
int init();
int loadMedia();
void closing();
SDL_Surface* loadSurface( char *path);

#endif
