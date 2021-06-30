//34. Program code for Best Fit Memory management Scheme using C:

#include <stdio.h>

// main function
void main()
{
	// declaration and initialization of variables
	int fragment[20], b[20], p[20], i, j, n_b, n_p, tem, low = 9999;
	static int barray[20], parray[20];
	printf("Memory Management Scheme - Best Fit\n");
	//input number of processes
	printf("Enter the number of processes:\t");
	scanf("%d", &n_p);
	//input number of blocks
	printf("\nEnter the number of blocks:");
	scanf("%d", &n_b);
	//input number of blocks
	printf("\nEnter the size of the blocks:-\n");
	for (i = 1; i <= n_b; i++)
	{
		printf("Block no.%d:", i);
		scanf("%d", &b[i]);
	}
	//input the size of process
	printf("\nEnter the size of the processes :-\n");
	for (i = 1; i <= n_p; i++)
	{
		printf("Process no.%d:", i);
		scanf("%d", &p[i]);
	}
	for (i = 1; i <= n_p; i++)
	{
		for (j = 1; j <= n_b; j++)
		{
			if (barray[j] != 1)
			{
				tem = b[j] - p[i];
				if (tem >= 0)
					if (low > tem)
					{
						parray[i] = j;
						low = tem;
					}
			}
		}
		fragment[i] = low;
		barray[parray[i]] = 1;
		low = 10000;
	}
	//Print the result
	printf("\nProcess_number \tProcess_size\tBlock_number \tBlock_size\tFragment");
	for (i = 1; i <= n_p && parray[i] != 0; i++)
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, p[i], parray[i], b[parray[i]], fragment[i]);
}