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
