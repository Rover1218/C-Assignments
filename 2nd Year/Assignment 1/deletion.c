#include <stdio.h>
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}
void sortedDeletion(int arr[], int size, int target)
{
    for (int i = target; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
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
    display(arr, f);
    printf("Enter the target element: ");
    scanf("%d", &h);
    if (f > h)
    {
        sortedDeletion(arr, f, h);
        f -= 1;
        display(arr, f);
    }
    else
    {
        printf("Target is greater than Size");
    }
    return 0;
}