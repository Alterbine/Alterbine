#include "header.h"

NODE* createNewNode(int data){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->totalNodes = 0;

    return newNode;
}
