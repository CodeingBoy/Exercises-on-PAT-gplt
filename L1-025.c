// L1-025 正整数A+B
// Language: C(C99)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define STR_SIZE (10000 + 5)
#define CONDITION_INRANGE(n) (n >= 1 && n <= 1000)

int is_valid_integer(char *buffer){
    char *c = buffer;
    while(*c != '\0'){
        if(!isdigit(*c)){
            return -1;
        }
        c++;
    }
    int result = atoi(buffer);
    if(!CONDITION_INRANGE(result)){
        return -1;
    }
    return result;
}

int main(void){
    char buffer_a[STR_SIZE], buffer_b[STR_SIZE];
    scanf("%s", buffer_a);
    getchar();
    fgets(buffer_b, STR_SIZE, stdin);
    buffer_b[strlen(buffer_b) - 1] = 0;

    int int_a = is_valid_integer(buffer_a),
        int_b = is_valid_integer(buffer_b);

    char operand_a[STR_SIZE] = "?",
         operand_b[STR_SIZE] = "?", 
         result[STR_SIZE] = "?";

    if(int_a != -1){
        sprintf(operand_a, "%d", int_a);
    }
    if(int_b != -1){
        sprintf(operand_b, "%d", int_b);
    }

    if(int_a != -1 && int_b != -1){
        int int_result = int_a + int_b;
        sprintf(result, "%d", int_result);
    }

    printf("%s + %s = %s", operand_a, operand_b, result);

    return 0;
}
