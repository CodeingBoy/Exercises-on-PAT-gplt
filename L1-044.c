// L1-044 稳赢
// Language: C

#include <stdio.h>
#include <stdbool.h>

const char *action_enemy[] = {"ChuiZi", "JianDao", "Bu"};
const char *action_win[] = {"Bu", "ChuiZi", "JianDao"};

int main(void){
    int draw_duration;
    scanf("%d", &draw_duration);

    while(getchar() != '\n')
        ;

    int time_to_draw = draw_duration;
    while(true){
        char buffer[10];
        fgets(buffer, 10, stdin);

        if(buffer[0] == 'E'){
            break;
        }

#ifdef DEBUG
        printf("%d: ", time_to_draw);
#endif
        if(!time_to_draw){
            printf("%s", buffer);
            time_to_draw = draw_duration;
        }else{
            for(int i = 0;i < 3;i++){
                if(buffer[0] == action_enemy[i][0]){
                    printf("%s\n", action_win[i]);
                    break;
                }
            }
            time_to_draw--;
        }
    }

    return 0;
}
