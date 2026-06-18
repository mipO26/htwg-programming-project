#include <stdio.h>

int main(void) {
    double sum = 0.0;
    double note = 0.0;
    int count = 0;
    int i = 1;

    printf("Durchschnittsnote\n");

    while (1) {
        printf("Bitte %d. Note eingeben: ", i);
        scanf("%lf", &note);
        if (note == 0.0) break;      
        sum += note;
        count++;
        i++;
    }

    if (note == 0) {
        double durchschnitt = sum / count;
        printf("Die Durchschnittsnote ist %.1f\n", durchschnitt);
    }

    return 0;
}