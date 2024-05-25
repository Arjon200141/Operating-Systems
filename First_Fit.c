#include <stdio.h>
#include <stdlib.h>

void firstFit(int block[], int m, int process[], int n)
{

	int allocation[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (block[j] >= process[i])
			{
				allocation[i] = j;

				block[j] -= process[i];

				break;
			}
		}
	}

	printf("\nProcess No.\tProcess Size\tBlock no.\n");
	for (int i = 0; i < m; i++)
	{
		printf(" %d\t\t%d\t\t", i+1, process[i]);
		if (allocation[i] != -1)
			printf("%d", allocation[i] + 1);
		else
			printf("Not Allocated");
		printf("\n");
	}
}

int main()
{
    printf("Enter number of Blocks :\n");
	int n;
	scanf("%d", &n);
	int block[n+1];
	for(int i=0;i<n;i++)
    {
        scanf("%d", &block[i]);
    }
    printf("Enter number of processes :\n");
    int m;
    scanf("%d", &m);
    int process[m+1];
    for(int i=0;i<m;i++)
    {
        scanf("%d", &process[i]);
    }
	firstFit(block, m, process, n);

	return 0 ;
}

