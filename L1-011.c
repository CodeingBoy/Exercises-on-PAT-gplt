// L1-011 A-B
// Language: C(C99)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STR_SIZE (10000+5)

char* find_and_delete(char *str, int len, char* pattern, int pattern_len, char* result){
    int pos = 0;
    char char_pattern[2] = {0};
    for(int i = 0;i < len;i++){
        char c = str[i];
#ifdef DEBUG
        printf("%d, %c\n", c, c);
#endif
        char_pattern[0] = c;
        if(!strstr(pattern, char_pattern)){
            result[pos] = c;
            pos++;
        }
    }
    /* char mask[256+1] = {0}; */

    /* for(int i = 0;i < pattern_len;i++){ */
    /*     char c = pattern[i]; */
    /*     mask[c] = 1; */
    /* } */

    /* for(int i = 0;i < len;i++){ */
    /*     char c = str[i]; */
    /*     if(!mask[c]){ */
    /*         result[pos] = c; */
    /*         pos++; */
    /*     } */
    /* } */
    return result;
}

int main(void){
    char str_a[STR_SIZE], str_b[STR_SIZE], result[STR_SIZE];

    int kase = 1;
    while(kase--){
        if(!fgets(str_a, STR_SIZE, stdin) 
                || !fgets(str_b, STR_SIZE, stdin)){
            break;
        }
        /* gets(str_a); */
        /* gets(str_b); */
        
        int len_a = strlen(str_a), len_b = strlen(str_b);

        if(str_a[len_a - 1] == '\n'){
            str_a[len_a - 1] = 0;
            len_a--;
        }
        if(str_b[len_b - 1] == '\n'){
            str_b[len_b - 1] = 0;
            len_b--;
        }

#ifdef DEBUG
        for(int i = 0;i < len_b;i++){
            char c = str_b[i];
        printf("%d, %c\n", c, c);
        }
#endif

        memset(result, 0, sizeof(char) * STR_SIZE);
        find_and_delete(str_a, len_a, str_b, len_b, result);
        printf("%s", result);
    }

    return 0;
}
