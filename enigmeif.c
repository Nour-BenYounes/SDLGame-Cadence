
#include "enigmeif.h"


void genererimage(enigmeif *e){
	
	srand(time(NULL));
	e->d=rand()%7; 
}

void InitEnigmeimage(enigmeif *e,char nomfichier[]){

	char im[100],imr1[100],imr2[100],imr3[100];
	nomfichier[100];
 	e->pos_image.x=400;
  	e->pos_image.y=200;
  	
  	e->pos_reponse.x=400;
  	e->pos_reponse.y=200;
e->score=0;
	sprintf( nomfichier,"fichierenigme/%d.txt",e->d); 
	sprintf(imr1,"reponse/%d/1.png",e->d); 
    	sprintf(imr2,"reponse/%d/2.png",e->d); 
    	sprintf(imr3,"reponse/%d/3.png",e->d); 
	
     
	FILE * f  = fopen(nomfichier,"r");   
	if(f==NULL){
		printf("cant open file");
	}
	else{
	    	fscanf(f,"%s",im);  
	    	fclose(f);
	    	
	    	e->image= IMG_Load(im);      
		e->reponse1= IMG_Load(imr1);
		e->reponse2= IMG_Load(imr2);
    		e->reponse3= IMG_Load(imr3);
    		e->image=e->reponse3;
    	
	
	    
	    }


}

void afficherEnigmeimage(enigmeif *e,SDL_Surface *screen){

		SDL_BlitSurface(e->image,NULL,screen,&e->pos_image);
	    	SDL_Delay(1000); 
 		SDL_BlitSurface(e->reponse3,NULL, screen, &e->pos_reponse);
		SDL_Flip(screen);
		SDL_Delay(1000);				
		resolution(screen,e);

}
void correct(SDL_Surface *screen,enigmeif *e){

	char im[100];
 
	sprintf(im,"correct.png");
	e->correct= IMG_Load(im);
	e->pos_correct.x=400;
	e->pos_correct.y=200;
	SDL_BlitSurface(e->correct,NULL,screen,&e->pos_correct);
e->score+=100;
	SDL_Flip(screen);
	SDL_Delay(1000);


}

void wrong(SDL_Surface *screen,enigmeif *e){
 	char im[100];
     
    	e->wrong= IMG_Load("wrong.png");
    	e->pos_wrong.x=0;
    	e->pos_wrong.y=0;
    	SDL_BlitSurface(e->wrong,NULL,screen,&e->pos_wrong);
    	SDL_Flip(screen);
    	SDL_Delay(1000);
    	
	e->score-=50;
    	SDL_Flip(screen);
    	SDL_Delay(1000);

}


void resolution(SDL_Surface *screen,enigmeif *e){
	SDL_Event event;
	int continuer =1;
	int i=0;
	while (continuer)
	    {
		SDL_WaitEvent(&event);
		switch(event.type)
		{
		case SDL_QUIT:
		    continuer=0;
		    break;

		case SDL_KEYDOWN:
		    switch(event.key.keysym.sym)
		    {

		    case SDLK_RETURN:
		        if(i>=1 && i<=3)
		        {

		            if (i==1 && e->d%3==1)
		            {
				correct(screen,e);
				continuer=0;
		            }
		            else if (i==2 && e->d%3==2)
		            {
				correct(screen,e);
				continuer=0;
		            }
		            else if (i==3 && e->d%3==0)
		            {
				correct(screen,e);
				continuer=0;
		            }
		            else
		            {
				wrong(screen,e);
				SDL_Delay(1000);
				continuer=0;
		            }
		        }
		        break;

		    case SDLK_DOWN:
		        i++;
		        if(i>=4)
		        {
		            i=1;
		        }
		        if(i==1)
		        {		          
		            e->image=e->reponse1;
		        }
		        if(i==2)
		        {		       
		         e->image=e->reponse2;		            
		        }
		        if(i==3)
		        {
		        	e->image=e->reponse3;		            
		        }
		        ;
		        break;
		    case SDLK_UP:
		        i--;
		        if(i<=0)
		        {
		            i=3;
		        }
		        if(i>=4)
		        {
		            i=1;
		        }
		        if(i==1)
		        {
		        	e->image = e->reponse1;
		        }
		        if(i==2)
		        {
		        	e->image = e->reponse2;
		        }
		        if(i==3)
		        {
		        	e->image=e->reponse3;		     
		        }
		        break;
		    }
		}
		SDL_BlitSurface(e->image,NULL,screen,&e->pos_image);
		SDL_Flip(screen);
    	}

}










