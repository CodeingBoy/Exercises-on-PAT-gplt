// L1-013 计算阶乘和
// Language: C(C99)

#include <stdio.h>

int factorials[11] = {0, 1};

int calc_factorial(int n){
    if(n == 0){
        return 0;
    }
    if(factorials[n] != 0){
        return factorials[n];
    }
    return factorials[n] = calc_factorial(n - 1) * n;
}

int calc_factorial_sum(int n){
    int sum = 0;
    for(int i = 1;i <= n;i++){
        sum += calc_factorial(i);
#ifdef DEBUG
        printf("sum: %d\n", sum);
#endif
    }
    return sum;
}

int main(void){
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n", calc_factorial_sum(n));
#ifdef DEBUG
        for(int i = 0;i < 11;i++){
            printf("%d, ", factorials[i]);
        }
        putchar('\n');
#endif
    }

    return 0;
}
