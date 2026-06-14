#pragma once
#include <stdint.h>

typedef enum {
    C3,  Cs3, D3,  Ds3, E3,  F3,  Fs3, G3,  Gs3, A3,  As3, B3,
    C4,  Cs4, D4,  Ds4, E4,  F4,  Fs4, G4,  Gs4, A4,  As4, B4,
    C5,  Cs5, D5,  Ds5, E5,  F5,  Fs5, G5,  Gs5, A5,  As5, B5,
    PAUSE, NOTE_COUNT
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
