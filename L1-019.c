// L1-019 谁先倒
// Language: C(C99)

#include <stdio.h>

int main(void){
    int a_chance, b_chance;
    scanf("%d %d", &a_chance, &b_chance);
    a_chance++;
    b_chance++;
    int a_hit = 0, b_hit = 0;

    int record_count;
    scanf("%d", &record_count);

    for(int i = 0;i < record_count;i++){
        int a_claim, a_act, b_claim, b_act;
        scanf("%d %d %d %d", &a_claim, &a_act, 
                &b_claim, &b_act);

        int lose_num = a_claim + b_claim;
        if(a_act == b_act && a_act == lose_num){
            continue;
        }

        if(a_act == lose_num){
#ifdef DEBUG
            printf("A get hit.\n");
#endif
            a_hit++;
            if(a_hit == a_chance){
                printf("A\n");
                printf("%d\n", b_hit);
                return 0;
            }
        }else if(b_act == lose_num){
#ifdef DEBUG
            printf("B get hit.\n");
#endif
            b_hit++;
            if(b_hit == b_chance){
                printf("B\n");
                printf("%d\n", a_hit);
                return 0;
            }
        }
    }

    return 0;
}
