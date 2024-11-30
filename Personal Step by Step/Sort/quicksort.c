#include <stdio.h>

int partition(int arr[], int low, int high);

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void quicksort(int arr[], int low, int high)
{
    int partionindex;
    if (low < high)
    {
        partionindex = partition(arr, low, high);
        quicksort(arr, low, partionindex - 1);
        quicksort(arr, partionindex + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do
    {

        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

int main()
{
    int a;
    printf("Enter size of array: ");
    scanf("%d", &a);
    int arr[a];
    for (int i = 0; i < a; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Array before sorting: ");
    display(arr, a);
    quicksort(arr, 0, a - 1);
    printf("Array after sorting: ");
    display(arr, a);
    return 0;
}