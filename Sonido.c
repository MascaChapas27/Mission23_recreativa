#include "Sonido.h"
#include <stdio.h>

struct SonidoRep
{
    SDL_AudioDeviceID device;
    SDL_AudioSpec audioSpec;
    Uint8* inicioOnda;
    Uint32 longitudOnda;
};

typedef struct SonidoRep * Sonido;

Sonido creaSonido(const char * archivo)
{
    Sonido s = malloc(sizeof(struct SonidoRep));
    if(SDL_LoadWAV(archivo, &(s->audioSpec), &(s->inicioOnda), &(s->longitudOnda)) == NULL)
    {
        printf("Error al cargar el sonido %s\n",archivo);
        exit(1);
    }
    preparaSonido(s);
    return s;
}

void reproduceMusica(Sonido s)
{
    if(SDL_GetQueuedAudioSize(s->device) == 0)
        SDL_QueueAudio(s->device, s->inicioOnda, s->longitudOnda);
    SDL_PauseAudioDevice(s->device,0);
}

void reproduceSonido(Sonido s)
{
    SDL_ClearQueuedAudio(s->device);
    SDL_QueueAudio(s->device, s->inicioOnda, s->longitudOnda);
    SDL_PauseAudioDevice(s->device,0);
}

void paraSonido(Sonido s)
{
    SDL_PauseAudioDevice(s->device,1);
}

void preparaSonido(Sonido s)
{
    s->device = SDL_OpenAudioDevice(NULL, 0, &(s->audioSpec), NULL, 0);

    if(s->device == 0){
        printf("Error al establecer el dispositivo de reproducción\n");
        exit(567);
    }
}

void liberaSonido(Sonido s)
{
    SDL_FreeWAV(s->inicioOnda);
    SDL_CloseAudioDevice(s->device);
    free(s);
}
