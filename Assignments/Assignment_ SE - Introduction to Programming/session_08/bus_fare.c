#include <stdio.h>

/* Prototypes (declarations) above main */
int fare_for(int stops);
void show_fare_chart(void);
void count_passengers(void);
void daily_collection(void);
void show_seat_map(void);
void show_fare_ladder(void);
void print_ticket_border(void);
void print_discounted(int fare);
int highest_of_three(int a, int b, int c);

int main()
{
    int choice;
    int fare = 86;               /* main's own fare, used in the discount demo */
    int a, b, c;

    do
    {
        printf("\n===== BUS FARE MENU =====\n");
        printf("1. Fare chart\n");
        printf("2. Count passengers\n");
        printf("3. Exit\n");
        printf("4. Daily collection\n");
        printf("5. Seat map\n");
        printf("6. Fare ladder\n");
        printf("7. Ticket border\n");
        printf("8. Highest of three fares\n");
        printf("9. Discount demo\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                show_fare_chart();
                break;
            case 2:
                count_passengers();
                break;
            case 3:
                printf("\nThank you, goodbye!\n");
                break;
            case 4:
                daily_collection();
                break;
            case 5:
                show_seat_map();
                break;
            case 6:
                show_fare_ladder();
                break;
            case 7:
                print_ticket_border();
                break;
            case 8:
                printf("\nEnter three fares: ");
                scanf("%d %d %d", &a, &b, &c);
                printf("Highest fare: %d\n", highest_of_three(a, b, c));
                break;
            case 9:
                print_discounted(fare);                       /* function gets a COPY */
                printf("Main's fare is still: %d\n", fare);   /* main's variable unchanged */
                break;
            default:
                printf("\nTry again\n");
        }
    } while (choice != 3);

    return 0;
}

/* Definitions below main */

/* Task 1: Rs.10 for the first stop plus Rs.4 for every extra stop */
int fare_for(int stops)
{
    return 10 + (stops - 1) * 4;
}

void show_fare_chart(void)
{
    int stop;

    printf("\nStops\tFare\n");
    for (stop = 1; stop <= 20; stop++)
    {
        printf("%d\t%d\n", stop, fare_for(stop));
    }
}

void count_passengers(void)
{
    int passengers;
    int total = 0;

    printf("\nEnter the number of passengers (0 to stop): ");
    scanf("%d", &passengers);
    while (passengers != 0)
    {
        total = total + passengers;
        printf("Enter the number of passengers (0 to stop): ");
        scanf("%d", &passengers);
    }
    printf("Total passengers: %d\n", total);
}

void daily_collection(void)
{
    int tickets, i, ticket_fare;
    int collection = 0;
    int highest = 0;

    printf("\nHow many tickets were sold? ");
    scanf("%d", &tickets);
    for (i = 1; i <= tickets; i++)
    {
        printf("Enter fare of ticket %d: ", i);
        scanf("%d", &ticket_fare);
        collection = collection + ticket_fare;
        if (ticket_fare > highest)
        {
            highest = ticket_fare;
        }
    }
    printf("Total collection: %d\n", collection);
    printf("Highest fare: %d\n", highest);
}

void show_seat_map(void)
{
    int row, col;
    char seat;

    printf("\nSEAT MAP (XX = booked)\n");
    for (row = 1; row <= 10; row++)
    {
        for (col = 1; col <= 4; col++)
        {
            seat = 'A' + col - 1;

            if ((row == 1 && col == 2) ||      /* 1B  */
                (row == 3 && col == 3) ||      /* 3C  */
                (row == 5 && col == 1) ||      /* 5A  */
                (row == 10 && col == 4))       /* 10D */
            {
                printf(" XX ");
            }
            else
            {
                printf("%2d%c ", row, seat);
            }

            if (col == 2)
            {
                printf("   ");
            }
        }
        printf("\n");
    }
}

void show_fare_ladder(void)
{
    int row, stops_in_row;

    printf("\nFARE LADDER\n");
    for (row = 1; row <= 6; row++)
    {
        for (stops_in_row = 1; stops_in_row <= row; stops_in_row++)
        {
            printf("%d\t", fare_for(stops_in_row));
        }
        printf("\n");
    }
}

void print_ticket_border(void)
{
    int row, col;

    printf("\n");
    for (row = 1; row <= 5; row++)
    {
        for (col = 1; col <= 24; col++)
        {
            if (row == 1 || row == 5 || col == 1 || col == 24)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* Task 3: pass by value. fare here is only a copy of main's value. */
void print_discounted(int fare)
{
    fare = fare * 75 / 100;      /* whole-number maths: 86 * 75 / 100 = 64 */
    printf("\nDiscounted fare (75%%): %d\n", fare);
}

/* Task 4: a function ends at the first return it reaches */
int highest_of_three(int a, int b, int c)
{
    if (a >= b && a >= c)
    {
        return a;
    }
    if (b >= c)
    {
        return b;
    }
    return c;
}