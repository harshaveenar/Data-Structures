#include <stdio.h>
#define MAX 10

int stack[MAX], top = -1;

void push(int element) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        top++;
        stack[top] = element;
        printf("Pushed %d to stack\n", element);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        printf("Popped %d from stack\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element of stack is %d\n", stack[top]);
    }
}

int main() {
    pop(); 
    push(5);
    push(10);
    push(15);
    peek(); 
    pop(); 
    peek(); 
    return 0;
}

