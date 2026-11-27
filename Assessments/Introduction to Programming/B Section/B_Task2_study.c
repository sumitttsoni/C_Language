#include <stdio.h>
#include <stdlib.h>

void clearInput(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

float readHours(void)
{
    float h;
    int ok;

    while (1) {
        ok = scanf("%f", &h);
        if (ok == EOF)
            exit(1);
        clearInput();
        if (ok == 1 && h >= 0 && h <= 24)
            return h;
        printf("Invalid. Enter hours from 0 to 24: ");
    }
}

int main(void)
{
    float hours[7], total = 0;
    int i, j, best = 0;

    for (i = 0; i < 7; i++) {
        printf("Hours studied on Day %d: ", i + 1);
        hours[i] = readHours();
        total = total + hours[i];
        if (hours[i] > hours[best])
            best = i;
    }

    printf("\nWeekly total : %.2f\n", total);
    printf("Daily average: %.2f\n", total / 7);
    printf("Highest day  : Day %d (%.2f hours)\n\n", best + 1, hours[best]);

    for (i = 0; i < 7; i++) {
        printf("Day %d: ", i + 1);
        for (j = 0; j < (int)hours[i]; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
