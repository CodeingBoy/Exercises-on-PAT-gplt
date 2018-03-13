// L1-035 情人节
// Language: C

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STR_SIZE 10+5

int main(void){
    char bad_luck_guys[2][STR_SIZE];
    int bad_luck_pos = 0;
    int pos = 0;

    while(true){
        char buffer[STR_SIZE];
        scanf("%s", buffer);
        if(buffer[0] == '.' || pos > 14){
            break;
        }

        pos++;
        if(pos == 2 || pos == 14){
            strcpy(bad_luck_guys[bad_luck_pos], buffer);
            bad_luck_pos++;
        }
    }

    if(bad_luck_pos == 2){
        printf("%s and %s are inviting you to dinner...",
                bad_luck_guys[0], bad_luck_guys[1]);
    }else if(bad_luck_pos == 1){
        printf("%s is the only one for you...", bad_luck_guys[0]);
    }else{
        printf("Momo... No one is for you ...");
    }

    return 0;
}
