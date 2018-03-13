// L1-028 判断素数
// Language: C(C99)

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int num){
    if(num <= 1){
        return false;
    }
    int end = sqrt(num) + 0.5;
    for(int i = 2; i < end;i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int main(void){
    int num_count;
    scanf("%d", &num_count);

    while(num_count--){
        int num;
        scanf("%d", &num);
        if(is_prime(num)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }

    return 0;
}
