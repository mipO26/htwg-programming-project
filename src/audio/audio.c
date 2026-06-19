#include "audio.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "songs.h"
#include <stdbool.h>
#include "timing.h"
#include <stdint.h>
#include "notes.h"
#include "noteScheduler.h"

#define DELAY_MS 70
#define DELAY_SAMPLES (SAMPLE_RATE * DELAY_MS / 1000)

static float delay_buffer[DELAY_SAMPLES];
static int delay_pos = 0;

double freq[NOTE_COUNT] = {
    // Octave 0
    27.50, 29.14, 30.87,

    // Octave 1
    32.70, 34.65, 36.71, 38.89, 41.20, 43.65,
    46.25, 49.00, 51.91, 55.00, 58.27, 61.74,

    // Octave 2
    65.41, 69.30, 73.42, 77.78, 82.41, 87.31,
    92.50, 98.00, 103.83, 110.00, 116.54, 123.47,

    // Octave 3
    130.81, 138.59, 146.83, 155.56, 164.81, 174.61,
    185.00, 196.00, 207.65, 220.00, 233.08, 246.94,

    // Octave 4
    261.63, 277.18, 293.66, 311.13, 329.63, 349.23,
    369.99, 392.00, 415.30, 440.00, 466.16, 493.88,

    // Octave 5
    523.25, 554.37, 587.33, 622.25, 659.25, 698.46,
    739.99, 783.99, 830.61, 880.00, 932.33, 987.77,

    // Octave 6
    1046.50, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91,
    1479.98, 1567.98, 1661.22, 1760.00, 1864.66, 1975.53,

    // Octave 7
    2093.00, 2217.46, 2349.32, 2489.02, 2637.02, 2793.83,
    2959.96, 3135.96, 3322.44, 3520.00, 3729.31, 3951.07,

    // Octave 8
    4186.01,

    // Pause
    0.0
};


typedef struct {
    double frequency;
    double phase;
    float amplitude;
    uint64_t start_time;
    uint64_t end_time;
} Oscillator;

Oscillator notes[NOTE_COUNT];

void init_notes(void)
{
    for (int i = 0; i < NOTE_COUNT; i++) {
        notes[i].phase = 0.0;
        notes[i].frequency = freq[i];
        notes[i].end_time = 0;
        if (freq[i] < 200)
            notes[i].amplitude = 0.30f;
        else if (freq[i] < 400)
            notes[i].amplitude = 0.22f;
        else
            notes[i].amplitude = 0.18f;
    }
}

float envelope(Oscillator note)
{
    float t = time_from_start(note.start_time) * 1e-6f;
    if (t < 0.005f)
        return t / 0.005f;
    return 0.5f * expf(-3.0f * t)
         + 0.5f * expf(-0.8f * t);
}

float hammer(Oscillator note)
{
    uint64_t t = time_from_start(note.start_time);
    float ham = 0.0f;
    if (t < 0.01f)
    {
        ham = ((float)rand()/RAND_MAX*2.0f-1.0f)
                * expf(-300*t)
                * 0.15f;
    }
    return ham;
}

void audio_callback(void *userdata, Uint8 *stream, int len)
{
    runSchedulers();

    // samples are represented as floats
    float *buffer = (float *)stream;
    int samples = len / sizeof(float);

    // collect samples
    for (int i = 0; i < samples; i++) {
        int active_count = 0;
        float sample = 0.0f;
        for (int j = 0; j < NOTE_COUNT; j++) {
            if (!is_in_future(notes[j].end_time))
                continue;
            double p = notes[j].phase;
            float t = time_from_start(notes[j].start_time) * 1e-6f;
            float osc =
                1.0f * sin(p)
                + 0.7f * expf(-0.5*t) * sin(2.0002*p)
                + 0.45f * expf(-1.2*t) * sin(3.0004*p)
                + 0.25f * expf(-1.9*t) * sin(4.0006*p)
                + 0.12f * expf(-2.4*t) * sin(5.0009*p);
            osc /= 2.52f;
            float env = envelope(notes[j]);
            float ham = hammer(notes[j]);
            sample += notes[j].amplitude * (ham + osc)  * 1.002 * env;
            notes[j].phase +=
                2.0 * M_PI *
                notes[j].frequency /
                SAMPLE_RATE;
            if (notes[j].phase >= 2.0 * M_PI)
                notes[j].phase -= 2.0 * M_PI;
            active_count++;
        }
        if (active_count > 0)
            sample /= sqrtf(active_count);
        
        float delayed = delay_buffer[delay_pos];

        float out = sample
                + 0.50f * delayed;

        delay_buffer[delay_pos] =
            sample
            + 0.65f * delayed;

        delay_pos++;
        if (delay_pos >= DELAY_SAMPLES)
            delay_pos = 0;

        buffer[i] = tanhf(out);
    }
}

SDL_AudioDeviceID audio_init()
{
    init_notes();
    initSchedulers();
    set_bpm(100);

    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("SDL init failed\n");
        return 0;
    }
    SDL_AudioSpec spec = {0};
    spec.freq = SAMPLE_RATE;
    spec.format = AUDIO_F32SYS; // audio samples will be 32-bit floating point
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
    notes[note].start_time = now_us();
    notes[note].end_time = add_time_note(0, duration);
}

void playNoteMs(Note note, uint32_t duration_ms)
{
    notes[note].end_time = add_time_ms(notes[note].end_time, duration_ms);
}

void stopNote(Note note)
{
    notes[note].end_time = 0;
}