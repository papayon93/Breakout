#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h> 
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "c/struct.h"
#include "c/global.h"
#include "c/functions.h"

int main( int argc, char* args[] ) {
    SDL_Rect srcRect, dstRect;
    int quit;
    /*Event handler*/
    SDL_Event e;
    
    /*Start up SDL and create window*/
    if( !init() ) {
        printf( "Failed to initialize!\n" );
    }
    else {
        /*Load media*/
        if( !loadMedia() ) {
            printf( "Failed to load media!\n" );
        }
        else {   
            ball = createBall(rand() % (SCREEN_WIDTH - IMAGE_WIDTH), 
                             rand() % (SCREEN_HEIGHT - IMAGE_HEIGHT), 
                             rand() % 2 ? -1: 1, 
                             rand() % 2 ? -1: 1, 
                             gJPGSurface);

            /*Main loop flag*/
            quit = false;

            

            /*While application is running*/
            while( !quit ) {
                while( SDL_PollEvent( &e ) != 0 ) {
                    switch (e.type) {
                        case SDL_QUIT:
                            quit = true;
                            break;
                        case SDL_KEYDOWN:
                            if (e.key.keysym.sym == SDLK_ESCAPE) {
                                quit = true;
                            }
                        break;
                    }
                }
            
                /*Fill the surface white*/
                SDL_FillRect( gScreenSurface, NULL, 
                              SDL_MapRGB( gScreenSurface->format, 
                              0x00, 0xFF, 0xFF ) );

                moveBall(&ball);

                srcRect.x = 0; srcRect.y = 0;
                srcRect.w = IMAGE_WIDTH;
                srcRect.h = IMAGE_HEIGHT;
                dstRect.x = ball.posX;
                dstRect.y = ball.posY;

                if( SDL_BlitSurface( ball.image, &srcRect, 
                                     gScreenSurface, &dstRect ) < 0 ) {
                    printf( "SDL could not blit! SDL Error: %s\n", SDL_GetError() );
                    quit = true;
                }

                /*Update the surface*/
                SDL_UpdateWindowSurface( gWindow );
                
                /* Not so good solution, depends on your computer*/
                SDL_Delay(5);
            }
        }
    }

    /*Free resources and closing SDL*/
    closing();

    return 0;
}