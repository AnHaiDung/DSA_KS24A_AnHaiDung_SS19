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

typedef struct queueNode {
    Node* data;
    struct queueNode* next;
}queueNode;

typedef struct {
    queueNode* front;
    queueNode* rear;
}Queue;

void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

bool isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enQueue(Queue* queue, Node* data) {
    queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
    if(newNode == NULL) {
        printf("khong the cap phat bo nho\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

Node* deQueue(Queue* queue) {
    if(isQueueEmpty(queue)) {
        printf("hang doi rong\n");
        return NULL;
    }
    queueNode* temp = queue->front;
    Node* data = temp ->data;
    queue->front = queue->front->next;
    if(queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

bool findData(Node *root, int value) {
    if(root == NULL) {
        return false;
    }
    Queue queue;
    initQueue(&queue);
    enQueue(&queue, root);
    while(!isQueueEmpty(&queue)) {
        Node *temp = deQueue(&queue);
        if(temp->data == value) {
            return true;
        }
        if(temp->left != NULL) {
            enQueue(&queue, temp->left);
        }
        if(temp->right != NULL) {
            enQueue(&queue, temp->right);
        }
    }
    return false;
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