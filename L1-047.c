// L1-047 装睡
// Language: C

#include <stdio.h>
#include <stdbool.h>

#define INRANGE(n, min, max) (n >= min && n <= max)

int main(void){
    int count = 0;
    scanf("%d", &count);
    while(count--){
        char name[5];
        scanf("%s", name);

        int breathing_freq, beating_freq;
        scanf("%d %d", &breathing_freq, &beating_freq);

        bool breathing_ok = INRANGE(breathing_freq, 15, 20);
        bool beating_ok = INRANGE(beating_freq, 50, 70);

        if(!breathing_ok || !beating_ok){
            printf("%s\n", name);
        }
    }

    return 0;
}
