// L1-042 日期格式化
// Language: C

#include <stdio.h>

int main(void){
    int year, month, day;
    scanf("%d-%d-%d", &month, &day, &year);

    printf("%4d-%02d-%02d", year, month, day);

    return 0;
}
