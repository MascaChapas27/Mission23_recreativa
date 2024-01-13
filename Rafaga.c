#include "Rafaga.h"
#include <stdlib.h>
#include "Colision.h"
#include "Bala.h"

struct RafagaRep
{
    Bala b;
    struct RafagaRep * sig;
};

typedef struct RafagaRep * Rafaga;

Rafaga RafagaCrea()
{
    Rafaga nuevo = malloc( sizeof( struct RafagaRep ));
    nuevo->sig = NULL;
    return nuevo;
}

void    RafagaInserta(Rafaga r, Imagen i, int x, int y, int w, int h, int v)
{
    Rafaga nuevo = malloc ( sizeof( struct RafagaRep));
    nuevo->b = BalaCrea(i,x,y,w,h,v);
    nuevo->sig = r->sig;
    r->sig = nuevo;
}

void    RafagaDibuja(Rafaga r)
{
    Rafaga aux = r;
    while ( aux->sig != NULL ){
        BalaDibuja(aux->sig->b);
        aux = aux->sig;
    }
}

void    RafagaMueve(Rafaga r, float tiempo_delta)
{
    Rafaga aux = r;
    while ( aux->sig != NULL ){
        BalaMueve(aux->sig->b, tiempo_delta);
        aux = aux->sig;
    }
}

void     RafagaTocaTecho(Rafaga r)
{
    Rafaga aux = r;
    while ( aux->sig != NULL ){
        if (BalaY(aux->sig->b)<=-50){
            Rafaga borrar = aux->sig;
            aux->sig = borrar->sig;
            BalaLibera(borrar->b);
            free( borrar );
        } else {
            aux = aux->sig;
        }
    }
}

int     RafagaColision(Rafaga r, Ejercito e, int dolor, Pelicula p, int n, Imagen balaColisionaImagen[], int w, int h)
{
    Ejercito aux1 = e;
    int hayColision = 0;
    while ( EjercitoSiguiente(aux1) != NULL ){
        Rafaga aux2 = r;
        while ( aux2->sig != NULL ){
            if (EnemigoS(EjercitoEnemigo(aux1))>0 && Colision(EnemigoX(EjercitoEnemigo(aux1)),EnemigoY(EjercitoEnemigo(aux1)),EnemigoW(EjercitoEnemigo(aux1)),EnemigoH(EjercitoEnemigo(aux1)),BalaX(aux2->sig->b),BalaY(aux2->sig->b),BalaW(aux2->sig->b),BalaH(aux2->sig->b))){
                hayColision=1;
                PeliculaInserta(p,balaColisionaImagen,n,BalaX(aux2->sig->b)-BalaW(aux2->sig->b)/2,BalaY(aux2->sig->b)-BalaH(aux2->sig->b)/2,w,h);
                EnemigoDolor(EjercitoEnemigo(aux1),dolor);
                Rafaga borrar = aux2->sig;
                aux2->sig = borrar->sig;
                BalaLibera(borrar->b);
                free( borrar );
            } else {
                aux2 = aux2->sig;
            }
        }
        aux1=EjercitoSiguiente(aux1);
    }
    return hayColision;
}

void    RafagaLibera(Rafaga r)
{
    while ( r->sig != NULL ){
        Rafaga borrar = r->sig;
        r->sig = borrar->sig;
        BalaLibera(borrar->b);
        free( borrar );
    }
    free ( r );
}
