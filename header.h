#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL_mixer.h>
#include "stdbool.h"
 #include <unistd.h>
#include "IA.h"

#include "background.h"

#define SCREEN_W 1500
#define SCREEN_H 900
typedef struct{
	SDL_Rect pos;
	SDL_Surface *img;
}image;



typedef struct
{
SDL_Surface *img;
SDL_Rect pos_img;
SDL_Surface *img_joueur ;
SDL_Rect pos_joueur;
}minimap;
typedef struct {
	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface * surfaceTexte;
	SDL_Color textColor;
	char texte [50];
}text;



typedef enum SPRITE SPRITE;
enum SPRITE {idle,idle1,idle2,walking,jumping,doublejumping,attacking,hit,die,crouch};
typedef struct 
{
	SDL_Surface *vie[4];
	SDL_Surface *bar_score;
	SDL_Surface *hero_right;
	SDL_Surface *hero_left;
	SDL_Rect pos_hero,pos_vie,pos_score;
	int direction,health,score,death,vitesse,acceleration,jump,jump_count,ground,vitesse_saut,up;
	SDL_Rect animheroRight[10][20];
	SDL_Rect animheroLeft[10][20];
	int frame_i,frame_i1,frame_i2,frame_wl,frame_j,frame_dj,frame_a,frame_h,frame_d,frame_c;
	SPRITE state;
	TTF_Font *police;


   
}personne;





////////////save
typedef struct save
{
  
  personne p;
  background b;
}save;



void sauvegarder (personne p,background b) ; 
void charger (personne *p,background *b);













void sautt (personne* p);






void initText(text *A,text *B,text *C,text *D);
void freeText(text A,text B,text C, text D);
void displayText(text t,SDL_Surface *screen);
void initButtons(image *A,image *B, image *C,image *D,image *E, image *F);
void initBackground(image *Backg);
void afficher(image A,SDL_Surface *screen);
void libererButtons(image A,image B, image C,image E,image F,image G);
void afficherparposition(int position, image *A,image *B, image *C,image *D);
void closeEverything();

void initSettingsButtons(image *A,image *B, image *C,image *D,image *E,Mix_Chunk *chunk);
int paintOptionsScreen(SDL_Surface* screen,SDL_Event *event,Mix_Chunk *chunk,int *volume);

void initTextagent(text *A,text *B);
void freeTextagent(text A,text B);
void displayTextagent(text t,SDL_Surface *screen);
void afficherparpositionagent(int position, image *A,image *B, image *C,image *D,image *E,image *F);
void initSettingsButtonsagent(image *A,image *B, image *C,image *D,image *E,image *F);
int paintOptionsScreenagent (SDL_Surface *screen,SDL_Event *event2,Mix_Chunk *chunk,int *gamemode);
void afficherparpositionsettings(int position, image *A,image *B);

void initanimation(image tabimg[]);
void libereranimation (image tabimg[]);


//perso
void initPerso(personne *p);
void initPerso2(personne *p);
void afficherPerso(personne p, SDL_Surface * screen_p,SDL_Rect back);
void deplacerPerso (personne *p);
void deplacerPerso2 (personne *p);
void animerPerso (personne* p);
void saut (personne* p);
void pulltrigger(personne* p);
void randomizer(personne *p,int state_i);
void afficherscorevie(personne p, SDL_Surface * screen_s);
void free_perso(personne *p);



//minimap
void initminimap (minimap *m,personne *p);
void MAJminimap (personne *p, minimap *m,SDL_Rect camera,int r);
void afficherminimap (minimap m,SDL_Surface *screen);
void Liberer (minimap * m);
void ajouternom (SDL_Surface *Screen,char *nom, SDL_Event event);
void sauvgarder (int score, char nom[],char nomfichier[],personne p);
void meilleur (char nomfichier[],int *score,char *nom);
void scrolling_bonhomme(minimap *m,int direction,float pasAvancement);

SDL_Rect MAJMinimap (SDL_Rect Posjoueur,int redemensionement,SDL_Rect camera);////////pos absoluee

//score
void initscore(text *A,text *B,char meilleurnom[],int meilleurscore);
void freescore(text A,text B);
void displayscore(text t,SDL_Surface *screen);
int rollscore (SDL_Surface *screen,SDL_Event *event1,char meilleurnom[],int meilleurscore);


//cpp

/*
SDL_Color GetPixel(SDL_Surface *Background, int x, int y);
int collisionPP( personne p, SDL_Surface * Masque);*/







SDL_Color GetPixel(SDL_Surface *mask,int x,int y);
int collisionPP_droite( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera);
int collisionPP_gauche( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera);
int collisionPP_up( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera);
int collisionPP_down( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera);
int collisionPP_hole( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera);
int collisionPP_end( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera);
int collisionPP_white( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera);




/////arduino
int arduinoWriteData(int x);
int arduinoReadData(char *x);








