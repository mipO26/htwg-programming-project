#include "songs.h"
#include "noteScheduler.h"

void d_dur_chord(void)
{
    printf("Playing D minor chord...");
    enqueueNote(1, D3, WHOLE_NOTE);
    enqueueNote(2, F3, WHOLE_NOTE);
    enqueueNote(3, A3, WHOLE_NOTE);
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
    getchar();
}

void ode_to_joy(void)
{
    printf("Playing Ode to joy...");

    d_dur_chord();

    enqueueNote(0, E4, QUARTER_NOTE);
    enqueueNote(0, E4, QUARTER_NOTE);
    enqueueNote(0, F4, QUARTER_NOTE);
    enqueueNote(0, G4, QUARTER_NOTE);
    enqueueNote(0, G4, QUARTER_NOTE);
    enqueueNote(0, F4, QUARTER_NOTE);
    enqueueNote(0, E4, QUARTER_NOTE);
    enqueueNote(0, D4, QUARTER_NOTE);
    enqueueNote(0, C4, QUARTER_NOTE);
    enqueueNote(0, C4, QUARTER_NOTE);
    enqueueNote(0, D4, QUARTER_NOTE);
    enqueueNote(0, E4, QUARTER_NOTE);
    enqueueNote(0, E4, QUARTER_NOTE);
    enqueueNote(0, D4, QUARTER_NOTE);
    enqueueNote(0, D4, HALF_NOTE);

    enqueueNote(0, E4, QUARTER_NOTE);
    enqueueNote(0, E4, QUARTER_NOTE);
    enqueueNote(0, F4, QUARTER_NOTE);
    enqueueNote(0, G4, QUARTER_NOTE);
    enqueueNote(0, G4, QUARTER_NOTE);
    enqueueNote(0, F4, QUARTER_NOTE);
    enqueueNote(0, E4, QUARTER_NOTE);
    enqueueNote(0, D4, QUARTER_NOTE);
    enqueueNote(0, C4, QUARTER_NOTE);
    enqueueNote(0, C4, QUARTER_NOTE);
    enqueueNote(0, D4, QUARTER_NOTE);
    enqueueNote(0, E4, QUARTER_NOTE);
    enqueueNote(0, D4, QUARTER_NOTE);
    enqueueNote(0, C4, QUARTER_NOTE);
    enqueueNote(0, C4, HALF_NOTE);
    getchar(); 
}

void hedwigs_theme(void)
{
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

    getchar();
}