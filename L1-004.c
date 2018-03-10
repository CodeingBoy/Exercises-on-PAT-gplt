// L1-004 计算摄氏温度
// Langauge: C(C99)

#include <stdio.h>

int main(void){
    double fahrenheit, celsius;
    while(scanf("%lf", &fahrenheit) == 1){
        celsius = 5 * (fahrenheit - 32) / 9;
        printf("Celsius = %d\n", (int)celsius);
    }

    return 0;
}
