#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Personaje.h"

/**
   \file Enemigo.h
   \brief  Fichero de cabecera para gestionar enemigos, utilizado por el m�dulo Ejercito.
   ADVERTENCIA: este m�dulo y sus funciones no est�n pensados para utilizarse en main.c, en su lugar hay que utilizar el m�dulo Ejercito.
*/

/**
    \brief TDA Enemigo.
 */
typedef struct EnemigoRep * Enemigo;

/**
    \brief Crea un nuevo enemigo listo para ser introducido en un ej�rcito.
    \pre Con respecto a Imagen i: El fichero debe existir y estar en formato Windows BMP 24 bits sin compresi�n.

    \param i Imagen del enemigo.
    \param x Posici�n x en la que aparece el enemigo.
    \param y Posici�n y en la que aparece el enemigo.
    \param w Anchura en p�xeles del enemigo.
    \param h Altura en p�xeles del enemigo.
    \param vx Velocidad en el eje x del enemigo.
    \param vy Velocidad en el eje y del enemigo.
    \param t Tipo del enemigo.
    \param s Salud del enemigo.
    \param p Puntos que da el enemigo tras ser destruido.
    \return Un enemigo con las caracter�sticas indicadas.
*/
Enemigo EnemigoCrea(Imagen i, int x, int y, int w, int h, int vx, int vy, int t, int s, int p);

/**
    \brief Libera el enemigo indicado.

    \param e Enemigo a liberar.
*/
void    EnemigoLibera(Enemigo e);

/**
    \brief Mueve el enemigo indicado. Dependiendo de su tipo puede cambiar su comportamiento seg�n la posici�n de los personajes.

    \param e Enemigo a mover.
    \param p[] Personaje(s) que se est�(n) manejando.
*/
void    EnemigoMueve(Enemigo e, Personaje p[], float tiempo_delta);

/**
    \brief Dibuja en la pantalla el enemigo indicado.

    \param e Enemigo a dibujar.
*/
void    EnemigoDibuja(Enemigo e);

/**
    \brief Resta al enemigo la cantidad de vida indicada.

    \param e Enemigo al que se le quiere restar vida.
    \param dolor Da�o que se hace al enemigo.
*/
void    EnemigoDolor(Enemigo e, int dolor);

/**
    \brief Devuelve la imagen del enemigo.

    \param e Enemigo.
    \return Imagen del enemigo.
*/
Imagen EnemigoI(Enemigo e);

/**
    \brief Devuelve la posici�n x del enemigo.

    \param e Enemigo.
    \return Posici�n x del enemigo.
*/
int    EnemigoX(Enemigo e);

/**
    \brief Devuelve la posici�n y del enemigo.

    \param e Enemigo.
    \return Posici�n y del enemigo.
*/
int    EnemigoY(Enemigo e);

/**
    \brief Devuelve la velocidad en el eje x del enemigo.

    \param e Enemigo.
    \return Velocidad en el eje x del enemigo.
*/
int    EnemigoVX(Enemigo e);

/**
    \brief Devuelve la velocidad en el eje y del enemigo.

    \param e Enemigo.
    \return Velocidad en el eje y del enemigo.
*/
int    EnemigoVY(Enemigo e);

/**
    \brief Devuelve la anchura en p�xeles del enemigo.

    \param e Enemigo.
    \return Anchura en p�xeles del enemigo.
*/
int    EnemigoW(Enemigo e);

/**
    \brief Devuelve la altura en p�xeles del enemigo.

    \param e Enemigo.
    \return Altura en p�xeles del enemigo.
*/
int    EnemigoH(Enemigo e);

/**
    \brief Devuelve la salud del enemigo.

    \param e Enemigo.
    \return Salud del enemigo.
*/
int    EnemigoS(Enemigo e);

/**
    \brief Devuelve el tipo del enemigo.

    \param e Enemigo.
    \return Tipo del enemigo.
*/
int    EnemigoT(Enemigo e);

/**
    \brief Devuelve los puntos que da el enemigo tras ser destruido.

    \param e Enemigo.
    \return Puntos que da el enemigo tras ser destruido.
*/
int    EnemigoP(Enemigo e);

#endif // Enemigo_H
