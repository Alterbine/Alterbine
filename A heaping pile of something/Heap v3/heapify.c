#include "header.h"
///if conditional operator dont work -.-
    /*int parent;
    if (index % 2){//index is a left subtree
        parent = (index - 1) / 2;
    }else {//index is a right subtree
        parent = (index - 2) / 2;
    }*/

void minHeapUp(HEAP* heap, int index){
    int parent = (index % 2) ? (index - 1) / 2 : (index - 2) / 2;
    if (parent < 0) return;

    if (heap->array[index] < heap->array[parent]){
        swap(&heap->array[index], &heap->array[parent]);
        printf("=== min heap ===\n");
        printf("heaping in progress... \n");
        print_tree(heap);
        pause();
        minHeapUp(heap, parent);
    }

    return;
}

void minHeapDown(HEAP* heap, int index, int last){
    int left = (2 * index) + 1;
    if (left <= last){
        int small = left;

        int right = (2 * index) + 2;
        if (right <= last) small = min(heap, left, right);

        if (heap->array[small] < heap->array[index]){
            swap(&heap->array[small], &heap->array[index]);
            printf("=== min heap ===\n");
            printf("heaping in progress... \n");
            print_tree(heap);
            pause();
            minHeapDown(heap, small, last);
        }
    }

    return;
}

void maxHeapUp(HEAP* heap, int index){
    int parent = (index % 2) ? (index - 1) / 2 : (index - 2) / 2;
    if (parent < 0) return;

    if (heap->array[index] > heap->array[parent]){
        swap(&heap->array[index], &heap->array[parent]);
        printf("=== max heap ===\n");
        printf("heaping in progress... \n");
        print_tree(heap);
        pause();
        maxHeapUp(heap, parent);
    }

    return;
}

void maxHeapDown(HEAP* heap, int index, int last){
    int left = (2 * index) + 1;
    if (left <= last){
        int large = left;

        int right = (2 * index) + 2;
        if (right <= last) large = max(heap, left, right);

        if (heap->array[large] > heap->array[index]){
            swap(&heap->array[large], &heap->array[index]);
            printf("=== max heap ===\n");
            printf("heaping in progress... \n");
            print_tree(heap);
            pause();
            maxHeapDown(heap, large, last);
        }
    }

    return;
}

