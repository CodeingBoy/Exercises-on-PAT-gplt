// L1-040 最佳情侣身高查
// Language: C

#include <stdio.h>

int main(void){
    int query_count;
    scanf("%d", &query_count);

    while(query_count--){
        while(getchar() != '\n')
            ;

        double height, result = 0;
        char gender = getchar();
        scanf("%lf", &height);

        if(gender == 'M'){
            result = height / 1.09;
        }else{
            result = height * 1.09;
        }
        printf("%.2lf\n", result);
    }

    return 0;
}
