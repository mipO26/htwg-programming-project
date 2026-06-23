#include "ui_active.h"
#include <stdio.h>
#include <string.h>

//Definition of format of piano (with, how many keys,...)
#define NUMBER_WHITE 7          //Number of white keys in a full octave
#define W_WHITE 6               //Width of white keys in signs
#define W_BLACK 4               //Width of black keys in signs
#define H_BLACK 4               //Hight of black keys in signs
#define H_WHITE 8               //Hight of white keys in signs
#define WIDTH_T (NUMBER_WHITE*W_WHITE)       //total width in signs

//how many octaves we display (C3-B5 = 3 octaves)
#define NUMBER_OCTAVES 3
#define WIDTH_TOTAL (WIDTH_T * NUMBER_OCTAVES) //total width over all octaves


//---------------------------------------------------------------
// TODO DESCRIPTION
//---------------------------------------------------------------
static int active_notes[88] = {0};

void setNoteDisplayActive(Note note)
{
    active_notes[note] = 1;
}

void setNoteDisplayInactive(Note note)
{
    active_notes[note] = 0;
}

void deactivateDisplayAllNotes()
{
    for (int i = 0; i < NOTE_COUNT; i++)
    {
        active_notes[i] = 0;
    }
}

//---------------------------------------------------------------
// note_vis: maps a Note enum value to (octave, key index, is_black)
// so the drawing code knows WHERE on the canvas to highlight.
//---------------------------------------------------------------

// is there a black key after the i-th white key in an octave?
// (no black key between E-F and B-C)
static const int white_black[NUMBER_WHITE] = { 1,1,0,1,1,1,0 };

// names of white keys in an octave, in order
static const char name[NUMBER_WHITE] = { 'C', 'D', 'E', 'F', 'G', 'A', 'B' };

// helper struct to describe where a Note sits on the keyboard
typedef struct {
    int octave;     // 0 = lowest octave shown (C3), 1 = C4, 2 = C5
    int white_idx;  // index of the white key (0=C ... 6=B) this note belongs/is closest to
    int is_black;   // 1 if this note is a black key, 0 if white
} KeyPos;

// translate a Note enum value into a KeyPos
// notes are laid out in blocks of 12 per octave: C, Cs, D, Ds, E, F, Fs, G, Gs, A, As, B
static KeyPos note_to_keypos(Note note) {
    KeyPos pos;
    int n = (int)note;          // raw enum value, 0 = C3, 1 = Cs3, ... 35 = B5
    n -= 27;
    pos.octave = n / 12;        // which of the 3 octaves
    int in_oct = n % 12;        // position within the octave (0-11)

    // lookup table: position within octave -> (white_idx, is_black)
    static const int white_idx_table[12] = { 0,0,1,1,2,3,3,4,4,5,5,6 };
    static const int is_black_table[12] = { 0,1,0,1,0,0,1,0,1,0,1,0 };

    pos.white_idx = white_idx_table[in_oct];
    pos.is_black = is_black_table[in_oct];
    return pos;
}

//---------------------------------------------------------------
// ui: draws the full keyboard (3 octaves) with no key highlighted.
// kept your original drawing logic, just looped over NUMBER_OCTAVES.
//---------------------------------------------------------------

//---------------------------------------------------------------
// note_vis: draws the full keyboard and highlights the key
// that corresponds to "note". Pass NOTE_COUNT (or any invalid
// Note) to draw the keyboard with nothing highlighted.
//---------------------------------------------------------------

// TODO - fix the comments here
void highlight_note(Note note, char bild[][WIDTH_TOTAL + 1])
{
    KeyPos pos = note_to_keypos(note);

    if (pos.is_black) {
        // overwrite the black key block with a highlight char
        int grenze = pos.octave * WIDTH_T + (pos.white_idx + 1) * W_WHITE;
        int start = grenze - W_WHITE / 2;
        for (int y = 0; y < H_BLACK; y++) {
            for (int x = 0; x < W_BLACK; x++) {
                bild[y][start + x] = '*'; // highlighted black key
            }
        }
    }
    else {
        // overwrite the white key body (between its borders) with a highlight char
        int x_start = pos.octave * WIDTH_T + pos.white_idx * W_WHITE + 1;
        int x_end = pos.octave * WIDTH_T + pos.white_idx * W_WHITE + W_WHITE - 1;
        for (int y = 0; y < H_WHITE - 1; y++) { // not the bottom border row
            for (int x = x_start; x < x_end; x++) {
                if (bild[y][x] == ' ') {
                    bild[y][x] = '*'; // highlighted white key area
                }
            }
        }
        // re-draw the note name on top so it stays readable
        int mitte = pos.octave * WIDTH_T + pos.white_idx * W_WHITE + W_WHITE / 2;
        bild[H_WHITE - 2][mitte] = name[pos.white_idx];
        bild[H_WHITE - 2][mitte + 1] = (char)('0' + (3 + pos.octave));
    }
}

void renderUi() {
    //2D-Array for canvas (now spans all octaves)
    char bild[H_WHITE][WIDTH_TOTAL + 1];

    //1. fill canvas with empty space
    for (int y = 0; y < H_WHITE; y++) {
        for (int x = 0; x < WIDTH_TOTAL; x++) {
            bild[y][x] = ' ';
        }
        bild[y][WIDTH_TOTAL] = '\0'; // end of string for each row, otherwise printf("%s") reads garbage
    }

    //2. vertikal line in between white keys (over all octaves)
    for (int o = 0; o < NUMBER_OCTAVES; o++) {
        for (int i = 0; i < NUMBER_WHITE; i++) {
            int x = o * WIDTH_T + i * W_WHITE; // left end of ith white key in octave o
            for (int y = 0; y < H_WHITE; y++) {
                bild[y][x] = '|';
            }
        }
    }
    // right end of last key (B5)
    for (int y = 0; y < H_WHITE; y++) {
        bild[y][WIDTH_TOTAL - 1] = '|';
    }

    // 3.bottom of key
    for (int x = 0; x < WIDTH_TOTAL; x++) {
        bild[H_WHITE - 1][x] = '_';
    }

    // names of keys (now with octave number, e.g. C3, D3, ... B5)
    for (int o = 0; o < NUMBER_OCTAVES; o++) {
        for (int i = 0; i < NUMBER_WHITE; i++) {
            int mitte = o * WIDTH_T + i * W_WHITE + W_WHITE / 2;
            bild[H_WHITE - 2][mitte] = name[i];
            // octave number goes one column to the right of the note letter
            bild[H_WHITE - 2][mitte + 1] = (char)('0' + (3 + o)); // 3,4,5
        }
    }

    // 5. black keys
    for (int o = 0; o < NUMBER_OCTAVES; o++) {
        for (int i = 0; i < NUMBER_WHITE; i++) {
            if (white_black[i]) {
                // position of the line between key i and i+1
                int grenze = o * WIDTH_T + (i + 1) * W_WHITE;
                // black key in the middle of line
                int start = grenze - W_WHITE / 2;

                for (int y = 0; y < H_BLACK; y++) {
                    for (int x = 0; x < W_BLACK; x++) {
                        bild[y][start + x] = '#';
                    }
                }
            }
        }
    }

    for (Note n = C3; n <= B5;n++)
    {
        if (active_notes[n])
        {
            highlight_note(n, bild);
        }
    }

    // top end
    for (int i = 0; i < 100; i++)
    {
        printf("\n");
    }
    for (int x = 0; x < WIDTH_TOTAL; x++) printf("_");
    printf("\n");

    for (int y = 0; y < H_WHITE; y++) {
        printf("%s\n", bild[y]);
    }
}