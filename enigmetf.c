#include "enigmetf.h"


void InitEnigme(enigmetf *e,char *nomfichier[]){   
 
	nomfichier[600];


	FILE *fquestion=NULL;
	FILE *freponse=NULL;
	FILE *fvraireponse=NULL;
	e->score=0;
	e->pos_selected=0;
	e->background= IMG_Load("1x/fond.png");
	e->button= IMG_Load("img/button.png");
	e->button_s= IMG_Load("img/button_s.png");

	TTF_Init();


	SDL_Color couleur = {0,0,0}; 

	(*e).police = TTF_OpenFont("ARIAL.ttf", 30);
	e->police1 = TTF_OpenFont("ARIAL.ttf", 20);
	  
	char questionn[500];
	
	srand(time(NULL)); 
	e->num_question=rand()%4;   

	while(e->num_question==0){
		srand(time(NULL));
		e->num_question=rand()%4;
	}
	 
	//sprintf(*nomfichier,"questions.txt"); 

	fquestion=fopen("questions.txt","r+");
	if(fquestion!=NULL){

		int test=1;
		while (fgets(questionn, 500, fquestion) &&(test!=e->num_question)){ 
			test++;
		}
		
		fclose(fquestion);
	}
	
	char reponse[50];

	int min,max;
    switch(e->num_question)
    {
    	case 1:
    	{
    		min=0;
    		max=2;
    		break;
    	}
    	case 2:
    	{
    		min=3;
    		max=5;
    		break;
    	}
    	case 3:
    	{
    		min=6;
    		max=8;
    		break;
    	}
    }


	freponse=fopen("reponses.txt","r+");
	if(freponse!=NULL){

		int test=0;
		while (fgets((reponse), 50, freponse) &&(test<max)){	
			
			if(test>=min){
				e->reponses[test-min]=TTF_RenderText_Blended(e->police1, reponse, couleur); 
			}
			test++;
		}	
		
		fclose(freponse);
	}
	
 
	


	
	fvraireponse=fopen("vraireponses.txt","r+");
	if(fvraireponse!=NULL){
		
		int test=1;
		while (fgets((reponse), 15, fvraireponse)){
			
			if(test==e->num_question){ 
				printf("%s\n",reponse);
				e->reponses[2]=TTF_RenderText_Blended(e->police1, reponse, couleur); 
			}
			test++;
		}
		fclose(freponse);
	}

	srand(time(NULL));
	e->positionVraiReponse=rand()%4; 

	while(e->positionVraiReponse==0){
		srand(time(NULL));
		e->positionVraiReponse=rand()%4;
	}
	printf("%d\n",e->positionVraiReponse);

	e->question = TTF_RenderText_Blended(e->police, questionn, couleur);

	e->pos_question.x=30;
	e->pos_question.y=270;
 
	e->pos_reponse1.x=375;
	e->pos_reponse1.y=522;


	e->pos_reponse2.x=177;
	e->pos_reponse2.y=648;

	e->pos_reponse3.x=566;
	e->pos_reponse3.y=651;

	e->pos_reponse1txt.x=e->pos_reponse1.x+50;
	e->pos_reponse1txt.y=522+30;

	e->pos_reponse2txt.x=177+50;
	e->pos_reponse2txt.y=648+30;

	e->pos_reponse3txt.x=566+50;
	e->pos_reponse3txt.y=651+30;
 

}

void afficherEnigme(enigmetf e,SDL_Surface *ecran){

	
	//SDL_BlitSurface(e.background, NULL, ecran, NULL);
	SDL_BlitSurface(e.question, NULL, ecran, &e.pos_question);

	

	switch(e.positionVraiReponse){
		case 1:{

			switch(e.pos_selected){
			case 1:
			{
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
				}
			}	
			break;
		}
		case 2:{
			switch(e.pos_selected){
			case 1:
			{
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
				}
			}
			break;
		}
		case 3:{
			switch(e.pos_selected){
			case 1:
			{
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:                       
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button_s, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.button, NULL, ecran, &e.pos_reponse3);
				SDL_Flip(ecran);

				SDL_BlitSurface(e.reponses[0], NULL, ecran, &e.pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[1], NULL, ecran, &e.pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e.reponses[2], NULL, ecran, &e.pos_reponse3txt);
				SDL_Flip(ecran);
				}
			}

			break;
		}
	}
	
	SDL_Delay(100);
}

void verify_enigme(enigmetf *e,SDL_Surface*ecran)
{

	SDL_Rect pos={160,330}; 
	if(e->positionVraiReponse==e->pos_selected)
	{
		printf("You win\n");
		SDL_Surface *win;
		win=IMG_Load("img/youwin.png");
		SDL_BlitSurface(win, NULL, ecran,&pos);



						e->score +=100;


		SDL_Flip(ecran);

	}
	else
	{
		SDL_Surface *lost;
		lost=IMG_Load("img/youlost.png");
		SDL_BlitSurface(lost, NULL, ecran, &pos);


						e->score -= 50;


		SDL_Flip(ecran);
		printf("You lost\n");
	}
	SDL_Delay(2000);

}

void free_Surface_enigme(enigmetf e){

	SDL_FreeSurface(e.background);
	SDL_FreeSurface(e.question);
	SDL_FreeSurface(e.reponses[0]);
	SDL_FreeSurface(e.reponses[1]);
	SDL_FreeSurface(e.reponses[2]);
	SDL_FreeSurface(e.button);
	SDL_FreeSurface(e.button_s);
}
















