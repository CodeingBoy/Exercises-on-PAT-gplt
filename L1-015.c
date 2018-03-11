// L1-015 跟奥巴马一起画方块
// Language: C(C99)

#include <stdio.h>
#include <math.h>

int main(void){
    int col;
    char symbol;
    scanf("%d %c", &col, &symbol);

    int row = (int)round(col / 2.0);

    while(row--){
        for(int i = 0;i < col;i++){
            putchar(symbol);
        }
        putchar('\n');
    }

    return 0;
}
