#ifndef bg_H_INCLUDED
#define bg_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "ES.h"



typedef struct
{

    SDL_Surface *image;
	    SDL_Surface *imagemask;
    SDL_Rect positionbackground;
    SDL_Rect positionback_partage;
    SDL_Rect camera;
    SDL_Rect camera2;

} background;



typedef struct
{

    int left, right,up,down,d,q,z,s;

} mouvement;



void initBack(background *b);
void initBackpartage(background *b);
void afficherBack(SDL_Surface *screen, background *b);
void afficherBackpartage(SDL_Surface *screen,background *b);
void scrollingright(background *b, SDL_Surface *screen, mouvement M, float speed,int colpp);
void scrollingrightpartage(background *b, SDL_Surface *screen, mouvement M, float speed,int colpp);
void scrollingleft(background *b, SDL_Surface *screen, mouvement M, float speed,int colpp);
void scrollingleftpartage(background *b, SDL_Surface *screen, mouvement M, float speed,int colpp);
void scrollingup(background *b, SDL_Surface *screen, mouvement M, float speed,int colpp);
void scrollinguppartage(background *b, SDL_Surface *screen, mouvement M, float speed,int colpp);
void scrollingdown(background *b, SDL_Surface *screen, mouvement M, float speed,int colpp);
void scrollingdownpartage(background *b, SDL_Surface *screen, mouvement M, float speed,int colpp);
void init_Mouvement(mouvement *M);

void freebackground(background *b);



#endif
