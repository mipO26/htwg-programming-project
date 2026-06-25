#include "songs.h"
#include "noteScheduler.h"
#include "chords.h"
#include "timing.h"
#include "ui/ui_active.h"
#include "audioConfig.h"

static int song_mode_active = 0;


void end_song()
{
    while (!isSongFinished())
    {
        // renderUi();
        if (SHOW_KEYBOARD) renderUiFullKeyboard();
        sleep_ms(10);
    }
    if (SHOW_KEYBOARD) renderUiFullKeyboard();
    sleep_ms(500);
}

int get_song_mode_active()
{
    return song_mode_active;
}

void set_song_mode_active(int active)
{
    song_mode_active = active;
}

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

    end_song();
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

    end_song();
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

    end_song();
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

    end_song();
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
        // Measure 3

    // Right hand - Voice 1
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    // Right hand - Voice 2
    enqueueNote(3, Fs5, EIGHTH_NOTE);
    enqueueNote(3, B5, EIGHTH_NOTE);
    enqueueNote(3, B5, HALF_NOTE);
    enqueueNote(3, A5, EIGHTH_NOTE);
    enqueueNote(3, Gs5, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 4

    // Right hand - Voice 1
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    // Right hand - Voice 2
    enqueueNote(3, E5, QUARTER_NOTE);
    enqueueNote(3, Cs5, DOTTED_HALF_NOTE);

    // Left hand
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 5

    // Right hand - Voice 1
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, QUARTER_NOTE);
    enqueueNote(2, Ds5, QUARTER_NOTE);

    // Right hand - Voice 2
    enqueueNote(3, PAUSE, DOTTED_HALF_NOTE);
    enqueueNote(3, Fs5, EIGHTH_NOTE);

    // Measure 5 (left hand)

    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 6

    // Right hand - Voice 1
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    // Right hand - Voice 2
    enqueueNote(3, Fs5, EIGHTH_NOTE);
    enqueueNote(3, Gs5, EIGHTH_NOTE);
    enqueueNote(3, Gs5, HALF_NOTE);
    enqueueNote(3, A5, SIXTEENTH_NOTE);
    enqueueNote(3, Gs5, SIXTEENTH_NOTE);
    enqueueNote(3, Fs5, SIXTEENTH_NOTE);
    enqueueNote(3, E5, SIXTEENTH_NOTE);

    // Left hand
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 7

    // Right hand - Voice 1
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    // Right hand - Voice 2
    enqueueNote(3, Fs5, EIGHTH_NOTE);
    enqueueNote(3, B5, EIGHTH_NOTE);
    enqueueNote(3, B5, HALF_NOTE);
    enqueueNote(3, Gs5, EIGHTH_NOTE);
    enqueueNote(3, B5, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 8

    // Right hand - Voice 1
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    // Right hand - Voice 2
    // Grace note omitted
    enqueueNote(3, Cs6, HALF_NOTE);
    enqueueNote(3, B5, HALF_NOTE);

    // Left hand
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 9

    // Right hand - Voice 1
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, QUARTER_NOTE);
    enqueueNote(2, Ds5, QUARTER_NOTE);

    // Right hand - Voice 2
    enqueueNote(3, Fs5, HALF_NOTE);
    enqueueNote(3, PAUSE, HALF_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);

        // Measure 10

    // Right hand
    enqueueNote(2, E4, DOTTED_QUARTER_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 11

    // Right hand
    enqueueNote(2, Ds4, QUARTER_NOTE);
    enqueueNote(2, E4, HALF_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 12

    // Right hand
    enqueueNote(2, Ds4, QUARTER_NOTE);
    enqueueNote(2, E4, HALF_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, Fs4, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 13

    // Right hand
    enqueueNote(2, Gs4, HALF_NOTE);
    enqueueNote(2, Fs4, HALF_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 14

    // Right hand
    enqueueNote(2, E4, DOTTED_QUARTER_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 15

    // Right hand
    enqueueNote(2, Ds4, QUARTER_NOTE);
    enqueueNote(2, E4, HALF_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 16

    // Right hand
    enqueueNote(2, B3, WHOLE_NOTE);

    // Left hand (visible portion)
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);

        // Measure 16 (continued)

    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 17

    // Right hand
    enqueueNote(2, A3, EIGHTH_NOTE);
    enqueueNote(2, B3, EIGHTH_NOTE);
    enqueueNote(2, Cs4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, A4, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, Cs5, EIGHTH_NOTE);
    enqueueNote(2, Ds5, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);


    // Measure 18

    // Right hand
    enqueueNote(2, E4, DOTTED_QUARTER_NOTE);
    enqueueNote(2, E5, QUARTER_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);


    // Measure 19

    // Right hand
    enqueueNote(2, Ds4, QUARTER_NOTE);
    enqueueNote(2, E4, HALF_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 20

    // Right hand
    enqueueNote(2, Ds4, QUARTER_NOTE);
    enqueueNote(2, E4, HALF_NOTE);
    enqueueNote(2, Fs4, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 21

    // Right hand
    enqueueNote(2, Gs4, HALF_NOTE);
    enqueueNote(2, Fs4, HALF_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 22

    // Right hand
    enqueueNote(2, E4, DOTTED_QUARTER_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);


    // Measure 23

    // Right hand
    enqueueNote(2, Ds4, QUARTER_NOTE);
    enqueueNote(2, E4, HALF_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);

        enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 24

    // Right hand
    enqueueNote(2, B3, WHOLE_NOTE);

    // Left hand
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 25

    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);
    enqueueNote(2, PAUSE, WHOLE_NOTE);


    // Measure 26

    // Right hand
    enqueueNote(2, E4, WHOLE_NOTE);
    enqueueNote(2, E5, WHOLE_NOTE);

    // Left hand
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);


    // Measure 27

    // Right hand
    enqueueNote(2, Fs4, DOTTED_HALF_NOTE);
    enqueueNote(2, Ds5, WHOLE_NOTE);
    enqueueNote(2, B3, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, Ds4, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, Ds4, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);


    // Measure 28

    // Right hand
    enqueueNote(2, B4, HALF_NOTE);
    enqueueNote(2, Cs5, WHOLE_NOTE);
    enqueueNote(2, A4, QUARTER_NOTE);
    enqueueNote(2, Gs4, EIGHTH_NOTE);
    enqueueNote(2, Fs4, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);


    // Measure 29

    // Right hand
    enqueueNote(2, Fs4, HALF_NOTE);
    enqueueNote(2, Ds5, HALF_NOTE);
    enqueueNote(2, Gs4, DOTTED_QUARTER_NOTE);
    enqueueNote(2, B4, HALF_NOTE);
    enqueueNote(2, A4, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, Ds4, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, Ds4, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);


    // Measure 30

    // Right hand
    enqueueNote(2, Gs4, WHOLE_NOTE);
    enqueueNote(2, Gs4, HALF_NOTE);
    enqueueNote(2, Fs4, DOTTED_QUARTER_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, E4, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);


    // Measure 31

    // Right hand
    enqueueNote(2, Ds4, QUARTER_NOTE);
    enqueueNote(2, E4, HALF_NOTE);
    enqueueNote(2, Ds4, QUARTER_NOTE);
    enqueueNote(2, B4, WHOLE_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);

        enqueueNote(0, Fs3, EIGHTH_NOTE);

    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);


    // Measure 32

    // Right hand
    enqueueNote(2, Cs4, DOTTED_HALF_NOTE);
    enqueueNote(2, Cs5, WHOLE_NOTE);
    enqueueNote(2, Cs4, EIGHTH_NOTE);
    enqueueNote(2, Ds4, SIXTEENTH_NOTE);
    enqueueNote(2, Cs4, SIXTEENTH_NOTE);

    // Left hand
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);


    // Measure 33

    // Right hand
    enqueueNote(2, B3, HALF_NOTE);
    enqueueNote(2, PAUSE, DOTTED_QUARTER_NOTE);
    enqueueNote(2, Gs4, EIGHTH_NOTE);
    enqueueNote(2, A4, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, Cs5, EIGHTH_NOTE);
    enqueueNote(2, Ds5, EIGHTH_NOTE);

    // Inner voice
    enqueueNote(1, PAUSE, HALF_NOTE);
    enqueueNote(1, A3, HALF_NOTE);

    // Left hand
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);


    // Measure 34

    // Right hand
    enqueueNote(2, E4, WHOLE_NOTE);
    enqueueNote(2, E5, WHOLE_NOTE);

    // Left hand
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);

    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);

        // Measure 35

    // Right hand
    enqueueNote(2, Fs4, DOTTED_HALF_NOTE);
    enqueueNote(2, Ds5, WHOLE_NOTE);
    enqueueNote(2, B3, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, Ds4, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);

    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, Ds4, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);


    // Measure 36

    // Right hand
    enqueueNote(2, B4, HALF_NOTE);
    enqueueNote(2, Cs5, WHOLE_NOTE);
    enqueueNote(2, A4, QUARTER_NOTE);
    enqueueNote(2, Gs4, EIGHTH_NOTE);
    enqueueNote(2, Fs4, EIGHTH_NOTE);   // tie start

    // Left hand
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);

    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);


    // Measure 37

    // Right hand
    enqueueNote(2, Fs4, HALF_NOTE);     // tie stop
    enqueueNote(2, Ds5, HALF_NOTE);
    enqueueNote(2, Gs4, QUARTER_NOTE);
    enqueueNote(2, B4, HALF_NOTE);
    enqueueNote(2, A4, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, Ds4, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);

    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, Ds4, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);


    // Measure 38

    // Right hand
    enqueueNote(2, Gs4, HALF_NOTE);
    enqueueNote(2, Gs4, WHOLE_NOTE);
    enqueueNote(2, Fs4, QUARTER_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, E4, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);

    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);


    // Measure 39

    // Right hand
    enqueueNote(2, Ds4, QUARTER_NOTE);
    enqueueNote(2, E4, HALF_NOTE);
    enqueueNote(2, PAUSE, HALF_NOTE);
    enqueueNote(2, B4, HALF_NOTE);
    enqueueNote(2, Ds4, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, Gs2, EIGHTH_NOTE);
    enqueueNote(0, Ds3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Ds3, EIGHTH_NOTE);

    enqueueNote(0, Gs2, EIGHTH_NOTE);
    enqueueNote(0, Ds3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Ds3, EIGHTH_NOTE);


    // Measure 40

    // Right hand
    enqueueNote(2, Ds4, QUARTER_NOTE);
    enqueueNote(2, E4, HALF_NOTE);
    enqueueNote(2, Fs4, QUARTER_NOTE);

        // Measure 40 (continued)

    // Right hand
    enqueueNote(2, Cs5, WHOLE_NOTE);

    // Left hand
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);

    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);


    // Measure 41

    // Right hand
    enqueueNote(2, Gs4, HALF_NOTE);
    enqueueNote(2, Fs4, HALF_NOTE);

    enqueueNote(2, PAUSE, HALF_NOTE);
    enqueueNote(2, PAUSE, QUARTER_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, Fs5, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, E4, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);

    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, Ds4, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);


    // Measure 42

    // Right hand
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);    // tie start
    enqueueNote(2, E5, EIGHTH_NOTE);    // tie stop
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    enqueueNote(2, Fs5, EIGHTH_NOTE);
    enqueueNote(2, Gs5, EIGHTH_NOTE);   // tie start
    enqueueNote(2, Gs5, HALF_NOTE);     // tie stop
    enqueueNote(2, A5, SIXTEENTH_NOTE);
    enqueueNote(2, Gs5, SIXTEENTH_NOTE);
    enqueueNote(2, Fs5, SIXTEENTH_NOTE);
    enqueueNote(2, E5, SIXTEENTH_NOTE);

    // Left hand
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);


    // Measure 43

    // Right hand
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);    // tie start
    enqueueNote(2, E5, EIGHTH_NOTE);    // tie stop
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    enqueueNote(2, Fs5, EIGHTH_NOTE);
    enqueueNote(2, B5, EIGHTH_NOTE);    // tie start
    enqueueNote(2, B5, HALF_NOTE);      // tie stop
    enqueueNote(2, Gs5, EIGHTH_NOTE);
    enqueueNote(2, B5, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

        // Measure 44

    // Right hand
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);      // tie start
    enqueueNote(2, E5, EIGHTH_NOTE);      // tie stop
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    // Upper voice
    enqueueNote(2, B5, WHOLE_NOTE);
    enqueueNote(2, Cs6, HALF_NOTE);
    enqueueNote(2, B5, HALF_NOTE);

    // Left hand
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);


    // Measure 45

    // Right hand
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B4, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);
    enqueueNote(2, E5, EIGHTH_NOTE);      // tie start
    enqueueNote(2, E5, QUARTER_NOTE);     // tie stop
    enqueueNote(2, Ds5, QUARTER_NOTE);

    enqueueNote(2, Fs5, HALF_NOTE);       // inverted mordent

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);


    // Measure 46

    // Right hand
    enqueueNote(2, E4, DOTTED_QUARTER_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);

    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);


    // Measure 47

    // Right hand
    enqueueNote(2, Ds4, QUARTER_NOTE);
    enqueueNote(2, E4, HALF_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);

    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);


    // Measure 48

    // Right hand
    enqueueNote(2, Ds4, QUARTER_NOTE);
    enqueueNote(2, E4, HALF_NOTE);
    enqueueNote(2, Fs4, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, Cs4, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);

    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, A3, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);


    // Measure 49
    // Right hand
    enqueueNote(2, Gs4, HALF_NOTE);
    enqueueNote(2, Fs4, HALF_NOTE);

    // Left hand
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);

    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs3, EIGHTH_NOTE);
    enqueueNote(0, B3, EIGHTH_NOTE);

    end_song();
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

    end_song();

}

void my_heart_will_go_on_low()
{
    set_bpm(100);
    printf("Playing My Heart Will Go On...\n");

    // Measure 1
    enqueueNote(2, PAUSE, QUARTER_NOTE);
    enqueueNote(3, E4, EIGHTH_NOTE);
    enqueueNote(3, Fs4, EIGHTH_NOTE);

    enqueueNote(0, PAUSE, QUARTER_NOTE);
    enqueueNote(1, PAUSE, QUARTER_NOTE);

    // Measure 2
    // Right hand - lower voice (melody)
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B3, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, B3, EIGHTH_NOTE);
    enqueueNote(2, E3, QUARTER_NOTE);

    // Right hand - upper voice
    enqueueNote(3, Fs4, EIGHTH_NOTE);
    enqueueNote(3, Gs4, EIGHTH_NOTE);
    enqueueNote(3, Gs4, HALF_NOTE);
    enqueueNote(3, Fs4, EIGHTH_NOTE);
    enqueueNote(3, E4, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, Cs2, EIGHTH_NOTE);
    enqueueNote(0, Gs2, EIGHTH_NOTE);
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);

    // Measure 3

    // Right hand - Voice 1
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B3, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, B3, EIGHTH_NOTE);
    enqueueNote(2, E3, QUARTER_NOTE);

    // Right hand - Voice 2
    enqueueNote(3, Fs4, EIGHTH_NOTE);
    enqueueNote(3, B4, EIGHTH_NOTE);
    enqueueNote(3, B4, HALF_NOTE);
    enqueueNote(3, A4, EIGHTH_NOTE);
    enqueueNote(3, Gs4, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 4

    // Right hand - Voice 1
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B3, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, B3, EIGHTH_NOTE);
    enqueueNote(2, E3, QUARTER_NOTE);

    // Right hand - Voice 2
    enqueueNote(3, E4, QUARTER_NOTE);
    enqueueNote(3, Cs4, DOTTED_HALF_NOTE);

    // Left hand
    enqueueNote(0, A1, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 5

    // Right hand - Voice 1
    enqueueNote(2, E3, EIGHTH_NOTE);
    enqueueNote(2, B3, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);
    enqueueNote(2, Ds4, QUARTER_NOTE);

    // Right hand - Voice 2
    enqueueNote(3, PAUSE, DOTTED_HALF_NOTE);
    enqueueNote(3, Fs4, EIGHTH_NOTE);

    // Measure 5 (left hand)

    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 6

    // Right hand - Voice 1
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B3, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, B3, EIGHTH_NOTE);
    enqueueNote(2, E3, QUARTER_NOTE);

    // Right hand - Voice 2
    enqueueNote(3, Fs4, EIGHTH_NOTE);
    enqueueNote(3, Gs4, EIGHTH_NOTE);
    enqueueNote(3, Gs4, HALF_NOTE);
    enqueueNote(3, A4, SIXTEENTH_NOTE);
    enqueueNote(3, Gs4, SIXTEENTH_NOTE);
    enqueueNote(3, Fs4, SIXTEENTH_NOTE);
    enqueueNote(3, E4, SIXTEENTH_NOTE);

    // Left hand
    enqueueNote(0, Cs2, EIGHTH_NOTE);
    enqueueNote(0, Gs2, EIGHTH_NOTE);
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 7

    // Right hand - Voice 1
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B3, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, B3, EIGHTH_NOTE);
    enqueueNote(2, E3, QUARTER_NOTE);

    // Right hand - Voice 2
    enqueueNote(3, Fs4, EIGHTH_NOTE);
    enqueueNote(3, B4, EIGHTH_NOTE);
    enqueueNote(3, B4, HALF_NOTE);
    enqueueNote(3, Gs4, EIGHTH_NOTE);
    enqueueNote(3, B4, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 8

    // Right hand - Voice 1
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B3, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, B3, EIGHTH_NOTE);
    enqueueNote(2, E3, QUARTER_NOTE);

    // Right hand - Voice 2
    // Grace note omitted
    enqueueNote(3, Cs5, HALF_NOTE);
    enqueueNote(3, B4, HALF_NOTE);

    // Left hand
    enqueueNote(0, A1, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 9

    // Right hand - Voice 1
    enqueueNote(2, PAUSE, EIGHTH_NOTE);
    enqueueNote(2, B3, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, EIGHTH_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);
    enqueueNote(2, Ds4, QUARTER_NOTE);

    // Right hand - Voice 2
    enqueueNote(3, Fs4, HALF_NOTE);
    enqueueNote(3, PAUSE, HALF_NOTE);

    // Left hand
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, EIGHTH_NOTE);
    enqueueNote(0, PAUSE, HALF_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);

    // Measure 10

    // Right hand
    enqueueNote(2, E3, DOTTED_QUARTER_NOTE);
    enqueueNote(2, E3, EIGHTH_NOTE);
    enqueueNote(2, E3, QUARTER_NOTE);
    enqueueNote(2, E3, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 11

    // Right hand
    enqueueNote(2, Ds3, QUARTER_NOTE);
    enqueueNote(2, E3, HALF_NOTE);
    enqueueNote(2, E3, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 12

    // Right hand
    enqueueNote(2, Ds3, QUARTER_NOTE);
    enqueueNote(2, E3, HALF_NOTE);
    enqueueNote(2, E3, EIGHTH_NOTE);
    enqueueNote(2, Fs3, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, A1, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A1, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 13

    // Right hand
    enqueueNote(2, Gs3, HALF_NOTE);
    enqueueNote(2, Fs3, HALF_NOTE);

    // Left hand
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 14

    // Right hand
    enqueueNote(2, E3, DOTTED_QUARTER_NOTE);
    enqueueNote(2, E3, EIGHTH_NOTE);
    enqueueNote(2, E3, QUARTER_NOTE);
    enqueueNote(2, E3, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 15

    // Right hand
    enqueueNote(2, Ds3, QUARTER_NOTE);
    enqueueNote(2, E3, HALF_NOTE);
    enqueueNote(2, E3, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 16

    // Right hand
    enqueueNote(2, B2, WHOLE_NOTE);

    // Left hand (visible portion)
    enqueueNote(0, A1, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);

    // Measure 16 (continued)

    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 17

    // Right hand
    enqueueNote(2, A2, EIGHTH_NOTE);
    enqueueNote(2, B2, EIGHTH_NOTE);
    enqueueNote(2, Cs3, EIGHTH_NOTE);
    enqueueNote(2, E3, EIGHTH_NOTE);
    enqueueNote(2, A3, EIGHTH_NOTE);
    enqueueNote(2, B3, EIGHTH_NOTE);
    enqueueNote(2, Cs4, EIGHTH_NOTE);
    enqueueNote(2, Ds4, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, A1, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);


    // Measure 18

    // Right hand
    enqueueNote(2, E3, DOTTED_QUARTER_NOTE);
    enqueueNote(2, E4, QUARTER_NOTE);
    enqueueNote(2, E3, EIGHTH_NOTE);
    enqueueNote(2, E3, QUARTER_NOTE);
    enqueueNote(2, E3, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, E1, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);


    // Measure 19

    // Right hand
    enqueueNote(2, Ds3, QUARTER_NOTE);
    enqueueNote(2, E3, HALF_NOTE);
    enqueueNote(2, E3, EIGHTH_NOTE);
    enqueueNote(2, E3, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 20

    // Right hand
    enqueueNote(2, Ds3, QUARTER_NOTE);
    enqueueNote(2, E3, HALF_NOTE);
    enqueueNote(2, Fs3, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, A1, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A1, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 21

    // Right hand
    enqueueNote(2, Gs3, HALF_NOTE);
    enqueueNote(2, Fs3, HALF_NOTE);

    // Left hand
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 22

    // Right hand
    enqueueNote(2, E3, DOTTED_QUARTER_NOTE);
    enqueueNote(2, E3, EIGHTH_NOTE);
    enqueueNote(2, E3, QUARTER_NOTE);
    enqueueNote(2, E3, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, Cs2, EIGHTH_NOTE);
    enqueueNote(0, Gs2, EIGHTH_NOTE);
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs2, EIGHTH_NOTE);
    enqueueNote(0, Cs2, EIGHTH_NOTE);
    enqueueNote(0, Gs2, EIGHTH_NOTE);
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs2, EIGHTH_NOTE);


    // Measure 23

    // Right hand
    enqueueNote(2, Ds3, QUARTER_NOTE);
    enqueueNote(2, E3, HALF_NOTE);
    enqueueNote(2, E3, EIGHTH_NOTE);
    enqueueNote(2, E3, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 24

    // Right hand
    enqueueNote(2, B2, WHOLE_NOTE);

    // Left hand
    enqueueNote(0, A1, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);


    // Measure 25

    enqueueNote(0, A1, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A2, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);

    enqueueNote(1, PAUSE, WHOLE_NOTE);
    enqueueNote(2, PAUSE, WHOLE_NOTE);


    // Measure 26

    // Right hand
    enqueueNote(2, E3, WHOLE_NOTE);
    enqueueNote(2, E4, WHOLE_NOTE);

    // Left hand
    enqueueNote(0, Cs2, EIGHTH_NOTE);
    enqueueNote(0, Gs2, EIGHTH_NOTE);
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs2, EIGHTH_NOTE);
    enqueueNote(0, Cs2, EIGHTH_NOTE);
    enqueueNote(0, Gs2, EIGHTH_NOTE);
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs2, EIGHTH_NOTE);


    // Measure 27

    // Right hand
    enqueueNote(2, Fs3, DOTTED_HALF_NOTE);
    enqueueNote(2, Ds4, WHOLE_NOTE);
    enqueueNote(2, B2, QUARTER_NOTE);

    // Left hand
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, Ds3, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, Ds3, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);


    // Measure 28

    // Right hand
    enqueueNote(2, B3, HALF_NOTE);
    enqueueNote(2, Cs4, WHOLE_NOTE);
    enqueueNote(2, A3, QUARTER_NOTE);
    enqueueNote(2, Gs3, EIGHTH_NOTE);
    enqueueNote(2, Fs3, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, A1, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, A1, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, E2, EIGHTH_NOTE);


    // Measure 29

    // Right hand
    enqueueNote(2, Fs3, HALF_NOTE);
    enqueueNote(2, Ds4, HALF_NOTE);
    enqueueNote(2, Gs3, DOTTED_QUARTER_NOTE);
    enqueueNote(2, B3, HALF_NOTE);
    enqueueNote(2, A3, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, Ds3, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, Ds3, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);


    // Measure 30

    // Right hand
    enqueueNote(2, Gs3, WHOLE_NOTE);
    enqueueNote(2, Gs3, HALF_NOTE);
    enqueueNote(2, Fs3, DOTTED_QUARTER_NOTE);
    enqueueNote(2, E3, EIGHTH_NOTE);

    // Left hand
    enqueueNote(0, Cs2, EIGHTH_NOTE);
    enqueueNote(0, Gs2, EIGHTH_NOTE);
    enqueueNote(0, E3, EIGHTH_NOTE);
    enqueueNote(0, Gs2, EIGHTH_NOTE);
    enqueueNote(0, Cs2, EIGHTH_NOTE);
    enqueueNote(0, Gs2, EIGHTH_NOTE);
    enqueueNote(0, Cs3, EIGHTH_NOTE);
    enqueueNote(0, Gs2, EIGHTH_NOTE);


    // Measure 31

    // Right hand
    enqueueNote(2, Ds3, QUARTER_NOTE);
    enqueueNote(2, E3, HALF_NOTE);
    enqueueNote(2, Ds3, QUARTER_NOTE);
    enqueueNote(2, B3, WHOLE_NOTE);

    // Left hand
    enqueueNote(0, B1, EIGHTH_NOTE);
    enqueueNote(0, Fs2, EIGHTH_NOTE);
    enqueueNote(0, B2, EIGHTH_NOTE);

    end_song();
}

int play_song(void)
{
    set_song_mode_active(1);

    printf("\n\n");
    char opt;
    do {
        printf("What do you like to do today?\n\t1] Play c-sequence\n\t2] Play Ode to joy\n\t3] Play Ode to joy - with basses\n\t4] Play My heart will go on\n\t5] Play Hedwigs Theme\n\t6] Main menu\n");
        scanf(" %c", &opt);
        emptyAllSchedulers();
        switch (opt)
        {
            case '1': octave(); break;
            case '2': ode_to_joy(); break;
            case '3': ode_to_joy2(); break;
            case '4': my_heart_will_go_on(); break;
            case '5': hedwigs_theme(); break;
            case '6': break;
            default: printf("Wrong input\n"); break;
        }
    } while (opt != '6');
    set_song_mode_active(0);
    deactivateDisplayAllNotes();
    return 0;
}