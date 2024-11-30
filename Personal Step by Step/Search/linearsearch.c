#include <stdio.h>
int main()
{
    int *ptr, n1, x, n;
    printf("Enter size of array: ");
    scanf("%d", &n1);
    int a[n1];
    printf("Enter integers: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the number you wanna search: ");
    scanf("%d", &x);
    n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i <= n; i++)
    {
        ptr = a + i;
        if (*ptr == x)
        {
            printf("Element found at index: %d", i);
            return 0;
        }
    }
    printf("Element not found in the array");
    return 0;
}