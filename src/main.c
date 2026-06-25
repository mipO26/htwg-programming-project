#include "audio/audio.h"
#include "keyboard.h"
#include "audio/songs.h"
#include <stdio.h>
#include "ui/ui_handler.h"
#include "ui/ui_active.h"
#include "audio/noteScheduler.h"

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
    printf("\n\n\n\n\n");
    printf("┏━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃ 𝗦𝗢𝗡𝗔𝗧𝗘 𝗜𝗡 𝗖-𝗖𝗢𝗗𝗘 ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━┛\n");
    printf("\n");
    ui();
    printf("\n\n");
    char opt;
    do {
        printf("What do you like to do today?\n\t1] Play predefined song\n\t2] Play custom chord\n\t3] Exit...\n");
        scanf(" %c", &opt);
        emptyAllSchedulers();
        switch (opt)
        {
            case '1': play_song(); break;
            case '2': keyboard(); break;
            case '3': break;
            default: printf("Wrong input\n"); break;
        }
    } while (opt != '3');
    
    /*==================================================
    * TERMINATION
    *==================================================*/
    audio_terminate(device);

    printf("\nBye...\n");

    return 0;
}