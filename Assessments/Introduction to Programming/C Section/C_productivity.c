#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <stdlib.h>

#define SUBJECTS 3
#define DAYS 7

struct StudyLog {
    char subject[40];
    float hours[DAYS];
};

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

void logHours(struct StudyLog logs[])
{
    int day, i;

    printf("Day number (1-7): ");
    if (scanf("%d", &day) != 1 || day < 1 || day > DAYS) {
        printf("Error: invalid day.\n");
        clearInput();
        return;
    }
    clearInput();

    for (i = 0; i < SUBJECTS; i++) {
        printf("Hours for %s: ", logs[i].subject);
        logs[i].hours[day - 1] = readHours();
    }
    printf("Saved for Day %d.\n", day);
}

void showTotals(struct StudyLog logs[])
{
    int i, d;
    float total;

    printf("\n%-20s %8s %8s\n", "Subject", "Total", "Average");
    for (i = 0; i < SUBJECTS; i++) {
        total = 0;
        for (d = 0; d < DAYS; d++)
            total += logs[i].hours[d];
        printf("%-20s %8.2f %8.2f\n", logs[i].subject, total, total / DAYS);
    }
}

void showChart(struct StudyLog logs[])
{
    int i, d, h;

    for (i = 0; i < SUBJECTS; i++) {
        printf("\n%s\n", logs[i].subject);
        for (d = 0; d < DAYS; d++) {
            printf("  Day %d: ", d + 1);
            for (h = 0; h < (int)logs[i].hours[d]; h++)
                printf("\xE2\x80\xA2");
            printf("\n");
        }
    }
}

void saveLogs(struct StudyLog logs[])
{
    int i, d;
    FILE *fp = fopen("productivity_log.txt", "w");

    if (fp == NULL) {
        printf("Error: cannot open file.\n");
        return;
    }
    for (i = 0; i < SUBJECTS; i++) {
        fprintf(fp, "%s", logs[i].subject);
        for (d = 0; d < DAYS; d++)
            fprintf(fp, ",%.2f", logs[i].hours[d]);
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Saved to productivity_log.txt\n");
}

int main(void)
{
    struct StudyLog logs[SUBJECTS] = {
        {"C Programming", {0}},
        {"HTML and CSS", {0}},
        {"SQL", {0}}
    };
    int choice;
#ifdef _WIN32
    SetConsoleOutputCP(65001);   
#endif
    do {
        printf("\n1. Log Today's Study Hours\n2. View Weekly Report\n3. Save & Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            choice = feof(stdin) ? 3 : 0;
        }
        clearInput();

        if (choice == 1) {
            logHours(logs);
        } else if (choice == 2) {
            showTotals(logs);
            showChart(logs);
        } else if (choice == 3) {
            saveLogs(logs);
        } else {
            printf("Invalid choice.\n");
        }
    } while (choice != 3);

    return 0;
}
