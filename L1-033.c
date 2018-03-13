// L1-033 出生年
// Language: C

#include <stdio.h>
#include <stdbool.h>

bool is_digits_unique(char *num, int unique_digits){
    bool mark[10] = {false};
    int unique_digit_count = 0;
    char *c = num;
    while(*c){
        int digit = *c - '0';
        if(!mark[digit]){
            mark[digit] = true;
            unique_digit_count++;
        }
        c++;
    }
    return unique_digit_count == unique_digits;
}

int main(void){
    int birth_year, unique_digit_count;
    scanf("%d %d", &birth_year, &unique_digit_count);

    for(int i = birth_year;i <= 9999;i++){
        char buffer[10];
        sprintf(buffer, "%04d", i);
        if(is_digits_unique(buffer, unique_digit_count)){
            printf("%d %04d", i - birth_year, i);
            break;
        }
    }

    return 0;
}
