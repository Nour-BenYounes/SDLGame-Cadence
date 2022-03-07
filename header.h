#ifndef GAME
#define GAME













void initPerso(Personne *p);
void afficherPerso(Personne p, SDL_Surface * screen);
void deplacerPerso (Personne *p, , int dt);
void animerPerso (Personne* p);
void saut (Personne* p);


void initBack(Background * b);
void aficherBack(Background b, SDL_Surface * screen);
void animerBackground( Background * e);
int collisionPP( Personne p, SDL_Surface * Masque);
void scrolling (background * b, int direction, int pasAvancement); soit void scrolling (SDL_Rect * b, int direction ,int pasAvancement);

void initEnnemi(Ennemi*e);
void afficherEnnemi(Ennemi e, SDL_Surface * screen);
void animerEnnemi( Ennemi * e);
void deplacer( Ennemi * e);
int collisionBB( personne p, Ennemi e) ou int collisionBB( SDL_Rect posp, SDL_Rect pose);
void deplacerIA( Ennemi * e, SDL_Rect posPerso);

initminimap( minimap * m);
MAJMinimap(perso p , minimap * m, SDL_Rect camera, int redimensionnement);
afficherminimap (minimap m, SDL_Surface * screen);
//ajouter une option permettant d'entrer le nom du joeur : exemple : clavier numerique avec des bouttons contenant des lettres
void sauvegarder( int score, char nomjoueur[], char nomfichier[]);
void meilleur( char nomfichier[], int *score, char nomjoueur[]);


void afficherEnigme(enigme e, SDL_Surface * screen);
void InitEnigme(enigme * e, char *nomfichier);
void animer (enigme * e); 
void sauvegarder (personne p, background b, char * nomfichier) ; int charger ( personne * p, background *b , char * nomfichier);


void InitEnigme(enigme * e, char *nomfichier);
void afficherEnigme(enigme e, SDL_Surface * screen);
void animer (enigme * e);



#endif









