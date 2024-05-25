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

    // Initialize work array with available resources
    for (i = 0; i < num_resources; i++)
        work[i] = available[i];

    // Initialize finish array to false
    for (i = 0; i < num_processes; i++)
        finish[i] = 0;

    // Find a process that can finish
    for (i = 0; i < num_processes; i++) {
        if (!finish[i]) {
            // Check if process i can be satisfied with available resources
            int can_allocate = 1;
            for (j = 0; j < num_resources; j++) {
                if (need[i][j] > work[j]) {
                    can_allocate = 0;
                    break;
                }
            }

            // If process i can be satisfied, release its resources
            if (can_allocate) {
                finish[i] = 1;
                count++;
                for (j = 0; j < num_resources; j++)
                    work[j] += allocation[i][j];
                i = -1; // Start from the beginning again
            }
        }
    }

    // If all processes can finish, return true; else, return false
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

