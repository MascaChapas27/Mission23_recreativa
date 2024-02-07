#define SDL_MAIN_HANDLED
#include "Pantalla.h"
#include "Personaje.h"
#include "Ejercito.h"
#include "Rafaga.h"
#include "Galaxia.h"
#include "Pelicula.h"
#include "Sonido.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>



const int TIEMPO_ESPERA = 40;
const float FPS = 200;

int main(int argc, char *argv[])
{
    Pantalla_Crea("Mission23",800,600);
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("Sound couldn't be initialized %s\n", SDL_GetError());
    }
    int terminado = 0;
    Imagen recordError = Pantalla_ImagenLee("imagenes/recordError.bmp",0);
    char nombreRecord1[20], nombreRecord2[20], nombreRecord3[20];
    int tRecord1, tRecord2, tRecord3, nRecord1, nRecord2, nRecord3, hechoRecord;
    srand(time(NULL));
    Imagen menuPrincipal1P = Pantalla_ImagenLee("imagenes/menuPrincipal1P.bmp",0);
    Imagen menuPrincipal2P = Pantalla_ImagenLee("imagenes/menuPrincipal2P.bmp",0);
    Imagen gameOver = Pantalla_ImagenLee("imagenes/gameOver.bmp",0);
    Imagen batallaFondo = Pantalla_ImagenLee("imagenes/batallaFondo.bmp",0);
    float fondoX=-200;
    float fondoY=-100;
    Imagen menuNaveTriska = Pantalla_ImagenLee("imagenes/menuNaveTriska.bmp",255);
    Imagen menuNaveBeta = Pantalla_ImagenLee("imagenes/menuNaveBeta.bmp",255);
    Imagen controles2P = Pantalla_ImagenLee("imagenes/controles2P.bmp",0);
    Imagen elegirPersonajeBeta = Pantalla_ImagenLee("imagenes/elegirPersonajeBeta.bmp",0);
    Imagen elegirPersonajeTriska = Pantalla_ImagenLee("imagenes/elegirPersonajeTriska.bmp",0);
    Imagen personajeElegidoBeta = Pantalla_ImagenLee("imagenes/personajeElegidoBeta.bmp",0);
    Imagen personajeElegidoTriska = Pantalla_ImagenLee("imagenes/personajeElegidoTriska.bmp",0);
    Imagen controlesBeta = Pantalla_ImagenLee("imagenes/controlesBeta.bmp",0);
    Imagen controlesTriska = Pantalla_ImagenLee("imagenes/controlesTriska.bmp",0);

    //Variables con sonidos
    Sonido sonidoAceptar = creaSonido("sonidos/sonidoAceptar.wav");

    Sonido sonidoMenu = creaSonido("sonidos/sonidoMenu.wav");

    Sonido sonidoComenzar = creaSonido("sonidos/sonidoComenzar.wav");

    Sonido sonidoDisparaBala = creaSonido("sonidos/sonidoDisparaBala.wav");

    Sonido sonidoChocaBala = creaSonido("sonidos/sonidoChocaBala.wav");

    Sonido sonidoDisparaCohete = creaSonido("sonidos/sonidoDisparaCohete.wav");

    Sonido sonidoChocaCohete = creaSonido("sonidos/sonidoChocaCohete.wav");

    Sonido sonidoRecogeMoneda = creaSonido("sonidos/sonidoRecogeMoneda.wav");

    Sonido sonidoConsigueMejora = creaSonido("sonidos/sonidoConsigueMejora.wav");

    Sonido sonidoDestruyeEnemigo = creaSonido("sonidos/sonidoDestruyeEnemigo.wav");

    Sonido sonidoColision = creaSonido("sonidos/sonidoColision.wav");

    Sonido sonidoUsaBomba = creaSonido("sonidos/sonidoUsaBomba.wav");

    Sonido musicaMenuPrincipal = creaSonido("sonidos/musicaMenuPrincipal.wav");

    Sonido sonidoConsigueEscudo = creaSonido("sonidos/sonidoConsigueEscudo.wav");

    Sonido sonidoConsigueBomba = creaSonido("sonidos/sonidoConsigueBomba.wav");

    //Creamos el ejército vacío y la ráfaga de balas vacía y la película vacía
    //Dos ráfagas, una para Triska y otra para Beta
    Ejercito ejercito = EjercitoCrea();
    Rafaga rafaga[2];
    rafaga[0] = RafagaCrea();
    rafaga[1] = RafagaCrea();
    Pelicula pelicula = PeliculaCrea();

    //Hacemos variables con imágenes para poder liberarlas más tarde
    Imagen triskaDialogoNeutral[8];
    triskaDialogoNeutral[0] = Pantalla_ImagenLee("imagenes/triskaDialogoNeutral0.bmp",0);
    triskaDialogoNeutral[1] = Pantalla_ImagenLee("imagenes/triskaDialogoNeutral1.bmp",0);
    triskaDialogoNeutral[2] = Pantalla_ImagenLee("imagenes/triskaDialogoNeutral2.bmp",0);
    triskaDialogoNeutral[3] = Pantalla_ImagenLee("imagenes/triskaDialogoNeutral3.bmp",0);
    triskaDialogoNeutral[4] = Pantalla_ImagenLee("imagenes/triskaDialogoNeutral4.bmp",0);
    triskaDialogoNeutral[5] = Pantalla_ImagenLee("imagenes/triskaDialogoNeutral5.bmp",0);
    triskaDialogoNeutral[6] = Pantalla_ImagenLee("imagenes/triskaDialogoNeutral6.bmp",0);
    triskaDialogoNeutral[7] = Pantalla_ImagenLee("imagenes/triskaDialogoNeutral7.bmp",0);
    Imagen betaDialogoNeutral[8];
    betaDialogoNeutral[0] = Pantalla_ImagenLee("imagenes/betaDialogoNeutral0.bmp",0);
    betaDialogoNeutral[1] = Pantalla_ImagenLee("imagenes/betaDialogoNeutral1.bmp",0);
    betaDialogoNeutral[2] = Pantalla_ImagenLee("imagenes/betaDialogoNeutral2.bmp",0);
    betaDialogoNeutral[3] = Pantalla_ImagenLee("imagenes/betaDialogoNeutral3.bmp",0);
    betaDialogoNeutral[4] = Pantalla_ImagenLee("imagenes/betaDialogoNeutral4.bmp",0);
    betaDialogoNeutral[5] = Pantalla_ImagenLee("imagenes/betaDialogoNeutral5.bmp",0);
    betaDialogoNeutral[6] = Pantalla_ImagenLee("imagenes/betaDialogoNeutral6.bmp",0);
    betaDialogoNeutral[7] = Pantalla_ImagenLee("imagenes/betaDialogoNeutral7.bmp",0);
    Imagen triskaDialogoColision[8];
    triskaDialogoColision[0] = Pantalla_ImagenLee("imagenes/triskaDialogoColision0.bmp",0);
    triskaDialogoColision[1] = Pantalla_ImagenLee("imagenes/triskaDialogoColision1.bmp",0);
    triskaDialogoColision[2] = Pantalla_ImagenLee("imagenes/triskaDialogoColision2.bmp",0);
    triskaDialogoColision[3] = Pantalla_ImagenLee("imagenes/triskaDialogoColision3.bmp",0);
    triskaDialogoColision[4] = Pantalla_ImagenLee("imagenes/triskaDialogoColision4.bmp",0);
    triskaDialogoColision[5] = Pantalla_ImagenLee("imagenes/triskaDialogoColision5.bmp",0);
    triskaDialogoColision[6] = Pantalla_ImagenLee("imagenes/triskaDialogoColision6.bmp",0);
    triskaDialogoColision[7] = Pantalla_ImagenLee("imagenes/triskaDialogoColision7.bmp",0);
    Imagen betaDialogoColision[8];
    betaDialogoColision[0] = Pantalla_ImagenLee("imagenes/betaDialogoColision0.bmp",0);
    betaDialogoColision[1] = Pantalla_ImagenLee("imagenes/betaDialogoColision1.bmp",0);
    betaDialogoColision[2] = Pantalla_ImagenLee("imagenes/betaDialogoColision2.bmp",0);
    betaDialogoColision[3] = Pantalla_ImagenLee("imagenes/betaDialogoColision3.bmp",0);
    betaDialogoColision[4] = Pantalla_ImagenLee("imagenes/betaDialogoColision4.bmp",0);
    betaDialogoColision[5] = Pantalla_ImagenLee("imagenes/betaDialogoColision5.bmp",0);
    betaDialogoColision[6] = Pantalla_ImagenLee("imagenes/betaDialogoColision6.bmp",0);
    betaDialogoColision[7] = Pantalla_ImagenLee("imagenes/betaDialogoColision7.bmp",0);
    Imagen conexionTerminada = Pantalla_ImagenLee("imagenes/conexionTerminada.bmp",0);
    Imagen enemigoImagen0 = Pantalla_ImagenLee("imagenes/enemigo0.bmp",255);
    Imagen enemigoImagen1 = Pantalla_ImagenLee("imagenes/enemigo1.bmp",255);
    Imagen enemigoImagen2 = Pantalla_ImagenLee("imagenes/enemigo2.bmp",255);
    Imagen enemigoImagen3 = Pantalla_ImagenLee("imagenes/enemigo3.bmp",255);
    Imagen enemigoImagen4 = Pantalla_ImagenLee("imagenes/enemigo4.bmp",255);
    Imagen enemigoImagen5 = Pantalla_ImagenLee("imagenes/enemigo5.bmp",255);
    Imagen enemigoImagen6 = Pantalla_ImagenLee("imagenes/enemigo6.bmp",255);
    Imagen enemigoImagen7 = Pantalla_ImagenLee("imagenes/enemigo7.bmp",255);
    Imagen enemigoImagen8 = Pantalla_ImagenLee("imagenes/enemigo8.bmp",255);
    Imagen enemigoImagen9 = Pantalla_ImagenLee("imagenes/enemigo9.bmp",255);
    Imagen enemigoImagen10 = Pantalla_ImagenLee("imagenes/enemigo10.bmp",255);
    Imagen portal = Pantalla_ImagenLee("imagenes/portal.bmp",255);
    Imagen conseguirMejora[8];
    conseguirMejora[0] = Pantalla_ImagenLee("imagenes/conseguirMejora0.bmp",255);
    conseguirMejora[1] = Pantalla_ImagenLee("imagenes/conseguirMejora1.bmp",255);
    conseguirMejora[2] = Pantalla_ImagenLee("imagenes/conseguirMejora2.bmp",255);
    conseguirMejora[3] = Pantalla_ImagenLee("imagenes/conseguirMejora3.bmp",255);
    conseguirMejora[4] = Pantalla_ImagenLee("imagenes/conseguirMejora4.bmp",255);
    conseguirMejora[5] = Pantalla_ImagenLee("imagenes/conseguirMejora5.bmp",255);
    conseguirMejora[6] = Pantalla_ImagenLee("imagenes/conseguirMejora6.bmp",255);
    conseguirMejora[7] = Pantalla_ImagenLee("imagenes/conseguirMejora7.bmp",255);
    Imagen explosion[11];
    explosion[0] = Pantalla_ImagenLee("imagenes/explosion0.bmp",255);
    explosion[1] = Pantalla_ImagenLee("imagenes/explosion1.bmp",255);
    explosion[2] = Pantalla_ImagenLee("imagenes/explosion2.bmp",255);
    explosion[3] = Pantalla_ImagenLee("imagenes/explosion3.bmp",255);
    explosion[4] = Pantalla_ImagenLee("imagenes/explosion4.bmp",255);
    explosion[5] = Pantalla_ImagenLee("imagenes/explosion5.bmp",255);
    explosion[6] = Pantalla_ImagenLee("imagenes/explosion6.bmp",255);
    explosion[7] = Pantalla_ImagenLee("imagenes/explosion7.bmp",255);
    explosion[8] = Pantalla_ImagenLee("imagenes/explosion8.bmp",255);
    explosion[9] = Pantalla_ImagenLee("imagenes/explosion9.bmp",255);
    explosion[10] = Pantalla_ImagenLee("imagenes/explosion10.bmp",255);
    Imagen enemigoExplota[8];
    enemigoExplota[0] = Pantalla_ImagenLee("imagenes/enemigoExplota0.bmp",255);
    enemigoExplota[1] = Pantalla_ImagenLee("imagenes/enemigoExplota1.bmp",255);
    enemigoExplota[2] = Pantalla_ImagenLee("imagenes/enemigoExplota2.bmp",255);
    enemigoExplota[3] = Pantalla_ImagenLee("imagenes/enemigoExplota3.bmp",255);
    enemigoExplota[4] = Pantalla_ImagenLee("imagenes/enemigoExplota4.bmp",255);
    enemigoExplota[5] = Pantalla_ImagenLee("imagenes/enemigoExplota5.bmp",255);
    enemigoExplota[6] = Pantalla_ImagenLee("imagenes/enemigoExplota6.bmp",255);
    enemigoExplota[7] = Pantalla_ImagenLee("imagenes/enemigoExplota7.bmp",255);
    Imagen balaColisiona[7];
    balaColisiona[0] = Pantalla_ImagenLee("imagenes/balaColisiona0.bmp",255);
    balaColisiona[1] = Pantalla_ImagenLee("imagenes/balaColisiona1.bmp",255);
    balaColisiona[2] = Pantalla_ImagenLee("imagenes/balaColisiona2.bmp",255);
    balaColisiona[3] = Pantalla_ImagenLee("imagenes/balaColisiona3.bmp",255);
    balaColisiona[4] = Pantalla_ImagenLee("imagenes/balaColisiona4.bmp",255);
    balaColisiona[5] = Pantalla_ImagenLee("imagenes/balaColisiona5.bmp",255);
    balaColisiona[6] = Pantalla_ImagenLee("imagenes/balaColisiona6.bmp",255);
    Imagen monedaDesvanece[6];
    monedaDesvanece[0] = Pantalla_ImagenLee("imagenes/monedaDesvanece0.bmp",255);
    monedaDesvanece[1] = Pantalla_ImagenLee("imagenes/monedaDesvanece1.bmp",255);
    monedaDesvanece[2] = Pantalla_ImagenLee("imagenes/monedaDesvanece2.bmp",255);
    monedaDesvanece[3] = Pantalla_ImagenLee("imagenes/monedaDesvanece3.bmp",255);
    monedaDesvanece[4] = Pantalla_ImagenLee("imagenes/monedaDesvanece4.bmp",255);
    monedaDesvanece[5] = Pantalla_ImagenLee("imagenes/monedaDesvanece5.bmp",255);
    Imagen conseguirEscudo[8];
    conseguirEscudo[0] = Pantalla_ImagenLee("imagenes/conseguirEscudo0.bmp",255);
    conseguirEscudo[1] = Pantalla_ImagenLee("imagenes/conseguirEscudo1.bmp",255);
    conseguirEscudo[2] = Pantalla_ImagenLee("imagenes/conseguirEscudo2.bmp",255);
    conseguirEscudo[3] = Pantalla_ImagenLee("imagenes/conseguirEscudo3.bmp",255);
    conseguirEscudo[4] = Pantalla_ImagenLee("imagenes/conseguirEscudo4.bmp",255);
    conseguirEscudo[5] = Pantalla_ImagenLee("imagenes/conseguirEscudo5.bmp",255);
    conseguirEscudo[6] = Pantalla_ImagenLee("imagenes/conseguirEscudo6.bmp",255);
    conseguirEscudo[7] = Pantalla_ImagenLee("imagenes/conseguirEscudo7.bmp",255);
    Imagen conseguirBomba[8];
    conseguirBomba[0] = Pantalla_ImagenLee("imagenes/conseguirBomba0.bmp",255);
    conseguirBomba[1] = Pantalla_ImagenLee("imagenes/conseguirBomba1.bmp",255);
    conseguirBomba[2] = Pantalla_ImagenLee("imagenes/conseguirBomba2.bmp",255);
    conseguirBomba[3] = Pantalla_ImagenLee("imagenes/conseguirBomba3.bmp",255);
    conseguirBomba[4] = Pantalla_ImagenLee("imagenes/conseguirBomba4.bmp",255);
    conseguirBomba[5] = Pantalla_ImagenLee("imagenes/conseguirBomba5.bmp",255);
    conseguirBomba[6] = Pantalla_ImagenLee("imagenes/conseguirBomba6.bmp",255);
    conseguirBomba[7] = Pantalla_ImagenLee("imagenes/conseguirBomba7.bmp",255);
    Imagen escudos3 = Pantalla_ImagenLee("imagenes/escudos3.bmp",255);
    Imagen escudos2 = Pantalla_ImagenLee("imagenes/escudos2.bmp",255);
    Imagen escudos1 = Pantalla_ImagenLee("imagenes/escudos1.bmp",255);
    Imagen bombas3 = Pantalla_ImagenLee("imagenes/bombas3.bmp",255);
    Imagen bombas2 = Pantalla_ImagenLee("imagenes/bombas2.bmp",255);
    Imagen bombas1 = Pantalla_ImagenLee("imagenes/bombas1.bmp",255);
    Imagen conseguirMoneda = Pantalla_ImagenLee("imagenes/conseguirMoneda.bmp",255);
    Imagen moneda = Pantalla_ImagenLee("imagenes/moneda.bmp",255);

    int numeroDeMonedas=10;
    Galaxia g = GalaxiaCrea(numeroDeMonedas);
    for(int i=0;i<5;i++){
        GalaxiaInserta(g,moneda,rand()%(Pantalla_Anchura()-50),rand()%(Pantalla_Altura()-200)+100,39,39);
    }

    //Monedas, puntuación y demás estadísticas
    int t1,t2,t=0;
    char score[100];
    char monedas[100];
    char cadencia[100];
    char dolor[100];
    char velocidad[100];
    char nivelActual[100];
    int dinero=0;

    int i=255;
    int j=rand()%30;
    int k=rand()%40;

    int unJugador = 1;

    while (Pantalla_Activa() && !terminado)
    {
        if(Pantalla_TeclaPulsada(REC_STOP)) exit(0);

        reproduceMusica(musicaMenuPrincipal);

        // Si se pulsa el botón azul se va al menú de selección de personaje
        if (Pantalla_TeclaPulsada(JUGADOR1_DISPARA) || Pantalla_TeclaPulsada(JUGADOR2_DISPARA))
        {
            reproduceSonido(sonidoAceptar);
            terminado=1;
        } else if (Pantalla_TeclaPulsada(JUGADOR1_IZQUIERDA) || Pantalla_TeclaPulsada(JUGADOR2_IZQUIERDA)){
            unJugador = 1;
        } else if (Pantalla_TeclaPulsada(JUGADOR1_DERECHA) || Pantalla_TeclaPulsada(JUGADOR2_DERECHA)){
            unJugador = 0;
        }

        Pantalla_DibujaImagen(unJugador ? menuPrincipal1P : menuPrincipal2P,0,0,Pantalla_Anchura(),Pantalla_Altura());

        if (j<30){  //mueve la nave de Beta en el menú
            j=j+1;
            Pantalla_DibujaImagen(menuNaveBeta,510,200+j,200,100);
        } else if (j<60) {
            j=j+1;
            Pantalla_DibujaImagen(menuNaveBeta,510,260-j,200,100);
        } else {
            j=0;
            Pantalla_DibujaImagen(menuNaveBeta,510,200,200,100);
        }

        if (k<40){  //mueve la nave de Triska en el menú
            k=k+1;
            Pantalla_DibujaImagen(menuNaveTriska,80,250+k,357,199);
        } else if (k<80) {
            k=k+1;
            Pantalla_DibujaImagen(menuNaveTriska,80,330-k,357,199);
        } else {
            k=0;
            Pantalla_DibujaImagen(menuNaveTriska,80,250,357,199);
        }

        if (i>=3){  //El menú aparece negro y se va aclarando
            i=i-3;
            Pantalla_ColorRelleno(0,0,0,i);
            Pantalla_DibujaRectangulo(0,0,Pantalla_Anchura(),Pantalla_Altura());
        }

        Pantalla_Actualiza();

        Pantalla_Espera(TIEMPO_ESPERA);
    }
    paraSonido(musicaMenuPrincipal);
    liberaSonido(musicaMenuPrincipal);
    terminado=0;
    Pantalla_ImagenLibera(menuNaveBeta);
    Pantalla_ImagenLibera(menuNaveTriska);
    Pantalla_ImagenLibera(menuPrincipal1P);
    Pantalla_ImagenLibera(menuPrincipal2P);

    terminado=0;

    Imagen personajeImagen[2];
    Imagen balaImagen[2];
    Personaje p[2];

    personajeImagen[1] = Pantalla_ImagenLee("imagenes/nave2.bmp",255);
    p[1] = PersonajeCrea(personajeImagen[1],rand()%Pantalla_Anchura(),500,37,47,8,20,10,2,2);
    balaImagen[1] = Pantalla_ImagenLee("imagenes/cohete.bmp",255);

    personajeImagen[0] = Pantalla_ImagenLee("imagenes/nave1.bmp",255);
    p[0] = PersonajeCrea(personajeImagen[0],rand()%Pantalla_Anchura(),500,37,47,10,6,8,3,1);
    balaImagen[0] = Pantalla_ImagenLee("imagenes/bala.bmp",255);

    char * ficheroRecord = unJugador ? "recordm23_1p.txt" : "recordm23_2p.txt";

    FILE * f = fopen(ficheroRecord, "r"); //r de read
    if( f == NULL ){
        FILE * f = fopen(ficheroRecord,"w");
        tRecord1=0;
        tRecord2=0;
        tRecord3=0;
        nRecord1=0;
        nRecord2=0;
        nRecord3=0;
        sprintf(nombreRecord1,"???");
        sprintf(nombreRecord2,"???");
        sprintf(nombreRecord3,"???");
        fprintf(f,"%d %d %s %d %d %s %d %d %s",nRecord1, tRecord1, nombreRecord1, nRecord2, tRecord2, nombreRecord2, nRecord3, tRecord3, nombreRecord3);
    } else {
        if(fscanf(f,"%d %d %s %d %d %s %d %d %s",&nRecord1, &tRecord1, nombreRecord1, &nRecord2, &tRecord2, nombreRecord2, &nRecord3, &tRecord3, nombreRecord3)!=9){
            int temporizador = 200;
            while(Pantalla_Activa()){
                Pantalla_DibujaImagen(recordError,0,0,Pantalla_Anchura(),Pantalla_Altura());
                if(temporizador<0){
                    fclose(f);
                    remove(ficheroRecord);
                    Pantalla_Libera();
                    exit(11);
                }
                Pantalla_Actualiza();
                Pantalla_Espera(TIEMPO_ESPERA);
                temporizador--;
            }
        }
    }

    int returnPulsado = 1;

    if(!unJugador){

        PersonajeValido(p[0]);
        PersonajeValido(p[1]);
        while(Pantalla_Activa() && !terminado){
            if((Pantalla_TeclaPulsada(JUGADOR1_DISPARA) || Pantalla_TeclaPulsada(JUGADOR2_DISPARA)) && !returnPulsado){
                reproduceSonido(sonidoComenzar);
                terminado=1;
            }
            if(!(Pantalla_TeclaPulsada(JUGADOR1_DISPARA) || Pantalla_TeclaPulsada(JUGADOR2_DISPARA)) && returnPulsado) returnPulsado = 0;
            if(Pantalla_TeclaPulsada(BOTON_SALIR)) exit(0);

            Pantalla_DibujaImagen(controles2P,0,0,Pantalla_Anchura(),Pantalla_Altura());

            Pantalla_Actualiza();
            Pantalla_Espera(TIEMPO_ESPERA);
        }

    } else {
        int personajeElegido = 0;
        Imagen elegido = elegirPersonajeTriska;
        while (Pantalla_Activa() && !terminado)
        {
            if(Pantalla_TeclaPulsada(BOTON_SALIR)) exit(0);

            if (Pantalla_TeclaPulsada(JUGADOR1_DISPARA) && !returnPulsado)
            {
                reproduceSonido(sonidoAceptar);
                terminado=1;
            } else if (!Pantalla_TeclaPulsada(JUGADOR1_DISPARA) && returnPulsado){
                returnPulsado = 0;
            }

            if (Pantalla_TeclaPulsada(JUGADOR1_IZQUIERDA))
            {
                if(personajeElegido==1) reproduceSonido(sonidoMenu);
                elegido = elegirPersonajeTriska;
                personajeElegido=0;
            }

            if (Pantalla_TeclaPulsada(JUGADOR1_DERECHA))
            {
                if(personajeElegido==0) reproduceSonido(sonidoMenu);
                elegido = elegirPersonajeBeta;
                personajeElegido=1;
            }

            Pantalla_DibujaImagen(elegido,0,0,Pantalla_Anchura(),Pantalla_Altura());

            Pantalla_Actualiza();

            Pantalla_Espera(TIEMPO_ESPERA);
        }

        terminado=0;
        i=255;

        if(personajeElegido){
            while (Pantalla_Activa() && !terminado)
            {
                if(i<10){
                    terminado=1;
                }

                Pantalla_DibujaImagen(personajeElegidoBeta,0,0,Pantalla_Anchura(),Pantalla_Altura());
                Pantalla_ColorRelleno(255,255,255,i);
                Pantalla_ColorTrazo(255,255,255,255);
                Pantalla_DibujaRectangulo(416,62,361,456);
                i=i-10;

                Pantalla_Actualiza();

                Pantalla_Espera(TIEMPO_ESPERA);
            }
        } else {
            while (Pantalla_Activa() && !terminado)
            {
                if(i<10){
                    terminado=1;
                }

                Pantalla_DibujaImagen(personajeElegidoTriska,0,0,Pantalla_Anchura(),Pantalla_Altura());
                Pantalla_ColorRelleno(255,255,255,i);
                Pantalla_ColorTrazo(255,255,255,255);
                Pantalla_DibujaRectangulo(23,62,361,456);
                i=i-10;

                Pantalla_Actualiza();

                Pantalla_Espera(TIEMPO_ESPERA);
            }
        }
        terminado=0;

        PersonajeValido(p[personajeElegido]);

        while(Pantalla_Activa() && !terminado){
            if(Pantalla_TeclaPulsada(JUGADOR1_DISPARA)){
                reproduceSonido(sonidoComenzar);
                terminado=1;
            }
            if(Pantalla_TeclaPulsada(BOTON_SALIR)) exit(0);
            if(personajeElegido){
                Pantalla_DibujaImagen(controlesBeta,0,0,Pantalla_Anchura(),Pantalla_Altura());
            } else {
                Pantalla_DibujaImagen(controlesTriska,0,0,Pantalla_Anchura(),Pantalla_Altura());
            }
            Pantalla_Actualiza();
            Pantalla_Espera(TIEMPO_ESPERA);
        }

    }

    terminado=0;
    t1=time(NULL);//Primer contador de tiempo, fijo
    int numeroAleatorio; //Numero aleatorio para decidir qué enemigo aparece
    float conseguirMonedaAnim=0; //Para la animación de conseguir moneda
    float conseguirMejoraAnim=-1; //Para la animación de conseguir mejora
    float explosionAnimColision=-1; //Para la animación de explosión al recibir un golpe
    float conseguirBombaAnim=-1; //Para la animación de conseguir bomba
    float conseguirEscudoAnim=-1; //Para la animación de conseguir escudo
    float dialogoNeutralAnim=0; //Para la animación de diálogo neutral
    float dialogoColisionAnim=-1; //Para la animación del diálogo después de una colisión
    float framesInvencibilidad=0; //Para obtener un momento de invencibilidad después de ser golpeado (y que la nave parpadee)
    float bombaUtilizadaAnim=-1; //Para la animación de explosión
    int nivel=1; //Cuanto mayor, más difícil
    int dialogo=0;
    int tiempoPausa=0; //Segundos que se ha estado en pausa para que no cuente en la puntuación
    int tiempoPausaTotal=0; //Segundos que se ha estado en pausa en total
    int mimoX,mimoY; //Coordenadas del enemigo Mimo, para evitar que aparezca enmedio del personaje.
    int t3; //Contador de tiempo que se inicializa cuando se pausa para poder contar tiempoPausa
    float contCadencia[2] = {0,0};//Contadores para controlar la cadencia de disparo
    int puntosDestruccion=0; //Puntos extra por destruir enemigos con balas o bombas
    int mejoraAleatoria=0; //Un contador utilizado para elegir una mejora aleatoria de entre las mejoras que hay
    int pausaPulsado=0; //Un flag booleano para tener en cuenta si se pulsa o no el botón de pausa
    int numBombas; //Número de bombas
    int numEscudos; //Número de escudos

    if(unJugador){
        if(PersonajeEsValido(p[0])){
            numBombas = 2;
            numEscudos = 3;
        } else {
            numBombas = 3;
            numEscudos = 2;
        }
    } else {
        numBombas = numEscudos = 3;
    }

    float temporizador_generador_enemigo = 0;

    clock_t tiempo_inicial = clock();

    int contador_fps = 0;
    int fps = 0;
    float temporizador_fps = 0;
    char textoFps[20];

    float temporizador_delta = 0;

    int triskaBotonDisparar = JUGADOR1_DISPARA;
    int betaBotonDisparar = unJugador ? JUGADOR1_DISPARA : JUGADOR2_DISPARA;

    while (Pantalla_Activa() && !terminado) //El bucle del juego
    {
        temporizador_delta += (float)(clock() - tiempo_inicial ) /  CLOCKS_PER_SEC;
        temporizador_fps += (float)(clock() - tiempo_inicial ) /  CLOCKS_PER_SEC;

        tiempo_inicial = clock();

        if(temporizador_fps >= 1){
            fps = contador_fps;
            contador_fps = 0;
            temporizador_fps = 0;
        }

        if(temporizador_delta>1/FPS){
            float tiempo_delta = 0;
            while(temporizador_delta>1/FPS){
                tiempo_delta += 1/FPS*40;
                temporizador_delta-=1.0/FPS;
            }
            contador_fps+=1;

            if(Pantalla_TeclaPulsada(BOTON_SALIR)) exit(0);

            t2=time(NULL);

            nivel=1+(t2-t1-tiempoPausaTotal)/(unJugador ? 20 : 15);

            //Se calcula la puntuación en base al tiempo, al dinero y a los puntos por destruir enemigos
            t = t2 - t1 + dinero*5 - tiempoPausaTotal + puntosDestruccion;

            //Pantalla de pausa
            if((Pantalla_TeclaPulsada(JUGADOR1_PAUSA) || Pantalla_TeclaPulsada(JUGADOR2_PAUSA)) && !pausaPulsado){
                    reproduceSonido(sonidoMenu);
                    Pantalla_ColorRelleno(0,0,0,150);
                    Pantalla_ColorTrazo(0,0,0,0);
                    Pantalla_DibujaRectangulo(0,0,Pantalla_Anchura(),Pantalla_Altura());
                    pausaPulsado = 1;
                    Pantalla_ColorTrazo(255,255,255,255);
                Pantalla_DibujaTexto("Pause: press the button again to continue",225,Pantalla_Altura()/2);
                    Pantalla_Actualiza();
                while (Pantalla_Activa() && !terminado){
                    if(Pantalla_TeclaPulsada(BOTON_SALIR)) exit(0);
                    if ((Pantalla_TeclaPulsada(JUGADOR1_PAUSA) || Pantalla_TeclaPulsada(JUGADOR2_PAUSA)) && !pausaPulsado)
                    {
                        reproduceSonido(sonidoComenzar);
                        terminado=1;
                        pausaPulsado=1;
                    } else if(!(Pantalla_TeclaPulsada(JUGADOR1_PAUSA) || Pantalla_TeclaPulsada(JUGADOR2_PAUSA)) && pausaPulsado) {
                        pausaPulsado = 0;
                    }
                    t3=time(NULL);
                    tiempoPausa=t3-t2;

                    Pantalla_Espera(TIEMPO_ESPERA);
                }
                tiempoPausaTotal+=tiempoPausa;
                terminado=0;
                tiempo_inicial = clock();
            } else if (!(Pantalla_TeclaPulsada(JUGADOR1_PAUSA) || Pantalla_TeclaPulsada(JUGADOR2_PAUSA)) && pausaPulsado){
                pausaPulsado = 0;
            }

            //Dibujamos el fondo
            Pantalla_DibujaImagen(batallaFondo,fondoX,fondoY,1200,800);

            //Estadísticas que aparecen arriba a la izquierda
            sprintf( score,"Score: %d",t );
            sprintf( monedas,"Coins: %d", dinero );

            if(unJugador){
                sprintf( cadencia,"Fire delay: %d", PersonajeEsValido(p[0]) ? PersonajeC(p[0]) : PersonajeC(p[1]));
            } else {
                sprintf( cadencia,"Fire delay: %d / %d", PersonajeC(p[0]), PersonajeC(p[1]));
            }

            if(unJugador){
                sprintf( dolor,"Power: %d", PersonajeEsValido(p[0]) ? PersonajeD(p[0]) : PersonajeD(p[1]));
            } else {
                sprintf( dolor,"Power: %d / %d", PersonajeD(p[0]), PersonajeD(p[1]));
            }

            if(unJugador){
                sprintf( velocidad,"Speed: %d", PersonajeEsValido(p[0]) ? PersonajeV(p[0]) : PersonajeV(p[1]));
            } else {
                sprintf( velocidad,"Speed: %d / %d", PersonajeV(p[0]), PersonajeV(p[1]));
            }

            sprintf( nivelActual,"Level: %d", nivel);
            sprintf( textoFps,"FPS: %d", fps);

            temporizador_generador_enemigo+=tiempo_delta;

            if(temporizador_generador_enemigo>1){

                temporizador_generador_enemigo = 0;

                //Vamos generando enemigos con el tiempo dependiendo del nivel
                numeroAleatorio=rand()%(unJugador ? 150-2*nivel : 125-2*nivel);

                switch(numeroAleatorio)
                {
                case 0:
                    EjercitoInserta(ejercito,enemigoImagen0,(Pantalla_Anchura()/2)-20,0,44,36,(rand()%4+4)*pow(-1,rand()%2),rand()%4+4,0,15,5);
                    break;
                case 1:
                    if ( nivel>=2 )
                        EjercitoInserta(ejercito,enemigoImagen1,(Pantalla_Anchura()/2)-20,0,44,36,(rand()%3+3)*pow(-1,rand()%2),rand()%3+10,0,40,10);
                    break;
                case 2:
                    if ( nivel>=3 )
                        EjercitoInserta(ejercito,enemigoImagen2,(Pantalla_Anchura()/2)-20,0,24,20,(rand()%13+15)*pow(-1,rand()%2),rand()%3+5,0,1,20);
                    break;
                case 3:
                    if ( nivel>=4 )
                        EjercitoInserta(ejercito,enemigoImagen3,(Pantalla_Anchura()/2)-20,0,104,84,(rand()%3+3)*pow(-1,rand()%2),rand()%3+3,0,130,35);
                    break;
                case 4:
                    if ( nivel>=5 )
                        EjercitoInserta(ejercito,enemigoImagen4,(Pantalla_Anchura()/2)-20,0,54,44,(rand()%6+5)*pow(-1,rand()%2),0,1,60,25);
                    break;
                case 5:
                    if ( nivel>=6 )
                        EjercitoInserta(ejercito,enemigoImagen5,(Pantalla_Anchura()/2)-20,0,104,84,(rand()%3+3)*pow(-1,rand()%2),rand()%3+3,2,100,40);
                    break;
                case 6:
                    if ( nivel>=7 )
                        EjercitoInserta(ejercito,enemigoImagen6,(Pantalla_Anchura()/2)-20,0,54,44,(rand()%4+4)*pow(-1,rand()%2),rand()%4+4,3,70,35);
                    break;
                case 7:
                    if ( nivel>=8 )
                        EjercitoInserta(ejercito,enemigoImagen7,(Pantalla_Anchura()/2)-20,0,74,60,(rand()%6+4)*pow(-1,rand()%2),rand()%6+4,4,150,40);
                    break;
                case 8:
                    if ( nivel>=9 )
                        EjercitoInserta(ejercito,enemigoImagen8,(Pantalla_Anchura()/2)-20,0,76,62,(rand()%5+5)*pow(-1,rand()%2),rand()%5+5,5,90,50);
                    break;
                case 9:
                    if ( nivel>=10 ){
                        mimoX=rand()%(Pantalla_Anchura()-50);
                        mimoY=rand()%(Pantalla_Altura()-200)+100;
                        //El enemigo se crea solo si está lejos del personaje (si no, aparecería encima y sería injusto).
                        if(abs(mimoY-PersonajeY(p[0]))>50 &&
                           abs(mimoX-PersonajeX(p[0]))>50 &&
                           abs(mimoY-PersonajeY(p[1]))>50 &&
                           abs(mimoX-PersonajeX(p[1]))>50)
                            EjercitoInserta(ejercito,enemigoImagen9,mimoX,mimoY,37,37,0,0,0,80,30);
                    }
                    break;
                case 10:
                    if ( nivel>=11 )
                        EjercitoInserta(ejercito,enemigoImagen10,(Pantalla_Anchura()/2)-20,-100,204,164,(rand()%2+2)*pow(-1,rand()%2),rand()%2+1,0,300+20*nivel,80);
                    break;
                }
            }

            //Creamos las balas para Triska
            if(PersonajeEsValido(p[0])){
                if(contCadencia[0]>=PersonajeC(p[0])){
                    if(Pantalla_TeclaPulsada(triskaBotonDisparar)){
                        reproduceSonido(sonidoDisparaBala);
                        RafagaInserta(rafaga[0],balaImagen[0],PersonajeX(p[0])+2,PersonajeY(p[0]),14,19,20);
                        RafagaInserta(rafaga[0],balaImagen[0],PersonajeX(p[0])+12,PersonajeY(p[0])-10,14,19,20);
                        RafagaInserta(rafaga[0],balaImagen[0],PersonajeX(p[0])+22,PersonajeY(p[0]),14,19,20);

                        contCadencia[0]=0;
                    }
                } else {
                    contCadencia[0]+=tiempo_delta;
                }
            }

            //Lo mismo para Beta
            if(PersonajeEsValido(p[1])){
                if(contCadencia[1]>=PersonajeC(p[1])){
                    if(Pantalla_TeclaPulsada(betaBotonDisparar)){
                        reproduceSonido(sonidoDisparaCohete);
                        RafagaInserta(rafaga[1],balaImagen[1],PersonajeX(p[1])-15,PersonajeY(p[1])-10,28,38,15);
                        RafagaInserta(rafaga[1],balaImagen[1],PersonajeX(p[1])+25,PersonajeY(p[1])-10,28,38,15);

                        contCadencia[1]=0;
                    }
                } else {
                    contCadencia[1]+=tiempo_delta;
                }
            }


            //Comprobamos si hemos utilizado una bomba
            if((Pantalla_TeclaPulsada(JUGADOR1_BOMBA) || Pantalla_TeclaPulsada(JUGADOR2_BOMBA)) &&
               numBombas>0 && bombaUtilizadaAnim==-1)
            {
                reproduceSonido(sonidoUsaBomba);
                numBombas--;
                puntosDestruccion+=EjercitoDestruye(ejercito,pelicula,enemigoExplota,8);
                dialogo=5;
                dialogoNeutralAnim=0;
                dialogoColisionAnim=-1;
                bombaUtilizadaAnim=0;
            }

            if(Pantalla_TeclaPulsada(JUGADOR1_ABAJO) && fondoY>-200){
                fondoY=fondoY-tiempo_delta;
            }
            if(Pantalla_TeclaPulsada(JUGADOR1_ARRIBA) && fondoY<0){
                fondoY=fondoY+tiempo_delta;
            }
            if(Pantalla_TeclaPulsada(JUGADOR1_DERECHA) && fondoX>-400){
                fondoX=fondoX-tiempo_delta;
            }
            if(Pantalla_TeclaPulsada(JUGADOR1_IZQUIERDA) && fondoX<0){
                fondoX=fondoX+tiempo_delta;
            }

            if(!unJugador){
                if(Pantalla_TeclaPulsada(JUGADOR2_ABAJO) && fondoY>-200){
                    fondoY=fondoY-tiempo_delta;
                }
                if(Pantalla_TeclaPulsada(JUGADOR2_ARRIBA) && fondoY<0){
                    fondoY=fondoY+tiempo_delta;
                }
                if(Pantalla_TeclaPulsada(JUGADOR2_DERECHA) && fondoX>-400){
                    fondoX=fondoX-tiempo_delta;
                }
                if(Pantalla_TeclaPulsada(JUGADOR2_IZQUIERDA) && fondoX<0){
                    fondoX=fondoX+tiempo_delta;
                }
            }

            //Comprobamos si nuestras balas han colisionado con algún enemigo. Si es así, sumamos puntos por destrucción
            int puntosSumados = EjercitoComprobar(ejercito,pelicula,enemigoExplota,8);
            if(puntosSumados){
                reproduceSonido(sonidoDestruyeEnemigo);
                puntosDestruccion+=puntosSumados;
            }

            //Movemos a nuestro personaje, al ejército y a las balas
            PersonajeMueve(p, tiempo_delta);
            EjercitoMueve(ejercito,p, tiempo_delta);
            if(PersonajeEsValido(p[0])) RafagaMueve(rafaga[0], tiempo_delta);
            if(PersonajeEsValido(p[1])) RafagaMueve(rafaga[1], tiempo_delta);

            //Comprobamos si nos hemos chocado con algún enemigo
            if(framesInvencibilidad==0 && EjercitoColision(ejercito,p)){
                reproduceSonido(sonidoColision);
                numEscudos--;
                explosionAnimColision=0;
                framesInvencibilidad=1;
                if(numEscudos==0){
                    terminado=1;
                }
                dialogo=4;
                dialogoNeutralAnim=-1;
                dialogoColisionAnim=0;
            }

            //Comprobamos si se ha conseguido una moneda y si esa moneda nos ha hecho conseguir una mejora
            if(GalaxiaColision(g,p,pelicula,monedaDesvanece,6)){
                reproduceSonido(sonidoRecogeMoneda);
                dinero=dinero+1;
                GalaxiaInserta(g,moneda,rand()%(Pantalla_Anchura()-50),rand()%(Pantalla_Altura()-200)+100,39,39);
                conseguirMonedaAnim=1;
                if(dinero%20==0) //Cada vez que conseguimos una moneda comprobamos si esa moneda nos ha hecho ganar una mejora
                {
                    reproduceSonido(sonidoConsigueMejora);
                    dialogoNeutralAnim=0;
                    dialogoColisionAnim=-1;
                    conseguirMejoraAnim=0;
                    mejoraAleatoria=rand()%3+1;

                    switch(mejoraAleatoria){
                    case 1:
                        if(PersonajeEsValido(p[0]) && PersonajeC(p[0])>2) PersonajeMejoraCadencia(p[0],1);
                        if(PersonajeEsValido(p[1]) && PersonajeC(p[1])>5) PersonajeMejoraCadencia(p[1],1);
                        break;
                    case 2:
                        if(PersonajeEsValido(p[0]) && PersonajeD(p[0])<20) PersonajeMejoraDolor(p[0],2);
                        if(PersonajeEsValido(p[1]) &&PersonajeD(p[1])<50) PersonajeMejoraDolor(p[1],5);
                        break;
                    case 3:
                        if(PersonajeEsValido(p[0]) && PersonajeV(p[0])<20) PersonajeMejoraVelocidad(p[0],1);
                        if(PersonajeEsValido(p[1]) && PersonajeV(p[1])<20) PersonajeMejoraVelocidad(p[1],1);
                        break;
                    }
                    dialogo=mejoraAleatoria;
                }
                if(dinero%75==0)
                {
                    reproduceSonido(sonidoConsigueEscudo);
                    conseguirEscudoAnim=0;
                    if(numEscudos<3) numEscudos++;
                }
                if(dinero%100==0)
                {
                    reproduceSonido(sonidoConsigueBomba);
                    conseguirBombaAnim=0;
                    if(numBombas<3) numBombas++;
                }
                if(dinero%50==0)
                {
                    GalaxiaInserta(g,moneda,rand()%(Pantalla_Anchura()-50),rand()%(Pantalla_Altura()-200)+100,39,39);
                }
            }

            //Comprobamos si las balas se han salido por arriba
            RafagaTocaTecho(rafaga[0]);
            RafagaTocaTecho(rafaga[1]);

            //Comprobamos si nuestras balas han impactado con algún enemigo
            if(RafagaColision(rafaga[1],ejercito,PersonajeD(p[1]),pelicula,11,explosion,78,78))
                reproduceSonido(sonidoChocaCohete);
            if(RafagaColision(rafaga[0],ejercito,PersonajeD(p[0]),pelicula,7,balaColisiona,24,33))
                reproduceSonido(sonidoChocaBala);

            switch(dialogo)
            {
            case 0:
                if(PersonajeEsValido(p[1]))
                {
                    Pantalla_ColorTrazo(255,150,0,255);
                    Pantalla_DibujaTexto("Let's kill them all",150 + (PersonajeEsValido(p[0]) ? 320 : 0),Pantalla_Altura()-40);
                }

                if(PersonajeEsValido(p[0]))
                {
                    Pantalla_ColorTrazo(0,255,255,255);
                    Pantalla_DibujaTexto("All Systems Initialized.",150,Pantalla_Altura()-60);
                }
                break;
            case 1:
                if(PersonajeEsValido(p[1]))
                {
                    Pantalla_ColorTrazo(255,150,0,255);
                    Pantalla_DibujaTexto("More rockets!",150 + (PersonajeEsValido(p[0]) ? 400 : 0),Pantalla_Altura()-40);
                }
                if(PersonajeEsValido(p[0]))
                {
                    Pantalla_ColorTrazo(0,255,255,255);
                    Pantalla_DibujaTexto("Update Acquired: Rate Of Fire Increased",150,Pantalla_Altura()-60);
                }
                break;
            case 2:
                if(PersonajeEsValido(p[1]))
                {
                    Pantalla_ColorTrazo(255,150,0,255);
                    Pantalla_DibujaTexto("More power!",150 + (PersonajeEsValido(p[0]) ? 400 : 0),Pantalla_Altura()-40);
                }
                if(PersonajeEsValido(p[0]))
                {
                    Pantalla_ColorTrazo(0,255,255,255);
                    Pantalla_DibujaTexto("Update Acquired: Power Increased",150,Pantalla_Altura()-60);
                }
                break;
            case 3:
                if(PersonajeEsValido(p[1]))
                {
                    Pantalla_ColorTrazo(255,150,0,255);
                    Pantalla_DibujaTexto("Now I'm faster!",150 + (PersonajeEsValido(p[0]) ? 380 : 0),Pantalla_Altura()-40);
                }
                if(PersonajeEsValido(p[0]))
                {
                    Pantalla_ColorTrazo(0,255,255,255);
                    Pantalla_DibujaTexto("Update Acquired: Speed Of Aircraft Increased",150,Pantalla_Altura()-60);
                }
                break;
            case 4:
                Pantalla_ColorTrazo(255,0,0,255);
                if(PersonajeEsValido(p[1]))
                {
                    Pantalla_DibujaTexto("Argh!! They hit me!!",150 + (PersonajeEsValido(p[0]) ? 320 : 0),Pantalla_Altura()-40);
                }
                if(PersonajeEsValido(p[0]))
                {

                    Pantalla_DibujaTexto("WARNING. WARNING. COLLISION DETECTED",150,Pantalla_Altura()-60);
                }
                break;
            case 5:
                if(PersonajeEsValido(p[1]))
                {
                    Pantalla_ColorTrazo(255,150,0,255);
                    Pantalla_DibujaTexto("Bomb used!",150 + (PersonajeEsValido(p[0]) ? 400 : 0),Pantalla_Altura()-40);
                }
                if(PersonajeEsValido(p[0]))
                {
                    Pantalla_ColorTrazo(0,255,255,255);
                    Pantalla_DibujaTexto("Explosive Artifact Deployed Successfully",150,Pantalla_Altura()-60);
                }
                break;
            }

            //Animación de diálogo neutral
            if(dialogoNeutralAnim>=0 && dialogoNeutralAnim<8){
                if(PersonajeEsValido(p[0])) Pantalla_DibujaImagen(triskaDialogoNeutral[(int)dialogoNeutralAnim],0,Pantalla_Altura()-137,111,137);
                if(PersonajeEsValido(p[1])) Pantalla_DibujaImagen(betaDialogoNeutral[(int)dialogoNeutralAnim],unJugador ? 0 : 800-111,Pantalla_Altura()-137,111,137);
                dialogoNeutralAnim+=tiempo_delta;

            } else if (dialogoNeutralAnim>=8){
                if(PersonajeEsValido(p[0])) Pantalla_DibujaImagen(triskaDialogoNeutral[0],0,Pantalla_Altura()-137,111,137);
                if(PersonajeEsValido(p[1])) Pantalla_DibujaImagen(betaDialogoNeutral[0],unJugador ? 0 : 800-111,Pantalla_Altura()-137,111,137);
                dialogoNeutralAnim=1;
            }

            //Animación de diálogo de colisión
            if(dialogoColisionAnim>=0 && dialogoColisionAnim<8){
                if(PersonajeEsValido(p[0])) Pantalla_DibujaImagen(triskaDialogoColision[(int)dialogoColisionAnim],0,Pantalla_Altura()-137,111,137);
                if(PersonajeEsValido(p[1])) Pantalla_DibujaImagen(betaDialogoColision[(int)dialogoColisionAnim],unJugador ? 0 : 800-111,Pantalla_Altura()-137,111,137);
                dialogoColisionAnim+=tiempo_delta;

            } else if (dialogoColisionAnim>=8){
                if(PersonajeEsValido(p[0])) Pantalla_DibujaImagen(triskaDialogoColision[0],0,Pantalla_Altura()-137,111,137);
                if(PersonajeEsValido(p[1])) Pantalla_DibujaImagen(betaDialogoColision[0],unJugador ? 0 : 800-111,Pantalla_Altura()-137,111,137);
                dialogoColisionAnim=1;
            }

            //Dibujamos los escudos arriba a la derecha
            switch(numEscudos)
            {
            case 3:
                Pantalla_DibujaImagen(escudos3,620,0,178,60);
                break;
            case 2:
                Pantalla_DibujaImagen(escudos2,620,0,178,60);
                break;
            case 1:
                Pantalla_DibujaImagen(escudos1,620,0,178,60);
                break;
            }

            //Dibujamos las bombas arriba a la derecha
            switch(numBombas)
            {
            case 3:
                Pantalla_DibujaImagen(bombas3,620,60,178,60);
                break;
            case 2:
                Pantalla_DibujaImagen(bombas2,620,60,178,60);
                break;
            case 1:
                Pantalla_DibujaImagen(bombas1,620,60,178,60);
                break;
            }

            //Dibujamos el portal, las monedas, el personaje, la ráfaga y el ejército
            Pantalla_DibujaImagen(portal,0,0,Pantalla_Anchura(),60);

            GalaxiaDibuja(g);
            RafagaDibuja(rafaga[0]);
            RafagaDibuja(rafaga[1]);
            EjercitoDibuja(ejercito);
            PeliculaMueve(pelicula, tiempo_delta);

            if(((int)framesInvencibilidad)%2==0){
                if(PersonajeEsValido(p[0])) PersonajeDibuja(p[0]);
                if(PersonajeEsValido(p[1])) PersonajeDibuja(p[1]);
            }

            if(framesInvencibilidad>0 && framesInvencibilidad<40){
                framesInvencibilidad+=tiempo_delta;
            } else{
                framesInvencibilidad=0;
            }

            //Animación de +1 al conseguir moneda
            if(conseguirMonedaAnim>0 && conseguirMonedaAnim<40){
                if(PersonajeEsValido(p[0])) Pantalla_DibujaImagen(conseguirMoneda,PersonajeX(p[0]),PersonajeY(p[0])-conseguirMonedaAnim-10,39,39);
                if(PersonajeEsValido(p[1])) Pantalla_DibujaImagen(conseguirMoneda,PersonajeX(p[1]),PersonajeY(p[1])-conseguirMonedaAnim-10,39,39);
                conseguirMonedaAnim+=5*tiempo_delta;
            } else {
                conseguirMonedaAnim=0;
            }

            //Animación de flechas verdes al conseguir mejora
            if(conseguirMejoraAnim>=0 && conseguirMejoraAnim<8){
                if(PersonajeEsValido(p[0])) Pantalla_DibujaImagen(conseguirMejora[(int)conseguirMejoraAnim],PersonajeX(p[0])-20,PersonajeY(p[0])-20,78,78);
                if(PersonajeEsValido(p[1])) Pantalla_DibujaImagen(conseguirMejora[(int)conseguirMejoraAnim],PersonajeX(p[1])-20,PersonajeY(p[1])-20,78,78);
                conseguirMejoraAnim+=tiempo_delta;
            } else {
                conseguirMejoraAnim=-1;
            }

            //Animación de explosión al usar una bomba
            if(bombaUtilizadaAnim>=0 && bombaUtilizadaAnim<8){
                Pantalla_DibujaImagen(explosion[(int)bombaUtilizadaAnim],0,0,Pantalla_Anchura(),Pantalla_Altura());
                bombaUtilizadaAnim+=tiempo_delta;
            } else {
                bombaUtilizadaAnim=-1;
            }

            //Animación de explosión al recibir un golpe
            if(explosionAnimColision>=0 && explosionAnimColision<10){
                if(PersonajeEsValido(p[0])) Pantalla_DibujaImagen(explosion[(int)explosionAnimColision],PersonajeX(p[0])-20,PersonajeY(p[0])-20,78,78);
                if(PersonajeEsValido(p[1])) Pantalla_DibujaImagen(explosion[(int)explosionAnimColision],PersonajeX(p[1])-20,PersonajeY(p[1])-20,78,78);
                explosionAnimColision+=tiempo_delta;
            } else {
                explosionAnimColision=-1;
            }

            //Animación de conseguir un nuevo escudo
            if(conseguirEscudoAnim>=0 && conseguirEscudoAnim<8){
                if(PersonajeEsValido(p[0])) Pantalla_DibujaImagen(conseguirEscudo[(int)conseguirEscudoAnim],PersonajeX(p[0])-20,PersonajeY(p[0])-20,78,78);
                if(PersonajeEsValido(p[1])) Pantalla_DibujaImagen(conseguirEscudo[(int)conseguirEscudoAnim],PersonajeX(p[1])-20,PersonajeY(p[1])-20,78,78);
                conseguirEscudoAnim+=tiempo_delta;
            } else {
                conseguirEscudoAnim=-1;
            }

            //Animación de conseguir una nueva bomba
            if(conseguirBombaAnim>=0 && conseguirBombaAnim<8){
                if(PersonajeEsValido(p[0])) Pantalla_DibujaImagen(conseguirBomba[(int)conseguirBombaAnim],PersonajeX(p[0])-20,PersonajeY(p[0])-20,78,78);
                if(PersonajeEsValido(p[1])) Pantalla_DibujaImagen(conseguirBomba[(int)conseguirBombaAnim],PersonajeX(p[1])-20,PersonajeY(p[1])-20,78,78);
                conseguirBombaAnim+=tiempo_delta;
            } else {
                conseguirBombaAnim=-1;
            }

            //Dibujamos las estadísticas de arriba a la izquierda
            Pantalla_ColorTrazo(255,255,255,255);
            Pantalla_DibujaTexto(score,10,10);
            Pantalla_ColorTrazo(255,255,100,255);
            Pantalla_DibujaTexto(monedas,10,30);
            Pantalla_ColorTrazo(100,255,255,255);
            Pantalla_DibujaTexto(cadencia,10,50);
            Pantalla_ColorTrazo(255,100,150,255);
            Pantalla_DibujaTexto(dolor,10,70);
            Pantalla_ColorTrazo(255,100,255,255);
            Pantalla_DibujaTexto(velocidad,10,90);
            Pantalla_ColorTrazo(100,255,150,255);
            Pantalla_DibujaTexto(nivelActual,10,110);
            Pantalla_ColorTrazo(255,150,0,255);
            Pantalla_DibujaTexto(textoFps,10,130);

            Pantalla_Actualiza();
        }
    }

    terminado=0;
    explosionAnimColision=0;

    if(t <= tRecord3 && rand()%12 == 11){
        Sonido _ = creaSonido("sonidos/_.wav");
        Imagen bystander = Pantalla_ImagenLee("imagenes/bystander.bmp",0);
        int await = 111;
        while (Pantalla_Activa() && await)
        {
            if(rand()%2) reproduceSonido(_);
            sprintf( score,"null" );
            sprintf( monedas,"null" );
            sprintf( cadencia,"null" );
            sprintf( dolor,"null" );
            sprintf( velocidad,"null" );
            sprintf( nivelActual,"null" );
            sprintf( textoFps,"null" );

            Pantalla_ColorRelleno(0,0,0,255);
            Pantalla_ColorTrazo(0,0,0,255);
            Pantalla_DibujaRectangulo(0,0,800,600);

            if(PersonajeEsValido(p[0])) Pantalla_DibujaImagen(bystander,0,Pantalla_Altura()-137,111,137);
            if(PersonajeEsValido(p[1])) Pantalla_DibujaImagen(bystander,800-111,Pantalla_Altura()-137,111,137);

            Pantalla_ColorTrazo(255,255,255,255);
            for(int i=0;i<(111-await);i++){
                Pantalla_DibujaTexto("DEBUG: UNABLE TO READ FROM MEMORY ADDRESS 0x00000000 AT main.c:790",100,0+i*20);
            }

            Pantalla_DibujaTexto(score,10,10);
            Pantalla_DibujaTexto(monedas,10,30);
            Pantalla_DibujaTexto(cadencia,10,50);
            Pantalla_DibujaTexto(dolor,10,70);
            Pantalla_DibujaTexto(velocidad,10,90);
            Pantalla_DibujaTexto(nivelActual,10,110);
            Pantalla_DibujaTexto(textoFps,10,130);

            Pantalla_Actualiza();

            printf("DEBUG: UNABLE TO READ FROM MEMORY ADDRESS 0x00000000 AT main.c:790\n");

            Pantalla_Espera(TIEMPO_ESPERA);

            await--;
        }
        liberaSonido(_);
        Pantalla_ImagenLibera(bystander);

        int* ______ = NULL;
        *______ = 11;
    }

    while (Pantalla_Activa() && !terminado) //Bucle de fin de juego
    {

        //Estadísticas que aparecen arriba a la izquierda
        sprintf( score,"Score: %d",t );
        sprintf( monedas,"Coins: %d", dinero );

        if(unJugador){
            sprintf( cadencia,"Fire delay: %d", PersonajeEsValido(p[0]) ? PersonajeC(p[0]) : PersonajeC(p[1]));
        } else {
            sprintf( cadencia,"Fire delay: %d / %d", PersonajeC(p[0]), PersonajeC(p[1]));
        }

        if(unJugador){
            sprintf( dolor,"Power: %d", PersonajeEsValido(p[0]) ? PersonajeD(p[0]) : PersonajeD(p[1]));
        } else {
            sprintf( dolor,"Power: %d / %d", PersonajeD(p[0]), PersonajeD(p[1]));
        }

        if(unJugador){
            sprintf( velocidad,"Speed: %d", PersonajeEsValido(p[0]) ? PersonajeV(p[0]) : PersonajeV(p[1]));
        } else {
            sprintf( velocidad,"Speed: %d / %d", PersonajeV(p[0]), PersonajeV(p[1]));
        }

        sprintf( nivelActual,"Level: %d", nivel);
        sprintf( textoFps,"FPS: %d", fps);

        Pantalla_DibujaImagen(batallaFondo,fondoX,fondoY,1200,800);

        Pantalla_DibujaImagen(portal,0,0,Pantalla_Anchura(),60);
        GalaxiaDibuja(g);
        RafagaDibuja(rafaga[0]);
        RafagaDibuja(rafaga[1]);
        EjercitoDibuja(ejercito);

        if(PersonajeEsValido(p[0])) Pantalla_DibujaImagen(conexionTerminada,0,Pantalla_Altura()-137,111,137);
        if(PersonajeEsValido(p[1])) Pantalla_DibujaImagen(conexionTerminada,unJugador ? 0 : 800-111,Pantalla_Altura()-137,111,137);
        Pantalla_ColorTrazo(255,255,255,255-explosionAnimColision);

        if(explosionAnimColision>=0 && explosionAnimColision<10){
            if(PersonajeEsValido(p[0])) Pantalla_DibujaImagen(explosion[(int)explosionAnimColision],PersonajeX(p[0])-20,PersonajeY(p[0])-20,78,78);
            if(PersonajeEsValido(p[1])) Pantalla_DibujaImagen(explosion[(int)explosionAnimColision],PersonajeX(p[1])-20,PersonajeY(p[1])-20,78,78);
            explosionAnimColision+=1;
        }

        if(explosionAnimColision>=10){
            Pantalla_ColorRelleno(0,0,0,explosionAnimColision);
            Pantalla_ColorTrazo(0,0,0,explosionAnimColision);
            Pantalla_DibujaRectangulo(0,0,Pantalla_Anchura(),Pantalla_Altura());
            explosionAnimColision+=5;
        }

        if(explosionAnimColision==255)
        {
            terminado=1;
        }

        Pantalla_ColorTrazo(255,255,255,255-explosionAnimColision);
        Pantalla_DibujaTexto(score,10,10);
        Pantalla_ColorTrazo(255,255,100,255-explosionAnimColision);
        Pantalla_DibujaTexto(monedas,10,30);
        Pantalla_ColorTrazo(100,255,255,255-explosionAnimColision);
        Pantalla_DibujaTexto(cadencia,10,50);
        Pantalla_ColorTrazo(255,100,150,255-explosionAnimColision);
        Pantalla_DibujaTexto(dolor,10,70);
        Pantalla_ColorTrazo(255,100,255,255-explosionAnimColision);
        Pantalla_DibujaTexto(velocidad,10,90);
        Pantalla_ColorTrazo(100,255,150,255-explosionAnimColision);
        Pantalla_DibujaTexto(nivelActual,10,110);

        Pantalla_Actualiza();

        Pantalla_Espera(TIEMPO_ESPERA);
    }

    terminado=0;

    //Si hemos hecho record, lo registramos
    char nombrePtr[6] = "AAAAA";
    hechoRecord=0;

    if(t > tRecord3){
        hechoRecord = 1;
    }

    int letraApuntada = 0;
    Pantalla_ColorRelleno(0,0,0,255);
    while(hechoRecord && Pantalla_Activa() && !terminado){

        if (Pantalla_TeclaPulsada(JUGADOR1_DISPARA))
        {
            terminado=1;
        }
        else if (Pantalla_TeclaPulsada(JUGADOR1_IZQUIERDA))
        {
            letraApuntada-=1;
            if(letraApuntada==-1) letraApuntada = 4;
        }
        else if (Pantalla_TeclaPulsada(JUGADOR1_DERECHA))
        {
            letraApuntada+=1;
            if(letraApuntada==5) letraApuntada = 0;
        }
        else if (Pantalla_TeclaPulsada(JUGADOR1_ARRIBA))
        {
            switch(nombrePtr[letraApuntada])
            {
            case 'Z':
                nombrePtr[letraApuntada] = '1';
                break;
            case '9':
                nombrePtr[letraApuntada] = '_';
                break;
            case '_':
                nombrePtr[letraApuntada] = 'A';
                break;
            default:
                nombrePtr[letraApuntada]++;
                break;
            }
        }
        else if (Pantalla_TeclaPulsada(JUGADOR1_ABAJO))
        {
            switch(nombrePtr[letraApuntada])
            {
            case 'A':
                nombrePtr[letraApuntada] = '_';
                break;
            case '_':
                nombrePtr[letraApuntada] = '9';
                break;
            case '1':
                nombrePtr[letraApuntada] = 'Z';
                break;
            default:
                nombrePtr[letraApuntada]--;
                break;
            }
        }

        Pantalla_ColorTrazo(0,0,0,255);
        Pantalla_DibujaRectangulo(0,0,Pantalla_Anchura(),Pantalla_Altura());
        Pantalla_ColorTrazo(255,255,255,255);
        Pantalla_DibujaTexto("Use the Joystick to enter your name",250,240);
        Pantalla_DibujaTexto("Press Shoot when you're done",270,260);
        Pantalla_DibujaTexto(nombrePtr,380,280);
        Pantalla_DibujaTexto("_",380+letraApuntada*9,290);

        Pantalla_Actualiza();
        Pantalla_Espera(100);
    }


    if(t>tRecord1){
        f=fopen(ficheroRecord, "w"); //w de write
        fprintf(f, "%d %d %s %d %d %s %d %d %s", nivel, t, nombrePtr, nRecord1, tRecord1, nombreRecord1, nRecord2, tRecord2, nombreRecord2);
        fclose(f);
        hechoRecord=1;
    } else if(t>tRecord2){
        f=fopen(ficheroRecord, "w"); //w de write
        fprintf(f, "%d %d %s %d %d %s %d %d %s", nRecord1, tRecord1, nombreRecord1, nivel, t, nombrePtr, nRecord2, tRecord2, nombreRecord2);
        fclose(f);
        hechoRecord=2;
    } else if(t>tRecord3){
        f=fopen(ficheroRecord, "w"); //w de write
        fprintf(f, "%d %d %s %d %d %s %d %d %s", nRecord1, tRecord1, nombreRecord1, nRecord2, tRecord2, nombreRecord2, nivel, t, nombrePtr);
        fclose(f);
        hechoRecord=3;
    }

    terminado = 0;

    while (Pantalla_Activa() && !terminado)
    {
        if (Pantalla_TeclaPulsada(BOTON_SALIR))
        {
            terminado=1;
        }

        sprintf(score,"Your score was: %d",t);
        sprintf(monedas,"Coins collected: %d",dinero);
        Pantalla_DibujaImagen(gameOver,0,0,Pantalla_Anchura(),Pantalla_Altura());
        Pantalla_ColorTrazo(255,255,255,255);
        Pantalla_DibujaTexto(score,275,300);
        Pantalla_DibujaTexto(monedas,275,330);
        if(hechoRecord==0){
            Pantalla_DibujaTexto("You couldn't beat any of the highest scores...",275,360);
            Pantalla_DibujaTexto("The current ranking is:",275,390);
            sprintf(score,"1 %s: %d points, level %d",nombreRecord1, tRecord1, nRecord1);
            Pantalla_DibujaTexto(score,275,420);
            sprintf(score,"2 %s: %d points, level %d",nombreRecord2, tRecord2, nRecord2);
            Pantalla_DibujaTexto(score,275,450);
            sprintf(score,"3 %s: %d points, level %d",nombreRecord3, tRecord3, nRecord3);
            Pantalla_DibujaTexto(score,275,480);
        } else if(hechoRecord==1){
            Pantalla_DibujaTexto("You beat the highest score!",275,360);
            Pantalla_DibujaTexto("The current ranking is:",275,390);
            sprintf(score,"1 %s: %d points, level %d",nombrePtr, t, nivel);
            Pantalla_DibujaTexto(score,275,420);
            sprintf(score,"2 %s: %d points, level %d",nombreRecord1, tRecord1, nRecord1);
            Pantalla_DibujaTexto(score,275,450);
            sprintf(score,"3 %s: %d points, level %d",nombreRecord2, tRecord2, nRecord2);
            Pantalla_DibujaTexto(score,275,480);
        } else if(hechoRecord==2){
            Pantalla_DibujaTexto("You beat the second highest score!",275,360);
            Pantalla_DibujaTexto("The current ranking is:",275,390);
            sprintf(score,"1 %s: %d points, level %d",nombreRecord1, tRecord1, nRecord1);
            Pantalla_DibujaTexto(score,275,420);
            sprintf(score,"2 %s: %d points, level %d",nombrePtr, t, nivel);
            Pantalla_DibujaTexto(score,275,450);
            sprintf(score,"3 %s: %d points, level %d",nombreRecord2, tRecord2, nRecord2);
            Pantalla_DibujaTexto(score,275,480);
        } else if(hechoRecord==3){
            Pantalla_DibujaTexto("You beat the third highest score!",275,360);
            Pantalla_DibujaTexto("The current ranking is:",275,390);
            sprintf(score,"1 %s: %d points, level %d",nombreRecord1, tRecord1, nRecord1);
            Pantalla_DibujaTexto(score,275,420);
            sprintf(score,"2 %s: %d points, level %d",nombreRecord2, tRecord2, nRecord2);
            Pantalla_DibujaTexto(score,275,450);
            sprintf(score,"3 %s: %d points, level %d",nombrePtr, t, nivel);
            Pantalla_DibujaTexto(score,275,480);
        }

        Pantalla_DibujaTexto("Press EXIT button to exit",275,510);

        Pantalla_Actualiza();

        Pantalla_Espera(TIEMPO_ESPERA);
    }
    PersonajeLibera(p[0]);
    PersonajeLibera(p[1]);
    GalaxiaLibera(g);
    EjercitoLibera(ejercito);
    RafagaLibera(rafaga[0]);
    RafagaLibera(rafaga[1]);
    Pantalla_ImagenLibera(conexionTerminada);
    Pantalla_ImagenLibera(personajeImagen[0]);
    Pantalla_ImagenLibera(personajeImagen[1]);
    Pantalla_ImagenLibera(portal);
    Pantalla_ImagenLibera(controles2P);
    Pantalla_ImagenLibera(enemigoImagen0);
    Pantalla_ImagenLibera(enemigoImagen1);
    Pantalla_ImagenLibera(enemigoImagen2);
    Pantalla_ImagenLibera(enemigoImagen3);
    Pantalla_ImagenLibera(enemigoImagen4);
    Pantalla_ImagenLibera(enemigoImagen5);
    Pantalla_ImagenLibera(enemigoImagen6);
    Pantalla_ImagenLibera(enemigoImagen7);
    Pantalla_ImagenLibera(enemigoImagen8);
    Pantalla_ImagenLibera(enemigoImagen9);
    Pantalla_ImagenLibera(enemigoImagen10);
    Pantalla_ImagenLibera(balaImagen[0]);
    Pantalla_ImagenLibera(balaImagen[1]);
    Pantalla_ImagenLibera(escudos3);
    Pantalla_ImagenLibera(escudos2);
    Pantalla_ImagenLibera(escudos1);
    Pantalla_ImagenLibera(bombas2);
    Pantalla_ImagenLibera(bombas1);
    Pantalla_ImagenLibera(gameOver);
    Pantalla_ImagenLibera(batallaFondo);
    Pantalla_ImagenLibera(moneda);
    Pantalla_ImagenLibera(conseguirMoneda);
    for(i=0;i<8;i++){
        Pantalla_ImagenLibera(triskaDialogoNeutral[i]);
    }
    for(i=0;i<8;i++){
        Pantalla_ImagenLibera(triskaDialogoColision[i]);
    }
    for(i=0;i<8;i++){
        Pantalla_ImagenLibera(betaDialogoNeutral[i]);
    }
    for(i=0;i<8;i++){
        Pantalla_ImagenLibera(betaDialogoColision[i]);
    }
    for(i=0;i<8;i++){
        Pantalla_ImagenLibera(conseguirMejora[i]);
    }
    for(i=0;i<8;i++){
        Pantalla_ImagenLibera(conseguirEscudo[i]);
    }
    for(i=0;i<10;i++){
        Pantalla_ImagenLibera(explosion[i]);
    }
    for(i=0;i<7;i++){
        Pantalla_ImagenLibera(balaColisiona[i]);
    }
    for(i=0;i<8;i++){
        Pantalla_ImagenLibera(conseguirBomba[i]);
    }
    for(i=0;i<8;i++){
        Pantalla_ImagenLibera(enemigoExplota[i]);
    }
    for(i=0;i<6;i++){
        Pantalla_ImagenLibera(monedaDesvanece[i]);
    }

    liberaSonido(sonidoAceptar);
    liberaSonido(sonidoMenu);
    liberaSonido(sonidoComenzar);
    liberaSonido(sonidoDisparaBala);
    liberaSonido(sonidoChocaBala);
    liberaSonido(sonidoRecogeMoneda);
    liberaSonido(sonidoConsigueMejora);
    liberaSonido(sonidoDestruyeEnemigo);
    liberaSonido(sonidoColision);
    liberaSonido(sonidoChocaCohete);
    liberaSonido(sonidoDisparaCohete);
    liberaSonido(sonidoUsaBomba);
    liberaSonido(sonidoConsigueBomba);
    liberaSonido(sonidoConsigueEscudo);

    PeliculaLibera(pelicula);
    Pantalla_Libera();
    return 0;
}
