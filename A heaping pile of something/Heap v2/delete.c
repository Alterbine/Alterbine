#include "header.h"

void deleteMin(HEAP* heap){
    if (heap->size <= 0){
        printf("heap is empty \n");\
    }else
    if (heap->size == 1){
        heap->size--;
        printf("heap emptied... \n");
    }else {
        heap->array[0] = heap->array[heap->size - 1];
        heap->size--;
        minHeapDown(heap, 0, heap->size);
    }

    return;
}

void deleteMax(HEAP* heap){
    if (heap->size <= 0){
        printf("heap is empty \n");\
    }else
    if (heap->size == 1){
        heap->size--;
        printf("heap emptied... \n");
    }else {
        heap->array[0] = heap->array[heap->size - 1];
        heap->size--;
        maxHeapDown(heap, 0, heap->size);
    }

    return;
}
