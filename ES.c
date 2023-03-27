#include<stdio.h>
#include<stdlib.h>

#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>


#include "ES.h"
#include "header.h"


void initEnnemi(Ennemi*e)
{ 

    e->pos.x = 1700;
    e->pos.y = 520;
    e->pos.w = 249; //82
    e->pos.h = 251; //86
    e->col = 0;
    e->death=0;
    e->animation.spriteSheet[0] = IMG_Load("ES/rightidle.png");
    e->animation.spriteSheet[1] = IMG_Load("ES/runright.png");
    e->animation.spriteSheet[2] = IMG_Load("ES/runleft.png");
    e->animation.spriteSheet[3] = IMG_Load("ES/attackright.png");
    e->animation.spriteSheet[4] = IMG_Load("ES/attackleft.png");
   // e->animation.spriteSheet[5] = IMG_Load("ES/deathleft.png");

    e->animation.frames = 5;
    e->animation.side = 1; //droite
    e->animation.clipLoaded = 0;
	
	e->state = WAITING;

    generate_Clips(e->animation.Clips, e->animation.frames, 249, 249, 251);

}




void generate_Clips(SDL_Rect Clips[], int frames, int frameWidth, int clipWidth, int clipHeight)
{
    int i, w;
    for (w = 0, i = 0; i < frames; i++, w += frameWidth)
    {
        Clips[i].x = w;
        Clips[i].y = 0;
        Clips[i].w = clipWidth;
        Clips[i].h = clipHeight;
    }
}








void afficherEnnemi(Ennemi e, SDL_Surface * screen,SDL_Rect back)
{
SDL_Rect draw={e.pos.x-back.x,e.pos.y-back.y,e.pos.h-back.h,e.pos.w-back.w};


SDL_BlitSurface(e.animation.spriteSheet[e.animation.side], &e.animation.Clips[e.animation.clipLoaded], screen, &e.pos);
}

void animerEnnemi( Ennemi * e)
{
SDL_Delay(50);
  e->animation.clipLoaded++;
    if (e->animation.clipLoaded >= e->animation.frames)
        e->animation.clipLoaded = 0;





}










void initCoin(PickUp *c)
{
    c->pos.x = 700;
    c->pos.y = 520;
    c->pos.w = 84;
    c->pos.h = 84;
    c->col = 0;
    c->type = 1;
    c->boost = 0;
    c->animation.spriteSheet[0] = IMG_Load("ES/coin.png");
    c->animation.frames = 6;
	c->animation.side = 0; 
    c->animation.clipLoaded = 0;

		

    generate_Clips(c->animation.Clips, c->animation.frames, 84, 84, 84);
}

void afficherCoin(PickUp c, SDL_Surface *screen,SDL_Rect back)
{SDL_Rect draw={c.pos.x-back.x,c.pos.y-back.y,c.pos.h-back.h,c.pos.w-back.w};
    SDL_BlitSurface(c.animation.spriteSheet[c.animation.side], &c.animation.Clips[c.animation.clipLoaded], screen, &c.pos);
}

void animerCoin(PickUp *c)
{
    SDL_Delay(50);
    c->animation.clipLoaded++;
    if (c->animation.clipLoaded >= c->animation.frames)
        c->animation.clipLoaded = 0;
}













void freeEnnemie(Ennemi e)
{

    SDL_FreeSurface(e.animation.spriteSheet[0]);
    SDL_FreeSurface(e.animation.spriteSheet[1]);
    SDL_FreeSurface(e.animation.spriteSheet[2]);
    SDL_FreeSurface(e.animation.spriteSheet[3]);


}

void freecoin(PickUp c)
{

    SDL_FreeSurface(c.animation.spriteSheet[0]);
}

























void deplacer( Ennemi * e)
{

int posmax=1500-64,posmin=500;      



if (e->animation.side == 1)
    {
        e->pos.x +=7;
        if (e->pos.x >= posmax)
            e->animation.side = 2;
    }
else if (e->animation.side == 2)
    {
        e->pos.x -=7;
        if (e->pos.x <= 0)
            e->animation.side = 1;



}



}



//perso //entite

int collisionBB(SDL_Rect posp, SDL_Rect pose)
{
    if ((posp.x > pose.x + pose.w) || ( posp.x + posp.w < pose.x )  || (posp.y > pose.y + pose.h ) || (posp.h + posp.y < pose.y))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}



void DeathEn( Ennemi * e, SDL_Rect posPerso)

{


if (e->pos.x ==posPerso.x)
            e->animation.side = 0;


}







void deplacerIA( Ennemi * e, SDL_Rect posPerso)
{

/*
 // player in aggro range and to the left of the enemy

 if (((e->pos.x - posPerso.x) < 200) && ((e->pos.x - posPerso.x) > 100) && e->animation.side == 1)
    {
       e->animation.side == 2;
        e->pos.x -= 10;


    }
    // player in aggro range and to the right of the enemy
    else if (((e->pos.x - posPerso.x) > -200) && ((e->pos.x - posPerso.x) < -100)&& e->animation.side == 2)
    {
       e->animation.side == 1;
        e->pos.x += 10;
    }
    // player out of aggro range
    else
    {
        deplacer(e);
    }


*/








	switch (e->state)
	{

	case WAITING:
		if (900 < e->pos.x) //left
		{
			
e->animation.side = 0;
animerEnnemi(e);
		}
	 if (1000 > e->pos.x) //right
		{
			
e->animation.side =0;
animerEnnemi(e);
		}

//animerEnnemi(e);
		break;

	case FOLLOWING:
		if (posPerso.x < e->pos.x)  //left
		{
			e->animation.side = 2;
				//animerEnnemi(e);
                      
			 // e->pos.x -= 10;
	//deplacer(e);
		}
		 if (posPerso.x > e->pos.x) //right
		{
			e->animation.side = 1;
	//animerEnnemi(e);
			 // e->pos.x += 10;
			
                      
	//deplacer(e);
		}
animerEnnemi(e);
deplacer(e);
		break;

	case ATTACKING:

		if (posPerso.x < e->pos.x)
		{
			e->animation.side = 4;
//animerEnnemi(e);
			  e->pos.x -= 4;
		}
		 if (posPerso.x > e->pos.x)
		{
			e->animation.side = 3;
//animerEnnemi(e);
			 e->pos.x += 4;
		}
animerEnnemi(e);
//deplacer(e);
		break;

	case ESCAPING:
		if (posPerso.x < e->pos.x)
		{
			e->animation.side = 2;
			//++(e->pos.x);
			 e->pos.x -= 20;
		}
		if (posPerso.x > e->pos.x)
		{
			e->animation.side = 1;
			//--(e->pos.x);
				 e->pos.x += 20;
		}

animerEnnemi(e);
//deplacer(e);
		break;

		break;
	}























}


void updateEnnemiState(Ennemi *e, int position,int att)
{





switch (e->state)
	{
	case WAITING:
		if (position > e->pos.x - 500 || position > e->pos.x + 500)
			e->state = WAITING;

		if ((position > e->pos.x - 500 && position < e->pos.x - 300) || (position > e->pos.x + 300 && position < e->pos.x + 500))
			e->state = FOLLOWING;
		break;

	case FOLLOWING:
		if ((position > e->pos.x - 500 && position < e->pos.x - 300) || (position > e->pos.x + 300 && position < e->pos.x + 500))
			e->state = FOLLOWING;
		if ((position > e->pos.x - 300 && position < e->pos.x) || (position > e->pos.x + 300 && position < e->pos.x))
			e->state = ATTACKING;
		break;

	case ATTACKING:
		if ((position > e->pos.x - 300 && position < e->pos.x) || (position > e->pos.x + 300 && position < e->pos.x))
			e->state = ATTACKING;
		if ((position > e->pos.x - 500 && position < e->pos.x - 300) || (position > e->pos.x + 300 && position < e->pos.x + 500))
			e->state = FOLLOWING;

		if (att== 1)//when attcked
			e->state = ESCAPING;
		break;

	case ESCAPING:
	if 	 (att== 1)
			e->state = ESCAPING;
		if ((position > e->pos.x - 500 && position < e->pos.x - 300) || (position > e->pos.x + 300 && position < e->pos.x + 500)&&(att=0))

			e->state = FOLLOWING;
	}
}













void scrolling_enemie(Ennemi *E,int direction,int pasAvancement){
  if (direction==1)
	{
		 E->pos.x += pasAvancement;
     //E->posmin.x += pasAvancement;
    // E->posmax.x += pasAvancement;
	}else if (direction==0)
	{
		E->pos.x -= pasAvancement;
   // E->posmin.x -= pasAvancement;
   // E->posmax.x -= pasAvancement;
	}
}






void scrolling_coin(PickUp *c,int direction,int pasAvancement){
  if (direction==1)
	{
		 c->pos.x += pasAvancement;
   
	}else if (direction==0)
	{
		c->pos.x -= pasAvancement;
   
	}
}


void scrolling_everything(SDL_Rect pos,int direction,int pasAvancement){

if (direction==1)
	{
		 pos.x += pasAvancement;
   
	}else if (direction==0)
	{
		pos.x -= pasAvancement;
   
	}
}





