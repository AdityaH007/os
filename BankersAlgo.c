#include <stdio.h>
#include <stdbool.h>

#define MAX_Process 10
#define MAX_res 10

bool isSafe(int processes, int resources, int max[10][10], int alloc[10][10], int available[10])
{
    int work[MAX_res];
    int finish[MAX_Process] = {false};
    int safeSequence[MAX_Process];
    int count = 0;

    // copy available resources to work array

    for (int i = 0; i < resources; i++)
    {
        work[i] = available[i];
    }

    // find the safeSequence
    while (count < processes)
    {
        bool found = false;

        for (int p = 0; p < processes; p++)
        {
            if (!finish[p])
            {
                bool canRun = true;

                for (int r = 0; r < resources; r++)
                {
                    if (max[p][r] - alloc[p][r] > work[r])
                    {
                        canRun = false;
                        break;
                    }
                }

                if (canRun)
                {
                    for (int r = 0; r < resources; r++)
                    {
                        work[r] += alloc[p][r];
                    }

                    finish[p] = true;
                    safeSequence[count++] = p;
                    found = true;
                }
            }
        }
        if (!found)
        {
            return false;
        }
    }

    printf("safe sequence:");
    for (int i = 0; i < processes; i++)
    {
        printf("P%d", safeSequence[i]);
    }
    printf("\n");
    return true;
}

int main()
{
    int processes, resources;
    scanf("%d", &processes);
    scanf("%d", &resources);

    int max[MAX_Process][MAX_res];
    int alloc[MAX_Process][MAX_res];
    int available[MAX_res];

    printf("enter the maximum demand for each process\n");
    for (int p = p; p < processes; p++)
    {
        printf("process %d:", p);
        for (int r = 0; r < resources; r++)
        {
            scanf("%d", &max[p][r]);
        }
    }

    printf("enter the current allocation \n");
    for (int p = 0; p < processes; p++)
    {
        printf("Process %d: \n", p);
        for (int r = 0; r < resources; r++)
        {
            scanf("%d", &alloc[p][r]);
        }
    }

    // available
    printf("enter available");
    for (int r = 0; r < resources; r++)
    {
        printf("resources %d", r);
        scanf("%d", &available[r]);
    }

    // check
    if (isSafe(processes, resources, max, alloc, available))
    {
        printf("safe");
    }
    else
    {
        printf("Unsafe");
    }
    return 0;
}
