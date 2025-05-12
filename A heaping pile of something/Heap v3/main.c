#include "header.h"
#define MAX_SIZE 64

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

        printf("=== min heap === \n");
        print_tree(minH);
        printf("=== max heap === \n");
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
                    printf("=== min heap ===\n");
                    print_tree(minH);
                    pause();
                minHeapUp(minH, minH->size - 1);

                //free(x[i]);
            }

            for (i = 0; i < count; i++){//inserting data values
                //printf("x[%d]: %d \n", i, x[i]);
                appendMax(maxH, x[i]);
                    printf("=== max heap ===\n");
                    print_tree(maxH);
                    pause();
                maxHeapUp(maxH, maxH->size - 1);

                //free(x[i]);
            }

            free(x);

            break;
        case 2:
            printf("=== DELETE === \n");
            deleteMin(minH);
                printf("=== min heap ===\n");
                print_tree(minH);
                pause();
            if(minH->size > 0) minHeapDown(minH, 0, minH->size);

            deleteMax(maxH);
                printf("=== max heap ===\n");
                print_tree(maxH);
                pause();
            if(maxH->size > 0) maxHeapDown(maxH, 0, maxH->size);

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
