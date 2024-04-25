#include <stdio.h>
#include <stdlib.h>

struct process
{
    int size; // Size of the process
    int id;   // ID of the block to which the process is assigned
};

struct block
{
    int no;   // Block number
    int size; // Size of the block
    int id;   // ID of the process assigned to the block
};

int main()
{
    struct process p[20];
    struct block b[20];
    int nb, np; // Number of blocks and processes
    int i, j;

    // Clear the console screen (not standard in most compilers, but used for Turbo C/C++)
    // clrscr();

    // Get the number of memory blocks and their sizes
    printf("Enter the number of memory blocks: ");
    scanf("%d", &nb);
    for (i = 0; i < nb; i++)
    {
        printf("Enter the size of block #%2d: ", i + 1);
        scanf("%d", &b[i].size);
        b[i].no = i + 1; // Set block number
        b[i].id = 0;     // Initialize block as empty
    }

    // Get the number of processes and their sizes
    printf("\nEnter the number of processes: ");
    scanf("%d", &np);
    for (i = 0; i < np; i++)
    {
        printf("Enter the size of process #%2d: ", i + 1);
        scanf("%d", &p[i].size);
        p[i].id = 0; // Initialize process with no block assigned
    }

    // Sort the blocks by size (ascending order) for best-fit allocation
    for (i = 0; i < nb - 1; i++)
    {
        for (j = 0; j < nb - i - 1; j++)
        {
            if (b[j].size > b[j + 1].size)
            {
                // Swap block sizes
                int tempSize = b[j].size;
                b[j].size = b[j + 1].size;
                b[j + 1].size = tempSize;

                // Swap block numbers
                int tempNo = b[j].no;
                b[j].no = b[j + 1].no;
                b[j + 1].no = tempNo;
            }
        }
    }

    // Allocate processes to blocks using best-fit logic
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nb; j++)
        {
            if (b[j].id == 0 && p[i].size <= b[j].size)
            {
                b[j].id = i + 1;   // Assign process to block
                p[i].id = b[j].no; // Assign block number to process
                break;             // Process is allocated, move to the next one
            }
        }
    }

    // Display block assignments
    printf("\nBlock Allocation");
    printf("\n----------------");
    printf("\nBlock ID   Block Size   Process ID   Process Size");

    for (i = 0; i < nb; i++)
    {
        if (b[i].id)
        {
            printf("\nBlock #%2d   %-10d   %-10d   %-10d",
                   b[i].no, b[i].size, b[i].id, p[b[i].id - 1].size);
        }
        else
        {
            printf("\nBlock #%2d   %-10d   Empty", b[i].no, b[i].size);
        }
    }

    // Display process assignments
    printf("\n\nProcess Allocation");
    printf("\n------------------");
    printf("\nProcess ID   Process Size   Block ID   Block Size");

    for (i = 0; i < np; i++)
    {
        if (p[i].id)
        {
            printf("\nProcess #%2d   %-10d   %-10d   %-10d",
                   i + 1, p[i].size, p[i].id, b[p[i].id - 1].size);
        }
        else
        {
            printf("\nProcess #%2d   %-10d   Waiting", i + 1, p[i].size);
        }
    }

    printf("\n");

    return 0;
}
