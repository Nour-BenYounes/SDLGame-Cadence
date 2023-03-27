#include "header.h"

void initTextagent(text *A,text *B)
{
	A->position.x=650;
	A->position.y=100;
	A->textColor.r=255;
	A->textColor.g=255;
	A->textColor.b=0;
	A->font=TTF_OpenFont("ARIAL.ttf",70);

	
	B->position.x=600;
	B->position.y=420;
	B->textColor.r=255;
	B->textColor.g=255;
	B->textColor.b=0;
	B->font=TTF_OpenFont("ARIAL.ttf",70);

}
void freeTextagent(text A,text B)
{
	SDL_FreeSurface(A.surfaceTexte);
	SDL_FreeSurface(B.surfaceTexte);
}
void displayTextagent(text t,SDL_Surface *screen)
{
	t.surfaceTexte=TTF_RenderText_Solid(t.font,t.texte,t.textColor);
	SDL_BlitSurface(t.surfaceTexte,NULL,screen,&t.position);
}
void afficherparpositionagent(int position, image *A,image *B, image *C,image *D,image *E,image *F)
{
 switch (position)
 {
	case 1:
	A->img = IMG_Load("1x/save.png");
	B->img=IMG_Load("1x/unloaded.png");

	break;
	
	case 2:
	A->img = IMG_Load("1x/saveunselected.png");
	B->img=IMG_Load("1x/load.png");


	break;
	
	case 3:
	C->img = IMG_Load("1x/soloselected.png");
	D->img = IMG_Load("1x/duounselected.png");
	break;
	
	case 4:
	C->img = IMG_Load("1x/solounselected.png");
	D->img = IMG_Load("1x/duoselected.png");
	break;
	
	case 5:
	E->img = IMG_Load("1x/buttonplay.png");
	break;
	case 6:
	F->img = IMG_Load("1x/Menureturnselected.png");
	break;
	
 }
}
void initSettingsButtonsagent(image *A,image *B, image *C,image *D,image *E,image *F)
{
	A->img = IMG_Load("1x/saveunselected.png");
		if (A->img== NULL) {
			return ;
		}
	A->pos.x = 680;
	A->pos.y = 230;
	
	B->img = IMG_Load("1x/unloaded.png");
		if (B->img== NULL) {
			return ;
		}
	B->pos.x = 1080;
	B->pos.y = 230;

	C->img = IMG_Load("1x/solounselected.png");
		if (C->img== NULL) {
			return ;
		}
	C->pos.x = 630;
	C->pos.y = 530;

	D->img = IMG_Load("1x/duounselected.png");
		if (D->img== NULL) {
			return ;
		}
	D->pos.x = 1030;
	D->pos.y = 530;
	
E->img = IMG_Load("1x/buttonplayunselected.png");
		if (D->img== NULL) {
			return ;
		}
	E->pos.x = 850;
	E->pos.y = 750;

	F->img = IMG_Load("1x/Menureturnunselected.png");
		if (D->img== NULL) {
			return ;
		}
	F->pos.x = 100;
	F->pos.y = 100;
}
int paintOptionsScreenagent (SDL_Surface *screen,SDL_Event *event2,Mix_Chunk *chunk,int *gamemode)
{
SDL_Event event;
image save,load,solo,duo,start,backg,menu;
text perso,mode;


personne p;
background b;

strcpy (perso.texte,"Saving Game & Loading");
strcpy (mode.texte,"Choose a gamemode");
initBackground (&backg);
backg.img=IMG_Load ("1x/fond.png");
initTextagent (&perso,&mode);
initSettingsButtonsagent(&save,&load,&solo,&duo,&start,&menu);
int position=1;
while (1)
{
		afficher(backg,screen);
		afficher(save,screen);
		afficher(load,screen);
		afficher(solo,screen);
		afficher(duo,screen);
		afficher(start,screen);
		afficher(menu,screen);
		displayTextagent (perso,screen);
		displayTextagent (mode,screen);
		SDL_Flip (screen);
		int x=0, y=0;
while (SDL_PollEvent (&event))
{
	switch (event.type)
{
	case SDL_QUIT:
		{
			closeEverything();
			exit(0);
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		{
			
			SDL_GetMouseState(&x,&y);
if( ( x > save.pos.x ) && ( y > save.pos.y) && ( x < (save.pos.x+128) ) && ( y < (save.pos.y+132)))
       	 {		position=1;
       			Mix_PlayChannel(-1,chunk,0);
       	 		afficherparpositionagent(position, &save,&load, &solo,&duo,&start,&menu);

						sauvegarder(p,b);

	
       	 }
if( ( x > load.pos.x ) && ( y > load.pos.y) && ( x < (load.pos.x+128) ) && ( y < (load.pos.y+132)))
       	 {		position=2;
       			Mix_PlayChannel(-1,chunk,0);
       	 		afficherparpositionagent(position, &save,&load, &solo,&duo,&start,&menu);
           		     charger(&p,&b);

	
       	 }
if( ( x > solo.pos.x ) && ( y > solo.pos.y) && ( x < (solo.pos.x+216) ) && ( y < (solo.pos.y+181)))
       	 {
       	 		position=3;
       	 		Mix_PlayChannel(-1,chunk,0);
       	 		afficherparpositionagent(position, &save,&load, &solo,&duo,&start,&menu);	
				*gamemode=2;
       	 }
if( ( x > duo.pos.x ) && ( y > duo.pos.y) && ( x < (duo.pos.x+216) ) && ( y < (duo.pos.y+181)))
       	 {
       	 		position=4;
       	 		Mix_PlayChannel(-1,chunk,0);
       	 		afficherparpositionagent(position, &save,&load, &solo,&duo,&start,&menu);	
			*gamemode=3;	
       	 }
if( ( x > start.pos.x ) && ( y >start.pos.y) && ( x < (start.pos.x+128) ) && ( y < (start.pos.y+132)))
       	 {
       	 	Mix_PlayChannel(-1,chunk,0);
			
			return 0;
		}
if( ( x > menu.pos.x ) && ( y > menu.pos.y) && ( x < (menu.pos.x+127) ) && ( y < (menu.pos.y+114)))
				{	Mix_PlayChannel(-1,chunk,0);
					event2->key.keysym.sym=SDLK_ESCAPE;
					TTF_CloseFont(perso.font);
					TTF_CloseFont(mode.font);
					return 0;
				}

		}
break ;
case SDL_MOUSEMOTION:
			SDL_GetMouseState(&x,&y);
if( ( x > start.pos.x ) && ( y >start.pos.y) && ( x < (start.pos.x+128) ) && ( y < (start.pos.y+132)))
       	 {
       	 		position=5;
       	 		afficherparpositionagent(position, &save,&load, &solo,&duo,&start,&menu);		
       	 }
else if( ( x > menu.pos.x ) && ( y > menu.pos.y) && ( x < (menu.pos.x+127) ) && ( y < (menu.pos.y+114)))
				{
				position=6;
					afficherparpositionagent(position, &save,&load, &solo,&duo,&start,&menu);	
				}
else 
{menu.img=IMG_Load("1x/Menureturnunselected.png");
start.img = IMG_Load("1x/buttonplayunselected.png");}
       	 		
break;
case SDL_KEYDOWN:
	if (event.key.keysym.sym == SDLK_ESCAPE)
			
		{

					Mix_PlayChannel(-1,chunk,0);
					event2->key.keysym.sym=SDLK_ESCAPE;
					TTF_CloseFont(perso.font);
					TTF_CloseFont(mode.font);
					return 0;
	}
break ;
}

}


}
return 0;
}





