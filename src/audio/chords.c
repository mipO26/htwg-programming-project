#include <stdio.h>
#include "chords.h"
#include "notes.h"      // Defines C3, D3, E3, ...
#include "songs.h"
#include "noteScheduler.h"

void c_major_chord(void)
{
    printf("Playing C major chord...\n");
    enqueueNote(1, C3, WHOLE_NOTE);
    enqueueNote(2, E3, WHOLE_NOTE);
    enqueueNote(3, G3, WHOLE_NOTE);
}

void d_minor_chord(void)
{
    printf("Playing D minor chord...\n");
    enqueueNote(1, D3, WHOLE_NOTE);
    enqueueNote(2, F3, WHOLE_NOTE);
    enqueueNote(3, A3, WHOLE_NOTE);
}

void d_major_chord(void)
{
    printf("Playing D major chord...\n");
    enqueueNote(1, D3, WHOLE_NOTE);
    enqueueNote(2, Fs3, WHOLE_NOTE);
    enqueueNote(3, A3, WHOLE_NOTE);
}

void e_minor_chord(void)
{
    printf("Playing E minor chord...\n");
    enqueueNote(1, E3, WHOLE_NOTE);
    enqueueNote(2, G3, WHOLE_NOTE);
    enqueueNote(3, B3, WHOLE_NOTE);
}

void e_major_chord(void)
{
    printf("Playing E major chord...\n");
    enqueueNote(1, E3, WHOLE_NOTE);
    enqueueNote(2, Gs3, WHOLE_NOTE);
    enqueueNote(3, B3, WHOLE_NOTE);
}

void f_major_chord(void)
{
    printf("Playing F major chord...\n");
    enqueueNote(1, F3, WHOLE_NOTE);
    enqueueNote(2, A3, WHOLE_NOTE);
    enqueueNote(3, C4, WHOLE_NOTE);
}

void g_major_chord(void)
{
    printf("Playing G major chord...\n");
    enqueueNote(1, G3, WHOLE_NOTE);
    enqueueNote(2, B3, WHOLE_NOTE);
    enqueueNote(3, D4, WHOLE_NOTE);
}

void a_minor_chord(void)
{
    printf("Playing A minor chord...\n");
    enqueueNote(1, A3, WHOLE_NOTE);
    enqueueNote(2, C4, WHOLE_NOTE);
    enqueueNote(3, E4, WHOLE_NOTE);
}

void a_major_chord(void)
{
    printf("Playing A major chord...\n");
    enqueueNote(1, A3, WHOLE_NOTE);
    enqueueNote(2, Cs4, WHOLE_NOTE);
    enqueueNote(3, E4, WHOLE_NOTE);
}

void b_diminished_chord(void)
{
    printf("Playing B diminished chord...\n");
    enqueueNote(1, B3, WHOLE_NOTE);
    enqueueNote(2, D4, WHOLE_NOTE);
    enqueueNote(3, F4, WHOLE_NOTE);
}