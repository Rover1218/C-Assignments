#include <stdio.h>
int main()
{
    int a, i, isprime = 1;
    printf("Enter number to check prime or not: ");
    scanf("%d", &a);
    if (a <= 1)
    {
        isprime = 0;
    }
    else
    {
        for (i = 2; i < a; i++)
        {
            if (a % i == 0)
            {
                isprime = 0;
                break;
            }
        }
    }
    if (isprime)
    {
        printf("%d is prime", a);
    }
    else
    {
        printf("%d is not prime", a);
    }
    return 0;
}