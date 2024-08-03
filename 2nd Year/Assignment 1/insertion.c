#include <stdio.h>
int main()
{
    int f;
    printf("Enter size of array: ");
    scanf("%d", &f);
    int arr[f];
    printf("Enter elements in array: ");
    for (int i = 0; i < f; i++)
    {
        scanf("%d", &arr[i]);
    }
    return 0;
}