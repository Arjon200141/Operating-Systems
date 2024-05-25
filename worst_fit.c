#include <stdio.h>

void worstFit(int block[], int m, int process[], int n)
{

    int allocation[n];


    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {

        int worstIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (block[j] >= process[i])
            {
                if (worstIdx == -1)
                    worstIdx = j;
                else if (block[worstIdx] < block[j])
                    worstIdx = j;
            }
        }


        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;


            block[worstIdx] -= process[i];
        }
    }


    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t\t%d\t\t", i + 1, process[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}


int main()
{
    int block[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    int m = sizeof(block) / sizeof(block[0]);
    int n = sizeof(process) / sizeof(process[0]);

    worstFit(block, m, process, n);

    return 0;
}

