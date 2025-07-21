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

bool findData(Node *root, int data) {
    if(root == NULL) {
        return false;
    }else if(root->data == data) {
        return true;
    }else {
        return findData(root->left, data)||findData(root->right,data);
    }
}

int main(void) {
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    int findNum;
    printf("nhap so can tim: ");
    scanf("%d", &findNum);
    findData(root, findNum);
    if(findData(root, findNum) == 1) {
        printf("true");
    }else {
        printf("false");
    }
    return 0;
}