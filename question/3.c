#include <stdio.h>
#include <string.h>

int main()
{
    char c[100];
    printf("Enter month: ");
    scanf("%s", c);
    if (strcmp(c, "January") == 0 || strcmp(c, "February") == 0 || strcmp(c, "March") == 0)
    {
        printf("1st Quater");
    }
    else if (strcmp(c, "April") == 0 || strcmp(c, "May") == 0 || strcmp(c, "June") == 0)
    {
        printf("2nd Quater");
    }
    else if (strcmp(c, "July") == 0 || strcmp(c, "August") == 0 || strcmp(c, "September") == 0)
    {
        printf("3rd Quater");
    }
    else if (strcmp(c, "October") == 0 || strcmp(c, "November") == 0 || strcmp(c, "December") == 0)
    {
        printf("4th Quater");
    }
    else
    {
        printf("Invalid Input");
    }
    return 0;
}