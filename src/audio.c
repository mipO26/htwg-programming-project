#include "audio.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <songs.h>

double freq[NOTE_COUNT] = {
    // Octave 3
    130.81, 138.59, 146.83, 155.56, 164.81, 174.61,
    185.00, 196.00, 207.65, 220.00, 233.08, 246.94,

    // Octave 4
    261.63, 277.18, 293.66, 311.13, 329.63, 349.23,
    369.99, 392.00, 415.30, 440.00, 466.16, 493.88,

    // Octave 5
    523.25, 554.37, 587.33, 622.25, 659.25, 698.46,
    739.99, 783.99, 830.61, 880.00, 932.33, 987.77
};

double phase = 0.0;
double frequency = 261.63;

void audio_callback(void *userdata, Uint8 *stream, int len)
{
    float *buffer = (float *)stream;
    int samples = len / sizeof(float);
    for (int i = 0; i < samples; i++) {
        buffer[i] = 0.2f * sin(phase);
        phase += 2.0 * M_PI * frequency / SAMPLE_RATE;
        if (phase > 2.0 * M_PI)
            phase -= 2.0 * M_PI;
    }
}

SDL_AudioDeviceID audio_init()
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL init failed\n");
        return 0;
    }
    SDL_AudioSpec spec = {0};
    spec.freq = SAMPLE_RATE;
    spec.format = AUDIO_F32SYS;
    spec.channels = 1;
    spec.samples = 1024;
    spec.callback = audio_callback;
    SDL_AudioDeviceID device =
        SDL_OpenAudioDevice(NULL, 0, &spec, NULL, 0);
    if (!device) {
        printf("Failed to open audio device\n");
        return 0;
    }
    SDL_PauseAudioDevice(device, 0);

    return device;
}

void audio_terminate(SDL_AudioDeviceID device)
{
    SDL_CloseAudioDevice(device);
    SDL_Quit();
}

void playNote(Note note)
{
    frequency = freq[note];
}

int sound_temp(void)
{
    ode_to_joy();
    return 0;
}