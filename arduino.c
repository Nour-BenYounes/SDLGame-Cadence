#include "header.h"



int arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyUSB0";
    FILE*f;

    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);

    fprintf(f,"%d",x);
    fclose(f);

    return(0);
}

int arduinoReadData(char *x)
{
    char chemin[]="/dev/ttyUSB0";
    FILE*f;
    char c;
    f=fopen(chemin,"r");

    if(f == NULL)
        return(-1);

    fscanf(f,"%s",x);

    fclose(f);

    return(0);
}
