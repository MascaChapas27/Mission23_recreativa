#include "Ejercito.h"
#include <stdlib.h>
#include "Colision.h"


struct EjercitoRep
{
    Enemigo e;
    struct EjercitoRep * sig;
};

typedef struct EjercitoRep * Ejercito;

Ejercito EjercitoCrea()
{
    Ejercito nuevo = malloc( sizeof( struct EjercitoRep ));
    nuevo->sig = NULL;
    return nuevo;
}

void    EjercitoInserta(Ejercito e, Imagen i, int x, int y, int w, int h, int vx, int vy, int t, int s, int p)
{
    Ejercito nuevo = malloc ( sizeof( struct EjercitoRep));
    nuevo->e = EnemigoCrea(i,x,y,w,h,vx,vy,t,s,p);
    nuevo->sig = e->sig;
    e->sig = nuevo;
}

void    EjercitoDibuja(Ejercito e)
{
    Ejercito aux = e;
    while ( aux->sig != NULL ){
        EnemigoDibuja(aux->sig->e);
        aux = aux->sig;
    }
}

void    EjercitoMueve(Ejercito e, Personaje p[], float tiempo_delta)
{
    Ejercito aux = e;
    while ( aux->sig != NULL ){
        EnemigoMueve(aux->sig->e, p, tiempo_delta);
        if(EnemigoT(aux->sig->e)==2 && rand()%1000 == 1) {
            EnemigoReseteaTemp(aux->sig->e);
            EjercitoInserta(e,EnemigoI(aux->sig->e),EnemigoX(aux->sig->e),EnemigoY(aux->sig->e),EnemigoW(aux->sig->e)/2,EnemigoH(aux->sig->e)/2,EnemigoVX(aux->sig->e)*2,EnemigoVY(aux->sig->e)*2,0,EnemigoS(aux->sig->e)/4,EnemigoP(aux->sig->e)/4);
        }
        if(EnemigoT(aux->sig->e)==3 && rand()%100 == 1){
            // El enemigo de tipo 3 dispara
            for(int i=0;i<2;i++){
                if(!PersonajeEsValido(p[i])) continue;
                EnemigoReseteaTemp(aux->sig->e);
                if(abs(PersonajeX(p[i])-EnemigoX(aux->sig->e))<20){
                    if(PersonajeY(p[i])<EnemigoY(aux->sig->e)){
                        EjercitoInserta(e,EnemigoI(aux->sig->e),EnemigoX(aux->sig->e),EnemigoY(aux->sig->e),EnemigoW(aux->sig->e)/2,EnemigoH(aux->sig->e)/2,0,-2*abs(EnemigoVY(aux->sig->e)),0,EnemigoS(aux->sig->e)/4,EnemigoP(aux->sig->e)/4);
                    } else {
                        EjercitoInserta(e,EnemigoI(aux->sig->e),EnemigoX(aux->sig->e),EnemigoY(aux->sig->e),EnemigoW(aux->sig->e)/2,EnemigoH(aux->sig->e)/2,0,2*abs(EnemigoVY(aux->sig->e)),0,EnemigoS(aux->sig->e)/4,EnemigoP(aux->sig->e)/4);
                    }
                }
                if(abs(PersonajeY(p[i])-EnemigoY(aux->sig->e))<20){
                    if(PersonajeX(p[i])<EnemigoX(aux->sig->e)){
                        EjercitoInserta(e,EnemigoI(aux->sig->e),EnemigoX(aux->sig->e),EnemigoY(aux->sig->e),EnemigoW(aux->sig->e)/2,EnemigoH(aux->sig->e)/2,-2*abs(EnemigoVX(aux->sig->e)),0,0,EnemigoS(aux->sig->e)/4,EnemigoP(aux->sig->e)/4);
                    } else {
                        EjercitoInserta(e,EnemigoI(aux->sig->e),EnemigoX(aux->sig->e),EnemigoY(aux->sig->e),EnemigoW(aux->sig->e)/2,EnemigoH(aux->sig->e)/2,2*abs(EnemigoVX(aux->sig->e)),0,0,EnemigoS(aux->sig->e)/4,EnemigoP(aux->sig->e)/4);
                    }
                }
            }

        }
        aux = aux->sig;
    }
}

int     EjercitoColision(Ejercito e, Personaje p[])
{
    Ejercito aux = e;
    while ( aux->sig != NULL ){
        if ((PersonajeEsValido(p[0]) && Colision(PersonajeX(p[0]), PersonajeY(p[0]), PersonajeW(p[0]), PersonajeH(p[0]), EnemigoX(aux->sig->e),EnemigoY(aux->sig->e),EnemigoW(aux->sig->e),EnemigoH(aux->sig->e))) ||
            (PersonajeEsValido(p[1]) && Colision(PersonajeX(p[1]), PersonajeY(p[1]), PersonajeW(p[1]), PersonajeH(p[1]), EnemigoX(aux->sig->e),EnemigoY(aux->sig->e),EnemigoW(aux->sig->e),EnemigoH(aux->sig->e)))){
            Ejercito borrar = aux->sig;
            aux->sig = borrar->sig;
            EnemigoLibera(borrar->e);
            free( borrar );
            return 1;
        }
        aux = aux->sig;
    }
    return 0;
}

int    EjercitoComprobar(Ejercito e, Pelicula p, Imagen enemigoExplota[], int n)
{
    int contador=0;
    Ejercito aux = e;
    while ( aux->sig != NULL ){
        if (EnemigoS(aux->sig->e) <= 0){
            if(EnemigoT(aux->sig->e)==4){
                Imagen i = EnemigoI(aux->sig->e);
                int x = EnemigoX(aux->sig->e);
                int y = EnemigoY(aux->sig->e);
                int w = EnemigoW(aux->sig->e)/2;
                int h = EnemigoH(aux->sig->e)/2;
                int v = EnemigoVX(aux->sig->e);
                EjercitoInserta(e,i,x,y,w,h,v,v,0,1,1);
                EjercitoInserta(e,i,x,y,w,h,v,-v,0,1,1);
                EjercitoInserta(e,i,x,y,w,h,-v,v,0,1,1);
                EjercitoInserta(e,i,x,y,w,h,-v,-v,0,1,1);
            }
            PeliculaInserta(p,enemigoExplota,n,EnemigoX(aux->sig->e),EnemigoY(aux->sig->e),EnemigoW(aux->sig->e),EnemigoH(aux->sig->e));
            contador+=EnemigoP(aux->sig->e);
            Ejercito borrar = aux->sig;
            aux->sig = borrar->sig;
            EnemigoLibera(borrar->e);
            free( borrar );
        } else {
            aux = aux->sig;
        }
    }
    return contador;
}

int    EjercitoDestruye(Ejercito e, Pelicula p, Imagen enemigoExplota[], int n)
{
    int contador=0;
    Ejercito aux = e;
    while ( aux->sig != NULL ){
        PeliculaInserta(p,enemigoExplota,n,EnemigoX(aux->sig->e),EnemigoY(aux->sig->e),EnemigoW(aux->sig->e),EnemigoH(aux->sig->e));
        contador+=EnemigoP(aux->sig->e);
        Ejercito borrar = aux->sig;
        aux->sig = borrar->sig;
        EnemigoLibera(borrar->e);
        free( borrar );
    }
    return contador;
}

void    EjercitoLibera(Ejercito e)
{
    while ( e->sig != NULL ){
        Ejercito borrar = e->sig;
        e->sig = borrar->sig;
        EnemigoLibera(borrar->e);
        free( borrar );
    }
    free ( e );
}

Ejercito EjercitoSiguiente(Ejercito e)
{
    return e->sig;
}

Enemigo EjercitoEnemigo(Ejercito e)
{
    return e->sig->e;
}
