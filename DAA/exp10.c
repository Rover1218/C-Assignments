#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int id;
    float profit;
    float weight;
    float ratio;
};

void readItems(struct Item items[], int n, float *capacity)
{
    printf("Enter the capacity of the knapsack: ");
    scanf("%f", capacity);

    printf("\nEnter the details of %d items:\n", n);
    for (int i = 0; i < n; i++)
    {
        items[i].id = i + 1;

        printf("\nItem %d:\n", i + 1);
        printf("Profit: ");
        scanf("%f", &items[i].profit);

        printf("Weight: ");
        scanf("%f", &items[i].weight);

        items[i].ratio = items[i].profit / items[i].weight;
    }
}

void sortItems(struct Item items[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

float fractionalKnapsack(struct Item items[], int n, float capacity, float result[])
{
    float totalProfit = 0;
    float currentWeight = 0;

    for (int i = 0; i < n; i++)
    {
        result[i] = 0.0;
    }

    for (int i = 0; i < n; i++)
    {
        if (currentWeight + items[i].weight <= capacity)
        {
            result[items[i].id - 1] = 1.0;
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
        }
        else
        {
            float remainingCapacity = capacity - currentWeight;
            result[items[i].id - 1] = remainingCapacity / items[i].weight;
            totalProfit += items[i].profit * result[items[i].id - 1];
            break;
        }
    }

    return totalProfit;
}

void displayResult(struct Item items[], int n, float result[], float totalProfit)
{
    printf("\n\nResults of Fractional Knapsack:\n");
    printf("Item\tProfit\tWeight\tRatio\t\tFraction\n");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        int id = items[i].id;
        printf("%d\t%.2f\t%.2f\t%.2f\t\t%.2f\n",
               id, items[i].profit, items[i].weight, items[i].ratio, result[id - 1]);
    }

    printf("\nMaximum profit: %.2f\n", totalProfit);

    printf("\nResult Vector: [");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f", result[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main()
{
    int n;

    printf("------------- FRACTIONAL KNAPSACK USING GREEDY METHOD -------------\n\n");

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    float capacity;
    float result[n];

    readItems(items, n, &capacity);

    printf("\nItems before sorting:\n");
    printf("Item\tProfit\tWeight\tRatio\n");
    printf("---------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               items[i].id, items[i].profit, items[i].weight, items[i].ratio);
    }

    sortItems(items, n);

    printf("\nItems after sorting by profit/weight ratio (descending):\n");
    printf("Item\tProfit\tWeight\tRatio\n");
    printf("---------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n",
               items[i].id, items[i].profit, items[i].weight, items[i].ratio);
    }

    float totalProfit = fractionalKnapsack(items, n, capacity, result);

    displayResult(items, n, result, totalProfit);

    return 0;
}