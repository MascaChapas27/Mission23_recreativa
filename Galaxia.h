#ifndef __GALAXIA_H
#define __GALAXIA_H
#include "Personaje.h"
#include "Pelicula.h"

/**
   \file Galaxia.h
   \brief  Fichero de cabecera para gestionar conjuntos de monedas.
*/

/**
    \brief TDA Galaxia.
 */
typedef struct GalaxiaRep * Galaxia;

/**
  \brief Crea una galaxia vacía en la que se podrán insertar monedas.

  Se debe ejecutar antes de comenzar el bucle principal del juego.

  \param maximo Máximo de monedas que contendrá la galaxia.
  \return Una galaxia vacía.
 */
Galaxia GalaxiaCrea(int maximo);

/**
  \brief Libera la galaxia y todas las monedas que contiene.

  Se debe ejecutar al final de la partida.

  \param g Galaxia a liberar.
 */
void GalaxiaLibera(Galaxia g);

/**
  \brief Dibuja todas las monedas de la galaxia.

  Se debe ejecutar en cada iteración del bucle principal para poder mostrar las monedas en sus posiciones.

  \param g Galaxia a dibujar.
 */
void GalaxiaDibuja(Galaxia g);

/**
  \brief Inserta una nueva moneda en la galaxia.
  \pre Con respecto a Imagen i: El fichero debe existir y estar en formato Windows BMP 24 bits sin compresión.

  Se debe ejecutar cada vez que se quiera insertar una nueva moneda.

  \param g Galaxia en la que se va a insertar una moneda.
  \param i Imagen de la moneda.
  \param x Posición x de la moneda.
  \param y Posición y de la moneda.
  \param w Anchura en píxeles de la moneda.
  \param h Altura en píxeles de la moneda.
 */
void GalaxiaInserta(Galaxia g, Imagen i, int x, int y, int w, int h);

/**
  \brief Comprueba si ha habido una colisión con alguna moneda. Si es así, crea una animación de desvanecimiento de la moneda.
  \pre Con respecto a Imagen monedaDesvanece[]: Los ficheros deben existir y estar en formato Windows BMP 24 bits sin compresión.
  \pre Con respecto a int num: debe ser el número exacto de imágenes que contiene el array monedaDesvanece[].

  Se debe ejecutar en cada iteración del bucle principal para poder comprobar si se ha conseguido alguna moneda.
  De ser así, devuelve un 1 y la moneda en cuestión desaparece, se crea una animación de desvanecimiento.

  \param g Galaxia a comprobar.
  \param p Personaje que se está manejando.
  \param pel Película en la que se va a insertar la animación de desvanecimiento.
  \param monedaDesvanece[] Array de imágenes en el que se encuentran los fotogramas de la animación de la moneda desvaneciéndose.
  \param num Número de fotogramas de la animación de desvanecimiento.
  \return 1 si ha habido colisión con alguna moneda. 0 en caso contrario.
 */
int GalaxiaColision(Galaxia g, Personaje p[], Pelicula pel, Imagen monedaDesvanece[], int num);

#endif  //__GALAXIA_H
