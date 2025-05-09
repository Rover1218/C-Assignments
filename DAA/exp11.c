#include <stdio.h>
#include <stdlib.h>

struct Job
{
    int id;
    float profit;
    int deadline;
};

void readJobs(struct Job jobs[], int n)
{
    printf("\nEnter the details of %d jobs:\n", n);
    for (int i = 0; i < n; i++)
    {
        jobs[i].id = i + 1;

        printf("\nJob %d:\n", i + 1);
        printf("Profit: ");
        scanf("%f", &jobs[i].profit);

        printf("Deadline: ");
        scanf("%d", &jobs[i].deadline);
    }
}

void sortJobs(struct Job jobs[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (jobs[j].profit < jobs[j + 1].profit)
            {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

int findMaxDeadline(struct Job jobs[], int n)
{
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++)
    {
        if (jobs[i].deadline > max)
        {
            max = jobs[i].deadline;
        }
    }
    return max;
}

float jobSequencing(struct Job jobs[], int n, int result[])
{
    int maxDeadline = findMaxDeadline(jobs, n);

    int slot[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
    {
        slot[i] = -1;
    }

    float totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    return totalProfit;
}

void displayResult(struct Job jobs[], int n, int result[], int maxDeadline, float totalProfit)
{
    printf("\n\nResults of Job Sequencing with Deadline:\n");
    printf("Job ID\tProfit\tDeadline\n");
    printf("---------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%d\n", jobs[i].id, jobs[i].profit, jobs[i].deadline);
    }

    printf("\nSelected Jobs in Sequence: ");
    for (int i = 0; i < maxDeadline; i++)
    {
        if (result[i] != -1)
        {
            printf("J%d ", result[i]);
        }
    }

    printf("\n\nMaximum profit: %.2f\n", totalProfit);
}

int main()
{
    int n;

    printf("------------- JOB SEQUENCING WITH DEADLINE USING GREEDY METHOD -------------\n\n");

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];

    readJobs(jobs, n);

    printf("\nJobs before sorting:\n");
    printf("Job\tProfit\tDeadline\n");
    printf("-------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%d\n", jobs[i].id, jobs[i].profit, jobs[i].deadline);
    }

    sortJobs(jobs, n);

    printf("\nJobs after sorting by profit (descending):\n");
    printf("Job\tProfit\tDeadline\n");
    printf("--------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%d\n", jobs[i].id, jobs[i].profit, jobs[i].deadline);
    }

    int maxDeadline = findMaxDeadline(jobs, n);
    int result[maxDeadline];

    for (int i = 0; i < maxDeadline; i++)
    {
        result[i] = -1;
    }

    float totalProfit = jobSequencing(jobs, n, result);

    displayResult(jobs, n, result, maxDeadline, totalProfit);

    return 0;
}