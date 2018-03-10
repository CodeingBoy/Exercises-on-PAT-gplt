// L1-008 求整数段和
// Language: C(C99)

#include <stdio.h>

int main(void){
    int start, end;
    while(scanf("%d %d", &start, &end) == 2){
        int cur = start, pos = 0, sum = 0;
        while(cur <= end){
            sum += cur;
            pos++;

            printf("%5d", cur);

            if(pos % 5 == 0){
                putchar('\n');
            }

            cur++;
        }
        if(pos % 5 != 0){
            putchar('\n');
        }
        printf("Sum = %d\n", sum);
    }

    return 0;
}
