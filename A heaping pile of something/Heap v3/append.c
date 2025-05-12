#include "header.h"

void appendMin(HEAP* heap, int data){
    if (heap->size >= heap->capacity) increaseHeap(heap);

    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = data;

    //printf("min something 1 \n");

    //minHeapUp(heap, i);

    //printf("min something 2 \n");
}

void appendMax(HEAP* heap, int data){
    if (heap->size >= heap->capacity) increaseHeap(heap);

    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = data;

    //printf("max something 1 \n");

    //maxHeapUp(heap, i);

    //printf("max something 2 \n");
}
