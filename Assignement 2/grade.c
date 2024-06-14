#include <stdio.h>
int main()
{
    int a;
    printf("Enter number:");
    scanf("%d", &a);
    if (a <= 100 && a >= 80)
    {
        printf("Grade is A");
    }
    else if (a >= 60 && a <= 79)
    {
        printf("Grade is B");
    }
    else if (a >= 40 && a <= 59)
    {
        printf("Grade is C");
    }
    else if (a >= 0 && a <= 39)
    {
        printf("Grade is F");
    }
    else
        printf("Number cannot be less than 0 or greater than 100");
    return 0;
}