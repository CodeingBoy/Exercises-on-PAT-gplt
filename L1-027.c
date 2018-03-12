// L1-027 出租
// Language: C(C99)

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int find_pos(int *dict, int num){
    int pos = 0;
    for(int i = 9;i >= 0;i--){
        if(i == num){
            return pos;
        }
        if(dict[i] > 0){
            pos++;
        }
    }
    return -1;
}

int main(void){
    char tel[15];
    scanf("%s", tel);

    // generate dict
    int dict[10] = {0};
    char *c = tel;
    while(*c){
        dict[*c - '0']++;
        c++;
    }

    // generate index
    int *pos = malloc(sizeof(int) * strlen(tel));

    c = tel;
    int *cur_element = pos;
    while(*c){
        *cur_element = find_pos(dict, *c - '0');
        cur_element++;
        c++;
    }

    // output array code for dict
    bool first = true;

    printf("int[] arr = new int[]{");
    for(int i = 9;i >= 0;i--){
        if(dict[i] > 0){
            if(!first){
                putchar(',');
            }
            putchar(i + '0');
            first = false;
        }
    }
    printf("};\n");

    // output array code for index
    first = true;
    printf("int[] index = new int[]{");
    for(int i = 0;i < strlen(tel);i++){
        if(!first){
            putchar(',');
        }
        putchar(pos[i] + '0');
        first = false;
    }
    printf("};\n");

    free(pos); // Hey, Java! System.gc();
    // That's why we love (and hate) Java?

    return 0;
}
