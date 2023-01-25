#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* last = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void deleteFromBeginning(struct Node** head) {
    struct Node* temp = *head;
    if (*head == NULL) {
        return;
    }
    *head = temp->next;
    free(temp);
}

void deleteFromEnd(struct Node** head) {
    struct Node* temp = *head;
    struct Node* prev;
    if (*head == NULL) {
        return;
    }
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);
    insertAtBeginning(&head, 2);
    printList(head);
    deleteFromBeginning(&head);
    deleteFromEnd(&head);
    printList(head);
    return 0;
}

