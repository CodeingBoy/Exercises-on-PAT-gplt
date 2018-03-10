// L1-007 念数字
// Language: C(C99)

#include <stdio.h>
#include <string.h>

const char *PINYINS[] = {
    "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};

const char* NEGATIVE_PINYIN = "fu";

void print_pinyin(char digit){
    char pos = digit - '0';
    printf("%s", PINYINS[pos]);
}

int main(void){
    int num;
    while(scanf("%d", &num) != EOF){
        if(num < 0){
            printf("%s ", NEGATIVE_PINYIN);
            num = -num;
        }

        char buffer[100] = {0};
        sprintf(buffer, "%d", num);
        
        int len = strlen(buffer);
        for(int i = 0;i < len;i++){
            if(i != 0){
                putchar(' ');
            }
            print_pinyin(buffer[i]);
        }
        putchar('\n');
    }

    return 0;
}
