#include "header.h"

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int min(HEAP* heap, int left, int right){
    return (heap->array[left] < heap->array[right]) ? left : right;
}

int max(HEAP* heap, int left, int right){
    return (heap->array[left] > heap->array[right]) ? left : right;
}
