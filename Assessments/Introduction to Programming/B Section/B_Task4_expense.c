#include <stdio.h>

#define MAX 10

struct Expense {
    char category[30];
    float amount;
};

void clearInput(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void addExpense(struct Expense list[], int *count)
{
    struct Expense e;

    if (*count == MAX) {
        printf("List is full (10 entries).\n");
        return;
    }
    printf("Category: ");
    if (scanf(" %29[^\n]", e.category) != 1)
        return;
    clearInput();
    printf("Amount: ");
    if (scanf("%f", &e.amount) != 1 || !(e.amount > 0)) {
        printf("Error: amount must be a positive number.\n");
        clearInput();
        return;
    }
    clearInput();
    list[*count] = e;
    (*count)++;
    printf("Expense added.\n");
}

void viewExpenses(struct Expense list[], int count)
{
    int i;
    float total = 0;

    if (count == 0) {
        printf("No expenses yet.\n");
        return;
    }
    for (i = 0; i < count; i++) {
        printf("%d. %-30s %10.2f\n", i + 1, list[i].category, list[i].amount);
        total += list[i].amount;
    }
    printf("Running total: %.2f\n", total);
}

void saveExpenses(struct Expense list[], int count)
{
    int i;
    FILE *fp = fopen("expenses.txt", "w");

    if (fp == NULL) {
        printf("Error: cannot open file.\n");
        return;
    }
    for (i = 0; i < count; i++)
        fprintf(fp, "%s,%.2f\n", list[i].category, list[i].amount);
    fclose(fp);
    printf("Saved to expenses.txt\n");
}

int main(void)
{
    struct Expense list[MAX];
    int count = 0, choice;

    do {
        printf("\n1. Add Expense\n2. View All Expenses\n3. Save & Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            choice = feof(stdin) ? 3 : 0;
        }
        clearInput();

        if (choice == 1)
            addExpense(list, &count);
        else if (choice == 2)
            viewExpenses(list, count);
        else if (choice == 3)
            saveExpenses(list, count);
        else
            printf("Invalid choice.\n");
    } while (choice != 3);

    return 0;
}
