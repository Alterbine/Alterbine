#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

///Data Structures
typedef struct heap{
    int *array;
    int size;
    int capacity;
} HEAP;

///Algorithms
//heap things
HEAP* createHeap();
HEAP* increaseHeap(HEAP* heap);

//printing tree
void buffer(HEAP* heap, int index, int last, int currow, int curcol, int cell_size, int height, char **grid);
void print_tree(HEAP* heap);

//heap tree operations
void appendMin(HEAP* heap, int data);
void deleteMin(HEAP* heap);

void appendMax(HEAP* heap, int data);
void deleteMax(HEAP* heap);

//heapify
void minHeapUp(HEAP* heap, int index);
void minHeapDown(HEAP* heap, int index, int last);

void maxHeapUp(HEAP* heap, int index);
void maxHeapDown(HEAP* heap, int index, int last);

//utils
void swap(int *x, int *y);
int min(HEAP* heap, int left, int right);
int max(HEAP* heap, int left, int right);
int getHeight(HEAP* heap, int index, int last);
void pause();

#endif // HEADER_H_INCLUDED
