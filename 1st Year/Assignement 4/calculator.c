#include <stdio.h>
#include <math.h>

int main()
{
    do
    {
        int num, u, a, b;
        {
            printf("Enter 1st Number: ");
            scanf("%d", &a);
            printf("Enter 2nd Number: ");
            scanf("%d", &b);
            printf("Enter 1. Sum\n2. Substract\n3. Multiply\n4. Division\n5. Modulus\n6. Square-Root\n7. Cube-Root: ");
            scanf("%d", &num);
            switch (num)
            {
            case 1:
                printf("The sum of two number is: %d\n", a + b);
                break;
            case 2:
                printf("The substraction of two number is: %d\n", a - b);
                break;
            case 3:
                printf("The multiplication of two number is: %d\n", a * b);
                break;
            case 4:
                if (b != 0)
                    printf("The division of two number is: %d\n", a / b);
                else
                    printf("Divisor cannot be zero\n");
                break;
            case 5:
                printf("The modulus of two number is: %d\n", a % b);
                break;
            case 6:
                printf("The Square-Root of two number is: %.2f\n%.2f\n", sqrt(a), sqrt(b));
                break;
            case 7:
                printf("The Cube-Root of two number is: %.2f\n%.2f\n", cbrt(a), cbrt(b));
                break;
            default:
                printf("Invalid Error!!\n");
                break;
            }
        }
        printf("Enter 1 for y or 2 for n: ");
        scanf("%d", &u);
        if (u == 1)
            continue;
        else
            break;
    } while (1);
    return 0;
}