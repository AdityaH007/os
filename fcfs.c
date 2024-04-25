#include <stdio.h>

struct process
{
    int burst, wait;
} p[20] = {0, 0};

int main()
{
    int n, i, totalwait = 0, totalturn = 0;
    printf("\n Enter the no of process: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("enter burst time for pprocess %d", i + 1);
        scanf("%d", &p[i].burst);
    }

    // main thing
    //
    for (i = 0; i < n; i++)
    {
        printf("process # %12d %15d %15d", i + 1, p[i].wait, p[i].wait + p[i].burst);
        p[i + 1].wait = p[i].wait + p[i].burst;
        totalwait = totalwait + p[i].wait;
        totalturn = totalturn + p[i].wait + p[i].burst;
    }

    return 0;
}
