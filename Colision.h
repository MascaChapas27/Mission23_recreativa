#ifndef COLISION_H
#define COLISION_H

/**
   \file Colision.h
   \brief  Fichero de cabecera para detectar colisiones entre elementos, utilizado por los módulos Rafaga, Galaxia y Ejercito.
   ADVERTENCIA: este módulo y sus funciones no están pensados para utilizarse en main.c, en su lugar hay que utilizar el módulo Pelicula.
*/

/**
  \brief Devuelve 1 si los dos elementos especificados colisionan.

  La "caja de colisiones" de los elementos se calcula en base a su tamaño. Si son más altos que anchos, se calcula en base a su anchura. Lo contrario si son más anchos que altos.

  \param x1 Posición x del primer elemento.
  \param y1 Posición y del primer elemento.
  \param w1 Anchura en píxeles del primer elemento.
  \param h1 Altura en píxeles del primer elemento.
  \param x2 Posición x del segundo elemento.
  \param y2 Posición y del segundo elemento.
  \param w2 Anchura en píxeles del segundo elemento.
  \param h2 Altura en píxeles del segundo elemento.
  \return 1 si hay colisión.
  \return 0 si no hay colisión.
 */
int Colision(int x1, int y1, int w1, int h1, int x2, int y2, int h2, int w2);

#endif // COLISION_H
