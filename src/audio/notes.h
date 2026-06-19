#pragma once
#include <stdint.h>

typedef enum {
    A0,  As0, B0,
    C1,  Cs1, D1,  Ds1, E1,  F1,  Fs1, G1,  Gs1, A1,  As1, B1,
    C2,  Cs2, D2,  Ds2, E2,  F2,  Fs2, G2,  Gs2, A2,  As2, B2,
    C3,  Cs3, D3,  Ds3, E3,  F3,  Fs3, G3,  Gs3, A3,  As3, B3,
    C4,  Cs4, D4,  Ds4, E4,  F4,  Fs4, G4,  Gs4, A4,  As4, B4,
    C5,  Cs5, D5,  Ds5, E5,  F5,  Fs5, G5,  Gs5, A5,  As5, B5,
    C6,  Cs6, D6,  Ds6, E6,  F6,  Fs6, G6,  Gs6, A6,  As6, B6,
    C7,  Cs7, D7,  Ds7, E7,  F7,  Fs7, G7,  Gs7, A7,  As7, B7,
    C8,

    PAUSE,
    NOTE_COUNT

} Note;

typedef struct ScheduledNote {
    uint64_t start;
    uint64_t end;
    Note note;
    double length;
} ScheduledNote;

#define WHOLE_NOTE 4.0
#define HALF_NOTE 2.0
#define QUARTER_NOTE 1.0
#define EIGHTH_NOTE 0.5
#define SIXTEENTH_NOTE 0.25
#define THIRTY_SECOND_NOTE 0.125
#define SIXTY_FOURTH_NOTE 0.0625

#define DOTTED_HALF_NOTE      3.0
#define DOTTED_QUARTER_NOTE   1.5
#define DOTTED_EIGHTH_NOTE    0.75
#define DOTTED_SIXTEENTH_NOTE 0.375
