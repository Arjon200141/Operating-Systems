#include <stdio.h>
#define MAX 30

int main() {
    int n, i, j, p[MAX], t, bt[MAX], wt[MAX], tat[MAX], at[MAX], ct[MAX], pr[MAX];
    float atat = 0, awt = 0;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    printf("Enter The Processes: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter The Arrival Time: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter The Burst Time: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("Enter The Priorities: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pr[i]);
    }

    // Sorting based on Priority (and Arrival Time if priorities are the same)
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(pr[j] > pr[j + 1] || (pr[j] == pr[j + 1] && at[j] > at[j + 1])) {
                // Swapping Priority
                t = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = t;

                // Swapping Burst Time
                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                // Swapping Process IDs
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;

                // Swapping Arrival Time
                t = at[j];
                at[j] = at[j + 1];
                at[j + 1] = t;
            }
        }
    }

    int currentTime = 0;
    for(i = 0; i < n; i++) {
        if(currentTime < at[i]) {
            currentTime = at[i];
        }
        ct[i] = currentTime + bt[i];
        currentTime = ct[i];

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        awt += wt[i];
        atat += tat[i];
    }

    printf("Process\t Arrival Time\t Burst Time\t Priority\t Completion Time\t Waiting Time\t Turn Around Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t\t %d\t\t %d\n", p[i], at[i], bt[i], pr[i], ct[i], wt[i], tat[i]);
    }

    printf("Average WT: %f\n", awt / n);
    printf("Average TAT: %f\n", atat / n);

    return 0;
}


