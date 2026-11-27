#include <stdio.h>

int main(void)
{
    float score;

    printf("Enter percentage score (0-100): ");

    if (scanf("%f", &score) != 1) {
        printf("Error: please enter a number.\n");
        return 1;
    }

    if (!(score >= 0 && score <= 100)) {
        printf("Error: score must be between 0 and 100.\n");
        return 1;
    }

    if (score >= 90)
        printf("A - Excellent! Outstanding performance.\n");
    else if (score >= 75)
        printf("B - Good work! Keep pushing.\n");
    else if (score >= 60)
        printf("C - Nice effort! You can do even better.\n");
    else if (score >= 45)
        printf("D - You passed. Practise more.\n");
    else
        printf("F - Do not give up. Try again!\n");

    return 0;
}
