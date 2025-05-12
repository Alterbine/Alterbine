#include "header.h"

NODE* swap(NODE* a, NODE* b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
    return a;
}

int totalNodes(NODE* root){
    if (root == NULL) return 0;

    QUE *fr = createqueue();
    enqueue(fr, root);
    int count = 0;

    while (!isEmpty(fr)){
        NODE* current = dequeue(fr);

        //visits node first
        printf ("%d ", current->data);
        //enqueue left child
        if (current->left != NULL) enqueue(fr, current->left);
        //enqueue right child
        if (current->right != NULL) enqueue(fr, current->right);
        count++;
    }

    return count;
}
