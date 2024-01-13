#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Personaje.h"

/**
   \file Enemigo.h
   \brief  Fichero de cabecera para gestionar enemigos, utilizado por el módulo Ejercito.
   ADVERTENCIA: este módulo y sus funciones no están pensados para utilizarse en main.c, en su lugar hay que utilizar el módulo Ejercito.
*/

/**
    \brief TDA Enemigo.
 */
typedef struct EnemigoRep * Enemigo;

/**
    \brief Crea un nuevo enemigo listo para ser introducido en un ejército.
    \pre Con respecto a Imagen i: El fichero debe existir y estar en formato Windows BMP 24 bits sin compresión.

    \param i Imagen del enemigo.
    \param x Posición x en la que aparece el enemigo.
    \param y Posición y en la que aparece el enemigo.
    \param w Anchura en píxeles del enemigo.
    \param h Altura en píxeles del enemigo.
    \param vx Velocidad en el eje x del enemigo.
    \param vy Velocidad en el eje y del enemigo.
    \param t Tipo del enemigo.
    \param s Salud del enemigo.
    \param p Puntos que da el enemigo tras ser destruido.
    \return Un enemigo con las características indicadas.
*/
Enemigo EnemigoCrea(Imagen i, int x, int y, int w, int h, int vx, int vy, int t, int s, int p);

/**
    \brief Libera el enemigo indicado.

    \param e Enemigo a liberar.
*/
void    EnemigoLibera(Enemigo e);

/**
    \brief Mueve el enemigo indicado. Dependiendo de su tipo puede cambiar su comportamiento según la posición de los personajes.

    \param e Enemigo a mover.
    \param p[] Personaje(s) que se está(n) manejando.
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
    \param dolor Daño que se hace al enemigo.
*/
void    EnemigoDolor(Enemigo e, int dolor);

/**
    \brief Devuelve la imagen del enemigo.

    \param e Enemigo.
    \return Imagen del enemigo.
*/
Imagen EnemigoI(Enemigo e);

/**
    \brief Devuelve la posición x del enemigo.

    \param e Enemigo.
    \return Posición x del enemigo.
*/
int    EnemigoX(Enemigo e);

/**
    \brief Devuelve la posición y del enemigo.

    \param e Enemigo.
    \return Posición y del enemigo.
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
    \brief Devuelve la anchura en píxeles del enemigo.

    \param e Enemigo.
    \return Anchura en píxeles del enemigo.
*/
int    EnemigoW(Enemigo e);

/**
    \brief Devuelve la altura en píxeles del enemigo.

    \param e Enemigo.
    \return Altura en píxeles del enemigo.
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
