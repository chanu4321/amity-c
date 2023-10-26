#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node* front;
    struct Node* rear;
};
void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}
void insert(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d inserted into the queue.\n", data);
}
int delete(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty. Cannot delete.\n");
        return -1; 
    }
    int deletedData = queue->front->data;
    struct Node* temp = queue->front;
    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }
    free(temp);
    return deletedData;
}
void display(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* current = queue->front;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    struct Queue queue;
    initializeQueue(&queue);
    insert(&queue, 10);
    insert(&queue, 20);
    insert(&queue, 30);
    display(&queue);
    int deletedItem = delete(&queue);
    if (deletedItem != -1) {
        printf("Deleted item: %d\n", deletedItem);
    }
    display(&queue);
    return 0;
}
