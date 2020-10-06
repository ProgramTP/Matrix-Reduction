#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX 10

void create_matrix(int matrix[MAX][MAX], int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            matrix[i][j] = 0;
        }
    }
    return;
}

void print_matrix(int matrix[MAX][MAX], int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void scale_matrix(int matrix[MAX][MAX], int scalar, int row, int col){
    for (int i = 0; i < col; i++){
        matrix[row][i] *= scalar;
    }
}

void row_swap(int matrix[MAX][MAX], int r1, int r2){
    int temp[MAX];
    int temp2[MAX];
    for (int i = 0; i < MAX; i++){
        temp[i] = matrix[r1][i];
        temp2[i] = matrix[r2][i];
    }
    for (int i = 0; i < MAX; i++){
        matrix[r1][i] = temp2[i];
        matrix[r2][i] = temp[i];
    }
}

void row_add(int matrix[MAX][MAX], int toadd, int add, int aors) {
    int mult = 1;
    if (aors == 's'){
        mult = -1;
    } 
    for (int i = 0; i < MAX; i++){
        matrix[toadd][i] += (mult)*(matrix[add][i]);
    }
}

int main(){

    int row = 0;
    int col = 0;
    int choice = 0;
    int edit_row = 0;
    int edit_col = 0;
    int valid_row = 0;
    int completed_rows = 0;
    int valid_choice_2 = 0;
    int valid_choice_3 = 0;
    int matrix[MAX][MAX];

    while(1){
        printf("Enter the rows: ");
        scanf("%d", &row);
        printf("Enter the columns: ");
        scanf("%d", &col);
        if (row <= MAX && row >= 1 && col <= MAX && col >= 1) {
            break;
        }
        else {
            printf("Invalid values. try again");
        }
    }

    create_matrix(matrix, row, col);

    while (choice != -1){
        printf("Functions\n");
        printf("1: Fill the values of your matrix\n");
        printf("2: Scalar Multiplication\n");
        printf("3: Row Swap\n");
        printf("4: Row Addition/Subtraction\n");
        printf("5: Print Matrix\n");


        printf("-1: Terminate Program\n");
        scanf("%d", &choice);
        
        if (choice == 1){
            while (completed_rows == 0){
                while (valid_row == 0){
                    printf("Pick which row you want to edit (row 0 = first row): ");
                    scanf("%d", &edit_row);
                    if (edit_row >= 0 && edit_row < row) valid_row = 1;
                    else printf("Invalid row. Try again.\n");
                }
                for (int i = 0; i < col; i++){
                    printf("Enter value for row: %d, col: %d - ", edit_row, i);
                    scanf("%d", &edit_col);
                    matrix[edit_row][i] = edit_col;
                }
                printf("Enter 1 if you are done editing all your rows and 0 if you are still editing: ");
                scanf("%d", &completed_rows);
                if (completed_rows != 1) valid_row = 0;
            }
        }
        completed_rows = 0;
        valid_row = 0;
            
        if (choice == 2){
            int scalar;
            int row_choice;
            while(valid_choice_2 == 0){
                printf("Pick which row you wish to scale. (row 0 = first row): ");
                scanf("%d", &row_choice);
                if (row_choice >= 0 && row_choice < row) valid_choice_2 = 1;
                else printf("Invalid row. Try again.\n");
            }
            printf("Pick a scalar: ");
            scanf("%d", &scalar);
            scale_matrix(matrix, scalar, row_choice, col);
        }
        valid_choice_2 = 0;

        if (choice == 3){
            int row_choice1;
            int row_choice2;
            while(valid_choice_3 == 0){
                printf("Pick the first row you wish to swap (row 0 = first row): ");
                scanf("%d", &row_choice1);
                if (row_choice1 >= 0 && row_choice1 < row) valid_choice_3 = 1;
                else printf("Invalid row. Try again\n");
            }
            valid_choice_3 = 0;
            while(valid_choice_3 == 0){
                printf("Pick the second row you wish to swap (row 0 = first row): ");
                scanf("%d", &row_choice2);
                if (row_choice2 >= 0 && row_choice2 < row) valid_choice_3 = 1;
                else printf("Invalid row. Try again\n");
            }
            row_swap(matrix, row_choice1, row_choice2);
        }

        if (choice == 4){
            int toadd;
            int add;
            char aors;
            while(1){
                printf("Press a to add or s to subtract");
                scanf("%c", &aors);
                if (aors == 'a' || aors == 's'){
                    break;
                }
                printf("Pick a or s please");
                
            }
            printf("Pick which row you would like to be the target: "); 
            scanf("%d", &toadd);
            printf("Pick which row you would like to modify to the target row: ");
            scanf("%d", &add);
            row_add(matrix, toadd, add, aors);

        }
        
        if (choice == 5){
            printf("___________________________\n");
            printf("\n");
            print_matrix(matrix, row, col);
            printf("___________________________\n");
        }
        
        if (choice == -1){
            return 0;
        }
    }

}
