//34. Program code for Worst Fit Memory management Scheme using C:
#include <stdio.h>
int main()
{
    int frag[10], blocks[10], process[10];
    int m, n, block_number, process_number, temp, top = 0;
    static int block_arr[10], process_arr[10];
    //Fill the number of blocks

    printf("\nEnter the Total Number of Blocks:\t");
    scanf("%d", &block_number);

    //Fill the number of processes
    printf("Enter the Total Number of Processes:\t");
    scanf("%d", &process_number);
    //Fill the size of the blocks
    printf("\nEnter the Size of the Blocks:\n");
    for (m = 0; m < block_number; m++)
    {
        printf("Block No.[%d]:\t", m);
        scanf("%d", &blocks[m]);
    }
    //Fill the size of the processes
    printf("Enter the Size of the processes:\n");
    for (m = 0; m < process_number; m++)
    {

        printf("process No.[%d]:\t", m);

        scanf("%d", &process[m]);
    }
    //memory allocation to the processes
    for (m = 0; m < process_number; m++)
    {
        for (n = 0; n < process_number; n++)
        {
            if (block_arr[n] != 1)
            {
                temp = blocks[n] - process[m];
                if (temp >= 0)
                {
                    if (top < temp)
                    {
                        process_arr[m] = n;
                        top = temp;
                    }
                }
            }

            frag[m] = top;
            block_arr[process_arr[m]] = 1;
            top = 0;
        }
    }
    //printing result after memory allocation
    printf("\nProcess Number\tProcess Size\tBlock Number\tBlock Size\tFragment");
    for (m = 0; m < process_number; m++)
    {

        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", m, process[m], process_arr[m], blocks[process_arr[m]], frag[m]);
    }

    printf("\n");
    return 0;
}