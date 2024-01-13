#ifndef __MONEDA_H
#define __MONEDA_H

#include "Pantalla.h"

/**
   \file Moneda.h
   \brief  Fichero de cabecera para gestionar monedas, utilizado por el módulo Galaxia.
   ADVERTENCIA: este módulo y sus funciones no están pensados para utilizarse en main.c, en su lugar hay que utilizar el módulo Galaxia.
*/

/**
    \brief TDA Moneda.
 */
typedef struct MonedaRep * Moneda;

/**
    \brief Crea una nueva moneda lista para ser introducida en una galaxia.
    \pre Con respecto a Imagen i: El fichero debe existir y estar en formato Windows BMP 24 bits sin compresión.

    \param i Imagen de la moneda.
    \param x Posición x en la que aparece la moneda.
    \param y Posición y en la que aparece la moneda.
    \param w Anchura en píxeles de la moneda.
    \param h Altura en píxeles de la moneda.
    \return Una moneda con las características indicadas.
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
    \brief Devuelve la posición x de la moneda.

    \param m Moneda.
    \return Posición x de la moneda.
*/
int    MonedaX(Moneda m);

/**
    \brief Devuelve la posición y de la moneda.

    \param m Moneda.
    \return Posición y de la moneda.
*/
int    MonedaY(Moneda m);

/**
    \brief Devuelve la anchura en píxeles de la moneda.

    \param m Moneda.
    \return Anchura en píxeles de la moneda.
*/
int    MonedaW(Moneda m);

/**
    \brief Devuelve la altura en píxeles de la moneda.

    \param m Moneda.
    \return Altura en píxeles de la moneda.
*/
int    MonedaH(Moneda m);

#endif // __MONEDA_H
