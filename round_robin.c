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

