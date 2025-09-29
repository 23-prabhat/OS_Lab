#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 20

int n, empty, full = 0, item, item1;
int buffer[BUFFERSIZE];
int in = 0, out = 0;
int mutex = 1;

void wait(int *s) {
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void produce() {
    wait(&empty);
    wait(&mutex);

    printf("Enter item to produce: ");
    scanf("%d", &item);

    buffer[in] = item;
    printf("%-10s %-10d %-10s %-10d\n", "Produced", item, "-", ++full);
    in = (in + 1) % n;

    signal(&mutex);
}

void consume() {
    wait(&full);
    wait(&mutex);

    item1 = buffer[out];
    printf("%-10s %-10s %-10d %-10d\n", "Consumed", "-", item1, --full);
    out = (out + 1) % n;

    signal(&mutex);
    signal(&empty);
}

int main() {
    int total;

    printf("Enter buffer size (max %d): ", BUFFERSIZE);
    scanf("%d", &n);

    empty = n;

    printf("Enter total number of items to produce/consume: ");
    scanf("%d", &total);

    printf("\n%-10s %-10s %-10s %-10s\n", "Action", "Produced", "Consumed", "BufferCount");
    printf("----------------------------------------------------------\n");

    for (int i = 0; i < total; i++) {
        produce();
    }

    for (int i = 0; i < total; i++) {
        consume();
    }

    return 0;
}
