#include "audio/audio.h"
#include "keyboard.h"
#include "audio/songs.h"
#include "ui/ui_handler.h"

#define False 0

int main(void)
{

    /*==================================================
    * INITIALIZATION
    *==================================================*/
    SDL_AudioDeviceID device = audio_init();

    /*==================================================
    * APP
    *==================================================*/
    ui();
    printf("What do you want to do today? \nOptions: a) play a song b) play chords");
    play_song();

    /*==================================================
    * TERMINATION
    *==================================================*/
    audio_terminate(device);

    return 0;
}