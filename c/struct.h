#ifndef Struct_H
#define Struct_H

typedef struct _Ball {
    int posX;
    int posY;
    int stepX;
    int stepY;
    SDL_Surface* image;
    SDL_Texture* texture;
    int imgW;
    int imgH;
} Ball;

#endif