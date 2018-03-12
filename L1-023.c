// L1-023 输出GPLT
// Language: C(C99)

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool has_chars(int chars_count[]){
    return chars_count[0] > 0 || chars_count[1] > 0
        || chars_count[2] > 0 || chars_count[3] > 0;
}

int main(void){
    char buffer[10000+5];
    /* scanf("%s", buffer); */
    fgets(buffer, 10000+5, stdin);

    const char chars[] = {'G', 'P', 'L', 'T'};
    int chars_count[4] = {0};
    char *c = buffer;
    while(*c != '\0'){
        char upper_char = toupper(*c);
        for(int i = 0;i < 4;i++){
            if(chars[i] == upper_char){
                chars_count[i]++;
                break;
            }
        }
        c++;
    }

    while(has_chars(chars_count)){
        for(int i = 0;i < 4;i++){
            if(chars_count[i] < 1){
                continue;
            }
            putchar(chars[i]);
            chars_count[i]--;
        }
    }

    return 0;
}
