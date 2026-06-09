#include "audio.h"
#include "keyboard.h"
#define False 0

int main(void)
{
    SDL_AudioDeviceID device = audio_init();
    sound_temp();
    audio_terminate(device);

    keyboard();

    return 0;
}