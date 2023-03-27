#include"header.h"
void initanimation(image tabimg[])
{
int i;
tabimg[0].img=IMG_Load("backg/1.png");
tabimg[1].img=IMG_Load("backg/2.png");
tabimg[2].img=IMG_Load("backg/3.png");
tabimg[3].img=IMG_Load("backg/4.png");


    
    for (i=0;i<4;i++)
    	{
    	tabimg[i].pos.y=0;
    	tabimg[i].pos.x = 0;

    	}

}
void libereranimation (image tabimg[])
{
int i;
for (i=0;i<3;i++)
    	SDL_FreeSurface(tabimg[i].img);
}

