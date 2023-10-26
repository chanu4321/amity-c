#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Stack {
    struct Node* data[MAX_STACK_SIZE];
    int top;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void push(struct Stack* stack, struct Node* node) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->data[++stack->top] = node;
    }
}

struct Node* pop(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return NULL;
}

int isStackEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

void nonRecursivePreorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Stack stack;
    stack.top = -1;
    push(&stack, root);
    while (!isStackEmpty(&stack)) {
        struct Node* current = pop(&stack);
        if (current != NULL) {
            printf("%d ", current->data);
            if (current->right) {
                push(&stack, current->right);
            }
            if (current->left) {
                push(&stack, current->left);
            }
        }
    }
}

void nonRecursivePostorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Stack stack1, stack2;
    stack1.top = -1;
    stack2.top = -1;
    push(&stack1, root);
    while (!isStackEmpty(&stack1)) {
        struct Node* current = pop(&stack1);
        if (current != NULL) {
            push(&stack2, current);
            if (current->left) {
                push(&stack1, current->left);
            }
            if (current->right) {
                push(&stack1, current->right);
            }
        }
    }
    while (!isStackEmpty(&stack2)) {
        printf("%d ", pop(&stack2)->data);
    }
}

void nonRecursiveInorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Stack stack;
    stack.top = -1;
    struct Node* current = root;
    while (current || !isStackEmpty(&stack)) {
        while (current) {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Non-recursive Preorder Traversal: ");
    nonRecursivePreorder(root);
    printf("\n");
    printf("Non-recursive Postorder Traversal: ");
    nonRecursivePostorder(root);
    printf("\n");
    printf("Non-recursive Inorder Traversal: ");
    nonRecursiveInorder(root);
    printf("\n");
    return 0;
}
