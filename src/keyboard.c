#include "keyboard.h"
#include "audio/audio.h"
#include "audio/notes.h"
#include "ui/ui_active.h"

void flushInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void getUserInputChar(char *input) {
    // flushInputBuffer(); // Clear the input buffer
    scanf(" %c", input);
}

void keyboard(void)
{
    char bassInput1;
    char bassInput2;
    char bassInput3;
    Note bassNote1; //bottom note
    Note bassNote2; //middle note
    Note bassNote3; //high note
    char yesNo = 'n' ; //yes or no

    printf("Enter your bass chord\n");
    printf("Use the following keys to select your notes:\n");
    do {
        printf("\nEnter bottom note = ");
        getUserInputChar(&bassInput1);
        switch (bassInput1) {
            case 'q': bassNote1 = C4; break;
            case 'w': bassNote1 = Cs4; break;
            case 'e': bassNote1 = D4; break;
            case 'r': bassNote1 = Ds4; break;
            case 't': bassNote1 = E4; break;
            case 'y': bassNote1 = F4; break;
            case 'u': bassNote1 = Fs4; break;
            case 'i': bassNote1 = G4; break;
            case 'o': bassNote1 = Gs4; break;
            case 'p': bassNote1 = A4; break;
            case 'a': bassNote1 = As4; break;
            case 's': bassNote1 = B4; break;
            case 'd': bassNote1 = C5; break;
            case 'f': bassNote1 = Cs5; break;
            case 'g': bassNote1 = D5; break;
            case 'h': bassNote1 = Ds5; break;
            case 'j': bassNote1 = E5; break;
            case 'k': bassNote1 = F5; break;
            case 'l': bassNote1 = Fs5; break;
            case 'z': bassNote1 = G5; break;
            default: printf("You have entered an invalid note. Please re-enter.\n"); continue; break;
        }

        setNoteDisplayActive(bassNote1);
        renderUi();
        

        printf("\nEnter middle note = ");
        getUserInputChar(&bassInput2);

        switch (bassInput2) {
            case 'q': bassNote2 = C4; break;
            case 'w': bassNote2 = Cs4; break;
            case 'e': bassNote2 = D4; break;
            case 'r': bassNote2 = Ds4; break;
            case 't': bassNote2 = E4; break;
            case 'y': bassNote2 = F4; break;
            case 'u': bassNote2 = Fs4; break;
            case 'i': bassNote2 = G4; break;
            case 'o': bassNote2 = Gs4; break;
            case 'p': bassNote2 = A4; break;
            case 'a': bassNote2 = As4; break;
            case 's': bassNote2 = B4; break;
            case 'd': bassNote2 = C5; break;
            case 'f': bassNote2 = Cs5; break;
            case 'g': bassNote2 = D5; break;
            case 'h': bassNote2 = Ds5; break;
            case 'j': bassNote2 = E5; break;
            case 'k': bassNote2 = F5; break;
            case 'l': bassNote2 = Fs5; break;
            case 'z': bassNote2 = G5; break;
            default: printf("You have entered an invalid note. Please re-enter.\n"); continue; break;
        }
        setNoteDisplayActive(bassNote2);
        renderUi();

        printf("\nEnter top note = ");
        getUserInputChar(&bassInput3);
        switch (bassInput3) {
            case 'q': bassNote3 = C4; break;
            case 'w': bassNote3 = Cs4; break;
            case 'e': bassNote3 = D4; break;
            case 'r': bassNote3 = Ds4; break;
            case 't': bassNote3 = E4; break;
            case 'y': bassNote3 = F4; break;
            case 'u': bassNote3 = Fs4; break;
            case 'i': bassNote3 = G4; break;
            case 'o': bassNote3 = Gs4; break;
            case 'p': bassNote3 = A4; break;
            case 'a': bassNote3 = As4; break;
            case 's': bassNote3 = B4; break;
            case 'd': bassNote3 = C5; break;
            case 'f': bassNote3 = Cs5; break;
            case 'g': bassNote3 = D5; break;
            case 'h': bassNote3 = Ds5; break;
            case 'j': bassNote3 = E5; break;
            case 'k': bassNote3 = F5; break;
            case 'l': bassNote3 = Fs5; break;
            case 'z': bassNote3 = G5; break;
            default: printf("You have entered an invalid note. Please re-enter.\n"); continue; break;
        }
        setNoteDisplayActive(bassNote3);
        renderUi();
        if (bassInput1 == bassInput2 && bassInput2 == bassInput3) {
            printf("You have entered the same notes three times.\n");
            deactivateDisplayAllNotes();
            yesNo = 'n';
        } else if (bassInput1 == bassInput2 || bassInput1 == bassInput3 || bassInput2 == bassInput3){
            printf("You have entered duplicate notes. Please enter different notes.\n");
            deactivateDisplayAllNotes();
            yesNo = 'n';
        } else if (bassInput1 != bassInput2 && bassInput2 != bassInput3 && bassInput1 != bassInput3) {
            printf("Are you certain with your selection of notes: %s, %s, %s", note_names[bassNote1], note_names[bassNote2], note_names[bassNote3]);
            printf("\npress y/n to confirm or change your selection: ");
            deactivateDisplayAllNotes();
            getUserInputChar(&yesNo);
        }

    } while (yesNo != 'y'); //        cmake --build build && ./build/Musicify         to run program

    playNoteMs(bassNote1, 5 * 1000);
    playNoteMs(bassNote2, 5 * 1000);
    playNoteMs(bassNote3, 5 * 1000);
}