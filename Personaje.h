#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "Pantalla.h"

#define JUGADOR1_ARRIBA REC_PLAYER1_UP
#define JUGADOR1_DERECHA REC_PLAYER1_RIGHT
#define JUGADOR1_ABAJO REC_PLAYER1_DOWN
#define JUGADOR1_IZQUIERDA REC_PLAYER1_LEFT
#define JUGADOR1_PAUSA REC_PLAYER1_E
#define JUGADOR1_DISPARA REC_PLAYER1_A
#define JUGADOR1_BOMBA REC_PLAYER1_D

#define JUGADOR2_ARRIBA REC_PLAYER2_UP
#define JUGADOR2_DERECHA REC_PLAYER2_RIGHT
#define JUGADOR2_ABAJO REC_PLAYER2_DOWN
#define JUGADOR2_IZQUIERDA REC_PLAYER2_LEFT
#define JUGADOR2_PAUSA REC_PLAYER2_E
#define JUGADOR2_DISPARA REC_PLAYER2_A
#define JUGADOR2_BOMBA REC_PLAYER2_D

#define BOTON_SALIR REC_STOP

/**
   \file Personaje.h
   \brief  Fichero de cabecera para gestionar nuestro personaje
*/

/**
    \brief TDA Personaje
 */
typedef struct PersonajeRep * Personaje;

/**
  \brief Crea un personaje manejable con las caracter�sticas especificadas.
  \pre Con respecto a Imagen i: El fichero debe existir y estar en formato Windows BMP 24 bits sin compresi�n

  Se crea una nave que podemos pilotar. Se debe crear despu�s de elegir al personaje y antes de comenzar el juego. Esta nave cambia dependiendo del personaje que hayamos elegido.

  \param i Imagen de la nave.
  \param x Posici�n x de la nave.
  \param y Posici�n y de la nave.
  \param w Anchura en p�xeles de la nave.
  \param h Altura en p�xeles de la nave.
  \param v Velocidad de movimiento de la nave (p�xeles que se desplaza al moverse).
  \param d Da�o que hace cada bala del personaje.
  \param c Cadencia de tiro de nuestro personaje (retraso entre disparo y disparo).
  \param e Escudos de nuestro personaje (golpes que aguanta antes de perder).
  \param b Bombas de nuestro personaje (eliminan a todos los enemigos en pantalla).
  \return El personaje que vamos a controlar. Hay que introducirlo en una variable de tipo Personaje.
 */
Personaje PersonajeCrea(Imagen i, int x, int y, int w, int h,int v, int d, int c, int e, int b);

/**
  \brief Elimina al personaje.

  Se debe hacer al final de la partida, ya sea cuando perdamos o cuando acabemos voluntariamente.

  \param p Personaje a liberar.
 */
void    PersonajeLibera(Personaje p);

/**
  \brief Mueve al personaje dependiendo de la tecla que estemos pulsando.

  Se debe ejecutar en cada iteraci�n de nuestro juego.

  Si pulsamos la W se mover� hacia arriba.
  Si pulsamos la S se mover� hacia abajo.
  Si pulsamos la A se mover� hacia la izquierda.
  Si pulsamos la D se mover� hacia la derecha.

  Si pulsamos varias teclas a la vez podremos hacer que se mueva en diagonal.

  Si atravesamos alg�n borde de la pantalla apareceremos en el extremo contrario

  \param p Personaje a mover
 */
void    PersonajeMueve(Personaje personajes[], float tiempo_delta);

/**
  \brief Dibuja a nuestro personaje en pantalla

  Se debe ejecutar en cada iteraci�n de nuestro juego.

  \param p Personaje a mover
 */
void    PersonajeDibuja(Personaje p);

/**
  \brief Incrementa la cadencia de nuestro personaje en la cantidad indicada

  \pre La cadencia alcanza su valor m�ximo en 1 por lo que no se puede permitir que alcance valores menores a 1. Hay que controlar que al mejorar la cadencia no se sobrepase el l�mite.

  Hay que tener en cuenta que la cadencia es el retraso entre disparos por lo que al aumentarla en 3, por ejemplo, la funci�n se encarga de restar 3 a la cadencia actual.

  Es posible reducir la cadencia si la cantidad introducida es un n�mero negativo (aumenta el retraso).

  \param p Personaje cuya cadencia queremos cambiar
  \param cantidad Cantidad que queremos restar a la cadencia actual
 */
void    PersonajeMejoraCadencia(Personaje p, int cantidad);

/**
  \brief Incrementa el da�o que hace cada bala de nuestro personaje

  Es posible reducir el da�o si la cantidad introducida es un n�mero negativo.

  \param p Personaje cuyo da�o queremos cambiar.
  \param cantidad Cantidad que queremos sumar al da�o actual.
 */
void    PersonajeMejoraDolor(Personaje p,int cantidad);

/**
  \brief Incrementa la velocidad a la que se mueve personaje.

  Es posible reducir la velocidad si la cantidad introducida es un n�mero negativo.

  \param p Personaje cuya velocidad queremos cambiar.
  \param cantidad Cantidad que queremos sumar a la velocidad actual.
 */
void    PersonajeMejoraVelocidad(Personaje p, int cantidad);

/**
  \brief Aumenta o disminuye el n�mero de escudos seg�n la cantidad indicada.

  \pre Si el personaje llega a tener 0 escudos la partida debe acabar. No deber�a ser posible tener escudos negativos.

  Por lo general se reduce en 1 cuando nuestra nave colisiona con un enemigo y aumenta en 1 cuando conseguimos un nuevo escudo.

  Si n es positivo se a�aden escudos. Si es negativo, se quitan.

  \param p Personaje cuyo n�mero de escudos queremos cambiar.
  \param n Cantidad que queremos sumar o restar al recuento de escudos.
 */
void    PersonajeAlteraEscudo(Personaje p, int n);

/**
  \brief Aumenta o disminuye el n�mero de bombas seg�n la cantidad indicada.

  \pre Si el personaje llega a tener 0 bombas no se puede utilizar otra bomba. No deber�a ser posible tener bombas negativas.

  Por lo general se reduce en 1 cuando utilizamos una bomba y aumenta en 1 cuando conseguimos una bomba.

  Si n es positivo se a�aden bombas. Si es negativo, se quitan.

  \param p Personaje cuyo n�mero de bombas queremos cambiar.
  \param n Cantidad que queremos sumar o restar al recuento de bombas.
 */
void    PersonajeAlteraBomba(Personaje p, int n);

void    PersonajeValido(Personaje p);

/**
  \brief Devuelve la coordenada X del personaje.

  \param p Personaje cuya posici�n X queremos conocer.
  \return Posici�n X del personaje.
 */
int    PersonajeX(Personaje p);

/**
  \brief Devuelve la coordenada Y del personaje.

  \param p Personaje cuya posici�n Y queremos conocer.
  \return Posici�n Y del personaje.
 */
int    PersonajeY(Personaje p);

/**
  \brief Devuelve la anchura en p�xeles del personaje.

  \param p Personaje cuya anchura queremos conocer.
  \return Anchura del personaje.
 */
int    PersonajeW(Personaje p);

/**
  \brief Devuelve la altura en p�xeles del personaje.

  \param p Personaje cuya altura queremos conocer.
  \return Altura del personaje.
 */
int    PersonajeH(Personaje p);

/**
  \brief Devuelve la velocidad del personaje.

  \param p Personaje cuya velocidad queremos conocer.
  \return Velocidad del personaje.
 */
int    PersonajeV(Personaje p);

/**
  \brief Devuelve el da�o por bala que hace el personaje.

  \param p Personaje cuyo da�o queremos conocer.
  \return Da�o del personaje.
 */
int    PersonajeD(Personaje p);

/**
  \brief Devuelve la cadencia de tiro del personaje.

  \param p Personaje cuya cadencia queremos conocer.
  \return Cadencia del personaje.
 */
int    PersonajeC(Personaje p);

/**
  \brief Devuelve la cantidad de escudos que le quedan al personaje.

  \param p Personaje cuya cantidad de escudos queremos conocer.
  \return Escudos del personaje.
 */
int    PersonajeE(Personaje p);

/**
  \brief Devuelve la cantidad de bombas que le quedan al personaje.

  \param p Personaje cuya cantidad de bombas queremos conocer.
  \return Bombas del personaje.
 */
int    PersonajeB(Personaje p);

int    PersonajeEsValido(Personaje p);

#endif // PERSONAJE_H
