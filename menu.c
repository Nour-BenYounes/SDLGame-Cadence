/**

* @file menu.c
*/



#include "header.h"

void initButtons(image *A, image *B, image *C, image *D, image *E, image *F)
{


	A->img = IMG_Load("1x/nplay.png");
	if (A->img == NULL)
	{
		return;
	}
	A->pos.x = 85;
	A->pos.y = 401;

	B->img = IMG_Load("1x/nsettings.png");
	if (B->img == NULL)
	{
		return;
	}
	B->pos.x = 85;
	B->pos.y = 512;

	C->img = IMG_Load("1x/nquit.png");
	if (C->img == NULL)
	{
		return;
	}
	C->pos.x = 85;
	C->pos.y = 734;

	D->img = IMG_Load("1x/Musicon.png");
	if (D->img == NULL)
	{
		return;
	}
	D->pos.x = 1350;
	D->pos.y = 30;

	E->img = IMG_Load("1x/ncredit.png");
	if (D->img == NULL)
	{
		return;
	}
	E->pos.x = 85;
	E->pos.y = 623;

	F->img = IMG_Load("1x/Tunisia_logo.png");
	if (D->img == NULL)
	{
		return;
	}
	F->pos.x = 1270;
	F->pos.y = 170;
}
void initBackground(image *Backg)
{
	Backg->img = IMG_Load("1x/fond.png");
	if (Backg->img == NULL)
	{
		printf("Unable to load : %s\n", SDL_GetError());
		return;
	}
	Backg->pos.x = 0;
	Backg->pos.y = 0;
	/*Backg->pos.w=(SCREEN_W);
	Backg->pos.h=SCREEN_H;*/
}
void libererButtons(image A, image B, image C, image E, image F, image G)
{
	SDL_FreeSurface(A.img);
	SDL_FreeSurface(B.img);
	SDL_FreeSurface(C.img);
	SDL_FreeSurface(E.img);
	SDL_FreeSurface(F.img);
	SDL_FreeSurface(G.img);
}
void afficher(image p, SDL_Surface *screen)
{
	SDL_BlitSurface(p.img, NULL, screen, &p.pos);
}
void afficherparposition(int position, image *A, image *B, image *C, image *D)
{

	switch (position)
	{
	case 1:
		A->img = IMG_Load("1x/Play.png");
		B->img = IMG_Load("1x/nsettings.png");
		C->img = IMG_Load("1x/ncredit.png");
		D->img = IMG_Load("1x/nquit.png");
		break;
	case 2:
		A->img = IMG_Load("1x/nplay.png");
		B->img = IMG_Load("1x/Settings.png");
		C->img = IMG_Load("1x/ncredit.png");
		D->img = IMG_Load("1x/nquit.png");
		break;
	case 3:
		A->img = IMG_Load("1x/nplay.png");
		B->img = IMG_Load("1x/nsettings.png");
		C->img = IMG_Load("1x/Credit.png");
		D->img = IMG_Load("1x/nquit.png");
		break;
	case 4:
		A->img = IMG_Load("1x/nplay.png");
		B->img = IMG_Load("1x/nsettings.png");
		C->img = IMG_Load("1x/ncredit.png");
		D->img = IMG_Load("1x/quit.png");
		break;
	}
}

void closeEverything()
{
	// atexit(Mix_Quit);
	atexit(IMG_Quit);
	atexit(SDL_Quit);
}
