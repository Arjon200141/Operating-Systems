#include <stdio.h>
#define MAX 30

int main()
{
    int i, j, n, at[MAX], wt[MAX], tat[MAX], bt[MAX], temp[MAX], ct[MAX];
    float awt = 0, atat = 0;

    printf("Enter The Number of Processes: ");
    scanf("%d", &n);
    printf("Enter The Burst Time: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("Enter The Arrival Time: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }
    temp[0] = 0;
    printf("Process\t Burst Time\t Arrival Time\t Waiting Time\t Turn Around Time\t Completion Time\n");

    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;

        temp[i + 1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        if (wt[i] < 0) wt[i] = 0;

        tat[i] = wt[i] + bt[i];
        ct[i] = at[i] + tat[i];

        atat += tat[i];
        awt += wt[i];

        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t\t %d\n", i + 1, bt[i], at[i], wt[i], tat[i], ct[i]);
    }

    printf("Average waiting time: %f\n", awt / n);
    printf("Average turn around time: %f\n", atat / n);

    return 0;
}
