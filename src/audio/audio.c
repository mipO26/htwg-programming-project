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
#include "audioConfig.h"

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

    bool releasing;
    uint64_t release_time;
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
        notes[i].releasing = false;
        notes[i].release_time = 0;
    }
}

float envelope(Oscillator note)
{
    if (!ENABLE_ENVELOPE)
        return 1;
float t = time_from_start(note.start_time) * 1e-6f;
    float env;

    if (t < 0.001f)
        env = t / 0.001f;
    else
        env =
            0.5f * expf(-1.5f * t) +
            0.5f * expf(-0.8f * t) +
            0.4f * expf(-0.6f * t) +
            0.2f * expf(-0.3f * t) +
            0.1f * expf(-0.1f * t);

    if (note.releasing)
    {
        float tr = time_from_start(note.release_time) * 1e-6f;
        if (tr >= RELEASE_TIME)
            return 0.0f;
        env *= 1.0f - tr / RELEASE_TIME;
    }

    return env;
}

static int useHammer = 1;

void setUseHammer(int v)
{
    useHammer = v;
}

float hammer(Oscillator note)
{
    if (useHammer == 0)
    {
        return 0;
    }

    float t = time_from_start(note.start_time) * 1e-6f;

    if (t > 0.001f)
        return 0;

    return 0.8f *
           sin(note.phase * 8.0) *
           expf(-7000.0f * t);
}

float get_expf(float x)
{
    if (ENABLE_DELAY)
    {
        return expf(x);
    }
    return 1;
}

static inline float clampf(float x, float lo, float hi)
{
    return x < lo ? lo : (x > hi ? hi : x);
}

static inline float smoothstep(float edge0, float edge1, float x)
{
    x = clampf((x - edge0) / (edge1 - edge0), 0.0f, 1.0f);
    return x * x * (3.0f - 2.0f * x);
}

float get_osc(float p, float t, float freq)
{
    float osc = 1.0f * sin(p);
    
    if (ENABLE_HARMONIES)
    {
        float k = smoothstep(400.0f, 1000.0f, freq); // 0..1

        float d2 = 1.0f + 0.0002f * k;
        float d3 = 1.0f + 0.0003f * k;
        float d4 = 1.0f + 0.0005f * k;
        float d5 = 1.0f + 0.0008f * k;

        // exponentional envelopes
        float env1 = get_expf(-0.5f * t);
        float env2 = get_expf(-1.2f * t);
        float env3 = get_expf(-2.9f * t);
        float env4 = get_expf(-3.4f * t);

        osc =
            sin(p)
        + 0.7f  * env1 * sin(2.0f * d2 * p)
        + 0.45f * env2 * sin(3.0f * d3 * p)
        + 0.25f * env3 * sin(4.0f * d4 * p)
        + 0.12f * env4 * sin(5.0f * d5 * p);
        // osc = osc
        // + 0.7f * get_expf(-0.5*t) * sin(2.0002*p)
        // + 0.45f * get_expf(-1.2*t) * sin(3.0004*p)
        // + 0.25f * get_expf(-1.9*t) * sin(4.0006*p)
        // + 0.12f * get_expf(-2.4*t) * sin(5.0009*p);
        // osc /= 2.52f;
    }
    return osc;
}

void audio_callback(void *userdata, Uint8 *stream, int len)
{
    
    // samples are represented as floats
    float *buffer = (float *)stream;
    int samples = len / sizeof(float);
    
    // collect samples
    for (int i = 0; i < samples; i++) {
        runSchedulers();
        int active_count = 0;
        float sample = 0.0f;
        for (int j = 0; j < NOTE_COUNT; j++) {
            if (notes[j].end_time == 0 && !notes[j].releasing)
                continue;
            if (!notes[j].releasing &&
                !is_in_future(notes[j].end_time))
            {
                notes[j].releasing = true;
                notes[j].release_time = now_us();
            }
            double p = notes[j].phase;
            float t = time_from_start(notes[j].start_time) * 1e-6f;
            float osc = get_osc(p, t, notes[j].frequency);
            float env = envelope(notes[j]);
            sample += notes[j].amplitude *
                      (osc * env + hammer(notes[j]));
            notes[j].phase +=
                2.0 * M_PI *
                notes[j].frequency /
                SAMPLE_RATE;
            if (notes[j].phase >= 2.0 * M_PI)
                notes[j].phase -= 2.0 * M_PI;

            if (notes[j].releasing)
            {
                float tr =
                    time_from_start(notes[j].release_time) * 1e-6f;
                if (tr >= RELEASE_TIME)
                {
                    notes[j].releasing = false;
                    notes[j].end_time = 0;
                }
            }
            active_count++;
        }
        if (active_count > 0)
            sample /= sqrtf(active_count);
        
        if (ENABLE_DELAY)
        {
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
        else {
            buffer[i] = tanhf(sample);
        }

    }
}

SDL_AudioDeviceID audio_init()
{
    SDL_SetMainReady();
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
    notes[note].releasing = false;
    notes[note].phase = 0.0;
    notes[note].start_time = now_us();
    notes[note].end_time = add_time_note(0, duration);
}

void playNoteMs(Note note, uint32_t duration_ms)
{
    // notes[note].phase = 0.0;
    notes[note].start_time = now_us();
    notes[note].end_time = add_time_ms(notes[note].end_time, duration_ms);
}

void stopNote(Note note)
{
    notes[note].end_time = 0;
}