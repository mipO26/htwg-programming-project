#include "audio.h"
#include "keyboard.h"
#include "tests/noteSchedulerTester.h"
#define False 0

int main(void)
{
    // tests
    // noteSchedulerTester();

    SDL_AudioDeviceID device = audio_init();
    sound_temp();
    audio_terminate(device);

    // keyboard();

    return 0;
}