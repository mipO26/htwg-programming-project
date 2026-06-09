#include "audio.h"

void d_dur_chord(void)
{
    printf("Playing D minor chord...");
    playNote(D4);
    playNote(F4);
    playNote(A4);
    getchar();
}

void octave(void)
{
    printf("Playing octave...");
    playNote(C4);
    getchar(); playNote(D4);
    getchar(); playNote(E4);
    getchar(); playNote(F4);
    getchar(); playNote(G4);
    getchar(); playNote(A4);
    getchar(); playNote(B4);
    getchar(); playNote(C5);
}

void ode_to_joy(void)
{
    printf("Playing Ode to joy...");
    playNote(E4);
    getchar(); playNote(E4);
    getchar(); playNote(F4);
    getchar(); playNote(G4);
    getchar(); playNote(G4);
    getchar(); playNote(F4);
    getchar(); playNote(E4);
    getchar(); playNote(D4);
    getchar(); playNote(C4);
    getchar(); playNote(C4);
    getchar(); playNote(D4);
    getchar(); playNote(E4);
    getchar(); playNote(E4);
    getchar(); playNote(D4);
    getchar(); playNote(D4);

    getchar(); playNote(E4);
    getchar(); playNote(E4);
    getchar(); playNote(F4);
    getchar(); playNote(G4);
    getchar(); playNote(G4);
    getchar(); playNote(F4);
    getchar(); playNote(E4);
    getchar(); playNote(D4);
    getchar(); playNote(C4);
    getchar(); playNote(C4);
    getchar(); playNote(D4);
    getchar(); playNote(E4);
    getchar(); playNote(D4);
    getchar(); playNote(C4);
    getchar(); playNote(C4);
}
