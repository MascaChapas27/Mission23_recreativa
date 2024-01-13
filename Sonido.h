#ifndef __SONIDO_H__
#define __SONIDO_H__

#include "SDL2/SDL.h"

typedef struct SonidoRep * Sonido;

Sonido creaSonido(const char * archivo);

void reproduceSonido(Sonido s);

void reproduceMusica(Sonido s);

void paraSonido(Sonido s);

void preparaSonido(Sonido s);

void liberaSonido(Sonido s);

#endif // __SONIDO_H__
