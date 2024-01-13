#include "Animacion.h"
#include <stdlib.h>

struct AnimacionRep{
    float cont;
    int n,x,y,w,h;
    Imagen * i;
};

typedef struct AnimacionRep * Animacion;

Animacion AnimacionCrea(Imagen i[], int n, int x, int y, int w, int h)
{
    Animacion a = malloc(sizeof(struct AnimacionRep));
    a->i = malloc(n*sizeof(Imagen));
    for(int j=0;j<n;j++) a->i[j] = i[j]; //¿A lo mejor no sirve?
    a->n = n;
    a->x = x;
    a->y = y;
    a->w = w;
    a->h = h;
    a->cont = 0;
    return a;
}

void    AnimacionLibera(Animacion a)
{
    free(a->i);
    free(a);
}

void    AnimacionMueve(Animacion a, float tiempo_delta)
{
    if(a->cont < a->n){
        Pantalla_DibujaImagen(a->i[(int)a->cont],a->x,a->y,a->w,a->h);
        a->cont+=tiempo_delta;
    }
}

int     AnimacionCont(Animacion a)
{
    return a->cont;
}

int     AnimacionN(Animacion a)
{
    return a->n;
}
