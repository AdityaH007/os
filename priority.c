#include <stdio.h>

struct process
{
    int burst;
    int wait;
    int no;
    int priority;
} p[20];

int main()
{
    int n, i, j;
    int totalWait = 0;
    int totalTurn = 0;

    // Get the number of processes
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    // Input burst time and priority for each process
    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time (in ms) for process #%2d: ", i + 1);
        scanf("%d", &p[i].burst);

        printf("Enter the priority for process #%2d: ", i + 1);
        scanf("%d", &p[i].priority);

        p[i].no = i + 1; // Assign process number
    }

    // Sort processes by priority (lower priority number means higher priority)
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].priority > p[j + 1].priority)
            {
                // Swapping burst times
                p[j].burst ^= p[j + 1].burst;
                p[j + 1].burst ^= p[j].burst;
                p[j].burst ^= p[j + 1].burst;

                // Swapping process numbers
                p[j].no ^= p[j + 1].no;
                p[j + 1].no ^= p[j].no;
                p[j].no ^= p[j + 1].no;

                // Swapping priorities
                p[j].priority ^= p[j + 1].priority;
                p[j + 1].priority ^= p[j].priority;
                p[j].priority ^= p[j + 1].priority;
            }
        }
    }

    // Print the waiting and turnaround times for each process
    printf("\nProcess\t   Start Time   End Time   Waiting Time   Turnaround Time");

    for (i = 0; i < n; i++)
    {
        int startTime = p[i].wait;
        int endTime = p[i].wait + p[i].burst;

        printf("\nProcess #%2d\t%-11d%-10d%-10d%-10d",
               p[i].no, startTime, endTime, p[i].wait, endTime);

        if (i < n - 1)
        {
            p[i + 1].wait = p[i].wait + p[i].burst; // Update wait time for the next process
        }

        totalWait += p[i].wait;
        totalTurn += endTime;
    }

    // Calculate and print the average waiting and turnaround times
    printf("\n\nAverage\n-------");
    printf("\nAverage Waiting Time: %f ms", totalWait / (float)n);
    printf("\nAverage Turnaround Time: %f ms\n\n", totalTurn / (float)n);

    return 0;
}
