#ifndef ENIGMETF_H_INCLUDED
#define ENIGMETF_H_INCLUDED

#include <stdio.h> 
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

typedef struct{
	SDL_Surface *background; 
	SDL_Surface *question;
	SDL_Surface *reponses[4]; 
	SDL_Surface *button; 
	SDL_Surface *button_s;

	int pos_selected;
	SDL_Rect pos_question; 
	SDL_Rect pos_reponse1;
	SDL_Rect pos_reponse2; 
	SDL_Rect pos_reponse3;
	int num_question;
	
	SDL_Rect pos_reponse1txt;
	SDL_Rect pos_reponse2txt;
	SDL_Rect pos_reponse3txt;
	int vrai_reponse;
	int score;
	int positionVraiReponse;
	TTF_Font *police; 
	TTF_Font *police1;

}enigmetf;

void InitEnigme(enigmetf *e,char *nomfichier[]);
void afficherEnigme(enigmetf e,SDL_Surface *ecran);
void verify_enigme(enigmetf *e,SDL_Surface*ecran);
void animer(enigmetf *e);
void free_Surface_enigme(enigmetf e);



//void enigmeintergration(int *enigmetext,SDL_Surface *screen);
#endif
