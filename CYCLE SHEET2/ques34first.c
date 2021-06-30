//34. Program code for First Fit Memory management Scheme using C:

#include <stdio.h>
void main()
{
	//declaration and initialization of variables
	int blocksize[10], process_size[10], block_no, process_no, flags[10], allocate[10], i, j;
	for (i = 0; i < 10; i++)
	{
		flags[i] = 0;
		allocate[i] = -1;
	}
	printf("\nEnter the number of blocks: ");
	scanf("%d", &block_no);
	//code to define block size
	printf("\nEnter block size: ");

	for (i = 0; i < block_no; i++)
		scanf("%d", &blocksize[i]);
	//code to define processes
	printf("\nEnter the number of processes: ");
	scanf("%d", &process_no);
	
	printf("\nEnter size of each process: ");
	for (i = 0; i < process_no; i++)
	{
		scanf("%d", &process_size[i]);
	}
	//allocate as per first fit
	for (i = 0; i < process_no; i++)
		for (j = 0; j < block_no; j++)
			if (flags[j] == 0 && blocksize[j] >= process_size[i])
			{
				allocate[j] = i;
				flags[j] = 1;
				break;
			}
	//code to show details for allocation
	printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
	for (i = 0; i < block_no; i++)
	{
		printf("\n%d\t\t%d\t\t", i + 1, blocksize[i]);
		if (flags[i] == 1)
			printf("%d\t\t\t%d\n", allocate[i] + 1, process_size[allocate[i]]);

		else
			printf("Not allocated\n");
	}
}