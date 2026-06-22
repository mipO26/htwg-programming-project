#include "audio/audio.h"
#include "keyboard.h"
#include "audio/songs.h"
#include <stdio.h>
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
    int opt;
    play_song();
    // do {
    //     printf("What do you want to do?\n\t1] Play predefined song\n\t2] Play custom chord\n\t3]exit");
    //     scanf("%i", &opt);
    //     switch (opt)
    //     {
    //         case 1: play_song(); break;
    //         case 2: keyboard(); break;
    //     }

    // } while (opt != 3);
    
    /*==================================================
    * TERMINATION
    *==================================================*/
    audio_terminate(device);

    return 0;
}