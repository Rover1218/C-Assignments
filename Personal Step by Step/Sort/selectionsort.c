#include <stdio.h>
void display(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}
void selectionsort(int *A, int n)
{
    int p, next;
    for (int i = 0; i < n - 1; i++)
    {
        p = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[p])
            {
                p = j;
            }
        }
        next = A[i];
        A[i] = A[p];
        A[p] = next;
    }
}
int main()
{
    int n;
    printf("Enter limit of array: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter elements inside array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Elements before sorting: ");
    display(A, n);
    printf("\nElements after Sorting: ");
    selectionsort(A, n);
    display(A, n);
    return 0;
}