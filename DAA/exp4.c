#include <stdio.h>

typedef struct
{
    int max;
    int min;
} MaxMin;

MaxMin findMaxMin(int arr[], int low, int high)
{
    MaxMin result, leftResult, rightResult;
    int mid;

    if (low == high)
    {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }

    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            result.max = arr[low];
            result.min = arr[high];
        }
        else
        {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }

    mid = (low + high) / 2;
    leftResult = findMaxMin(arr, low, mid);
    rightResult = findMaxMin(arr, mid + 1, high);

    if (leftResult.max > rightResult.max)
    {
        result.max = leftResult.max;
    }
    else
    {
        result.max = rightResult.max;
    }

    if (leftResult.min < rightResult.min)
    {
        result.min = leftResult.min;
    }
    else
    {
        result.min = rightResult.min;
    }

    return result;
}

void displayMaxMin(MaxMin result)
{
    printf("\nMaximum element: %d\n", result.max);
    printf("Minimum element: %d\n", result.min);
}

int main()
{
    int n;

    printf("------------- MAXIMUM-MINIMUM USING DIVIDE & CONQUER -------------\n\n");

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nArray elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    MaxMin result = findMaxMin(arr, 0, n - 1);

    displayMaxMin(result);

    return 0;
}