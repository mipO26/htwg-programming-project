#ifndef SOUND_H
#define SOUND_H

#include <SDL.h>
#include <stdbool.h>

#define False 0
#define SAMPLE_RATE 44100

typedef enum {
    C3,  Cs3, D3,  Ds3, E3,  F3,  Fs3, G3,  Gs3, A3,  As3, B3,
    C4,  Cs4, D4,  Ds4, E4,  F4,  Fs4, G4,  Gs4, A4,  As4, B4,
    C5,  Cs5, D5,  Ds5, E5,  F5,  Fs5, G5,  Gs5, A5,  As5, B5,
    NOTE_COUNT
} Note;


/* Sound system */
SDL_AudioDeviceID audio_init();
void audio_terminate(SDL_AudioDeviceID device);
void playNote(Note note);

/* Test/demo function */
int sound_temp(void);

#endif /* SOUND_H */