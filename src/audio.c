#include "audio.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <songs.h>
#include <stdbool.h>
#include "timing.h"
#include <stdint.h>
#include "notes.h"

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


typedef struct {
    double frequency;
    double phase;
    float amplitude;
    uint64_t end_time;
} Oscillator;

Oscillator notes[NOTE_COUNT];

void init_notes(void)
{
    for (int i = 0; i < NOTE_COUNT; i++) {
        notes[i].phase = 0.0;
        notes[i].frequency = freq[i];
        notes[i].amplitude = 0.2f;
        notes[i].end_time = 0;
    }
}

void audio_callback(void *userdata, Uint8 *stream, int len)
{
    float *buffer = (float *)stream;
    int samples = len / sizeof(float);
    for (int i = 0; i < samples; i++) {
        int active_count = 0;
        float sample = 0.0f;
        for (int j = 0; j < NOTE_COUNT; j++) {
            if (!is_active(notes[j].end_time))
                continue;
            sample += notes[j].amplitude *
                    sin(notes[j].phase);
            notes[j].phase +=
                2.0 * M_PI *
                notes[j].frequency /
                SAMPLE_RATE;
            if (notes[j].phase >= 2.0 * M_PI)
                notes[j].phase -= 2.0 * M_PI;
            active_count++;
        }
        if (active_count > 0)
            sample /= active_count;
        buffer[i] = sample;
    }
}

SDL_AudioDeviceID audio_init()
{
    init_notes();
    set_bpm(120);

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

void playNote(Note note, double duration)
{
    notes[note].end_time = add_time_note(notes[note].end_time, duration);
}

void playNoteMs(Note note, uint32_t duration_ms)
{
    notes[note].end_time = add_time_ms(notes[note].end_time, duration_ms);
}

int sound_temp(void)
{
    // d_dur_chord();
    // ode_to_joy();
    hedwigs_theme();
    return 0;
}