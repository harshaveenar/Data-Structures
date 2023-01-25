#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE], top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
    } else {
        top++;
        stack[top] = value;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
    } else {
        top--;
    }
}

int peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return stack[top];
    }
}

int main() {
    push(1);
    push(2);
    push(3);
    printf("%d\n", peek());
    pop();
    printf("%d\n", peek());
    pop();
    printf("%d\n", peek());
    pop();
    return 0;
}

