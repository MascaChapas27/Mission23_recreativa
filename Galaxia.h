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
  \brief Crea una galaxia vac�a en la que se podr�n insertar monedas.

  Se debe ejecutar antes de comenzar el bucle principal del juego.

  \param maximo M�ximo de monedas que contendr� la galaxia.
  \return Una galaxia vac�a.
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

  Se debe ejecutar en cada iteraci�n del bucle principal para poder mostrar las monedas en sus posiciones.

  \param g Galaxia a dibujar.
 */
void GalaxiaDibuja(Galaxia g);

/**
  \brief Inserta una nueva moneda en la galaxia.
  \pre Con respecto a Imagen i: El fichero debe existir y estar en formato Windows BMP 24 bits sin compresi�n.

  Se debe ejecutar cada vez que se quiera insertar una nueva moneda.

  \param g Galaxia en la que se va a insertar una moneda.
  \param i Imagen de la moneda.
  \param x Posici�n x de la moneda.
  \param y Posici�n y de la moneda.
  \param w Anchura en p�xeles de la moneda.
  \param h Altura en p�xeles de la moneda.
 */
void GalaxiaInserta(Galaxia g, Imagen i, int x, int y, int w, int h);

/**
  \brief Comprueba si ha habido una colisi�n con alguna moneda. Si es as�, crea una animaci�n de desvanecimiento de la moneda.
  \pre Con respecto a Imagen monedaDesvanece[]: Los ficheros deben existir y estar en formato Windows BMP 24 bits sin compresi�n.
  \pre Con respecto a int num: debe ser el n�mero exacto de im�genes que contiene el array monedaDesvanece[].

  Se debe ejecutar en cada iteraci�n del bucle principal para poder comprobar si se ha conseguido alguna moneda.
  De ser as�, devuelve un 1 y la moneda en cuesti�n desaparece, se crea una animaci�n de desvanecimiento.

  \param g Galaxia a comprobar.
  \param p Personaje que se est� manejando.
  \param pel Pel�cula en la que se va a insertar la animaci�n de desvanecimiento.
  \param monedaDesvanece[] Array de im�genes en el que se encuentran los fotogramas de la animaci�n de la moneda desvaneci�ndose.
  \param num N�mero de fotogramas de la animaci�n de desvanecimiento.
  \return 1 si ha habido colisi�n con alguna moneda. 0 en caso contrario.
 */
int GalaxiaColision(Galaxia g, Personaje p[], Pelicula pel, Imagen monedaDesvanece[], int num);

#endif  //__GALAXIA_H
