// L1-031 到底是不是太胖了
// Language: C(C99)

#include <stdio.h>

int main(void){
    int kase;
    scanf("%d", &kase);
    while(kase--){
        int height, weight;
        scanf("%d %d", &height, &weight);

        double standard_weight = (height - 100) * 0.9;
        standard_weight *= 2;

        double min = standard_weight * 0.9, max = standard_weight * 1.1;
        min *= 100;
        max *= 100;
        weight *= 100;
#ifdef DEBUG
        printf("standard: %lf, ", standard_weight);
        printf("min: %lf, max: %lf, weight: %d\n", min, max, weight);
#endif
        if(weight <= (int)min){
            printf("You are tai shou le!\n");
        }else if(weight >= (int)max){
            printf("You are tai pang le!\n");
        }else{
            printf("You are wan mei!\n");
        }
        // No chinglish, thanks!
    }

    return 0;
}
