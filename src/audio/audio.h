#ifndef SOUND_H
#define SOUND_H

#include <SDL.h>
#include "audioInterface.h"

#define False 0
#define SAMPLE_RATE 44100

/* Sound system */
SDL_AudioDeviceID audio_init();
void audio_terminate(SDL_AudioDeviceID device);

#endif /* SOUND_H */