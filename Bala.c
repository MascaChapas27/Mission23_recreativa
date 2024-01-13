#include "Bala.h"
#include <stdlib.h>

struct BalaRep{
    int w,h;
    float x, y;
    Imagen i;
    int v;
};

typedef struct BalaRep * Bala;

Bala BalaCrea(Imagen i, int x, int y, int w, int h, int v)
{
    Bala b = malloc(sizeof(struct BalaRep));
    b->i = i;
    b->x = x;
    b->y = y;
    b->w = w;
    b->h = h;
    b->v = v;
    return b;
}

void    BalaLibera(Bala b)
{
    free(b);
}

void    BalaMueve(Bala b, float tiempo_delta)
{
    b->y-=b->v*tiempo_delta;
}

void    BalaDibuja(Bala b)
{
    Pantalla_DibujaImagen(b->i,b->x,b->y,b->w,b->h);
}


int    BalaX(Bala b)
{
    return b->x;
}

int    BalaY(Bala b)
{
    return b->y;
}

int    BalaW(Bala b)
{
    return b->w;
}

int    BalaH(Bala b)
{
    return b->h;
}

