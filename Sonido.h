#ifndef __SONIDO_H__
#define __SONIDO_H__

#include "SDL2/SDL.h"
/**
   \file Sonido.h
   \brief  Fichero de cabecera para gestionar sonidos
*/

/**
    \brief TDA Sonido
*/
typedef struct SonidoRep * Sonido;

/**
  \brief Crea un sonido en base a un fichero de audio

  El sonido no se reproduce al crearlo, se tiene que llamar a reproduceSonido() o reproduceMusica()

  \pre Por alguna razón en algunas máquinas no se pueden crear sonidos o solo se puede crear un número limitado

  \param archivo Ruta al fichero, puede ser absoluta o relativa
  \return Un sonido listo para ser reproducido
*/
Sonido creaSonido(const char * archivo);

/**
  \brief Reproduce un sonido dado

  \param s Sonido a reproducir
*/
void reproduceSonido(Sonido s);

/**
  \brief Reproduce un sonido, y lo vuelve a reproducir si se termina. Es necesario llamar a esta función periódicamente para que compruebe si ha terminado y lo reproduzca otra vez

  \param s Música a reproducir
*/
void reproduceMusica(Sonido s);

/**
    \brief Termina la reproducción del sonido

    \param s Sonido a detener
*/
void paraSonido(Sonido s);

/**
    \brief Prepara un sonido (ya se encarga creaSonido(), no hace falta usarlo desde fuera)

    Si esto fuera java sería un método de esos private.

    \param s Sonido a preparar
*/
void preparaSonido(Sonido s);

/**
    \brief Libera los recursos asociados al sonido

    \param s Sonido a liberar
*/
void liberaSonido(Sonido s);

#endif // __SONIDO_H__
