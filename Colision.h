#ifndef COLISION_H
#define COLISION_H

/**
   \file Colision.h
   \brief  Fichero de cabecera para detectar colisiones entre elementos, utilizado por los m�dulos Rafaga, Galaxia y Ejercito.
   ADVERTENCIA: este m�dulo y sus funciones no est�n pensados para utilizarse en main.c, en su lugar hay que utilizar el m�dulo Pelicula.
*/

/**
  \brief Devuelve 1 si los dos elementos especificados colisionan.

  La "caja de colisiones" de los elementos se calcula en base a su tama�o. Si son m�s altos que anchos, se calcula en base a su anchura. Lo contrario si son m�s anchos que altos.

  \param x1 Posici�n x del primer elemento.
  \param y1 Posici�n y del primer elemento.
  \param w1 Anchura en p�xeles del primer elemento.
  \param h1 Altura en p�xeles del primer elemento.
  \param x2 Posici�n x del segundo elemento.
  \param y2 Posici�n y del segundo elemento.
  \param w2 Anchura en p�xeles del segundo elemento.
  \param h2 Altura en p�xeles del segundo elemento.
  \return 1 si hay colisi�n.
  \return 0 si no hay colisi�n.
 */
int Colision(int x1, int y1, int w1, int h1, int x2, int y2, int h2, int w2);

#endif // COLISION_H
