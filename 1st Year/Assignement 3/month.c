#include <stdio.h>
int main()
{
    int a, b;
    printf("Enter Month Number: ");
    scanf("%d", &a);
    printf("Enter Year: ");
    scanf("%d", &b);
    if (a == 2)
    {
        if (b % 400 == 0 || b % 100 != 0 && b % 4 == 0)
        {
            printf("29");
        }
        else
        {
            printf("28");
        }
    }
    else if (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12)
    {
        printf("31");
    }
    else
    {
        printf("30");
    }
    return 0;
}