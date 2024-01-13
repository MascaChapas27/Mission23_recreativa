#ifndef __ANIMACION_H
#define __ANIMACION_H
#include "Pantalla.h"

/**
   \file Animacion.h
   \brief  Fichero de cabecera para gestionar animaciones, utilizado por el módulo Pelicula.
   ADVERTENCIA: este módulo y sus funciones no están pensados para utilizarse en main.c, en su lugar hay que utilizar el módulo Pelicula.
*/

/**
    \brief TDA Animacion.
 */
typedef struct AnimacionRep * Animacion;

/**
    \brief Crea una nueva animación lista para ser insertada en una Pelicula.
    \pre Con respecto a Imagen i[]: Los ficheros deben existir y estar en formato Windows BMP 24 bits sin compresión.

    \pre Con respecto a int n: debe ser el número exacto de imágenes que contiene el array i[].

    \param i[] Array de imágenes que contiene los fotogramas de la animación.
    \param n Número de fotogramas de la animación.
    \param x Posición x de la animación.
    \param y Posición x de la animación.
    \param w Anchura en píxeles de la animación.
    \param h Altura en píxeles de la animación.
    \return Una animación con las características indicadas.
*/
Animacion AnimacionCrea(Imagen i[], int n, int x, int y, int w, int h);

/**
    \brief Libera la animación indicada.

    \param a Animación a liberar.
*/
void    AnimacionLibera(Animacion a);

/**
    \brief Muestra el fotograma actual de la animación y avanza al siguiente.

    \param a Animación a mover.
*/
void    AnimacionMueve(Animacion a, float tiempo_delta);

/**
    \brief Devuelve el fotograma por el que va la animación.

    \param a Animación cuyo contador de fotograma queremos conocer.
    \return Número de fotograma por el que va la animación (valor entre 0 y n-1).
*/
int     AnimacionCont(Animacion a);

/**
    \brief Devuelve el número de fotogramas que tiene la animación.

    \param a Animación cuyo número de fotogramas se quiere conocer.
    \return Número de fotogramas de la animación en total.
*/
int     AnimacionN(Animacion a);

#endif
