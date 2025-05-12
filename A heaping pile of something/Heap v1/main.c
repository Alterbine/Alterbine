#include "header.h"
#define MAX_SIZE 64

int height(NODE* root){
    if(root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);

    return 1 + ((left < right) ? right : left);
}

void print_tree(NODE *root) {
    if (root == NULL) return;

    int h = height(root);
    int rows = 2 * h - 1;
    int width = (1 << (h + 2)) - 3;

    char **grid = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        grid[i] = (char *)malloc(width + 1);
        memset(grid[i], ' ', width);
        grid[i][width] = '\0';
    }

    struct queue_node {
        NODE *n;
        int depth;
        int pos;
    };

    int queue_size = 1 << h;
    struct queue_node *queue = (struct queue_node *)malloc(queue_size * sizeof(struct queue_node));
    int front = 0, rear = 0;

    int root_pos = (width - 1) / 2;
    queue[rear++] = (struct queue_node){root, 0, root_pos};

    while (front < rear) {
        struct queue_node current = queue[front++];
        NODE *n = current.n;
        int depth = current.depth;
        int pos = current.pos;

        char val_str[12];
        snprintf(val_str, sizeof(val_str), "%d", n->data);
        int val_len = strlen(val_str);

        int start_pos = pos - (val_len / 2);
        for (int i = 0; i < val_len; i++) {
            grid[2 * depth][start_pos + i] = val_str[i];
        }

        if (depth >= h - 1) continue;

        int offset = 1 << (h - depth);
        int left_pos = pos - offset;
        int right_pos = pos + offset;

        if (n->left != NULL) {
            queue[rear++] = (struct queue_node){n->left, depth + 1, left_pos};
        }
        if (n->right != NULL) {
            queue[rear++] = (struct queue_node){n->right, depth + 1, right_pos};
        }

        int line_row = 2 * depth + 1;

        if (n->left != NULL) {
            grid[line_row][left_pos] = 'v';
            for (int i = left_pos + 1; i < pos; i++) {
                grid[line_row][i] = '-';
            }
        }

        if (n->right != NULL) {
            grid[line_row][right_pos] = 'v';
            for (int i = pos + 1; i < right_pos; i++) {
                grid[line_row][i] = '-';
            }
        }

        if (n->left != NULL && n->right != NULL) {
            grid[line_row][pos] = '+';
        } else if (n->left != NULL || n->right != NULL) {
            grid[line_row][pos] = '-';
        }
    }

    for (int i = 0; i < rows; i++) {
        printf("%s\n", grid[i]);
        free(grid[i]);
    }
    free(grid);
    free(queue);
}

void printMenu(){
    printf("=== MENU === \n");
    printf("[1] APPEND NODE \n");
    printf("[2] DELETE NODE \n");
    printf("[3] SEARCH NODE \n");
    printf("[4] TRAVERSE \n");
    printf("[5] EXIT PROGRAM \n");

    printf("Choice? ");
}

int main()
{
    NODE* minH = NULL;
    NODE* maxH = NULL;
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
                printf("x[%d]: %d \n", i, x[i]);
                minH = appendMin(minH, x[i]);
            }

            free(x);

            break;
        case 2:
            printf("=== DELETE === \n");
            printf("Delete a value: ");
            scanf("%d", &key);

            //root = deleteNode(root, key);

            break;
        case 3:
            printf("=== SEARCH === \n");
            printf("Search a value: ");
            scanf("%d", &key);

            //root = searchNode(root, key);

            break;
        case 4:

            break;
        case 5:
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
