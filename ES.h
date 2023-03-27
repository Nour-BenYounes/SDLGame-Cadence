#ifndef GAME
#define GAME


typedef enum STATE STATE;
enum STATE   {WAITING,FOLLOWING,ATTACKING,ESCAPING};





typedef struct
{
    SDL_Surface *spriteSheet[6]; // 0: dead 1: right 2:left
    SDL_Rect Clips[10];
    int side; // 1: right 2: left 0: dead
    int frames;
    int clipLoaded;
} animation;





typedef struct
{
    SDL_Rect pos;
    animation animation;
    int col; // 0: non colusion 1: colusion
	int death;

	STATE state;


} Ennemi;






typedef struct
{
    SDL_Rect pos;
    animation animation;
    int col;
    int type;  // 1: coin 2: boost
    int boost; // 0: no boost 1: health
	
} PickUp;





//typedef struct Ennemi Ennemi; 


void generate_Clips(SDL_Rect Clips[], int frames, int frameWidth, int clipWidth, int clipHeight);


void initEnnemi(Ennemi*e);
void afficherEnnemi(Ennemi e, SDL_Surface * screen,SDL_Rect back);
void animerEnnemi( Ennemi * e);

void deplacer( Ennemi * e);
int collisionBB( SDL_Rect posp, SDL_Rect pose);
void deplacerIA( Ennemi * e, SDL_Rect posPerso);
void updateEnnemiState(Ennemi *e, int position,int att);
void DeathEn( Ennemi * e, SDL_Rect posPerso);


void freeEnnemie(Ennemi e);
void freecoin(PickUp c);






void initCoin(PickUp *c);
void afficherCoin(PickUp c, SDL_Surface *screen,SDL_Rect back);
void animerCoin(PickUp *c);


void scrolling_enemie(Ennemi *E,int direction,int pasAvancement);
void scrolling_coin(PickUp *c,int direction,int pasAvancement);
void scrolling_everything(SDL_Rect pos,int direction,int pasAvancement);

#endif









