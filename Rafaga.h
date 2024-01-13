#ifndef __RAFAGA_H
#define __RAFAGA_H
#include "Pelicula.h"
#include "Ejercito.h"

/**
   \file Rafaga.h
   \brief  Fichero de cabecera para gestionar ráfagas de balas.
*/

/**
    \brief TDA Rafaga.
 */
typedef struct RafagaRep * Rafaga;

/**
  \brief Crea una ráfaga vacía en la que podremos meter balas.

  Se debe ejecutar antes de comenzar el bucle principal del juego.

  \return Una ráfaga vacía.
 */
Rafaga RafagaCrea();

/**
  \brief Inserta una nueva bala en la ráfaga.
  \pre Con respecto a Imagen i: El fichero debe existir y estar en formato Windows BMP 24 bits sin compresión.

  Se debe ejecutar en el bucle principal del juego, cuando disparemos una o varias balas.

  \param r Ráfaga en la que queremos insertar la bala.
  \param i Imagen del la bala.
  \param x Posición x de la bala.
  \param y Posición y de la bala.
  \param w Anchura en píxeles de la bala.
  \param h Altura en píxeles de la bala.
  \param v Velocidad de la bala.
 */
void    RafagaInserta(Rafaga r, Imagen i, int x, int y, int w, int h, int v);

/**
  \brief Dibuja las balas en la pantalla.

  Se debe ejecutar cuando queramos mostrar las balas en la pantalla (preferiblemente después de RafagaMueve).

  \param r Ráfaga cuyas balas queremos dibujar.
 */
void    RafagaDibuja(Rafaga r);

/**
  \brief Mueve las balas de la ráfaga.

  Se debe ejecutar en cada iteración del bucle para que las balas se muevan.

  \param r Ráfaga cuyas balas queremos mover.
 */
void    RafagaMueve(Rafaga r, float tiempo_delta);

/**
  \brief Comprueba si las balas se han escapado por arriba y libera las que lo han hecho.

  Se debe ejecutar en cada iteración del bucle para comprobar si las balas han superado el límite superior de la pantalla en 50 píxeles.

  \param r Ráfaga cuyas balas queremos comprobar.
 */
void     RafagaTocaTecho(Rafaga r);

/**
  \brief Va comprobando si las balas colisionan con los enemigos que hay en pantalla. De ser así, se crea una colisión de impacto de bala.

  Se debe ejecutar en cada iteración del bucle para comprobar si los disparon han acertado.

  \param r Ráfaga que contiene las balas.
  \param e Ejército que contiene los enemigos.
  \param dolor Daño que hace el personaje por bala.
  \param p Película en la que se va a insertar la animación de impacto de bala.
  \param n Número de fotogramas que contiene la animación de impacto de bala.
  \param balaColisionaImagen[] Array que contiene los fotogramas de la animación de impacto de bala.
  \param w Anchura de la animación de impacto de bala.
  \param h Altura de la animación de impacto de bala.
 */
int     RafagaColision(Rafaga r, Ejercito e, int dolor, Pelicula p, int n, Imagen balaColisionaImagen[], int w, int h);

/**
  \brief Libera la ráfaga y todas las balas que contiene.

  Se debe ejecutar al final de la partida.

  \param r Ráfaga que queremos liberar.
 */
void     RafagaLibera(Rafaga r);

#endif // __RAFAGA_H__
