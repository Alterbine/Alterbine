#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

///Data Structures
typedef struct node{
    int data;
    struct node *left, *right;
    int totalNodes;
} NODE;

typedef struct queNode{
    NODE* treeNode;
    struct queNode* next;
}QUENODE;

typedef struct que{
    QUENODE* front;
    QUENODE* rear;
}QUE;

///Algorithms
//creating nodes
NODE* createNewNode(int data);
QUE* createqueue();
void enqueue(QUE* , NODE* treeNode);
NODE* dequeue(QUE* fr);
bool isEmpty(QUE* fr);

//heap tree operations
NODE* appendMin(NODE* minH, int data);
NODE* deleteMin(NODE* minH, int data);

NODE* appendMax(NODE* maxH, int data);
NODE* deleteMax(NODE* maxH, int data);

//utils
NODE* swap(NODE* a, NODE* b);
int getHeight(NODE* root);

#endif // HEADER_H_INCLUDED
