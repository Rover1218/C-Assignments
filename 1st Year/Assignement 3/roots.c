#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c;
    double ab, bc, ac, d, ad, bd;
    printf("Enter the 1st coefficient of quadratic equation: ");
    scanf("%d", &a);
    printf("Enter the 2nd coefficient of quadratic equation: ");
    scanf("%d", &b);
    printf("Enter the 3rd coefficient of quadratic equation: ");
    scanf("%d", &c);
    ab = b * b - 4 * a * c;
    if (ab > 0)
    {
        bc = -b + sqrt(ab) / 2 * a;
        ac = -b - sqrt(ab) / 2 * a;
        printf("Two roots are: %.2lf, %.2lf\n", bc, ac);
        }
    else if (ab == 0)
    {
        bc = ac = -b / 2 * a;
        printf("Two roots are: %.2lf, %.2lf\n", bc, ac);
    }
    else
    {
        bc = -b / 2 * a;
        ac = sqrt(-ab) / 2 * a;
        printf("Two roots are: %.2lf + %.2lfi, %.2lf - %.2lfi", bc, ac, bc, ac);
    }
    return 0;
}