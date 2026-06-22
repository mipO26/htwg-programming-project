#include "keyboard.h"
#include "audio/audio.h"
#include "audio/notes.h"

void keyboard(void)
{
    char bassInput1;
    char bassInput2;
    char bassInput3;
    char bassNote1[4]; //bottom note
    char bassNote2[4]; //middle note
    char bassNote3[4]; //high note
    char yesNo ; //yes or no

    printf("Enter your bass chord\n");
    do {
        printf("Enter bottom note = ");
        scanf(" %c", &bassInput1);
        printf("Enter middle note = ");
        scanf(" %c", &bassInput2);
        printf("Enter top note = ");
        scanf(" %c", &bassInput3);

        switch (bassInput1) {
        case 'q': playNote(C4, WHOLE_NOTE); break;
        case 'w': playNote(Cs4, WHOLE_NOTE); break;
        case 'e': playNote(D4, WHOLE_NOTE); break;
        case 'r': playNote(Ds4, WHOLE_NOTE); break;
        case 't': playNote(E4, WHOLE_NOTE); break;
        case 'y': playNote(F4, WHOLE_NOTE); break;
        case 'u': playNote(Fs4, WHOLE_NOTE); break;
        case 'i': playNote(G4, WHOLE_NOTE); break;
        case 'o': playNote(Gs4, WHOLE_NOTE); break;
        case 'p': playNote(A4, WHOLE_NOTE); break;
        case 'a': playNote(As4, WHOLE_NOTE); break;
        case 's': playNote(B4, WHOLE_NOTE); break;
        case 'd': playNote(C5, WHOLE_NOTE); break;
        case 'f': playNote(Cs5, WHOLE_NOTE); break;
        case 'g': playNote(D5, WHOLE_NOTE); break;
        case 'h': playNote(Ds5, WHOLE_NOTE); break;
        case 'j': playNote(E5, WHOLE_NOTE); break;
        case 'k': playNote(F5, WHOLE_NOTE); break;
        case 'l': playNote(Fs5, WHOLE_NOTE); break;
        case 'z': playNote(G5, WHOLE_NOTE); break;
        default: playNote(C3, WHOLE_NOTE); break;
        }

        switch (bassInput2) {
        case 'q': playNote(C4, WHOLE_NOTE); break;
        case 'w': playNote(Cs4, WHOLE_NOTE); break;
        case 'e': playNote(D4, WHOLE_NOTE); break;
        case 'r': playNote(Ds4, WHOLE_NOTE); break;
        case 't': playNote(E4, WHOLE_NOTE); break;
        case 'y': playNote(F4, WHOLE_NOTE); break;
        case 'u': playNote(Fs4, WHOLE_NOTE); break;
        case 'i': playNote(G4, WHOLE_NOTE); break;
        case 'o': playNote(Gs4, WHOLE_NOTE); break;
        case 'p': playNote(A4, WHOLE_NOTE); break;
        case 'a': playNote(As4, WHOLE_NOTE); break;
        case 's': playNote(B4, WHOLE_NOTE); break;
        case 'd': playNote(C5, WHOLE_NOTE); break;
        case 'f': playNote(Cs5, WHOLE_NOTE); break;
        case 'g': playNote(D5, WHOLE_NOTE); break;
        case 'h': playNote(Ds5, WHOLE_NOTE); break;
        case 'j': playNote(E5, WHOLE_NOTE); break;
        case 'k': playNote(F5, WHOLE_NOTE); break;
        case 'l': playNote(Fs5, WHOLE_NOTE); break;
        case 'z': playNote(G5, WHOLE_NOTE); break;
        default: playNote(C3, WHOLE_NOTE); break;
        }

        switch (bassInput3) {
       case 'q': playNote(C4, WHOLE_NOTE); break;
        case 'w': playNote(Cs4, WHOLE_NOTE); break;
        case 'e': playNote(D4, WHOLE_NOTE); break;
        case 'r': playNote(Ds4, WHOLE_NOTE); break;
        case 't': playNote(E4, WHOLE_NOTE); break;
        case 'y': playNote(F4, WHOLE_NOTE); break;
        case 'u': playNote(Fs4, WHOLE_NOTE); break;
        case 'i': playNote(G4, WHOLE_NOTE); break;
        case 'o': playNote(Gs4, WHOLE_NOTE); break;
        case 'p': playNote(A4, WHOLE_NOTE); break;
        case 'a': playNote(As4, WHOLE_NOTE); break;
        case 's': playNote(B4, WHOLE_NOTE); break;
        case 'd': playNote(C5, WHOLE_NOTE); break;
        case 'f': playNote(Cs5, WHOLE_NOTE); break;
        case 'g': playNote(D5, WHOLE_NOTE); break;
        case 'h': playNote(Ds5, WHOLE_NOTE); break;
        case 'j': playNote(E5, WHOLE_NOTE); break;
        case 'k': playNote(F5, WHOLE_NOTE); break;
        case 'l': playNote(Fs5, WHOLE_NOTE); break;
        case 'z': playNote(G5, WHOLE_NOTE); break;
        default: playNote(C3, WHOLE_NOTE); break;
        }

        if (bassInput1==bassInput2 || bassInput1==bassInput3 || bassInput2==bassInput3) {
            printf("You have entered duplicate notes. Please enter different notes.\n");
            char yesNo = 'n';
        } else if (bassInput1 == bassInput2 && bassInput2 == bassInput3) {
            printf("You have entered the same notes three times.\n");
            char yesNo = 'n';
        } else if (bassInput1 != bassInput2 != bassInput3) {
            printf("Are you certain with your selection of notes? y/n: %s, %s, %s ", bassNote1, bassNote2, bassNote3);
        scanf(" %c", &yesNo);
        }
    } while (yesNo != 'y'); //        cmake --build build && ./build/Musicify         to run program

    while (yesNo != 'n') {
        playNoteMs(bassInput1, UINT32_MAX);
        playNoteMs(bassInput2, UINT32_MAX);
        playNoteMs(bassInput3, UINT32_MAX);
    }
}