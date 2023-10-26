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
int countOccurrences(struct Node* head, int target) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == target) {
            count++;
        }
        current = current->next;
    }
    return count;
}
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(4);
    int target = 2;
    printf("Linked List: ");
    display(head);
    int count = countOccurrences(head, target);
    printf("The number of times %d is present in the linked list: %d\n", target, count);
    return 0;
}
