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
                             gJPGSurface,gTexture);

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
                            switch( e.key.keysym.sym )
                            {
                                case SDLK_LEFT:
                                moveControl(&ball, Move_Left);
                                break;

                                case SDLK_RIGHT:
                                moveControl(&ball, Move_Right);
                                break;

                                case SDLK_ESCAPE:
                                quit = true;
                                break;

                                //default:
                                //gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                                //break;
                            }
                        break;
                    }
                }

                //Colocar una Imagen en el ScreenSurface
                //SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
            
                /*Fill the surface white*/
                SDL_FillRect( gScreenSurface, NULL, SDL_MapRGB( gScreenSurface->format, 0x00, 0xFF, 0xFF ) );

                //moveBall(&ball);

                srcRect.x = 0; srcRect.y = 0;
                srcRect.w = IMAGE_WIDTH;
                srcRect.h = IMAGE_HEIGHT;
                dstRect.x = ball.posX;
                dstRect.y = ball.posY;

                //Redimensiona la imagen y la pinta en el Surface con las coordenadas y el tamaño que coloque en srcRect, para moverla solo muevo el srcRect.x y srcRect.y
                //SDL_BlitScaled( ball.image, NULL, gScreenSurface, &srcRect );

                if( SDL_BlitSurface( ball.image, &srcRect, gScreenSurface, &dstRect ) < 0 ) {
                    printf( "SDL could not blit! SDL Error: %s\n", SDL_GetError() );
                    quit = true;
                }

                /*Update the surface*/
                SDL_UpdateWindowSurface( gWindow );


                //Clear screen
                //SDL_RenderClear( gRenderer );

                //Render texture to screen
                //SDL_RenderCopy( gRenderer, ball.texture, NULL, &dstRect );
                /*if( SDL_RenderCopy( gRenderer, ball.texture, &srcRect, &dstRect ) < 0 ) {
                    printf( "SDL could not Render! SDL Error: %s\n", SDL_GetError() );
                    quit = true;
                }*/

                //Update screen
                //SDL_RenderPresent( gRenderer );

                /* Not so good solution, depends on your computer*/
                SDL_Delay(5);
            }
        }
    }

    /*Free resources and closing SDL*/
    closing();

    return 0;
}