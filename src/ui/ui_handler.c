#include "ui_handler.h"
#include <stdio.h>

//Definition of format of piano (with, how many keys,...)
#define NUMBER_WHITE 7          //Number of white keys in a full octave
#define W_WHITE 6               //Width of white keys in signs
#define W_BLACK 4               //Width of black keys in signs
#define H_BLACK 4               //Hight of black keys in signs
#define H_WHITE 8               //Hight of white keys in signs
#define WIDTH_T (NUMBER_WHITE*W_WHITE)       //total width in signs

void ui() {
    //names of white keys in a octave
    char name[NUMBER_WHITE] = { 'C', 'D', 'E', 'F', 'G', 'A', 'B' };
    //q: is there a black key after a white key
    int white_black[NUMBER_WHITE] = { 1,1,0,1,1,1,0 };
    //2D-Array for canvas
    char bild[H_WHITE][WIDTH_T + 1];

    //1. fill canvas with empty space
    for (int y = 0; y < H_WHITE; y++) {
        for (int x = 0; x < WIDTH_T; x++) {
            bild[y][x] = ' ';
        }
        bild[y][WIDTH_T] = '\0'; // end of string for each row, otherwise printf("%s") reads garbage
    }

    //2. vertikal line in between white keys
    for (int i = 0; i < NUMBER_WHITE; i++) {
        int x = i * W_WHITE; // left end of ith white key
        for (int y = 0; y < H_WHITE; y++) {
            bild[y][x] = '|';
        }
    }
    // right end of last key (B)
    for (int y = 0; y < H_WHITE; y++) {
        bild[y][WIDTH_T - 1] = '|';
    }

    // 3.bottom of key
    for (int x = 0; x < WIDTH_T; x++) {
        bild[H_WHITE - 1][x] = '_';
    }

    // names of keys
    for (int i = 0; i < NUMBER_WHITE; i++) {
        int mitte = i * W_WHITE + W_WHITE / 2;
        bild[H_WHITE - 2][mitte] = name[i];
    }

    // 5. black keys
    for (int i = 0; i < NUMBER_WHITE; i++) {
        if (white_black[i]) {
            // position of the line between key i and i+1
            int grenze = (i + 1) * W_WHITE;
            // black key in the middle of line
            int start = grenze - W_WHITE / 2;

            for (int y = 0; y < H_BLACK; y++) {
                for (int x = 0; x < W_BLACK; x++) {
                    bild[y][start + x] = '#';
                }
            }
        }
    }

    // top end
    for (int x = 0; x < WIDTH_T; x++) printf("_");
    printf("\n");

    for (int y = 0; y < H_WHITE; y++) {
        printf("%s\n", bild[y]);
    }
}