/*
 * funcoes.c
 * 
 * Copyright 2016 Adriano Cruz <adriano@nce.ufrj.br>
 * 
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h> 
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "struct.h"
#include "global.h"

void moveBall(Ball *p) {
    p->posX += p->stepX;
    p->posY += p->stepY;
    
    if ( (p->posX + IMAGE_WIDTH > SCREEN_WIDTH) ||
         (p->posX < 0) ) {
        Mix_PlayChannel( -1, gSonidoMoneda, 0 );
        p->stepX = -p->stepX;
        p->posX += p->stepX; 
    }
    if ( (p->posY + IMAGE_HEIGHT > SCREEN_HEIGHT) ||
         (p->posY < 0) ) {
        if(p->posY < 0){
            Mix_PlayChannel( -1, gSonidoSalto, 0 );
        }
        else{
            Mix_PlayChannel( -1, gSonidoVida, 0 );
        }
        p->stepY = -p->stepY;
        p->posY += p->stepY;
    }   
}

Ball createBall( int posX, int posY, int stepX, int stepY, SDL_Surface *image) {
    
    Ball p;
    p.posX = posX;
    p.posY = posY;
    p.stepX = stepX;
    p.stepY = stepY;
    p.image = image;
    return p;
}

int init() {
    /*Initialization flag*/
    /*int success = true;*/
    int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;

    srand(time(NULL));

    /*Initialize SDL*/
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 ) {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        /*success = false;*/
        return false;
    }
    /*else {*/
        /*Create window*/
    gWindow = SDL_CreateWindow( "SDL Tutorial: BreakOut", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL ) {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        /*success = false;*/
        return false;
    }
    /*else { */
        /*Initialize JPG and PNG loading */
    if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        /*success = false;*/
        return false;
    }
    /*Initialize SDL_mixer*/
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }
    /*else { */
        /*Get window surface*/
    gScreenSurface = SDL_GetWindowSurface( gWindow );
    /*}*/
    /*}*/
    /*}*/

   

    /*return success;*/
    return true;
}


SDL_Surface* loadSurface( char *path ) {
    /*The final optimized image*/
    SDL_Surface* optimizedSurface = NULL;

    /*Load image at specified path*/
    SDL_Surface* loadedSurface = IMG_Load( path );
    if( loadedSurface == NULL ) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
    }
    else {
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0x00, 0xFF, 0xFF ) );
        /*Convert surface to screen format*/
        optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
        if( optimizedSurface == NULL ) {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path, SDL_GetError() );
        }

        /*Get rid of old loaded surface*/
        SDL_FreeSurface( loadedSurface );
    }

    return optimizedSurface;
}

int loadMedia() {
    /*Loading success flag*/
    int success = true;
    /*uint32_t colorKey;*/
    
    /*Load PNG surface*/
    gJPGSurface = loadSurface( "./assets/circle.jpeg" );
    if( gJPGSurface == NULL ) {
        printf( "Failed to load image! SDL Error: %s\n", SDL_GetError() );
        success = false;
    } 

    gSonidoSalto = Mix_LoadWAV( "./assets/salto.wav" );
    if( gSonidoSalto == NULL ) {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    } 

    gSonidoVida = Mix_LoadWAV( "./assets/vida.wav" );
    if( gSonidoVida == NULL ) {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    } 

    gSonidoMoneda = Mix_LoadWAV( "./assets/moneda.wav" );
    if( gSonidoMoneda == NULL ) {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    } 
    return success;
}

void closing() {
    /*Free loaded image*/
    SDL_FreeSurface( gJPGSurface );
    gJPGSurface = NULL;

    /*Destroy window*/
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    /*Quit SDL subsystems*/
    IMG_Quit();
    SDL_Quit();
}
