// L1-022 奇偶分家
// Language: C(C99)

#include <stdio.h>

int main(void){
    int num_count;
    scanf("%d", &num_count);

    int odd_count = 0, even_count = 0;
    while(num_count--){
        int num;
        scanf("%d", &num);

        if(num % 2 == 0){
            even_count++;
        }else{
            odd_count++;
        }
    }
    printf("%d %d", odd_count, even_count);

    return 0;
}
