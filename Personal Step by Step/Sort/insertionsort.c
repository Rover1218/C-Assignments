#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion(int *A, int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        while (A[j] > key && j >= 0)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    int a;
    printf("Enter the size of the array: ");
    scanf("%d", &a);
    int arr[a];
    for (int i = 0; i < a; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("The array is: ");
    display(arr, a);
    insertion(arr, a);
    display(arr, a);
    return 0;
}

// 7 1 3 4 2
// i = 1 key = 1 j = 0(7)
// aj = 7 > key = 1
// 1 = 7
// 7 7 3 4 2
// j--;
// j = -1
// 0 = 1
// 1 7 3 4 2 1st pass
// i = 2 key = 3 j = 1(7)
// aj = 7 > key = 3
// 3 = 7
// 1 7 7 4 2
// j--;
// j = 0
// 1 3 7 4 2 2nd pass
// i = 3 key = 4 j = 2(7)
// aj = 7 > key = 4
// 4 = 7
// 1 3 7 7 2
// j--;
// j = 1
// 1 3 4 7 2 3rd pass
// i = 4 key = 2 j = 3(7)
// aj = 7 > key = 2
// 2 = 7
// 1 3 4 7 7
// j--;
// j = 2
// aj = 4 > key = 2
// 2 = 4
// 1 3 4 4 7
// j--;
// j = 1
// aj = 3 > key = 2
// 1 = 3
// 1 3 3 4 7
// j--;
// j = 0
// aj = 1 > key = 2
// 1 2 3 4 7 4th pass