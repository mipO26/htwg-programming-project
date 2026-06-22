#include "songs.h"
#include "noteScheduler.h"
#include "chords.h"
#include "timing.h"


void octave(void)
{
    printf("Playing octave...");
    enqueueNote(0, C4, QUARTER_NOTE);
    enqueueNote(0, D4, QUARTER_NOTE);
    enqueueNote(0, E4, QUARTER_NOTE);
    enqueueNote(0, F4, QUARTER_NOTE);
    enqueueNote(0, G4, QUARTER_NOTE);
    enqueueNote(0, A4, QUARTER_NOTE);
    enqueueNote(0, B4, QUARTER_NOTE);
    enqueueNote(0, C5, QUARTER_NOTE);
}

void ode_to_joy(void)
{
    set_bpm(132);
    printf("Playing Ode to joy...");

    enqueueNote(1, E4, QUARTER_NOTE);
    enqueueNote(1, E4, QUARTER_NOTE);
    enqueueNote(1, F4, QUARTER_NOTE);
    enqueueNote(1, G4, QUARTER_NOTE);

    enqueueNote(1, G4, QUARTER_NOTE);
    enqueueNote(1, F4, QUARTER_NOTE);
    enqueueNote(1, E4, QUARTER_NOTE);
    enqueueNote(1, D4, QUARTER_NOTE);

    enqueueNote(1, C4, QUARTER_NOTE);
    enqueueNote(1, C4, QUARTER_NOTE);
    enqueueNote(1, D4, QUARTER_NOTE);
    enqueueNote(1, E4, QUARTER_NOTE);

    enqueueNote(1, E4, DOTTED_QUARTER_NOTE);
    enqueueNote(1, D4, EIGHTH_NOTE);
    enqueueNote(1, D4, HALF_NOTE);

    enqueueNote(1, E4, QUARTER_NOTE);
    enqueueNote(1, E4, QUARTER_NOTE);
    enqueueNote(1, F4, QUARTER_NOTE);
    enqueueNote(1, G4, QUARTER_NOTE);

    enqueueNote(1, G4, QUARTER_NOTE);
    enqueueNote(1, F4, QUARTER_NOTE);
    enqueueNote(1, E4, QUARTER_NOTE);
    enqueueNote(1, D4, QUARTER_NOTE);

    enqueueNote(1, C4, QUARTER_NOTE);
    enqueueNote(1, C4, QUARTER_NOTE);
    enqueueNote(1, D4, QUARTER_NOTE);
    enqueueNote(1, E4, QUARTER_NOTE);

    enqueueNote(1, D4, DOTTED_QUARTER_NOTE);
    enqueueNote(1, C4, EIGHTH_NOTE);
    enqueueNote(1, C4, HALF_NOTE);
}
void ode_to_joy1(void)
{
    set_bpm(132);
    printf("Playing Ode to joy...");

    enqueueNote(0, G3, HALF_NOTE);
    enqueueNote(1, E4, QUARTER_NOTE);
    enqueueNote(1, E4, QUARTER_NOTE);
    enqueueNote(0, A3, HALF_NOTE);
    enqueueNote(1, F4, QUARTER_NOTE);
    enqueueNote(1, G4, QUARTER_NOTE);

    enqueueNote(0, B3, HALF_NOTE);
    enqueueNote(1, G4, QUARTER_NOTE);
    enqueueNote(1, F4, QUARTER_NOTE);
    enqueueNote(0, G3, HALF_NOTE);
    enqueueNote(1, E4, QUARTER_NOTE);
    enqueueNote(1, D4, QUARTER_NOTE);

    enqueueNote(0, E3, HALF_NOTE);
    enqueueNote(1, C4, QUARTER_NOTE);
    enqueueNote(1, C4, QUARTER_NOTE);
    enqueueNote(0, F3, HALF_NOTE);
    enqueueNote(1, D4, QUARTER_NOTE);
    enqueueNote(1, E4, QUARTER_NOTE);

    enqueueNote(0, G3, HALF_NOTE);
    enqueueNote(1, E4, DOTTED_QUARTER_NOTE);
    enqueueNote(0, F3, HALF_NOTE);
    enqueueNote(1, D4, EIGHTH_NOTE);
    enqueueNote(1, D4, HALF_NOTE);

    enqueueNote(0, G3, HALF_NOTE);
    enqueueNote(1, E4, QUARTER_NOTE);
    enqueueNote(1, E4, QUARTER_NOTE);
    enqueueNote(0, A3, HALF_NOTE);
    enqueueNote(1, F4, QUARTER_NOTE);
    enqueueNote(1, G4, QUARTER_NOTE);

    enqueueNote(0, B3, HALF_NOTE);
    enqueueNote(0, G3, HALF_NOTE);
    enqueueNote(1, G4, QUARTER_NOTE);
    enqueueNote(1, F4, QUARTER_NOTE);
    enqueueNote(1, E4, QUARTER_NOTE);
    enqueueNote(1, D4, QUARTER_NOTE);

    enqueueNote(0, E3, HALF_NOTE);
    enqueueNote(0, D3, HALF_NOTE);
    enqueueNote(1, C4, QUARTER_NOTE);
    enqueueNote(1, C4, QUARTER_NOTE);
    enqueueNote(1, D4, QUARTER_NOTE);
    enqueueNote(1, E4, QUARTER_NOTE);

    enqueueNote(0, G3, HALF_NOTE);
    enqueueNote(0, E3, HALF_NOTE);
    enqueueNote(1, D4, DOTTED_QUARTER_NOTE);
    enqueueNote(1, C4, EIGHTH_NOTE);
    enqueueNote(1, C4, HALF_NOTE);
}

void ode_to_joy2()
{
    // https://tomplay.com/piano-sheet-music/beethoven/symphony-no-9-opus-125-iv-finale-ode-to-joy-easy-intermediate-level-piano-score?currency=EUR&gad_source=1&gad_campaignid=22165436047&gbraid=0AAAAAo-e4fgCKLWDFiFg521KLKbBVhnrf&gclid=Cj0KCQjwrs7RBhDuARIsAIVfBD2OFTn2Rju3e5y5Cxt73AeugQx7ywgei4gmJUCPxMoPLWK7I1CWicMaAvCjEALw_wcB
    set_bpm(132);
    printf("Playing Ode to joy 2...\n");
    // tact 1
    enqueueNote(2, C4, QUARTER_NOTE);
    enqueueNote(2, C4, QUARTER_NOTE);
    enqueueNote(2, D4, QUARTER_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    enqueueNote(3, E4, QUARTER_NOTE);
    enqueueNote(3, E4, QUARTER_NOTE);
    enqueueNote(3, F4, QUARTER_NOTE);
    enqueueNote(3, G4, QUARTER_NOTE);

    enqueueNote(0, G3, HALF_NOTE);
    enqueueNote(1, C3, HALF_NOTE);
    enqueueNote(0, G3, QUARTER_NOTE);
    enqueueNote(1, C3, QUARTER_NOTE);
    enqueueNote(0, G3, QUARTER_NOTE);
    enqueueNote(1, C3, QUARTER_NOTE);

    // tact 2
    enqueueNote(2, E4, QUARTER_NOTE);
    enqueueNote(2, D4, QUARTER_NOTE);
    enqueueNote(2, C4, QUARTER_NOTE);
    enqueueNote(2, D4, QUARTER_NOTE);

    enqueueNote(3, G4, QUARTER_NOTE);
    enqueueNote(3, F4, QUARTER_NOTE);
    enqueueNote(3, E4, QUARTER_NOTE);
    enqueueNote(3, PAUSE, QUARTER_NOTE);


    enqueueNote(0, G2, HALF_NOTE);
    enqueueNote(0, G2, QUARTER_NOTE);
    enqueueNote(0, G2, QUARTER_NOTE);
    enqueueNote(1, PAUSE, DOTTED_HALF_NOTE);
    enqueueNote(1, G3, QUARTER_NOTE);

    // tact 3
    enqueueNote(2, C4, QUARTER_NOTE);
    enqueueNote(2, C4, QUARTER_NOTE);
    enqueueNote(2, B3, QUARTER_NOTE);
    enqueueNote(2, C4, QUARTER_NOTE);

    enqueueNote(3, PAUSE, HALF_NOTE);
    enqueueNote(3, D4, QUARTER_NOTE);
    enqueueNote(3, E4, QUARTER_NOTE);

    enqueueNote(0, C3, HALF_NOTE);
    enqueueNote(0, D3, QUARTER_NOTE);
    enqueueNote(0, C3, QUARTER_NOTE);
    enqueueNote(1, E3, HALF_NOTE);
    enqueueNote(1, G3, QUARTER_NOTE);
    enqueueNote(1, G3, QUARTER_NOTE);

    // tact 4
    enqueueNote(2, C4, DOTTED_QUARTER_NOTE);
    enqueueNote(2, D4, EIGHTH_NOTE);
    enqueueNote(2, B3, HALF_NOTE);
    enqueueNote(3, E4, DOTTED_QUARTER_NOTE);
    enqueueNote(3, PAUSE, EIGHTH_NOTE);
    enqueueNote(3, D4, HALF_NOTE);

    enqueueNote(0, G3, QUARTER_NOTE);
    enqueueNote(0, G2, QUARTER_NOTE);
    enqueueNote(0, G2, HALF_NOTE);
    enqueueNote(1, PAUSE, WHOLE_NOTE);

    // tact 5
    enqueueNote(2, C4, QUARTER_NOTE);
    enqueueNote(2, C4, QUARTER_NOTE);
    enqueueNote(2, D4, QUARTER_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    enqueueNote(3, E4, QUARTER_NOTE);
    enqueueNote(3, E4, QUARTER_NOTE);
    enqueueNote(3, F4, QUARTER_NOTE);
    enqueueNote(3, G4, QUARTER_NOTE);

    enqueueNote(0, G3, HALF_NOTE);
    enqueueNote(0, G3, QUARTER_NOTE);
    enqueueNote(0, G3, QUARTER_NOTE);
    enqueueNote(1, C3, HALF_NOTE);
    enqueueNote(1, C3, QUARTER_NOTE);
    enqueueNote(1, C3, QUARTER_NOTE);

    // tact 6
    enqueueNote(2, E4, QUARTER_NOTE);
    enqueueNote(2, D4, QUARTER_NOTE);
    enqueueNote(2, C4, QUARTER_NOTE);
    enqueueNote(2, D4, QUARTER_NOTE);

    enqueueNote(3, G4, QUARTER_NOTE);
    enqueueNote(3, F4, QUARTER_NOTE);
    enqueueNote(3, E4, QUARTER_NOTE);
    enqueueNote(3, PAUSE, QUARTER_NOTE);


    enqueueNote(0, G2, HALF_NOTE);
    enqueueNote(0, G3, QUARTER_NOTE);
    enqueueNote(0, F2, QUARTER_NOTE);
    enqueueNote(1, PAUSE, DOTTED_HALF_NOTE);
    enqueueNote(1, G3, QUARTER_NOTE);

    // tact 7
    enqueueNote(2, C4, QUARTER_NOTE);
    enqueueNote(2, C4, QUARTER_NOTE);
    enqueueNote(2, B3, QUARTER_NOTE);
    enqueueNote(2, C4, QUARTER_NOTE);

    enqueueNote(3, PAUSE, HALF_NOTE);
    enqueueNote(3, D4, QUARTER_NOTE);
    enqueueNote(3, E4, QUARTER_NOTE);

    enqueueNote(0, G3, HALF_NOTE);
    enqueueNote(0, G3, QUARTER_NOTE);
    enqueueNote(0, G3, QUARTER_NOTE);
    enqueueNote(1, C3, HALF_NOTE);
    enqueueNote(1, C3, QUARTER_NOTE);
    enqueueNote(1, C3, QUARTER_NOTE);

    // tact 8
    enqueueNote(2, B3, DOTTED_QUARTER_NOTE);
    enqueueNote(2, C4, EIGHTH_NOTE);
    enqueueNote(2, G3, HALF_NOTE);
    enqueueNote(3, D4, DOTTED_QUARTER_NOTE);
    enqueueNote(3, PAUSE, EIGHTH_NOTE);
    enqueueNote(3, C4, HALF_NOTE);

    enqueueNote(0, G3, QUARTER_NOTE);
    enqueueNote(0, G2, QUARTER_NOTE);
    enqueueNote(0, G2, HALF_NOTE);
    enqueueNote(1, PAUSE, WHOLE_NOTE);

}

void my_heart_will_go_on()
{
    set_bpm(100);
    printf("Playing My Heart Will Go On...\n");

    // Measure 1
    enqueueNote(2, PAUSE, QUARTER_NOTE);
    enqueueNote(3, E5, EIGHTH_NOTE);
    enqueueNote(3, Fs5, EIGHTH_NOTE);

    enqueueNote(0, PAUSE, QUARTER_NOTE);
    enqueueNote(1, PAUSE, QUARTER_NOTE);

    // Measure 2
    // Right hand - lower voice (melody)
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    // Right hand - upper voice
    enqueueNote(3, Fs5, EIGHTH_NOTE);
    enqueueNote(3, Gs5, EIGHTH_NOTE);
    enqueueNote(3, Gs5, HALF_NOTE);
    enqueueNote(3, Fs5, EIGHTH_NOTE);
    enqueueNote(3, E5, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);
}

void hedwigs_theme(void)
{
    set_bpm(150);
    printf("Playing Hedwig's theme...");
    enqueueNote(0, E4, QUARTER_NOTE);
    enqueueNote(0, A4, QUARTER_NOTE);
    enqueueNote(0, C5, QUARTER_NOTE);
    enqueueNote(0, B4, QUARTER_NOTE);
    enqueueNote(0, A4, HALF_NOTE);
    enqueueNote(0, E5, QUARTER_NOTE);
    enqueueNote(0, D5, QUARTER_NOTE);
    enqueueNote(0, B4, QUARTER_NOTE);
    enqueueNote(0, A4, QUARTER_NOTE);
    enqueueNote(0, C5, QUARTER_NOTE);
    enqueueNote(0, B4, QUARTER_NOTE);
    enqueueNote(0, G4, QUARTER_NOTE);
    enqueueNote(0, As4, QUARTER_NOTE);
    enqueueNote(0, E4, WHOLE_NOTE);

    enqueueNote(0, A4, QUARTER_NOTE);
    enqueueNote(0, C5, QUARTER_NOTE);
    enqueueNote(0, B4, QUARTER_NOTE);
    enqueueNote(0, A4, HALF_NOTE);
    enqueueNote(0, E5, QUARTER_NOTE);
    enqueueNote(0, G5, HALF_NOTE);
    enqueueNote(0, Fs5, QUARTER_NOTE);
    enqueueNote(0, F5, HALF_NOTE);
    enqueueNote(0, Cs5, QUARTER_NOTE);
    enqueueNote(0, F5, QUARTER_NOTE);
    enqueueNote(0, E5, QUARTER_NOTE);
    enqueueNote(0, Cs5, QUARTER_NOTE);
    enqueueNote(0, Fs4, HALF_NOTE);
    enqueueNote(0, C5, QUARTER_NOTE);
    enqueueNote(0, A4, HALF_NOTE);
    enqueueNote(0, A4, HALF_NOTE);
    enqueueNote(0, C5, QUARTER_NOTE);

}

int play_song(void)
{
    // playNoteMs(C4, 3000);
    // c_major_chord();
    // octave();
    // ode_to_joy();
    // ode_to_joy1();
    ode_to_joy2();
    // my_heart_will_go_on();
    // hedwigs_theme();

    getchar();
    return 0;
}