#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

struct Student
{
    char Name[50];
    int RollNo;
    int Marks[3];
    double Average;
};

int main()
{
    struct Student students[MAX_STUDENTS];
    int i, j;
    double totalAverage = 0;
    for (i = 0; i < MAX_STUDENTS; i++)
    {
        printf("Enter details for Student %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", students[i].Name);

        printf("Roll No: ");
        scanf("%d", &students[i].RollNo);

        printf("Marks for 3 subjects: ");
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &students[i].Marks[j]);
        }
        students[i].Average = (students[i].Marks[0] + students[i].Marks[1] + students[i].Marks[2]) / 3.0;
        totalAverage += students[i].Average;
    }
    printf("\nStudent Details:\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Roll No", "Marks", "Average");
    for (i = 0; i < MAX_STUDENTS; i++)
    {
        printf("%-20s %-10d %-10d %-10.2f\n", students[i].Name, students[i].RollNo, students[i].Marks[0], students[i].Average);
    }
    printf("\nAverage marks of all students: %.2f\n", totalAverage / MAX_STUDENTS);

    return 0;
}