#include <stdio.h>
#include <stdlib.h>

#include "header.h"

QUE* createqueue(){
    QUE* newque = (QUE*)malloc(sizeof(QUE));

    newque->front = NULL;
    newque->rear = NULL;

    return newque;
}

void enqueue (QUE* fr, NODE* treeNode){
    QUENODE* newNode = (QUENODE*)malloc(sizeof(QUENODE));
    newNode->treeNode = treeNode;
    newNode->next = NULL;

    if (fr->rear == NULL){
        fr->front = fr->rear = newNode;
    }else {
        fr->rear->next = newNode;
        fr->rear = newNode;
    }

    return;
}

NODE* dequeue (QUE* fr){
    if (fr->front == NULL) return;
    NODE* treeNode = fr->front->treeNode;

    //removing from queue
    QUENODE* temp = fr->front;
    fr->front = fr->front->next;
    if (fr->front == NULL){
        fr->rear = NULL;
    }
    free(temp);

    return treeNode;
}


bool isEmpty(QUE* fr) {
    return fr->front == NULL;
}
