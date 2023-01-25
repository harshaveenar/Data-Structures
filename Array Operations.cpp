#include <stdio.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int size = 0;

int insert(int element, int position) {
    if (position < 0 || position > size) 
	{
        printf("Invalid position!\n");
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i-1];
    }

    arr[position] = element;
    size++;
}

 int del(int position) {
    if (position < 0 || position >= size) {
        printf("Invalid position!\n");
    }

    for (int i = position; i < size-1; i++) {
        arr[i] = arr[i+1];
    }

    size--;
}

int display() {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    insert(1, 0);
    insert(2, 1);
    insert(3, 2);

    printf("Original array: ");
    display();

    insert(4, 1);

    printf("Array after insertion: ");
    display();

    del(1);

    printf("Array after deletion: ");
    display();

    return 0;
}

