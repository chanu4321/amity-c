#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void displayForward(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void displayBackward(struct Node* tail) {
    struct Node* current = tail;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

struct Node* deleteNode(struct Node* head, int data) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            if (current == head) {
                head = current->next;
            }
            free(current);
            return head;
        }
        current = current->next;
    }
    printf("Data not found in the Doubly Linked List.\n");
    return head;
}

void search(struct Node* head, int data) {
    struct Node* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == data) {
            printf("Data %d found at position %d in the Doubly Linked List.\n", data, position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("Data %d not found in the Doubly Linked List.\n", data);
}
int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    head = insertAtEnd(head, 10);
    tail = head;
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtBeginning(head, 5);
    tail = head->next->next;
    printf("Doubly Linked List (forward):\n");
    displayForward(head);
    printf("Doubly Linked List (backward):\n");
    displayBackward(tail);
    head = deleteNode(head, 20);
    printf("Doubly Linked List after deleting 20 (forward):\n");
    displayForward(head);
    search(head, 30);
    search(head, 40);
    return 0;
}
