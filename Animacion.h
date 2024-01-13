#ifndef __ANIMACION_H
#define __ANIMACION_H
#include "Pantalla.h"

/**
   \file Animacion.h
   \brief  Fichero de cabecera para gestionar animaciones, utilizado por el m�dulo Pelicula.
   ADVERTENCIA: este m�dulo y sus funciones no est�n pensados para utilizarse en main.c, en su lugar hay que utilizar el m�dulo Pelicula.
*/

/**
    \brief TDA Animacion.
 */
typedef struct AnimacionRep * Animacion;

/**
    \brief Crea una nueva animaci�n lista para ser insertada en una Pelicula.
    \pre Con respecto a Imagen i[]: Los ficheros deben existir y estar en formato Windows BMP 24 bits sin compresi�n.

    \pre Con respecto a int n: debe ser el n�mero exacto de im�genes que contiene el array i[].

    \param i[] Array de im�genes que contiene los fotogramas de la animaci�n.
    \param n N�mero de fotogramas de la animaci�n.
    \param x Posici�n x de la animaci�n.
    \param y Posici�n x de la animaci�n.
    \param w Anchura en p�xeles de la animaci�n.
    \param h Altura en p�xeles de la animaci�n.
    \return Una animaci�n con las caracter�sticas indicadas.
*/
Animacion AnimacionCrea(Imagen i[], int n, int x, int y, int w, int h);

/**
    \brief Libera la animaci�n indicada.

    \param a Animaci�n a liberar.
*/
void    AnimacionLibera(Animacion a);

/**
    \brief Muestra el fotograma actual de la animaci�n y avanza al siguiente.

    \param a Animaci�n a mover.
*/
void    AnimacionMueve(Animacion a, float tiempo_delta);

/**
    \brief Devuelve el fotograma por el que va la animaci�n.

    \param a Animaci�n cuyo contador de fotograma queremos conocer.
    \return N�mero de fotograma por el que va la animaci�n (valor entre 0 y n-1).
*/
int     AnimacionCont(Animacion a);

/**
    \brief Devuelve el n�mero de fotogramas que tiene la animaci�n.

    \param a Animaci�n cuyo n�mero de fotogramas se quiere conocer.
    \return N�mero de fotogramas de la animaci�n en total.
*/
int     AnimacionN(Animacion a);

#endif
