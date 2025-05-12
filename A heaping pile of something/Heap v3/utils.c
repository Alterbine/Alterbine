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

int getHeight(HEAP* heap, int index, int last){
    int left = (2 * index) + 1;
    if (left > last) return 0;

    return 1 + getHeight(heap, left, last);
}

void pause(){
    printf("\npress space to continue... \n");
    int c;
    do{
        c = getch();
    }while(c != 32);
    system("cls");
    return;
}
