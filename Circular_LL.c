#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }
    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("...\n");
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = head;
    struct Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = head;
    struct Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return head;
    }
    struct Node* current = head;
    struct Node* prev = NULL;
    do {
        if (current->data == data) {
            if (prev == NULL) {
                if (current->next == head) {
                    head = NULL;
                } else {
                    struct Node* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = current->next;
                    last->next = head;
                }
            } else {
                prev->next = current->next;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    } while (current != head);
    printf("Data not found in the Circular Linked List.\n");
    return head;
}
void search(struct Node* head, int data) {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }
    struct Node* current = head;
    int position = 1;
    do {
        if (current->data == data) {
            printf("Data %d found at position %d in the Circular Linked List.\n", data, position);
            return;
        }
        current = current->next;
        position++;
    } while (current != head);
    printf("Data %d not found in the Circular Linked List.\n", data);
}
int main() {
    struct Node* head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    printf("Circular Linked List after insertions:\n");
    displayList(head);
    head = insertAtBeginning(head, 5);
    head = insertAtBeginning(head, 0);
    printf("Circular Linked List after insertions at the beginning:\n");
    displayList(head);
    head = deleteNode(head, 20);
    printf("Circular Linked List after deleting 20:\n");
    displayList(head);
    search(head, 30);
    search(head, 40);
    return 0;
}
