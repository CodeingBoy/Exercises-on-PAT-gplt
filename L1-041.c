// L1-041 寻找250
// Language: C

#include <stdio.h>
#include <stdbool.h>

int main(void){
    int count = 0;
    while(true){
        int num;
        scanf("%d", &num);
        
        count++;
        if(num == 250){
            printf("%d", count);
            break;
        }
    }

    return 0;
}
