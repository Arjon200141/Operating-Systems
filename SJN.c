#include<stdio.h>
#define MAX 30

int main()
{
    int n, i, j, currentTime = 0, completed = 0, minIndex;
    int p[MAX], at[MAX], bt[MAX], ct[MAX], wt[MAX], tat[MAX], remaining_bt[MAX];
    float atat = 0, awt = 0;
    int is_completed[MAX] = {0};

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    printf("Enter Process IDs: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter Arrival Times: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter Burst Times: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        remaining_bt[i] = bt[i];
    }

    while(completed != n) {
        minIndex = -1;
        int min_bt = 99999;

        for(i = 0; i < n; i++) {
            if(at[i] <= currentTime && is_completed[i] == 0) {
                if(remaining_bt[i] < min_bt) {
                    min_bt = remaining_bt[i];
                    minIndex = i;
                }
                if(remaining_bt[i] == min_bt) {
                    if(at[i] < at[minIndex]) {
                        minIndex = i;
                    }
                }
            }
        }

        if(minIndex == -1) {
            currentTime++;
        } else {
            remaining_bt[minIndex]--;
            currentTime++;
            if(remaining_bt[minIndex] == 0) {
                ct[minIndex] = currentTime;
                tat[minIndex] = ct[minIndex] - at[minIndex];
                wt[minIndex] = tat[minIndex] - bt[minIndex];

                awt += wt[minIndex];
                atat += tat[minIndex];

                is_completed[minIndex] = 1;
                completed++;
            }
        }
    }

    printf("Process\t Arrival Time\t Burst Time\t Completion Time\t Waiting Time\t Turn Around Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t\t %d\t\t %d\n", p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("Average WT: %f\n", awt / n);
    printf("Average TAT: %f\n", atat / n);

    return 0;
}
