#include <stdio.h>
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main()
{
    int f, g, h;
    printf("Enter size of array: ");
    scanf("%d", &f);
    int arr[f];
    printf("Enter elements in array: ");
    for (int i = 0; i < f; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the elemnt to insert: ");
    scanf("%d", &g);
    printf("Enter the target element: ");
    scanf("%d", &h);
    if (f > h)
    {
        sortedDeletion(arr, f, g, h);
        display(arr, f);
    }
    else
    {
        printf("Target is greater than Size");
    }
    return 0;
}