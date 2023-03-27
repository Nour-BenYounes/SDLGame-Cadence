#include "header.h"

void sauvegarder (personne p,background b) {
FILE *fichier;
save s;
s.p=p;
s.b=b;
fichier=fopen("save_perso","wb");
if (fichier != NULL)
{
    fwrite(&s,sizeof(save),1,fichier);
    printf("game saved\n");
}else printf("failed");


fclose(fichier);

}

void charger (personne *p,background *b ){
    FILE *fichier;
    save s;
    fichier=fopen("save_perso","rb");
    fread(&s,sizeof(save),1,fichier);
    fclose(fichier);
    p->pos_hero.x=s.p.pos_hero.x;
    p->pos_hero.y=s.p.pos_hero.y;
    b->camera.x=s.b.camera.x;
    b->camera.y=s.b.camera.y;
    


    

    printf("perso et background chargés\n");


}





