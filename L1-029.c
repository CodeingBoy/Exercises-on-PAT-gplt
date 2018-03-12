// L1-029 是不是太胖了
// Language: C(C99)

#include <stdio.h>

int main(void){
    int height;
    scanf("%d", &height);

    double standard_weight = (height - 100) * 0.9;
    standard_weight *= 2;

    printf("%.1f", standard_weight);

    return 0;
}
