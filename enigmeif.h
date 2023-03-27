#ifndef ENIGMEIF_H_INCLUDED
#define ENIGMEIF_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>     
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include <time.h>


typedef struct{  
	
	SDL_Surface *image;  
	SDL_Rect pos_image;
	
	SDL_Surface *reponse1; 
	SDL_Surface *reponse2; 
	SDL_Surface *reponse3; 
	SDL_Rect pos_reponse;
	
	SDL_Surface *correct; 
	SDL_Rect pos_correct;
	
	SDL_Surface *wrong; 
	SDL_Rect pos_wrong;
	
	SDL_Surface *solution; 
	SDL_Rect pos_solution;
	int score;
	int d; //l noumrou mta3 l question yama 1 ou 2 ou 3 ..... ou 7 o ali ikoune aléatoire a l'aide de la fonction rand(); 
	
}enigmeif;

void InitEnigmeimage(enigmeif *e ,char nomfichier[]);
void afficherEnigmeimage(enigmeif *e,SDL_Surface *screen);
void resolution(SDL_Surface *screen,enigmeif *e);
void correct(SDL_Surface *screen,enigmeif *e);
void wrong(SDL_Surface *screen,enigmeif *e);
void genererimage(enigmeif *e);


#endif  

