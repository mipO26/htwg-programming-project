#pragma once

#ifndef SOUND_H
#define SOUND_H

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdbool.h>
#include "notes.h"

#define False 0
#define SAMPLE_RATE 44100


SDL_AudioDeviceID audio_init();
void audio_terminate(SDL_AudioDeviceID device);


/* Notes api */
void playNote(Note note, double duration);
void playNoteMs(Note note, uint32_t duration_ms);
void stopNote(Note note);

#endif /* SOUND_H */