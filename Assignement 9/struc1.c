#include <stdio.h>
#include <string.h>

struct Employee
{
    int Id;
    char Name[50];
    double Salary;
};

int main()
{
    struct Employee emp;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.Id);

    printf("Enter Employee Name: ");
    scanf("%s", emp.Name);

    printf("Enter Employee Salary: ");
    scanf("%lf", &emp.Salary);

    printf("\nEmployee Details:\n");
    printf("ID: %d\n", emp.Id);
    printf("Name: %s\n", emp.Name);
    printf("Salary: %.2f\n", emp.Salary);

    return 0;
}