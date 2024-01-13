#include "Galaxia.h"
#include <stdlib.h>
#include "Colision.h"
#include "Moneda.h"

struct GalaxiaRep
{
    Moneda * m;
    int n, maximo;
};

typedef struct GalaxiaRep * Galaxia;

Galaxia GalaxiaCrea(int maximo)
{
    Galaxia g = malloc(sizeof(struct GalaxiaRep));
    g->m = malloc(maximo*sizeof(Moneda));
    g->maximo = maximo;
    g->n = 0;
    return g;
}

void GalaxiaLibera(Galaxia g)
{
    for(int i=0;i<g->n;i++) MonedaLibera(g->m[i]);
    free(g->m);
    free(g);
}

void GalaxiaDibuja(Galaxia g)
{
    for(int i=0;i<g->n;i++) MonedaDibuja(g->m[i]);
}

void GalaxiaInserta(Galaxia g, Imagen i, int x, int y, int w, int h)
{
    if(g->n < g->maximo){
        g->m[g->n] = MonedaCrea(i,x,y,w,h);
        g->n++;
    }
}

int GalaxiaColision(Galaxia g, Personaje p[], Pelicula pel, Imagen monedaDesvanece[], int num)
{
    int i=0,salida=0;
    while(i<g->n && !((PersonajeEsValido(p[0]) && (Colision(PersonajeX(p[0]), PersonajeY(p[0]), PersonajeW(p[0]), PersonajeH(p[0]), MonedaX(g->m[i]),MonedaY(g->m[i]),MonedaW(g->m[i]),MonedaH(g->m[i])))) ||
                      (PersonajeEsValido(p[1]) && (Colision(PersonajeX(p[1]), PersonajeY(p[1]), PersonajeW(p[1]), PersonajeH(p[1]), MonedaX(g->m[i]),MonedaY(g->m[i]),MonedaW(g->m[i]),MonedaH(g->m[i])))))){
        i++;
    }
    if(i<g->n){
        PeliculaInserta(pel,monedaDesvanece,num,MonedaX(g->m[i]),MonedaY(g->m[i]),MonedaW(g->m[i]),MonedaH(g->m[i]));
        salida=1;
        MonedaLibera(g->m[i]);
        g->m[i]=g->m[g->n-1];
        g->n--;
    }
    return salida;
}
