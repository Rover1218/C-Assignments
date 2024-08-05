#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f;
    printf("Enter size of array: ");
    scanf("%d", &f);    
    int *ptr;
    ptr = (int *)malloc(f * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < f; i++)
    {
        scanf("%d", &(ptr[i]));
    }
    printf("Output: ");
    for (int i = 0; i < f; i++)
    {
        printf("%d ", ptr[i]);
    }
    
    return 0;
}