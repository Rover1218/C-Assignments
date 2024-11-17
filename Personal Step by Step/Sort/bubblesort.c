#include <stdio.h>
void bubblesort1(int *arr, int n)
{
    int *ptr1, *ptr2, temp;
    int issorted = 0;
    for (int i = 0; i < n; i++)
    {
        printf("\nPass Number: %d\n", i);
        issorted = 1;
        for (int j = 0; j < n - i - 1; j++)
        {
            ptr1 = arr + j;
            ptr2 = arr + j + 1;
            if (*ptr1 > *ptr2)
            {
                temp = *ptr1;
                *ptr1 = *ptr2;
                *ptr2 = temp;
                issorted = 0;
            }
        }
        if (issorted)
        {
            return;
        }
    }
}
int main()
{
    int n1;
    printf("Enter size of array: ");
    scanf("%d", &n1);
    int a[n1];
    printf("Enter integers: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("UnSorted Array: ");
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", a[i]);
    }
    bubblesort1(a, n1);
    printf("Sorted Array: ");
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}