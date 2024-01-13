#ifndef BALA_H
#define BALA_H

#include "Pantalla.h"

/**
   \file Bala.h
   \brief  Fichero de cabecera para gestionar balas, utilizado por el m�dulo Rafaga.
   ADVERTENCIA: este m�dulo y sus funciones no est�n pensados para utilizarse en main.c, en su lugar hay que utilizar el m�dulo Rafaga.
*/

/**
    \brief TDA Bala.
 */
typedef struct BalaRep * Bala;

/**
    \brief Crea una nueva bala lista para ser introducida en una r�faga.
    \pre Con respecto a Imagen i: El fichero debe existir y estar en formato Windows BMP 24 bits sin compresi�n.

    \param i Imagen de la bala.
    \param x Posici�n x de la bala.
    \param y Posici�n y de la bala.
    \param w Anchura en p�xeles de la bala.
    \param h Altura en p�xeles de la bala.
    \param v Velocidad a la que se mueve la bala.
    \return Una bala con las caracter�sticas indicadas.
*/
Bala BalaCrea(Imagen i, int x, int y, int w, int h, int v);

/**
    \brief Libera la bala indicada.

    \param b Bala a liberar.
*/
void    BalaLibera(Bala b);

/**
    \brief Mueve la bala hacia arriba.

    \param b Bala a mover.
*/
void    BalaMueve(Bala b, float tiempo_delta);

/**
    \brief Dibuja la bala en pantalla.

    \param b Bala a dibujar.
*/
void    BalaDibuja(Bala b);

/**
    \brief Devuelve la coordenada x de la bala.

    \param b Bala cuya coordenada x se quiere conocer.
*/
int    BalaX(Bala b);

/**
    \brief Devuelve la coordenada y de la bala.

    \param b Bala cuya coordenada y se quiere conocer.
*/
int    BalaY(Bala b);

/**
    \brief Devuelve la anchura en p�xeles de la bala.

    \param b Bala cuya anchura en p�xeles se quiere conocer.
*/
int    BalaW(Bala b);

/**
    \brief Devuelve la altura en p�xeles de la bala.

    \param b Bala cuya altura en p�xeles se quiere conocer.
*/
int    BalaH(Bala b);

#endif // BALA_H
