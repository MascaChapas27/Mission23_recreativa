#include "Personaje.h"
#include <stdlib.h>

struct PersonajeRep{ //Nuestro personaje
    int w,h,d,c,e,b;
    float x, y;
    Imagen i;
    int v;
    int valido;
};

typedef struct PersonajeRep * Personaje;

Personaje PersonajeCrea(Imagen i, int x, int y, int w, int h, int v, int d, int c, int e, int b)
{
    Personaje p = malloc(sizeof(struct PersonajeRep));
    p->i = i;
    p->x = x;
    p->y = y;
    p->w = w;
    p->h = h;
    p->v = v;
    p->d = d;
    p->c = c;
    p->e = e;
    p->b = b;
    p->valido = 0;
    return p;
}

void    PersonajeLibera(Personaje p)
{
    free(p);
}

void    PersonajeMueve(Personaje personajes[], float tiempo_delta)
{
    if(!PersonajeEsValido(personajes[0]) || !PersonajeEsValido(personajes[1])){
        Personaje p = PersonajeEsValido(personajes[0]) ? personajes[0] : personajes[1];
        if (Pantalla_TeclaPulsada(JUGADOR1_ARRIBA))
        {
            p->y-=p->v*tiempo_delta;
            if(p->y<0)
            {
                p->y=0;
            }
        }
        if (Pantalla_TeclaPulsada(JUGADOR1_ABAJO))
        {
            p->y+=p->v*tiempo_delta;
            if(p->y>(Pantalla_Altura()-p->h))
            {
                p->y=Pantalla_Altura()-p->h;
            }
        }
        if (Pantalla_TeclaPulsada(JUGADOR1_DERECHA))
        {
            p->x+=p->v*tiempo_delta;
            if(p->x>(Pantalla_Anchura()-p->w))
            {
                p->x=Pantalla_Anchura()-p->w;
            }
        }
        if (Pantalla_TeclaPulsada(JUGADOR1_IZQUIERDA))
        {
            p->x-=p->v*tiempo_delta;
            if(p->x<0)
            {
                p->x=0;
            }
        }
        return;
    }

    Personaje p = personajes[0];
    if (Pantalla_TeclaPulsada(JUGADOR1_ARRIBA))
    {
        p->y-=p->v*tiempo_delta;
        if(p->y<0)
        {
            p->y=0;
        }
    }
    if (Pantalla_TeclaPulsada(JUGADOR1_ABAJO))
    {
        p->y+=p->v*tiempo_delta;
        if(p->y>(Pantalla_Altura()-p->h))
        {
            p->y=Pantalla_Altura()-p->h;
        }
    }
    if (Pantalla_TeclaPulsada(JUGADOR1_DERECHA))
    {
        p->x+=p->v*tiempo_delta;
        if(p->x>(Pantalla_Anchura()-p->w))
        {
            p->x=Pantalla_Anchura()-p->w;
        }
    }
    if (Pantalla_TeclaPulsada(JUGADOR1_IZQUIERDA))
    {
        p->x-=p->v*tiempo_delta;
        if(p->x<0)
        {
            p->x=0;
        }
    }

    p = personajes[1];

    if (Pantalla_TeclaPulsada(JUGADOR2_ARRIBA))
    {
        p->y-=p->v*tiempo_delta;
        if(p->y<0)
        {
            p->y=0;
        }
    }
    if (Pantalla_TeclaPulsada(JUGADOR2_ABAJO))
    {
        p->y+=p->v*tiempo_delta;
        if(p->y>(Pantalla_Altura()-p->h))
        {
            p->y=Pantalla_Altura()-p->h;
        }
    }
    if (Pantalla_TeclaPulsada(JUGADOR2_DERECHA))
    {
        p->x+=p->v*tiempo_delta;
        if(p->x>(Pantalla_Anchura()-p->w))
        {
            p->x=Pantalla_Anchura()-p->w;
        }
    }
    if (Pantalla_TeclaPulsada(JUGADOR2_IZQUIERDA))
    {
        p->x-=p->v*tiempo_delta;
        if(p->x<0)
        {
            p->x=0;
        }
    }
}

void    PersonajeDibuja(Personaje p)
{
    Pantalla_DibujaImagen(p->i,p->x,p->y,p->w,p->h);
}

void    PersonajeMejoraCadencia(Personaje p,int cantidad)
{
    p->c-=cantidad;
}

void    PersonajeMejoraDolor(Personaje p,int cantidad)
{
    p->d+=cantidad;
}

void    PersonajeMejoraVelocidad(Personaje p, int cantidad)
{
    p->v+=cantidad;
}

void    PersonajeAlteraEscudo(Personaje p, int n)
{
    p->e+=n;
}

void    PersonajeAlteraBomba(Personaje p, int n)
{
    p->b+=n;
}

void PersonajeValido(Personaje p){
    p->valido = 1;
}

int    PersonajeX(Personaje p)
{
    return p->x;
}

int    PersonajeY(Personaje p)
{
    return p->y;
}

int    PersonajeW(Personaje p)
{
    return p->w;
}

int    PersonajeH(Personaje p)
{
    return p->h;
}

int    PersonajeV(Personaje p)
{
    return p->v;
}

int    PersonajeD(Personaje p)
{
    return p->d;
}

int    PersonajeC(Personaje p)
{
    return p->c;
}

int    PersonajeE(Personaje p)
{
    return p->e;
}

int    PersonajeB(Personaje p)
{
    return p->b;
}

int    PersonajeEsValido(Personaje p){
    return p->valido;
}
