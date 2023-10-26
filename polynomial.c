#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    if (poly1 == NULL) {
        return poly2;
    }
    if (poly2 == NULL) {
        return poly1;
    }
    struct Node* result = NULL;
    if (poly1->exponent == poly2->exponent) {
        result = createNode(poly1->coefficient + poly2->coefficient, poly1->exponent);
        result->left = addPolynomials(poly1->left, poly2->left);
        result->right = addPolynomials(poly1->right, poly2->right);
    } else if (poly1->exponent > poly2->exponent) {
        result = createNode(poly1->coefficient, poly1->exponent);
        result->left = addPolynomials(poly1->left, poly2);
        result->right = addPolynomials(poly1->right, NULL);
    } else {
        result = createNode(poly2->coefficient, poly2->exponent);
        result->left = addPolynomials(poly1, poly2->left);
        result->right = addPolynomials(NULL, poly2->right);
    }
    return result;
}

struct Node* subtractPolynomials(struct Node* poly1, struct Node* poly2) {
    if (poly1 == NULL) {
        return poly2;
    }
    if (poly2 == NULL) {
        return poly1;
    }
    struct Node* result = NULL;
    if (poly1->exponent == poly2->exponent) {
        result = createNode(poly1->coefficient - poly2->coefficient, poly1->exponent);
        result->left = subtractPolynomials(poly1->left, poly2->left);
        result->right = subtractPolynomials(poly1->right, poly2->right);
    } else if (poly1->exponent > poly2->exponent) {
        result = createNode(poly1->coefficient, poly1->exponent);
        result->left = subtractPolynomials(poly1->left, poly2);
        result->right = subtractPolynomials(poly1->right, NULL);
    } else {
        result = createNode(-poly2->coefficient, poly2->exponent);
        result->left = subtractPolynomials(poly1, poly2->left);
        result->right = subtractPolynomials(NULL, poly2->right);
    }

    return result;
}

void displayPolynomial(struct Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->exponent == 0) {
        printf("%d", root->coefficient);
    } else if (root->exponent == 1) {
        printf("%dx", root->coefficient);
    } else {
        printf("%dx^%d", root->coefficient, root->exponent);
    }
    if (root->right != NULL) {
        if (root->right->coefficient >= 0) {
            printf(" + ");
        } else {
            printf(" - ");
        }
    }
    displayPolynomial(root->left);
    displayPolynomial(root->right);
}
int main() {

    struct Node* poly1 = createNode(3, 2);
    poly1->left = createNode(2, 1);
    poly1->right = createNode(1, 0);

    struct Node* poly2 = createNode(2, 2);
    poly2->left = createNode(-4, 1);
    poly2->right = createNode(1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("\n");

    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    printf("\n");

    struct Node* sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    displayPolynomial(sum);
    printf("\n");

    struct Node* difference = subtractPolynomials(poly1, poly2);
    printf("Difference: ");
    displayPolynomial(difference);
    printf("\n");
    return 0;
}
