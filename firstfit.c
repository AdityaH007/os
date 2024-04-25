#include <stdio.h>
#include <string.h>

struct process
{
    int size;      // Size of the process
    char name[20]; // Name of the process
    int id;        // ID of the block to which the process is assigned
};

struct block
{
    int size; // Size of the block
    int id;   // ID of the process assigned to the block
};

int main()
{
    struct process p[20];
    struct block b[20];
    int nb, np;
    int i, j;

    // Get the number of memory blocks
    printf("\nEnter the number of memory blocks: ");
    scanf("%d", &nb);

    // Get the size of each block
    for (i = 0; i < nb; i++)
    {
        printf("Enter the size of block #%2d: ", i + 1);
        scanf("%d", &b[i].size);
        b[i].id = 0; // Initialize the block as empty (no process assigned)
    }

    // Get the number of processes
    printf("\nEnter the number of processes: ");
    scanf("%d", &np);

    // Get the details for each process (name and size)
    for (i = 0; i < np; i++)
    {
        printf("Enter the name of process #%2d: ", i + 1);
        scanf("%s", p[i].name);

        printf("Enter the size of process #%2d: ", i + 1);
        scanf("%d", &p[i].size);
        p[i].id = 0; // Initialize process with no block assigned
    }

    // Assign processes to blocks (best-fit allocation)
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nb; j++)
        {
            if (b[j].id == 0 && p[i].size <= b[j].size)
            {
                b[j].id = i + 1; // Assign process to block
                p[i].id = j + 1; // Assign block to process
                break;           // Move to the next process
            }
        }
    }

    // Display block assignments
    printf("\nBlock Allocation");
    printf("\n----------------");
    printf("\nBlock ID   Block Size   Process Name   Process Size");

    for (i = 0; i < nb; i++)
    {
        if (b[i].id)
        {
            printf("\nBlock #%2d   %-10d   %-10s   %-10d", i + 1, b[i].size, p[b[i].id - 1].name, p[b[i].id - 1].size);
        }
        else
        {
            printf("\nBlock #%2d   %-10d   Empty", i + 1, b[i].size);
        }
    }

    // Display process assignments
    printf("\n\nProcess Allocation");
    printf("\n------------------");
    printf("\nProcess Name   Process Size   Block ID   Block Size");

    for (i = 0; i < np; i++)
    {
        if (p[i].id)
        {
            printf("\n%-10s   %-10d   %-10d   %-10d", p[i].name, p[i].size, p[i].id, b[p[i].id - 1].size);
        }
        else
        {
            printf("\n%-10s   %-10d   Waiting", p[i].name, p[i].size);
        }
    }

    printf("\n");
    return 0;
}
