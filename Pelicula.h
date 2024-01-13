#ifndef __PELICULA_H
#define __PELICULA_H
#include "Animacion.h"

/**
   \file Pelicula.h
   \brief  Fichero de cabecera para gestionar conjuntos de animaciones est�ticas (es decir, que ocurren en un punto fijo de la pantalla).
   Permite crear animaciones compuestas de varios fotogramas que se reproducen con una posici�n y tama�o determinadas.
*/

/**
    \brief TDA Pelicula.
 */
typedef struct PeliculaRep * Pelicula;

/**
  \brief Crea una pel�cula vac�a en la que podemos insertar animaciones

  Se debe ejecutar antes de comenzar el bucle principal del juego.

  \return Una pel�cula vac�a.
 */
Pelicula PeliculaCrea();

/**
  \brief Inserta una nueva animaci�n en la pel�cula.
  \pre Con respecto a Imagen i[]: Los ficheros deben existir y estar en formato Windows BMP 24 bits sin compresi�n.
  \pre Con respecto a int n: debe ser el n�mero exacto de im�genes que contiene el array i[].

  Se debe ejecutar en el bucle principal del juego, cuando queramos que se reproduzca una animaci�n.

  \param p Pel�cula en la que queremos insertar la animaci�n.
  \param i[] Array de im�genes en el que est�n los fotogramas de la animaci�n.
  \param n N�mero de fotogramas de la animaci�n.
  \param x Posici�n x de la animaci�n.
  \param y Posici�n y de la animaci�n.
  \param w Anchura en p�xeles de la animaci�n.
  \param h Altura en p�xeles de la animaci�n.
 */
void    PeliculaInserta(Pelicula p, Imagen i[], int n, int x, int y, int w, int h);

/**
  \brief Avanza al siguiente fotograma en todas las animaciones y lo muestra. Si una animaci�n ha acabado, la libera.

  Se debe ejecutar en el bucle principal del juego.

  \param p Pel�cula que queremos mover.
 */
void    PeliculaMueve(Pelicula p, float tiempo_delta);

/**
  \brief Libera todas las animaciones, y luego libera la pel�cula.

  Se debe ejecutar al terminar el juego.

  \param p Pel�cula que queremos liberar.
 */
void    PeliculaLibera(Pelicula p);

#endif
