#include "header.h"
/*
SDL_Color GetPixel(SDL_Surface *Background, int x, int y)
{
        
        SDL_Color color;
        Uint32 col = 0;
        //Determine position

                char *pixelPosition = (char*)Background->pixels;
                //Offset by Y
                pixelPosition += (Background->pitch * y);
                //Offset by X
                pixelPosition += (Background->format->BytesPerPixel * x);
                //Copy pixel data
                memcpy(&col, pixelPosition, Background->format->BytesPerPixel);
                //Convert to color
                SDL_GetRGB(col, Background->format, &color.r, &color.g, &color.b);

                return (color);
}


int collisionPP( personne p, SDL_Surface * Masque)
{
    SDL_Color test ,couleurnoir= {0,0,0};

    SDL_Rect pos[8];
    pos[0].x=p.pos_hero.x;
    pos[0].y=p.pos_hero.y;
    pos[1].x=p.pos_hero.x+p.pos_hero.w/2;
    pos[1].y=p.pos_hero.y;
    pos[2].x=p.pos_hero.x+p.pos_hero.w;
    pos[2].y=p.pos_hero.y;
    pos[3].x=p.pos_hero.x;
    pos[3].y=p.pos_hero.y+p.pos_hero.h/2;   
    pos[4].x=p.pos_hero.x;
    pos[4].y=p.pos_hero.y+p.pos_hero.h;
    pos[5].x=p.pos_hero.x+p.pos_hero.w/2;
    pos[5].y=p.pos_hero.y+p.pos_hero.h;
    pos[6].x=p.pos_hero.x+p.pos_hero.w;
    pos[6].y=p.pos_hero.y+p.pos_hero.h;    
    pos[7].x=p.pos_hero.x+p.pos_hero.w;
    pos[7].y=p.pos_hero.y+p.pos_hero.h/2;


     int collision=0 , x ,y ;

     for(int i=0 ;i<8 && collision==0;i++)
     {
        x=pos[i].x;
        y=pos[i].y;
        test=GetPixel(Masque,x,y);
        if(test.r==0 && test.g==0 && test.b==0)
            collision=1;
     }
     return collision;

}*/






SDL_Color GetPixel(SDL_Surface *mask,int x,int y)
{
SDL_Color color;
Uint32 col=0;
//determine position
char * pPosition=(char*)mask->pixels;
pPosition+=(mask->pitch *y);
pPosition+=(mask->format->BytesPerPixel *x);
memcpy(&col,pPosition,mask->format->BytesPerPixel);
//convertir color 
SDL_GetRGB(col,mask->format,&color.r,&color.g,&color.b);
return(color);
}
int collisionPP_droite( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera)
{
int collision=0;
int i;
SDL_Color couleur_obstacle={0,0,0},test;
//int couleur_obstacle;
//SDL_Color couleur_obstacle;
//Uint32 col=0;
int pos[3][2];
pos[0][0]=100+camera.x+posjoueur.x+posjoueur.w;
pos[0][1]=120+posjoueur.y;
pos[1][0]=100+camera.x+posjoueur.x+posjoueur.w;
pos[1][1]=120+posjoueur.y+posjoueur.h/2;
pos[2][0]=100+camera.x+posjoueur.x+posjoueur.w;
pos[2][1]=120+posjoueur.y+posjoueur.h;
for(i=0;i<2 && collision==0;i++)
{test=GetPixel(mask,pos[i][0],pos[i][1]);
if ((test.r==couleur_obstacle.r)&&(test.g==couleur_obstacle.g)&&(test.b==couleur_obstacle.b))
collision=1;
//collision=1;

}
return collision;
}


int collisionPP_gauche( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera)
{
int collision=0;
int i;
SDL_Color couleur_obstacle={0,0,0},test;
//int couleur_obstacle;
//SDL_Color couleur_obstacle;
//Uint32 col=0;
int pos[3][2];
pos[0][0]=100+camera.x+posjoueur.x;
pos[0][1]=120+posjoueur.y;
pos[1][0]=100+camera.x+posjoueur.x;
pos[1][1]=120+posjoueur.y+posjoueur.h/2;
pos[2][0]=100+camera.x+posjoueur.x;
pos[2][1]=120+posjoueur.y+posjoueur.h;
for(i=0;i<2 && collision==0;i++)
{test=GetPixel(mask,pos[i][0],pos[i][1]);
if ((test.r==couleur_obstacle.r)&&(test.g==couleur_obstacle.g)&&(test.b==couleur_obstacle.b))
collision=1;
//collision=1;

}
return collision;
}




int collisionPP_up( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera)
{
int collision=0;
int i;
SDL_Color couleur_obstacle={0,0,0},test;
//int couleur_obstacle;
//SDL_Color couleur_obstacle;
//Uint32 col=0;
int posX,posY;
posX=100+camera.x+ posjoueur.x+ posjoueur.w/2;
posY=120+posjoueur.y;

test=GetPixel(mask,posX,posY);
if ((test.r==couleur_obstacle.r)&&(test.g==couleur_obstacle.g)&&(test.b==couleur_obstacle.b))
collision=1;

return collision;
}


int collisionPP_down( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera)
{
int collision=0;
int i;
SDL_Color couleur_obstacle={0,0,0},test;
//int couleur_obstacle;
//SDL_Color couleur_obstacle;
//Uint32 col=0;
int posX,posY;
posX=10+camera.x+ posjoueur.x+ posjoueur.w/2;
posY=10+posjoueur.y+ posjoueur.h;

test=GetPixel(mask,posX,posY);
if ((test.r==couleur_obstacle.r)&&(test.g==couleur_obstacle.g)&&(test.b==couleur_obstacle.b))
collision=1;

return collision;
}









int collisionPP_hole( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera)
{
int collision=0;
int i;
SDL_Color couleur_obstacle={255,0,0},test;
//int couleur_obstacle;
//SDL_Color couleur_obstacle;
//Uint32 col=0;
int pos[3][2];
pos[0][0]=100+camera.x+posjoueur.x;
pos[0][1]=120+posjoueur.y;
pos[1][0]=100+camera.x+posjoueur.x;
pos[1][1]=120+posjoueur.y+posjoueur.h/2;
pos[2][0]=100+camera.x+posjoueur.x;
pos[2][1]=120+posjoueur.y+posjoueur.h;
for(i=0;i<2 && collision==0;i++)
{test=GetPixel(mask,pos[i][0],pos[i][1]);
if ((test.r==couleur_obstacle.r)&&(test.g==couleur_obstacle.g)&&(test.b==couleur_obstacle.b))
collision=1;
//collision=1;

}
return collision;
}




int collisionPP_end( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera)
{
int collision=0;
int i;
SDL_Color couleur_obstacle={0,0,255},test;
//int couleur_obstacle;
//SDL_Color couleur_obstacle;
//Uint32 col=0;
int pos[3][2];
pos[0][0]=100+camera.x+posjoueur.x;
pos[0][1]=120+posjoueur.y;
pos[1][0]=100+camera.x+posjoueur.x;
pos[1][1]=120+posjoueur.y+posjoueur.h/2;
pos[2][0]=100+camera.x+posjoueur.x;
pos[2][1]=120+posjoueur.y+posjoueur.h;
for(i=0;i<2 && collision==0;i++)
{test=GetPixel(mask,pos[i][0],pos[i][1]);
if ((test.r==couleur_obstacle.r)&&(test.g==couleur_obstacle.g)&&(test.b==couleur_obstacle.b))
collision=1;
//collision=1;

}
return collision;
}


int collisionPP_white( SDL_Rect posjoueur, SDL_Surface *mask,SDL_Rect camera)
{



int collision=0;
int i;
SDL_Color couleur_obstacle={255,255,255},test;
//int couleur_obstacle;
//SDL_Color couleur_obstacle;
//Uint32 col=0;
int pos[3][2];
pos[0][0]=100+camera.x+posjoueur.x;
pos[0][1]=120+posjoueur.y;
pos[1][0]=100+camera.x+posjoueur.x;
pos[1][1]=120+posjoueur.y+posjoueur.h/2;
pos[2][0]=100+camera.x+posjoueur.x;
pos[2][1]=120+posjoueur.y+posjoueur.h;
for(i=0;i<2 && collision==0;i++)
{test=GetPixel(mask,pos[i][0],pos[i][1]);
if ((test.r==couleur_obstacle.r)&&(test.g==couleur_obstacle.g)&&(test.b==couleur_obstacle.b))
collision=1;
//collision=1;

}
return collision;


















}


