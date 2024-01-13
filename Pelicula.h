#ifndef __PELICULA_H
#define __PELICULA_H
#include "Animacion.h"

/**
   \file Pelicula.h
   \brief  Fichero de cabecera para gestionar conjuntos de animaciones estáticas (es decir, que ocurren en un punto fijo de la pantalla).
   Permite crear animaciones compuestas de varios fotogramas que se reproducen con una posición y tamaño determinadas.
*/

/**
    \brief TDA Pelicula.
 */
typedef struct PeliculaRep * Pelicula;

/**
  \brief Crea una película vacía en la que podemos insertar animaciones

  Se debe ejecutar antes de comenzar el bucle principal del juego.

  \return Una película vacía.
 */
Pelicula PeliculaCrea();

/**
  \brief Inserta una nueva animación en la película.
  \pre Con respecto a Imagen i[]: Los ficheros deben existir y estar en formato Windows BMP 24 bits sin compresión.
  \pre Con respecto a int n: debe ser el número exacto de imágenes que contiene el array i[].

  Se debe ejecutar en el bucle principal del juego, cuando queramos que se reproduzca una animación.

  \param p Película en la que queremos insertar la animación.
  \param i[] Array de imágenes en el que están los fotogramas de la animación.
  \param n Número de fotogramas de la animación.
  \param x Posición x de la animación.
  \param y Posición y de la animación.
  \param w Anchura en píxeles de la animación.
  \param h Altura en píxeles de la animación.
 */
void    PeliculaInserta(Pelicula p, Imagen i[], int n, int x, int y, int w, int h);

/**
  \brief Avanza al siguiente fotograma en todas las animaciones y lo muestra. Si una animación ha acabado, la libera.

  Se debe ejecutar en el bucle principal del juego.

  \param p Película que queremos mover.
 */
void    PeliculaMueve(Pelicula p, float tiempo_delta);

/**
  \brief Libera todas las animaciones, y luego libera la película.

  Se debe ejecutar al terminar el juego.

  \param p Película que queremos liberar.
 */
void    PeliculaLibera(Pelicula p);

#endif
