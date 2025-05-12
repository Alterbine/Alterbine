#include "header.h"

HEAP* createHeap(){
    HEAP* heap = (HEAP*)malloc(sizeof(HEAP));
    heap->size = 0;
    heap->capacity = 16;
    heap->array = (int*)calloc(sizeof(int), heap->capacity);

    return heap;
}

HEAP* increaseHeap(HEAP* heap){
    heap->capacity = heap->capacity + 16;
    heap->array = (int*)realloc(heap->array, heap->capacity * sizeof(int));

    return heap;
}
