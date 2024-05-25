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
