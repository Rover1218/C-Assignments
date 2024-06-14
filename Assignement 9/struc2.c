#include <stdio.h>
#include <string.h>
#define MAX_EMPLOYEES 3

struct Employee
{
    int Id;
    char Name[50];
    double Salary;
};

int main()
{
    struct Employee employees[MAX_EMPLOYEES];
    int i;
    int highestSalaryIndex = 0;
    for (i = 0; i < MAX_EMPLOYEES; i++)
    {
        printf("Enter details for Employee %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &employees[i].Id);

        printf("Name: ");
        scanf("%s", employees[i].Name);

        printf("Salary: ");
        scanf("%lf", &employees[i].Salary);
    }
    for (i = 1; i < MAX_EMPLOYEES; i++)
    {
        if (employees[i].Salary > employees[highestSalaryIndex].Salary)
        {
            highestSalaryIndex = i;
        }
    }
    printf("\nEmployee with the highest salary:\n");
    printf("ID: %d\n", employees[highestSalaryIndex].Id);
    printf("Name: %s\n", employees[highestSalaryIndex].Name);
    printf("Salary: %.2f\n", employees[highestSalaryIndex].Salary);

    return 0;
}