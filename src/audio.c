#include "audio.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double freq[] = {
    261.63,
    293.66,
    329.63,
    349.23,
    392.00,
    440.00,
    493.88
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

void sound_init()
{

}

void sound_terminate()
{

}

int sound_temp(void)
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

    printf("Playing 440 Hz. Press Enter to quit.\n");
    getchar();
    frequency = freq[D4];
    printf("Playing 440 Hz. Press Enter to quit.\n");
    getchar();
    frequency = freq[E4];
    printf("Playing 440 Hz. Press Enter to quit.\n");
    getchar();

        SDL_CloseAudioDevice(device);
    SDL_Quit();

    return 0;
}