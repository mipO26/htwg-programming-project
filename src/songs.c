#include "songs.h"

void d_dur_chord(void)
{
    printf("Playing D minor chord...");
    playNoteMs(D4, 3000);
    playNoteMs(F4, 3000);
    playNoteMs(A4, 3000);
    getchar();
}

void octave(void)
{
    printf("Playing octave...");
    playNote(C4, QUARTER_NOTE);
    getchar(); playNote(D4, QUARTER_NOTE);
    getchar(); playNote(E4, QUARTER_NOTE);
    getchar(); playNote(F4, QUARTER_NOTE);
    getchar(); playNote(G4, QUARTER_NOTE);
    getchar(); playNote(A4, QUARTER_NOTE);
    getchar(); playNote(B4, QUARTER_NOTE);
    getchar(); playNote(C5, QUARTER_NOTE);
}

void ode_to_joy(void)
{
    printf("Playing Ode to joy...");
    playNote(E4, QUARTER_NOTE);
    getchar(); playNote(E4, QUARTER_NOTE);
    getchar(); playNote(F4, QUARTER_NOTE);
    getchar(); playNote(G4, QUARTER_NOTE);
    getchar(); playNote(G4, QUARTER_NOTE);
    getchar(); playNote(F4, QUARTER_NOTE);
    getchar(); playNote(E4, QUARTER_NOTE);
    getchar(); playNote(D4, QUARTER_NOTE);
    getchar(); playNote(C4, QUARTER_NOTE);
    getchar(); playNote(C4, QUARTER_NOTE);
    getchar(); playNote(D4, QUARTER_NOTE);
    getchar(); playNote(E4, QUARTER_NOTE);
    getchar(); playNote(E4, QUARTER_NOTE);
    getchar(); playNote(D4, QUARTER_NOTE);
    getchar(); playNote(D4, HALF_NOTE);

    getchar(); playNote(E4, QUARTER_NOTE);
    getchar(); playNote(E4, QUARTER_NOTE);
    getchar(); playNote(F4, QUARTER_NOTE);
    getchar(); playNote(G4, QUARTER_NOTE);
    getchar(); playNote(G4, QUARTER_NOTE);
    getchar(); playNote(F4, QUARTER_NOTE);
    getchar(); playNote(E4, QUARTER_NOTE);
    getchar(); playNote(D4, QUARTER_NOTE);
    getchar(); playNote(C4, QUARTER_NOTE);
    getchar(); playNote(C4, QUARTER_NOTE);
    getchar(); playNote(D4, QUARTER_NOTE);
    getchar(); playNote(E4, QUARTER_NOTE);
    getchar(); playNote(D4, QUARTER_NOTE);
    getchar(); playNote(C4, QUARTER_NOTE);
    getchar(); playNote(C4, HALF_NOTE);
    getchar(); 
}

void hedwigs_theme(void)
{
    printf("Playing Hedwig's theme...");
    playNote(E4, QUARTER_NOTE);
    getchar(); playNote(A4, QUARTER_NOTE);
    getchar(); playNote(C5, QUARTER_NOTE);
    getchar(); playNote(B4, QUARTER_NOTE);
    getchar(); playNote(A4, HALF_NOTE);
    getchar(); playNote(E5, QUARTER_NOTE);
    getchar(); playNote(D5, QUARTER_NOTE);
    getchar(); playNote(B4, QUARTER_NOTE);
    getchar(); playNote(A4, QUARTER_NOTE);
    getchar(); playNote(C5, QUARTER_NOTE);
    getchar(); playNote(B4, QUARTER_NOTE);
    getchar(); playNote(G4, QUARTER_NOTE);
    getchar(); playNote(As4, QUARTER_NOTE);
    getchar(); playNote(E4, WHOLE_NOTE);


    getchar(); playNote(A4, QUARTER_NOTE);
    getchar(); playNote(C5, QUARTER_NOTE);
    getchar(); playNote(B4, QUARTER_NOTE);
    getchar(); playNote(A4, HALF_NOTE);
    getchar(); playNote(E5, QUARTER_NOTE);
    getchar(); playNote(G5, HALF_NOTE);
    getchar(); playNote(Fs5, QUARTER_NOTE);
    getchar(); playNote(F5, HALF_NOTE);
    getchar(); playNote(Cs5, QUARTER_NOTE);
    getchar(); playNote(F5, QUARTER_NOTE);
    getchar(); playNote(E5, QUARTER_NOTE);
    getchar(); playNote(Cs5, QUARTER_NOTE);
    getchar(); playNote(Fs4, HALF_NOTE);
    getchar(); playNote(C5, QUARTER_NOTE);
    getchar(); playNote(A4, HALF_NOTE);
    getchar(); playNote(A4, HALF_NOTE);
    getchar(); playNote(C5, QUARTER_NOTE);



    getchar();
}