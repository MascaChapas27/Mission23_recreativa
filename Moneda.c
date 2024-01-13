#include "Moneda.h"
#include <stdlib.h>

struct MonedaRep{
    int x,y,w,h;
    Imagen i;
};

typedef struct MonedaRep * Moneda;

Moneda MonedaCrea(Imagen i, int x, int y, int w, int h)
{
    Moneda m = malloc(sizeof(struct MonedaRep));
    m->i = i;
    m->x = x;
    m->y = y;
    m->w = w;
    m->h = h;
    return m;
}

void    MonedaLibera(Moneda m)
{
    free(m);
}

void    MonedaDibuja(Moneda m)
{
    Pantalla_DibujaImagen(m->i,m->x,m->y,m->w,m->h);
}


int    MonedaX(Moneda m)
{
    return m->x;
}

int    MonedaY(Moneda m)
{
    return m->y;
}

int    MonedaW(Moneda m)
{
    return m->w;
}

int    MonedaH(Moneda m)
{
    return m->h;
}

