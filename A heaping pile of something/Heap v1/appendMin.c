#include "header.h"

NODE* appendMin(NODE* minH, int data){
    if (minH == NULL){
        minH = createNewNode(data);
        return minH;
    }

    if (minH->left == NULL){
        minH->left = appendMin(minH->left, data);
    }else
    if (minH->right == NULL){
        minH->right = appendMin(minH->right, data);
    }else {
        minH->left = appendMin(minH->left, data);
    }

    if (minH->left != NULL || minH->right !=NULL){
        if (minH->left != NULL){
            if (minH->data > minH->left->data) swap(minH, minH->left);
        }
        if (minH->right != NULL){
            if (minH->data > minH->right->data) swap(minH, minH->right);
        }
    }

    return minH;
}
