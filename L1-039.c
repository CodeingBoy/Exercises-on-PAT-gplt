// L1-039 古风排版
// Language: C

#include <stdio.h>
#include <math.h>
#include <string.h>

#define STR_SIZE (100000 + 1)

int main(void){
    int row;
    scanf("%d", &row);
    while(getchar() != '\n')
        ;

    char input[STR_SIZE];
    fgets(input, STR_SIZE, stdin);

    int input_len = strlen(input);
    input[input_len - 1] = 0;
    input_len--;

    int col = ceil(input_len / (double)row);

    // (3, 0) => 0
    // (0, 3) => 3
    // (x, y) => row * (col - x) + y
    for(int y = 0;y < row;y++){
        for(int x = 0;x < col;x++){
            int pos = row * (col - 1 - x) + y;
            char c = ' ';
            if(pos < input_len){
                c = input[pos];
            }
            putchar(c);
        }
        putchar('\n');
    }

    return 0;
}
