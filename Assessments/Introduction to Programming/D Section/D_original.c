#include <stdio.h>

int main(void)
{
    int a[10], i, j, temp, min, max;
    long long sum = 0;
    double mean, toMin, toMax;

    for (i = 0; i < 10; i++) {
        printf("Enter integer %d: ", i + 1);
        if (scanf("%d", &a[i]) != 1) {
            printf("Error: invalid integer.\n");
            return 1;
        }
        sum += a[i];
    }

   
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    min = a[0];
    max = a[9];
    mean = sum / 10.0;

    printf("Maximum: %d\nMinimum: %d\nMean: %.2f\n", max, min, mean);
    printf("Sorted list: ");
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");

    toMin = mean - min;
    toMax = max - mean;
    if (toMin < toMax)
        printf("Mean is closer to the minimum.\n");
    else if (toMax < toMin)
        printf("Mean is closer to the maximum.\n");
    else
        printf("Mean is exactly midway.\n");

    return 0;
}
