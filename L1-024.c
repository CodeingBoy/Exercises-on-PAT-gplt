// L1-024 后天
// Language: C(C99)

#include <stdio.h>

int main(void){
    int d;
    scanf("%d", &d);

    d = (d + 2) % 7;

    printf("%d", d);

    return 0;
}
