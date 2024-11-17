#include <stdio.h>
int binarysearch(int arr[], int n, int x)
{
    int low, mid, high;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
void sort(int *arr, int n)
{
    int *ptr1, *ptr2, temp;
    int issorted = 0;
    for (int i = 0; i < n; i++)
    {
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
    int n1, x, result;
    printf("Enter size of array: ");
    scanf("%d", &n1);
    int a[n1];
    printf("Enter integers:\n");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the number you wanna search: ");
    scanf("%d", &x);
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, n);
    result = binarysearch(a, n, x);
    if (result == -1)
    {
        printf("Element was not found");
    }
    else
    {
        printf("The elemnt was found at index %d", result);
    }
    return 0;
}