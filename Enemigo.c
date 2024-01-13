#include "Enemigo.h"
#include <stdlib.h>
#include <math.h>

struct EnemigoRep{
    int w,h,t,s,sMax,p;
    float x, y;
    Imagen i;
    int vx,vy;
};

typedef struct EnemigoRep * Enemigo;

Enemigo EnemigoCrea(Imagen i, int x, int y, int w, int h, int vx, int vy, int t, int s, int p)
{
    Enemigo e = malloc(sizeof(struct EnemigoRep));
    e->i = i;
    e->x = x;
    e->y = y;
    e->w = w;
    e->h = h;
    e->vx = vx;
    e->vy = vy;
    e->t = t;
    e->s = s;
    e->sMax = s;
    e->p = p;
    return e;
}

void    EnemigoLibera(Enemigo e)
{
    free(e);
}

void    EnemigoMueve(Enemigo e, Personaje p[], float tiempo_delta)
{   if((e->t == 0) || (e->t == 2) || (e->t == 3) || (e->t == 4))
    {

        e->x+=e->vx*tiempo_delta;
        e->y+=e->vy*tiempo_delta;

        int velX=abs(e->vx);
        int velY=abs(e->vy);

        //Hacemos que el enemigo rebote
        if(e->x>(Pantalla_Anchura()-e->w)){
            e->vx=-velX;
        } else if (e->x<0){
            e->vx=+velX;
        }
        if(e->y>(Pantalla_Altura()-e->h)) {
            e->vy=-velY;
        } else if (e->y<0){
            e->vy=+velY;
        }
    }
    else if(e->t==1)
    {
        int vel=abs(e->vx+e->vy);

        e->x+=e->vx*tiempo_delta;
        e->y+=e->vy*tiempo_delta;

        // Se comprueba si persigue a algún personaje

        for(int i=0;i<2;i++){
            if(!PersonajeEsValido(p[i])) continue;
            if(abs(PersonajeX(p[i]) - e->x)<20){
                if(PersonajeY(p[i]) < e->y){
                    e->vy=-vel;
                    e->vx=0;
                } else {
                    e->vy=vel;
                    e->vx=0;
                }
            } else if(abs(PersonajeY(p[i])-e->y)<20){
                if(PersonajeX(p[i]) < e->x){
                    e->vx=-vel;
                    e->vy=0;
                } else {
                    e->vx=vel;
                    e->vy=0;
                }
            }
        }

        if(e->x>(Pantalla_Anchura()-e->w) || e->x<0){
            e->vx=-e->vx;
            if(e->x<0){
                e->x+=1;
            }
        }
        if(e->y>(Pantalla_Altura()-e->h) || e->y<0){
            e->vy=-e->vy;
        }
    }
    else if(e->t==5)
    {
        e->x+=e->vx*tiempo_delta;
        e->y+=e->vy*tiempo_delta;

        int vxRand=6+rand()%10;
        int vyRand=6+rand()%10;
        if(e->x>(Pantalla_Anchura()-e->w)){
            e->vx=-vxRand;
            e->vy=vyRand*(pow(-1,vyRand));
        }
        if(e->x<0){
            e->vx=vxRand;
            e->vy=vyRand*(pow(-1,vyRand));
        }
        if(e->y>(Pantalla_Altura()-e->h)){
            e->vy=-vyRand;
            e->vx=vxRand*(pow(-1,vxRand));
        }
        if(e->y<0){
            e->vy=vyRand;
            e->vx=vxRand*(pow(-1,vxRand));
        }
    }
}

void    EnemigoDibuja(Enemigo e)
{
    Pantalla_ColorTrazo(0,0,0,255);
    double salud = (double)e->s/(double)e->sMax;
    if(salud<0) salud=0;
    if(salud>0.5) Pantalla_ColorRelleno(255.99*(1-(salud-0.5)*2),255,0,255);
    else Pantalla_ColorRelleno(255,255.99*2*salud,0,255);
    Pantalla_DibujaRectangulo(e->x,e->y-8,e->w*salud,8);
    Pantalla_DibujaImagen(e->i,e->x,e->y,e->w,e->h);
}

void    EnemigoDolor(Enemigo e, int dolor)
{
    e->s-=dolor;
}

Imagen    EnemigoI(Enemigo e)
{
    return e->i;
}

int    EnemigoX(Enemigo e)
{
    return e->x;
}

int    EnemigoY(Enemigo e)
{
    return e->y;
}

int    EnemigoVX(Enemigo e)
{
    return e->vx;
}

int    EnemigoVY(Enemigo e)
{
    return e->vy;
}

int    EnemigoW(Enemigo e)
{
    return e->w;
}

int    EnemigoH(Enemigo e)
{
    return e->h;
}

int    EnemigoS(Enemigo e)
{
    return e->s;
}

int    EnemigoT(Enemigo e)
{
    return e->t;
}

int    EnemigoP(Enemigo e)
{
    return e->p;
}

