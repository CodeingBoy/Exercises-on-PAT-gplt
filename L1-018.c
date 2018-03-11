// L1-018 大笨钟
// Language: C(C99)

#include <stdio.h>

#define DANG "Dang"

int main(void){
    int hour, minute;
    scanf("%d:%d", &hour, &minute);

    if(hour <= 12){
        printf("Only %02d:%02d.  Too early to Dang.", hour, minute);
        return 0;
    }

    if(minute != 0){
        hour++;
    }

    hour -= 12;
    for(int i = 0;i < hour;i++){
        printf("%s", DANG);
    }

    return 0;
}
