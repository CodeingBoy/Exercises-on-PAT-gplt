// L1-012 计算指数
// Language: C(C99)

#include <stdio.h>
#include <math.h>

int main(void){
    int n;
    while(scanf("%d", &n) != EOF){
        printf("2^%d = %d\n", n, (int)pow(2, n));
    }

    return 0;
}
