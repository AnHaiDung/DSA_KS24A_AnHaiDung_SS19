#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int findHeight(Node *root) {
    if(root == NULL) {
        return -1;
    }else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        if(leftHeight > rightHeight) {
            return 1 + leftHeight;
        }else {
            return 1 + rightHeight;
        }
    }
}



int main(void) {
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    int result = findHeight(root);
    printf("%d\n", result);
    return 0;
}