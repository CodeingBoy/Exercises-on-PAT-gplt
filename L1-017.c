// L1-017 到底有多二
// Language: C(C99)

#include <stdio.h>
#include <string.h>

int count_2(char *str){
    int count = 0;
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == '2'){
            count++;
        }
        i++;
    }
    return count;
}

int main(void){
    char buffer[50 + 5];
    scanf("%s", buffer);

    int len = strlen(buffer), last = len;
    double negative_index = 1;
    if(buffer[0] == '-'){
        negative_index = 1.5;
        len--;
    }
    double two_ratio = count_2(buffer) / (double)len;
    two_ratio *= negative_index;

    if((buffer[last - 1] - '0') % 2 == 0){
        two_ratio *= 2;
    }
    two_ratio *= 100;
    printf("%.2f%%\n", two_ratio);

    return 0;
}
