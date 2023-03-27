#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "ES.h"


void initBack(background *b)
{

    b->image = IMG_Load("backg/desert.png"); 

b->imagemask = IMG_Load("backg/masklvl1.png");
    b->positionbackground.x = 0;
    b->positionbackground.y = 0;
    b->positionbackground.w = 0;
    b->positionbackground.h = 0;

    b->camera.x = 0;
    b->camera.y = 0;
    b->camera.w = 1800;
    b->camera.h = 1000;






}


void afficherBack(SDL_Surface *screen, background *b)
{

    SDL_BlitSurface(b->image, &b->camera, screen, &b->positionbackground);

}



void scrollingright(background *b, SDL_Surface *screen, mouvement M, float speed,int colpp)
{   if (colpp!=2) {
    if (M.right == 1 )
    {
        if (b->camera.x < 15780-1800)
        {
            b->camera.x += speed;
        }
    }
}
}




void scrollingleft(background *b, SDL_Surface *screen, mouvement M, float speed,int colpp)
{
 if (colpp!=2) {
    if (M.left == 1)
    {
        if (b->camera.x > 0)
        {
            b->camera.x -= speed;
        }
    }
}
}



void scrollingup(background *b, SDL_Surface *screen, mouvement M, float speed,int colpp)
{
 if (colpp!=2) {
    if (M.up == 1)
    {
        if (b->camera.y > 0)
        {
            b->camera.y -= speed;
        }
    }
}
}



void scrollingdown(background *b, SDL_Surface *screen, mouvement M, float speed,int colpp)
{ if (colpp!=2) {
    if (M.down == 1 )
    {
        if (b->camera.y < 600 - 528)
        {
            b->camera.y += speed;
        }
    }
}
}



void init_Mouvement(mouvement *M)
{
    M->left = 0;
    M->right = 0;

    M->up = 0;
    M->down = 0;

    M->z = 0;
    M->s = 0;

    M->d = 0;
    M->q = 0;

}





void initBackpartage(background *b)

{




    b->image = IMG_Load("backg/desert.png"); 


    b->positionbackground.x = 0;
    b->positionbackground.y = 0;
    b->positionbackground.w = 0;
    b->positionbackground.h = 0;

    b->camera.x = 0;
    b->camera.y = 0;
    b->camera.w = 900;
    b->camera.h = 1000;


    b->positionback_partage.x = 900;
    b->positionback_partage.y = 0;
    b->positionback_partage.h = 0;
    b->positionback_partage.w = 0;

    b->camera2.x = 0;
    b->camera2.y = 0;
    b->camera2.w = 900;
    b->camera2.h = 1000;




}








void afficherBackpartage(SDL_Surface *screen,background *b)
{


    SDL_BlitSurface(b->image, &b->camera2, screen, &b->positionback_partage);
}


void scrollingrightpartage(background *b, SDL_Surface *screen, mouvement M, float speed,int colpp)
{
 if (colpp!=2) {
    if (M.d == 1)
    {
        if (b->camera2.x < 15780 - 900)
        {
            b->camera2.x += speed;
        }
    }
}
}


void scrollingleftpartage(background *b, SDL_Surface *screen, mouvement M, float speed,int colpp)
{
 if (colpp!=2) {
    if (M.q == 1)
    {
        if (b->camera2.x > 0)
        {
            b->camera2.x -= speed;
        }
    }
}
}




void scrollinguppartage(background *b, SDL_Surface *screen, mouvement M, float speed,int colpp)
{
 if (colpp!=2) {
    if (M.z == 1)
    {
        if (b->camera2.y > 0)
        {
            b->camera2.y -= speed;
        }
    }
}
}



void scrollingdownpartage(background *b, SDL_Surface *screen, mouvement M, float speed,int colpp)
{
 if (colpp!=2) {
    if (M.s == 1 )
    {
        if (b->camera2.y < 600 - 528)
        {
            b->camera2.y += speed;
        }
    }
}
}






void freebackground(background *b)

{
 SDL_FreeSurface (b->image) ;
}
