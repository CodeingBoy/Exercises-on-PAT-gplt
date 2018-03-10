// L1-002 打印沙漏
// Langauge: C(C99)

#include <stdio.h>

int calculate_line_count(int *symbol_count){
    int line_symbol_count = 1;
    int line_count = 0;
    *symbol_count += 1;

    while(*symbol_count >= 2 * line_symbol_count){
        *symbol_count -= 2 * line_symbol_count;
        line_count++;
        line_symbol_count += 2;
#ifdef DEBUG
        printf("line symbols: %d, line_count: %d\n", line_symbol_count, line_count);
        printf("rest symbols: %d\n", *symbol_count);
#endif
    }

    return line_count;
}

void print_line(int space_count, int symbol_count, char symbol){
    for(int i = 0;i < space_count;i++){
        putchar(' ');
    }

    while(symbol_count--){
        putchar(symbol);
    }

    /* for(int i = 0;i < space_count;i++){ */
    /*     putchar(' '); */
    /* } */

    putchar('\n');
}

void print(int line_count, const char symbol){
    int max_width = 1 + 2 * (line_count - 1);
    for(int i = 0;i < line_count;i++){
        int space_count = i, symbol_count = max_width - 2 * space_count;
        print_line(i, symbol_count, symbol);
    }

    for(int i = line_count - 2;i >= 0;i--){
        int space_count = i, symbol_count = max_width - 2 * space_count;
        print_line(i, symbol_count, symbol);
    }
}

int main(void){
    int symbol_count;
    char symbol;
    scanf("%d %c", &symbol_count, &symbol);

    int line_count = calculate_line_count(&symbol_count);

#ifdef DEBUG
    printf("line count: %d, rest symbols: %d\n", line_count, symbol_count);
#endif

    print(line_count, symbol);
    printf("%d", symbol_count);

    return 0;
}
