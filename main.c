#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define False 0

int main(void)
{
    char bassInput1;
    char bassInput2;
    char bassInput3;
    char bassNote1[4]; //bottom note
    char bassNote2[4]; //middle note
    char bassNote3[4]; //high note
    char yesNo; //yes or no

    printf("Enter your bass chord\n");
    do {
        printf("Enter bottom note = ");
        scanf(" %c", &bassInput1);
        printf("Enter middle note = ");
        scanf(" %c", &bassInput2);
        printf("Enter top note = ");
        scanf(" %c", &bassInput3);

        switch (bassInput1) {
        case 'q': strcpy(bassNote1, "c"); break;
        case 'w': strcpy(bassNote1, "c#"); break;
        case 'e': strcpy(bassNote1, "d"); break;
        case 'r': strcpy(bassNote1, "d#"); break;
        case 't': strcpy(bassNote1, "e"); break;
        case 'y': strcpy(bassNote1, "f"); break;
        case 'u': strcpy(bassNote1, "f#"); break;
        case 'i': strcpy(bassNote1, "g"); break;
        case 'o': strcpy(bassNote1, "g#"); break;
        case 'p': strcpy(bassNote1, "a"); break;
        case 'a': strcpy(bassNote1, "a#"); break;
        case 's': strcpy(bassNote1, "b"); break;
        case 'd': strcpy(bassNote1, "c^"); break;
        case 'f': strcpy(bassNote1, "c#^"); break;
        case 'g': strcpy(bassNote1, "d^"); break;
        case 'h': strcpy(bassNote1, "d#^"); break;
        case 'j': strcpy(bassNote1, "e^"); break;
        case 'k': strcpy(bassNote1, "e#^"); break;
        case 'l': strcpy(bassNote1, "f^"); break;
        case 'z': strcpy(bassNote1, "f#^"); break;
        default: strcpy(bassNote1, "?"); break;
        }

        switch (bassInput2) {
        case 'q': strcpy(bassNote2, "c"); break;
        case 'w': strcpy(bassNote2, "c#"); break;
        case 'e': strcpy(bassNote2, "d"); break;
        case 'r': strcpy(bassNote2, "d#"); break;
        case 't': strcpy(bassNote2, "e"); break;
        case 'y': strcpy(bassNote2, "f"); break;
        case 'u': strcpy(bassNote2, "f#"); break;
        case 'i': strcpy(bassNote2, "g"); break;
        case 'o': strcpy(bassNote2, "g#"); break;
        case 'p': strcpy(bassNote2, "a"); break;
        case 'a': strcpy(bassNote2, "a#"); break;
        case 's': strcpy(bassNote2, "b"); break;
        case 'd': strcpy(bassNote2, "c^"); break;
        case 'f': strcpy(bassNote2, "c#^"); break;
        case 'g': strcpy(bassNote2, "d^"); break;
        case 'h': strcpy(bassNote2, "d#^"); break;
        case 'j': strcpy(bassNote2, "e^"); break;
        case 'k': strcpy(bassNote2, "e#^"); break;
        case 'l': strcpy(bassNote2, "f^"); break;
        case 'z': strcpy(bassNote2, "f#^"); break;
        default: strcpy(bassNote2, "?"); break;
        }

        switch (bassInput3) {
        case 'q': strcpy(bassNote3, "c"); break;
        case 'w': strcpy(bassNote3, "c#"); break;
        case 'e': strcpy(bassNote3, "d"); break;
        case 'r': strcpy(bassNote3, "d#"); break;
        case 't': strcpy(bassNote3, "e"); break;
        case 'y': strcpy(bassNote3, "f"); break;
        case 'u': strcpy(bassNote3, "f#"); break;
        case 'i': strcpy(bassNote3, "g"); break;
        case 'o': strcpy(bassNote3, "g#"); break;
        case 'p': strcpy(bassNote3, "a"); break;
        case 'a': strcpy(bassNote3, "a#"); break;
        case 's': strcpy(bassNote3, "b"); break;
        case 'd': strcpy(bassNote3, "c^"); break;
        case 'f': strcpy(bassNote3, "c#^"); break;
        case 'g': strcpy(bassNote3, "d^"); break;
        case 'h': strcpy(bassNote3, "d#^"); break;
        case 'j': strcpy(bassNote3, "e^"); break;
        case 'k': strcpy(bassNote3, "e#^"); break;
        case 'l': strcpy(bassNote3, "f^"); break;
        case 'z': strcpy(bassNote3, "f#^"); break;
        default: strcpy(bassNote3, "?"); break;
        }

        printf("Are you certain with your selection of notes? y/n: %s, %s, %s ", bassNote1, bassNote2, bassNote3);
        scanf(" %c", &yesNo);
    } while (yesNo != 'y');

    return 0;
}