// L1-048 矩阵A乘以B
// Language: C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void){
    int row_a, col_a;
    scanf("%d %d", &row_a, &col_a);

    int **matrix_a = malloc(row_a * sizeof(int*));
    for(int i = 0;i < row_a;i++){
        int *row = matrix_a[i] = malloc(col_a * sizeof(int));
        for(int j = 0;j < col_a;j++){
            int num;
            scanf("%d", &num);
            row[j] = num;
        }
    }

    int row_b, col_b;
    scanf("%d %d", &row_b, &col_b);

    int **matrix_b = malloc(row_b * sizeof(int*));
    for(int i = 0;i < row_b;i++){
        int *row = matrix_b[i] = malloc(col_b * sizeof(int));
        for(int j = 0;j < col_b;j++){
            int num;
            scanf("%d", &num);
            row[j] = num;
        }
    }

    if(col_a != row_b){
        printf("Error: %d != %d\n", col_a, row_b);
    }else{
        printf("%d %d\n", row_a, col_b);
        for(int i = 0;i < row_a;i++){
            bool first = true;
            for(int j = 0;j < col_b;j++){
                int sum = 0;
                for(int k = 0;k < row_b;k++){
                    sum += matrix_a[i][k] * matrix_b[k][j];
                }
                if(!first){
                    putchar(' ');
                }
                printf("%d", sum);
                first = false;
            }
            putchar('\n');
        }
    }

    // free... I'm so lazy so I will leave it to operating system

    return 0;
}
