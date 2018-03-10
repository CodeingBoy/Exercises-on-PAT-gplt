// L1-003 个位数统计
// Language: C(C99)

#include <stdio.h>

int main(void){
    int digits[10] = {0};

    char c;
    while((c = getchar()) != EOF){
        int index = c - '0';
        digits[index]++;
    }

    for(int i = 0;i < 10;i++){
        if(digits[i] != 0){
            printf("%d:%d\n", i, digits[i]);
        }
    }

    return 0;
}
