#ifndef GAME
#define GAME



typedef struct ennemi
{
SDL_Surface *imges;
SDL_Rect poses;
SDL_Event event;
int damage,state,direction;



}ennemi;
typedef struct ennemi ennemi; 



void initEnnemi(Ennemi*e);
void afficherEnnemi(Ennemi e, SDL_Surface * screen);
void animerEnnemi( Ennemi * e);
void deplacer( Ennemi * e);
int collisionBB( personne p, Ennemi e) //ou int collisionBB( SDL_Rect posp, SDL_Rect pose);
void deplacerIA( Ennemi * e, SDL_Rect posPerso);




#endif









