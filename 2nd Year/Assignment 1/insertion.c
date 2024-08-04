#include <stdio.h>
void display(int arr[], int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}
void sortedInsertion(int arr[], int size, int element, int target)
{
    for (int i = size - 1; i >= target; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[target] = element;
}
int main()
{
    int f, g, h;
    printf("Enter size of array: ");
    scanf("%d", &f);
    int arr[f];
    printf("Enter elements in array:\n");
    for (int i = 0; i < f; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to insert: ");
    scanf("%d", &g);
    printf("Enter the target element: ");
    scanf("%d", &h);
    if (f > h)
    {
        sortedInsertion(arr, f, g, h);
        display(arr, f);
    }
    else
    {
        printf("Target is greater than Size");
    }
    return 0;
}