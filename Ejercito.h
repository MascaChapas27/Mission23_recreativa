#ifndef __EJERCITO_H
#define __EJERCITO_H
#include "Enemigo.h"
#include "Pelicula.h"

/**
   \file Ejercito.h
   \brief  Fichero de cabecera para gestionar ej�rcitos de enemigos.
*/

/**
    \brief TDA Ejercito.
 */
typedef struct EjercitoRep * Ejercito;

/**
  \brief Crea un ej�rcito vac�o en el que se pueden insertar enemigos.

  Se debe ejecutar antes de comenzar el bucle principal del juego.

  \return Un ej�rcito vac�o.
 */
Ejercito EjercitoCrea();

/**
  \brief Inserta un nuevo enemigo en el ej�rcito.
  \pre Con respecto a Imagen i: El fichero debe existir y estar en formato Windows BMP 24 bits sin compresi�n.
  \pre Con respecto a int t: el tipo del enemigo es un n�mero entre el 0 y el 5.
  \pre Tipo 0: rebota por las paredes.
  \pre Tipo 1: se mueve en una sola coordenada y persigue a nuestro personaje cuando se alinea con nosotros.
  \pre Tipo 2: rebota por las paredes y genera copias m�s peque�as de s� mismo aleatoriamente.
  \pre Tipo 3: rebota por las paredes y dispara copias m�s peque�as de s� mismo a nuestro personaje cuando se alinea con nosotros.
  \pre Tipo 4: rebota contra las paredes y se divide en 4 copias m�s peque�as de s� mismo tras ser destruido.
  \pre Tipo 5: rebota por las paredes y al rebotar se aleatoriza su velocidad en ambos ejes entre 6 y 15.

  Se debe ejecutar en el bucle principal del juego, cuando se quiera introducir un nuevo enemigo en el ej�rcito.

  \param e Ej�rcito en el que se quiere insertar el enemigo.
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
 */
void    EjercitoInserta(Ejercito e, Imagen i, int x, int y, int w, int h, int vx, int vy, int t, int s, int p);

/**
  \brief Dibuja los enemigos en la pantalla.

  Se debe ejecutar en cada iteraci�n del bucle principal para mostrar a los enemigos.

  \param e Ej�rcito cuyos enemigos se quieren dibujar.
 */
void    EjercitoDibuja(Ejercito e);

/**
  \brief Mueve los enemigos del ej�rcito dependiendo de su tipo.

  Se debe ejecutar en cada iteraci�n del bucle para que los enemigos se muevan.

  \param e Ej�rcito cuyos enemigos se quieren mover.
  \param p Personaje que se est� manejando.
 */
void    EjercitoMueve(Ejercito e, Personaje p[], float tiempo_delta);

/**
  \brief Comprueba si ha habido una colisi�n con alg�n enemigo del ej�rcito.

  Se debe ejecutar en cada iteraci�n del bucle para comprobar si alg�n personaje se ha chocado con alg�n enemigo.
  Si ha habido una colisi�n con un enemigo, ese enemigo se liberar�. Adem�s la funci�n devolver� un 1.
  Se puede utilizar esta funci�n, por ejemplo, en un an�lisis de casos que elimine un escudo si hay una colisi�n, o que directamente acabe la partida.

  \param e Ej�rcito que queremos comprobar.
  \param p[] Personaje(s) que se est�(n) manejando.
  \return 1 si ha habido una colisi�n, 0 en caso contrario.
 */
int     EjercitoColision(Ejercito e, Personaje p[]);

/**
  \brief Va comprobando la salud de los enemigos y libera los que tienen 0 o menos. Adem�s introduce una animaci�n de destrucci�n.
  \pre Con respecto a Imagen enemigoExplota[]: Los ficheros deben existir y estar en formato Windows BMP 24 bits sin compresi�n.
  \pre Con respecto a int n: debe ser el n�mero exacto de im�genes que contiene el array enemigoExplota[].

  Se debe ejecutar en cada iteraci�n del bucle para eliminar aquellos enemigos que hemos destruido.
  Adicionalmente, tras destruir un enemigos de tipo 4 se crean 4 copias m�s peque�as de este.

  \param e Ej�rcito que se quiere comprobar.
  \param p Pel�cula en la que se quiere introducir la animaci�n de destrucci�n.
  \param enemigoExplota[] array en el que est�n los fotogramas de la animaci�n de explosi�n del enemigo.
  \param n N�mero de fotogramas de la animaci�n de destrucci�n.
  \return Puntos que se han conseguido al destruir a los enemigos.
 */
int    EjercitoComprobar(Ejercito e, Pelicula p, Imagen enemigoExplota[], int n);

/**
  \brief Destruye todos los enemigos del ej�rcito pero no lo libera. Adicionalmente crea animaciones de destrucci�n para todos los enemigos.
  \pre Con respecto a Imagen enemigoExplota[]: Los ficheros deben existir y estar en formato Windows BMP 24 bits sin compresi�n.
  \pre Con respecto a int n: debe ser el n�mero exacto de im�genes que contiene el array enemigoExplota[].

  Se debe ejecutar tras utilizar una bomba, ya que limpia por completo el ej�rcito y recoge todos los puntos de los enemigos.

  \param e Ej�rcito que se quiere destruir.
  \param p Pel�cula en la que se quieren introducir las animaciones de destrucci�n.
  \param enemigoExplota[] array en el que est�n los fotogramas de la animaci�n de explosi�n del enemigo.
  \param n N�mero de fotogramas de la animaci�n de destrucci�n.
  \return Puntos conseguidos al destruir a los enemigos.
 */
int    EjercitoDestruye(Ejercito e, Pelicula p, Imagen enemigoExplota[], int n);

/**
  \brief Libera al ej�rcito y a todos los enemigos que contiene.

  Se debe ejecutar al final de la partida.

  \param e Ej�rcito que se quiere liberar.
 */
void    EjercitoLibera(Ejercito e);

/**
  \brief Utilizado en otras funciones para obtener el siguiente nodo del ej�rcito. ADVERTENCIA: no est� pensado para ser utilizado en main.c

  \param e Nodo cuyo siguiente se quiere conocer.
  \return Nodo siguiente al indicado.
 */
Ejercito EjercitoSiguiente(Ejercito e);

/**
  \brief Utilizado en otras funciones para obtener el enemigo situado en un nodo del ej�rcito. ADVERTENCIA: no est� pensado para ser utilizado en main.c

  \param e Nodo del cual se quiere extraer el enemigo.
  \return Enemigo situado en el nodo.
 */
Enemigo EjercitoEnemigo(Ejercito e);

#endif // __EJERCITO_H__
