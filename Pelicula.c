#include "Pelicula.h"
#include <stdlib.h>

struct PeliculaRep
{
    struct PeliculaRep * sig;
    Animacion a;
};

typedef struct PeliculaRep * Pelicula;

Pelicula PeliculaCrea()
{
    Pelicula nuevo = malloc( sizeof( struct PeliculaRep ));
    nuevo->sig = NULL;
    return nuevo;
}

void    PeliculaInserta(Pelicula p, Imagen i[], int n, int x, int y, int w, int h)
{
    Pelicula nuevo = malloc ( sizeof( struct PeliculaRep));
    nuevo->a = AnimacionCrea(i,n,x,y,w,h);
    nuevo->sig = p->sig;
    p->sig = nuevo;
}

void    PeliculaMueve(Pelicula p, float tiempo_delta)
{
    Pelicula aux = p;
    while ( aux->sig != NULL ){
        if(AnimacionCont(aux->sig->a) == AnimacionN(aux->sig->a)){
            Pelicula borra = aux->sig;
            aux->sig = borra->sig;
            AnimacionLibera(borra->a);
            free( borra );
        } else {
            AnimacionMueve(aux->sig->a, tiempo_delta);
            aux = aux->sig;
        }
    }
}

void    PeliculaLibera(Pelicula p)
{
    while ( p->sig != NULL ){
        Pelicula borrar = p->sig;
        p->sig = borrar->sig;
        AnimacionLibera(borrar->a);
        free( borrar );
    }
    free ( p );
}
