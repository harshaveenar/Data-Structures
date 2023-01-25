#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int item) {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = item;
    printf("Item enqueued: %d\n", item);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Item dequeued: %d\n", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    display();
    return 0;
}

