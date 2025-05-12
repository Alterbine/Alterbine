#include "header.h"
#define MAX_SIZE 64

int getHeight(HEAP* heap, int index, int last){
    int left = (2 * index) + 1;
    if (left > last) return 0;

    return 1 + getHeight(heap, left, last);
}

void buffer(HEAP* heap, int index, int last, int currow, int curcol, int cell_size, int height, char **grid){
    if (index > last) return;

    int left = (2 * index) + 1;
    int right = (2 * index) + 2;

    int offset = pow(2, height - currow - 1);

    if (left <= last){
        buffer(heap, left, last, currow + 1, curcol - offset, cell_size, height, grid);
    }

    char val_str[cell_size];
    sprintf(val_str, "%3d", heap->array[index]);

    int val_len = strlen(val_str);
    int start_pos = (cell_size * curcol) - (val_len / 2);
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
    int cell_size = 3;
    int width = cell_size * col;

    grid = (char **)malloc(row * sizeof(char *));
    for (int i = 0; i < row; i++){
        grid[i] = (char *)malloc(width + 1);
        memset(grid[i], ' ', width);
        grid[i][width] = '\0';
    }

    buffer(heap, 0, heap->size - 1, 0, (col - 1) / 2, cell_size, height, grid);

    for (int i = 0; i < row; i++){
        printf("%s\n", grid[i]);
        free(grid[i]);
    }
    free(grid);
}

void printMenu(){
    printf("=== MENU === \n");
    printf("[1] APPEND NODE \n");
    printf("[2] DELETE NODE \n");
    printf("[3] EXIT PROGRAM \n");

    printf("Choice? ");
}

int main()
{
    HEAP* minH = createHeap();
    HEAP* maxH = createHeap();
    int choice, key;

    do{
        int size = 10, count = 0, i = 0;
        int *x;

        char input[MAX_SIZE] = {'\0'};

        const char* result;
        int position;

        const char delimiter[] = ", ";
        char* token;

        print_tree(minH);
        print_tree(maxH);
        printMenu();
        scanf(" %d", &choice);

        switch(choice){
        case 1:
            x = calloc(size, sizeof(int));
            printf("=== APPEND === \n");
            printf("Add values: ");
            gets(input);
            gets(input);

            result = strchr(input, '!');
            position = result - input;
            if (result != NULL) strncpy(input, input, position);

            token = strtok(input, delimiter);
            while (token != 0){
                if (count >= size){
                    x = realloc(x, sizeof(int) * (++size));
                    continue;
                }
                x[i++] = atoi(token);
                token = strtok(0, delimiter);
                count++;
            }

            for (i = 0; i < count; i++){//inserting data values
                //printf("x[%d]: %d \n", i, x[i]);
                appendMin(minH, x[i]);
                appendMax(maxH, x[i]);
                //free(x[i]);
            }

            free(x);

            break;
        case 2:
            printf("=== DELETE === \n");
            deleteMin(minH);
            deleteMax(maxH);

            break;
        case 3:
            printf("exiting program... \n");

            break;
        default:
            printf("invalid input... \n");

            getch();
            system("cls");

            break;
        }

    }while(choice != 5);
}
