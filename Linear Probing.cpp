#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int i;
    for (i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;
        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            return;
        }
    }
    printf("Hash table is full!\n");
}

int search(int key) {
    int index = hashFunction(key);
    int i;
    for (i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;
        if (hashTable[newIndex] == key) {
            return newIndex;
        }
    }
    return -1;
}

void init() {
    int i;
    for (i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

int main() {
    init();
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    int index = search(30);
    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }
    return 0;
}
