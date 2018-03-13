// L1-037 A除以B
// Language: C

#include <stdio.h>

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);

    char b_str[10], result[10] = "Error";
    sprintf(b_str, "%d", b);
    if(b < 0){
        sprintf(b_str, "(%d)", b);
    }

    if(b != 0){
        sprintf(result, "%.2lf", a / (double)b);
    }
    printf("%d/%s=%s", a, b_str, result);

    return 0;
}
