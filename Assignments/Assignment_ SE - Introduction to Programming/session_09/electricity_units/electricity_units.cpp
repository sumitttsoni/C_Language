#include <stdio.h>

#define MONTHS 12
#define HOUSES 3
#define LIMIT 300

int main(void)
{
    int units[MONTHS] = {120, 135, 180, 260, 340, 410,
                         390, 360, 310, 240, 170, 130};
    int society[HOUSES][MONTHS] = {
        {110, 125, 170, 230, 320, 380, 350, 330, 290, 220, 160, 115},
        { 95, 105, 140, 210, 280, 345, 330, 300, 260, 190, 130, 100},
        {150, 165, 220, 300, 390, 450, 420, 395, 350, 270, 200, 160}
    };
    int i, row, col;

    /* Task 1: monthly readings, yearly total and average */
    int total = 0;

    printf("Monthly readings\n");
    for (i = 0; i < MONTHS; i++) {
        printf("Month %d: %d units\n", i + 1, units[i]);
        total += units[i];
    }
    printf("Yearly total: %d units\n", total);
    printf("Average: %.2f units\n", (float)total / MONTHS);

    /* Task 2: highest, lowest and count above 300 in one loop */
    int high = 0;   /* index of highest, starts at first element */
    int low = 0;    /* index of lowest, starts at first element */
    int crossed = 0;

    for (i = 0; i < MONTHS; i++) {
        if (units[i] > units[high])
            high = i;
        if (units[i] < units[low])
            low = i;
        if (units[i] > LIMIT)
            crossed++;
    }
    printf("\nHighest: Month %d with %d units\n", high + 1, units[high]);
    printf("Lowest: Month %d with %d units\n", low + 1, units[low]);
    printf("Months above %d units: %d\n", LIMIT, crossed);

    /* Task 3: society table with a total for each household */
    printf("\nSociety readings\n");
    printf("House  ");
    for (col = 0; col < MONTHS; col++)
        printf("  M%-3d", col + 1);
    printf(" Total\n");

    for (row = 0; row < HOUSES; row++) {
        int rowTotal = 0;

        printf("%-7d", row + 1);
        for (col = 0; col < MONTHS; col++) {
            printf("%5d ", society[row][col]);
            rowTotal += society[row][col];
        }
        printf("%6d\n", rowTotal);
    }

    /* Task 4: society total for each month and the highest month
     * Hand check:
     * Month 1: 110 + 95 + 150 = 355
     * Month 6: 380 + 345 + 450 = 1175
     */
    int topMonth = 0;
    int topTotal = 0;

    printf("\nSociety total for each month\n");
    for (col = 0; col < MONTHS; col++) {
        int colTotal = 0;

        for (row = 0; row < HOUSES; row++)
            colTotal += society[row][col];

        printf("Month %d: %d units\n", col + 1, colTotal);

        if (col == 0 || colTotal > topTotal) {
            topTotal = colTotal;
            topMonth = col;
        }
    }
    printf("Highest society usage: Month %d with %d units\n",
           topMonth + 1, topTotal);

    return 0;
}