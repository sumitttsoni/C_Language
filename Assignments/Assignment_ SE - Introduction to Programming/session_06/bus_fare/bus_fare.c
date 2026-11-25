#include <stdio.h>

int main()
{
    int choice;
    int stop, fare;
    int passengers, total = 0;
    int tickets, i, ticket_fare, collection, highest;

    do
    {
        printf("\n===== BUS FARE MENU =====\n");
        printf("1. Fare chart\n");
        printf("2. Count passengers\n");
        printf("3. Exit\n");
        printf("4. Daily collection\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nStops\tFare\n");
                for (stop = 1; stop <= 20; stop++)
                {
                    fare = 10 + (stop - 1) * 4;
                    printf("%d\t%d\n", stop, fare);
                }
                break;

            case 2:
                total = 0;
                printf("\nEnter the number of passengers (0 to stop): ");
                scanf("%d", &passengers);
                while (passengers != 0)
                {
                    total = total + passengers;
                    printf("Enter the number of passengers (0 to stop): ");
                    scanf("%d", &passengers);
                }
                printf("Total passengers: %d\n", total);
                break;

            case 3:
                printf("\nThank you, goodbye!\n");
                break;

            case 4:
                collection = 0;
                highest = 0;
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
                break;

            default:
                printf("\nTry again\n");
        }
    } while (choice != 3);

    return 0;
}