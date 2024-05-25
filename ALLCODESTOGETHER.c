//First Come First Serve


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


//Shortest Job First

#include<stdio.h>
#define MAX 30

int main()
{
    int n, i, j, p[MAX], t, bt[MAX], wt[MAX], tat[MAX], at[MAX], ct[MAX];
    float atat = 0, awt = 0;

    printf("Enter Number of Process: ");
    scanf("%d", &n);

    printf("Enter The Processes: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter The Arrival Time: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("Enter The Burst Time: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(at[j] > at[j + 1] || (at[j] == at[j + 1] && bt[j] > bt[j + 1]))
            {
                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;

                t = at[j];
                at[j] = at[j + 1];
                at[j + 1] = t;
            }
        }
    }

    int currentTime = 0;
    for(i = 0; i < n; i++)
    {
        if(currentTime < at[i])
        {
            currentTime = at[i];
        }
        ct[i] = currentTime + bt[i];
        currentTime = ct[i];

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        awt += wt[i];
        atat += tat[i];
    }

    printf("Process\t Arrival Time\t Burst Time\t Completion Time\t Waiting Time\t Turn Around Time\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n", p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("Average WT: %f\n", awt / n);
    printf("Average TAT: %f\n", atat / n);

    return 0;
}

//Priority Scheduling

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

    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(pr[j] > pr[j + 1] || (pr[j] == pr[j + 1] && at[j] > at[j + 1])) {

                t = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = t;

                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;

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

//round robin

#include <stdio.h>

#define MAX 100

typedef struct {
    int process_id;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateTimes(Process processes[], int n, int quantum) {
    int time = 0;
    int completed = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > quantum) {
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    time += processes[i].remaining_time;
                    processes[i].waiting_time = time - processes[i].burst_time;
                    processes[i].turnaround_time = time;
                    processes[i].remaining_time = 0;
                    completed++;
                }
            }
        }
    }
}

void printProcesses(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].process_id,
               processes[i].burst_time,
               processes[i].waiting_time,
               processes[i].turnaround_time);
    }
}

int main() {
    int n, quantum;
    Process processes[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    calculateTimes(processes, n, quantum);
    printProcesses(processes, n);

    return 0;
}

//Bankers Algorithm

#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int max_claim[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int work[MAX_RESOURCES];
int finish[MAX_PROCESSES];

int num_processes, num_resources;

int is_safe_state() {
    int i, j;
    int count = 0;

    for (i = 0; i < num_resources; i++)
        work[i] = available[i];

    for (i = 0; i < num_processes; i++)
        finish[i] = 0;

    for (i = 0; i < num_processes; i++) {
        if (!finish[i]) {
            int can_allocate = 1;
            for (j = 0; j < num_resources; j++) {
                if (need[i][j] > work[j]) {
                    can_allocate = 0;
                    break;
                }
            }

            if (can_allocate) {
                finish[i] = 1;
                count++;
                for (j = 0; j < num_resources; j++)
                    work[j] += allocation[i][j];
                i = -1;
            }
        }
    }

    return count == num_processes;
}

int main() {
    int i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    printf("Enter the available resources: ");
    for (i = 0; i < num_resources; i++)
        scanf("%d", &available[i]);

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < num_processes; i++)
        for (j = 0; j < num_resources; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter the maximum claim matrix:\n");
    for (i = 0; i < num_processes; i++)
        for (j = 0; j < num_resources; j++) {
            scanf("%d", &max_claim[i][j]);
            need[i][j] = max_claim[i][j] - allocation[i][j];
        }

    if (is_safe_state())
        printf("The system is in a safe state.\n");
    else
        printf("The system is not in a safe state.\n");

    return 0;
}

//First fit

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

//Best fit

#include <stdio.h>

void bestFit(int block[], int m, int process[], int n)
{
    int allocation[n];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (block[j] >= process[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (block[bestIdx] > block[j])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;

            block[bestIdx] -= process[i];
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

    bestFit(block, m, process, n);

    return 0;
}


//Worst Fit

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


//bounded  buffer problem

#include <stdio.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int count = 0;

void produce(int item) {
    if (count == BUFFER_SIZE) {
        printf("Buffer is full. Producer cannot produce.\n");
    } else {
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        printf("Produced item: %d\n", item);
    }
}

void consume() {
    if (count == 0) {
        printf("Buffer is empty. Consumer cannot consume.\n");
    } else {
        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        printf("Consumed item: %d\n", item);
    }
}

int main() {
    int choice;
    int item;

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to produce: ");
                scanf("%d", &item);
                produce(item);
                break;
            case 2:
                consume();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

//Counting semaphore


#include <stdio.h>

typedef struct {
    int value;
} Semaphore;


void initSemaphore(Semaphore *sem, int value) {
    sem->value = value;
}

void waitSemaphore(Semaphore *sem) {

    while (sem->value <= 0) {
    }
    sem->value--;
}

void signalSemaphore(Semaphore *sem) {
    sem->value++;
}

int main() {
    Semaphore sem;

    initSemaphore(&sem, 1);

    printf("Initial semaphore value: %d\n", sem.value);

    printf("Performing wait operation...\n");
    waitSemaphore(&sem);
    printf("Semaphore value after wait: %d\n", sem.value);

    printf("Performing signal operation...\n");
    signalSemaphore(&sem);
    printf("Semaphore value after signal: %d\n", sem.value);

    return 0;
}






