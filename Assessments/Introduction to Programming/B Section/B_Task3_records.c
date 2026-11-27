#include <stdio.h>

struct Student {
    char name[50];
    int rollno;
    float marks;
    char grade;
};

void assignGrade(struct Student *s)
{
    if (s->marks >= 90)
        s->grade = 'A';
    else if (s->marks >= 75)
        s->grade = 'B';
    else if (s->marks >= 60)
        s->grade = 'C';
    else if (s->marks >= 45)
        s->grade = 'D';
    else
        s->grade = 'F';
}

void printTopper(struct Student list[], int n)
{
    int i, top = 0;

    for (i = 1; i < n; i++) {
        if (list[i].marks > list[top].marks)
            top = i;
    }
    printf("\nTopper: %s with %.2f marks\n", list[top].name, list[top].marks);
}

int main(void)
{
    struct Student list[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Name: ");
        if (scanf(" %49[^\n]", list[i].name) != 1)
            return 1;
        printf("Roll number: ");
        if (scanf("%d", &list[i].rollno) != 1 || list[i].rollno <= 0) {
            printf("Error: invalid roll number.\n");
            return 1;
        }
        printf("Marks (0-100): ");
        if (scanf("%f", &list[i].marks) != 1 ||
            !(list[i].marks >= 0 && list[i].marks <= 100)) {
            printf("Error: invalid marks.\n");
            return 1;
        }
        assignGrade(&list[i]);
    }

    printf("\n%-8s %-20s %8s %6s\n", "Roll", "Name", "Marks", "Grade");
    for (i = 0; i < 3; i++)
        printf("%-8d %-20s %8.2f %6c\n", list[i].rollno, list[i].name,
               list[i].marks, list[i].grade);

    printTopper(list, 3);
    return 0;
}
