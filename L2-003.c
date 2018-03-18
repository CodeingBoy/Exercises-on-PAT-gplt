// L2-003 月饼
// Language: C

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
    int kind_count, need_count;
    scanf("%d %d", &kind_count, &need_count);

    int stocks[kind_count];
    int prices[kind_count];
    double unit_prices[kind_count];
    bool sold[kind_count];
    memset(sold, 0, sizeof(sold));
    for(int i = 0;i < kind_count;i++){
        scanf("%d", stocks + i);
    }
    for(int i = 0;i < kind_count;i++){
        scanf("%d", prices + i);
        unit_prices[i] = (double)prices[i] / stocks[i];
    }
#ifdef DEBUG
    printf("Unit prices: ");
    for(int i = 0;i < kind_count;i++){
        printf("%lf ", unit_prices[i]);
    }
    putchar('\n');
#endif

    double total_income = 0;
    int total_saled_stock = 0;
    while(total_saled_stock < need_count){
        double max_unit_prices = 0;
        int max_index = -1;
        for(int i = 0;i < kind_count;i++){
            if(!sold[i]){
                if(unit_prices[i] > max_unit_prices){
                    max_unit_prices = unit_prices[i];
                    max_index = i;
                }
            }
        }
#ifdef DEBUG
        printf("max_index: %d\n", max_index);
#endif

        if(max_index == -1){ // all sold
            break;
        }

        sold[max_index] = true;
        if(total_saled_stock + stocks[max_index] <= need_count){
            total_saled_stock += stocks[max_index];
            total_income += prices[max_index];
        }else{
            int actual_need_stock = need_count - total_saled_stock;
            total_income += actual_need_stock * unit_prices[max_index];
            total_saled_stock = need_count;
        }
    }

    printf("%.2f", total_income);

    return 0;
}
