#include "header.h"

void buffer(HEAP* heap, int index, int last, int currow, int curcol, int cell_size, int height, char **grid){
    if (index > last) return;

    int left = (2 * index) + 1;
    int right = (2 * index) + 2;

    int offset = pow(2, height - currow - 1);

    if (left <= last){
        buffer(heap, left, last, currow + 1, curcol - offset, cell_size, height, grid);
    }

    char val_str[cell_size];
    sprintf(val_str, "%d", heap->array[index]);

    int val_len = strlen(val_str);
    int start_pos = (cell_size * curcol);
    for (int i = 0; i < val_len; i++){
        grid[currow][start_pos + i] = val_str[i];
    }

    if (right <= last){
        buffer(heap, right, last, currow + 1, curcol + offset, cell_size, height, grid);
    }
}

void print_tree(HEAP* heap){
    if (heap->size < 1) return;

    char **grid = NULL;

    int height = getHeight(heap, 0, heap->size - 1);
    int row = height + 1;
    int col = pow(2, row) - 1;

    //customization
    int cell_size = 4;
    int width = cell_size * col;
    grid = (char **)malloc(row * sizeof(char *));
    for (int i = 0; i < row; i++){
        grid[i] = (char *)calloc(sizeof(char), width + 1);
        memset(grid[i], '.', width);
        grid[i][width] = '\0';
    }

    buffer(heap, 0, heap->size - 1, 0, (col - 1) / 2, cell_size, height, grid);

    for (int i = 0; i < row; i++){
        printf("%s\n", grid[i]);
        free(grid[i]);
    }
    free(grid);

    for(int i = 0; i < heap->capacity; i++){
        printf("heap->array[%d]: %d \n", i, heap->array[i]);
    }
}
