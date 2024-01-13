#ifndef __RAFAGA_H
#define __RAFAGA_H
#include "Pelicula.h"
#include "Ejercito.h"

/**
   \file Rafaga.h
   \brief  Fichero de cabecera para gestionar r�fagas de balas.
*/

/**
    \brief TDA Rafaga.
 */
typedef struct RafagaRep * Rafaga;

/**
  \brief Crea una r�faga vac�a en la que podremos meter balas.

  Se debe ejecutar antes de comenzar el bucle principal del juego.

  \return Una r�faga vac�a.
 */
Rafaga RafagaCrea();

/**
  \brief Inserta una nueva bala en la r�faga.
  \pre Con respecto a Imagen i: El fichero debe existir y estar en formato Windows BMP 24 bits sin compresi�n.

  Se debe ejecutar en el bucle principal del juego, cuando disparemos una o varias balas.

  \param r R�faga en la que queremos insertar la bala.
  \param i Imagen del la bala.
  \param x Posici�n x de la bala.
  \param y Posici�n y de la bala.
  \param w Anchura en p�xeles de la bala.
  \param h Altura en p�xeles de la bala.
  \param v Velocidad de la bala.
 */
void    RafagaInserta(Rafaga r, Imagen i, int x, int y, int w, int h, int v);

/**
  \brief Dibuja las balas en la pantalla.

  Se debe ejecutar cuando queramos mostrar las balas en la pantalla (preferiblemente despu�s de RafagaMueve).

  \param r R�faga cuyas balas queremos dibujar.
 */
void    RafagaDibuja(Rafaga r);

/**
  \brief Mueve las balas de la r�faga.

  Se debe ejecutar en cada iteraci�n del bucle para que las balas se muevan.

  \param r R�faga cuyas balas queremos mover.
 */
void    RafagaMueve(Rafaga r, float tiempo_delta);

/**
  \brief Comprueba si las balas se han escapado por arriba y libera las que lo han hecho.

  Se debe ejecutar en cada iteraci�n del bucle para comprobar si las balas han superado el l�mite superior de la pantalla en 50 p�xeles.

  \param r R�faga cuyas balas queremos comprobar.
 */
void     RafagaTocaTecho(Rafaga r);

/**
  \brief Va comprobando si las balas colisionan con los enemigos que hay en pantalla. De ser as�, se crea una colisi�n de impacto de bala.

  Se debe ejecutar en cada iteraci�n del bucle para comprobar si los disparon han acertado.

  \param r R�faga que contiene las balas.
  \param e Ej�rcito que contiene los enemigos.
  \param dolor Da�o que hace el personaje por bala.
  \param p Pel�cula en la que se va a insertar la animaci�n de impacto de bala.
  \param n N�mero de fotogramas que contiene la animaci�n de impacto de bala.
  \param balaColisionaImagen[] Array que contiene los fotogramas de la animaci�n de impacto de bala.
  \param w Anchura de la animaci�n de impacto de bala.
  \param h Altura de la animaci�n de impacto de bala.
 */
int     RafagaColision(Rafaga r, Ejercito e, int dolor, Pelicula p, int n, Imagen balaColisionaImagen[], int w, int h);

/**
  \brief Libera la r�faga y todas las balas que contiene.

  Se debe ejecutar al final de la partida.

  \param r R�faga que queremos liberar.
 */
void     RafagaLibera(Rafaga r);

#endif // __RAFAGA_H__
