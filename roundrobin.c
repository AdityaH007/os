#include <stdio.h>

struct process
{
    int burst; // Burst time for each process
    int wait;  // Waiting time for each process
    int comp;  // Completion time for each process
    int f;     // Flag indicating if the process is complete
} p[20];

int main()
{
    int n, i, j;
    int totalWait = 0, totalTurn = 0;
    int quantum;
    int flag = 1; // Flag indicating if there's any process left to execute
    int time = 0; // Keeps track of time

    // Get the number of processes and quantum time
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    printf("\nEnter the quantum time (in ms): ");
    scanf("%d", &quantum);

    // Get burst times for each process
    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time (in ms) for process #%2d: ", i + 1);
        scanf("%d", &p[i].burst);
        p[i].f = 1;    // Flag indicating the process hasn't finished
        p[i].comp = 0; // Initialization of completion time
    }

    printf("\nOrder of Execution:");
    printf("\nProcess   Start Time   End Time   Remaining");

    // Loop until all processes are completed
    while (flag == 1)
    {
        flag = 0; // Assume no process needs more execution time

        for (i = 0; i < n; i++)
        {
            if (p[i].f == 1)
            {             // If the process is not completed
                flag = 1; // A process is still pending

                j = quantum; // Time to run in this iteration
                if ((p[i].burst - p[i].comp) > quantum)
                {
                    p[i].comp += quantum; // Increase the completed time by quantum
                }
                else
                {
                    // Last segment, process completes
                    p[i].wait = time - p[i].comp; // Calculate waiting time
                    j = p[i].burst - p[i].comp;   // Time remaining to complete the process
                    p[i].comp = p[i].burst;       // Mark process as complete
                    p[i].f = 0;                   // Flag this process as completed
                }

                // Output process execution details
                printf("\nProcess #%2d   %-10d   %-10d   %-10d",
                       i + 1, time, time + j, p[i].burst - p[i].comp);
                time += j; // Update the global time counter
            }
        }
    }

    printf("\n\n------------------");
    printf("\nProcess   Waiting Time   Turnaround Time");

    // Calculate and display waiting and turnaround times
    for (i = 0; i < n; i++)
    {
        int turnTime = p[i].wait + p[i].burst; // Turnaround time
        printf("\nProcess #%2d   %-10d   %-10d", i + 1, p[i].wait, turnTime);
        totalWait += p[i].wait; // Accumulate total waiting time
        totalTurn += turnTime;  // Accumulate total turnaround time
    }

    // Display average waiting time and turnaround time
    printf("\n\nAverage");
    printf("\nAverage Waiting Time: %f ms", totalWait / (float)n);
    printf("\nAverage Turnaround Time: %f ms\n\n", totalTurn / (float)n);

    return 0;
}
