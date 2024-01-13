#ifndef __MONEDA_H
#define __MONEDA_H

#include "Pantalla.h"

/**
   \file Moneda.h
   \brief  Fichero de cabecera para gestionar monedas, utilizado por el m�dulo Galaxia.
   ADVERTENCIA: este m�dulo y sus funciones no est�n pensados para utilizarse en main.c, en su lugar hay que utilizar el m�dulo Galaxia.
*/

/**
    \brief TDA Moneda.
 */
typedef struct MonedaRep * Moneda;

/**
    \brief Crea una nueva moneda lista para ser introducida en una galaxia.
    \pre Con respecto a Imagen i: El fichero debe existir y estar en formato Windows BMP 24 bits sin compresi�n.

    \param i Imagen de la moneda.
    \param x Posici�n x en la que aparece la moneda.
    \param y Posici�n y en la que aparece la moneda.
    \param w Anchura en p�xeles de la moneda.
    \param h Altura en p�xeles de la moneda.
    \return Una moneda con las caracter�sticas indicadas.
*/
Moneda MonedaCrea(Imagen i, int x, int y, int w, int h);

/**
    \brief Libera la moneda indicada.

    \param m Moneda a liberar.
*/
void    MonedaLibera(Moneda m);

/**
    \brief Dibuja en pantalla la moneda.

    \param m Moneda a dibujar.
*/
void    MonedaDibuja(Moneda m);

/**
    \brief Devuelve la posici�n x de la moneda.

    \param m Moneda.
    \return Posici�n x de la moneda.
*/
int    MonedaX(Moneda m);

/**
    \brief Devuelve la posici�n y de la moneda.

    \param m Moneda.
    \return Posici�n y de la moneda.
*/
int    MonedaY(Moneda m);

/**
    \brief Devuelve la anchura en p�xeles de la moneda.

    \param m Moneda.
    \return Anchura en p�xeles de la moneda.
*/
int    MonedaW(Moneda m);

/**
    \brief Devuelve la altura en p�xeles de la moneda.

    \param m Moneda.
    \return Altura en p�xeles de la moneda.
*/
int    MonedaH(Moneda m);

#endif // __MONEDA_H
