#ifndef SOUND_H
#define SOUND_H

#include <SDL.h>
#include <stdbool.h>

#define False 0
#define SAMPLE_RATE 44100

typedef enum {
    C4,
    D4,
    E4,
    F4,
    G4,
    A4,
    B4
} Note;

/* Global variables */
extern double freq[];
extern double phase;
extern double frequency;

/* Audio callback */
void audio_callback(void *userdata, Uint8 *stream, int len);

/* Sound system */
SDL_AudioDeviceID audio_init();
void audio_terminate(SDL_AudioDeviceID device);

/* Test/demo function */
int sound_temp(void);

#endif /* SOUND_H */