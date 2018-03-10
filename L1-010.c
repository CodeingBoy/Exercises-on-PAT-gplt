// L1-010 比较大小
// Language: C(C99)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int comp(const void *pnum1, const void *pnum2){
    int num1 = *((int*)pnum1), num2 = *((int*)pnum2);
    return num1 - num2;
}

int main(void){
    while(true){
        int nums[3];
        for(int i = 0;i < 3;i++){
            int j = scanf("%d", &nums[i]);
            if(j == EOF){
                return 0;
            }
        }

        qsort(nums, 3, sizeof(int), comp);

        printf("%d->%d->%d\n", nums[0], nums[1], nums[2]);
    }

    return 0;
}
