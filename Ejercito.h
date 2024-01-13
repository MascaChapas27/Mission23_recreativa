#ifndef __EJERCITO_H
#define __EJERCITO_H
#include "Enemigo.h"
#include "Pelicula.h"

/**
   \file Ejercito.h
   \brief  Fichero de cabecera para gestionar ejércitos de enemigos.
*/

/**
    \brief TDA Ejercito.
 */
typedef struct EjercitoRep * Ejercito;

/**
  \brief Crea un ejército vacío en el que se pueden insertar enemigos.

  Se debe ejecutar antes de comenzar el bucle principal del juego.

  \return Un ejército vacío.
 */
Ejercito EjercitoCrea();

/**
  \brief Inserta un nuevo enemigo en el ejército.
  \pre Con respecto a Imagen i: El fichero debe existir y estar en formato Windows BMP 24 bits sin compresión.
  \pre Con respecto a int t: el tipo del enemigo es un número entre el 0 y el 5.
  \pre Tipo 0: rebota por las paredes.
  \pre Tipo 1: se mueve en una sola coordenada y persigue a nuestro personaje cuando se alinea con nosotros.
  \pre Tipo 2: rebota por las paredes y genera copias más pequeñas de sí mismo aleatoriamente.
  \pre Tipo 3: rebota por las paredes y dispara copias más pequeñas de sí mismo a nuestro personaje cuando se alinea con nosotros.
  \pre Tipo 4: rebota contra las paredes y se divide en 4 copias más pequeñas de sí mismo tras ser destruido.
  \pre Tipo 5: rebota por las paredes y al rebotar se aleatoriza su velocidad en ambos ejes entre 6 y 15.

  Se debe ejecutar en el bucle principal del juego, cuando se quiera introducir un nuevo enemigo en el ejército.

  \param e Ejército en el que se quiere insertar el enemigo.
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
 */
void    EjercitoInserta(Ejercito e, Imagen i, int x, int y, int w, int h, int vx, int vy, int t, int s, int p);

/**
  \brief Dibuja los enemigos en la pantalla.

  Se debe ejecutar en cada iteración del bucle principal para mostrar a los enemigos.

  \param e Ejército cuyos enemigos se quieren dibujar.
 */
void    EjercitoDibuja(Ejercito e);

/**
  \brief Mueve los enemigos del ejército dependiendo de su tipo.

  Se debe ejecutar en cada iteración del bucle para que los enemigos se muevan.

  \param e Ejército cuyos enemigos se quieren mover.
  \param p Personaje que se está manejando.
 */
void    EjercitoMueve(Ejercito e, Personaje p[], float tiempo_delta);

/**
  \brief Comprueba si ha habido una colisión con algún enemigo del ejército.

  Se debe ejecutar en cada iteración del bucle para comprobar si algún personaje se ha chocado con algún enemigo.
  Si ha habido una colisión con un enemigo, ese enemigo se liberará. Además la función devolverá un 1.
  Se puede utilizar esta función, por ejemplo, en un análisis de casos que elimine un escudo si hay una colisión, o que directamente acabe la partida.

  \param e Ejército que queremos comprobar.
  \param p[] Personaje(s) que se está(n) manejando.
  \return 1 si ha habido una colisión, 0 en caso contrario.
 */
int     EjercitoColision(Ejercito e, Personaje p[]);

/**
  \brief Va comprobando la salud de los enemigos y libera los que tienen 0 o menos. Además introduce una animación de destrucción.
  \pre Con respecto a Imagen enemigoExplota[]: Los ficheros deben existir y estar en formato Windows BMP 24 bits sin compresión.
  \pre Con respecto a int n: debe ser el número exacto de imágenes que contiene el array enemigoExplota[].

  Se debe ejecutar en cada iteración del bucle para eliminar aquellos enemigos que hemos destruido.
  Adicionalmente, tras destruir un enemigos de tipo 4 se crean 4 copias más pequeñas de este.

  \param e Ejército que se quiere comprobar.
  \param p Película en la que se quiere introducir la animación de destrucción.
  \param enemigoExplota[] array en el que están los fotogramas de la animación de explosión del enemigo.
  \param n Número de fotogramas de la animación de destrucción.
  \return Puntos que se han conseguido al destruir a los enemigos.
 */
int    EjercitoComprobar(Ejercito e, Pelicula p, Imagen enemigoExplota[], int n);

/**
  \brief Destruye todos los enemigos del ejército pero no lo libera. Adicionalmente crea animaciones de destrucción para todos los enemigos.
  \pre Con respecto a Imagen enemigoExplota[]: Los ficheros deben existir y estar en formato Windows BMP 24 bits sin compresión.
  \pre Con respecto a int n: debe ser el número exacto de imágenes que contiene el array enemigoExplota[].

  Se debe ejecutar tras utilizar una bomba, ya que limpia por completo el ejército y recoge todos los puntos de los enemigos.

  \param e Ejército que se quiere destruir.
  \param p Película en la que se quieren introducir las animaciones de destrucción.
  \param enemigoExplota[] array en el que están los fotogramas de la animación de explosión del enemigo.
  \param n Número de fotogramas de la animación de destrucción.
  \return Puntos conseguidos al destruir a los enemigos.
 */
int    EjercitoDestruye(Ejercito e, Pelicula p, Imagen enemigoExplota[], int n);

/**
  \brief Libera al ejército y a todos los enemigos que contiene.

  Se debe ejecutar al final de la partida.

  \param e Ejército que se quiere liberar.
 */
void    EjercitoLibera(Ejercito e);

/**
  \brief Utilizado en otras funciones para obtener el siguiente nodo del ejército. ADVERTENCIA: no está pensado para ser utilizado en main.c

  \param e Nodo cuyo siguiente se quiere conocer.
  \return Nodo siguiente al indicado.
 */
Ejercito EjercitoSiguiente(Ejercito e);

/**
  \brief Utilizado en otras funciones para obtener el enemigo situado en un nodo del ejército. ADVERTENCIA: no está pensado para ser utilizado en main.c

  \param e Nodo del cual se quiere extraer el enemigo.
  \return Enemigo situado en el nodo.
 */
Enemigo EjercitoEnemigo(Ejercito e);

#endif // __EJERCITO_H__
