#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("cap phat khong thanh cong\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(Node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d\n", root->data);
    inorder(root->right);
}
int main(void) {
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    inorder(root);
    return 0;
}