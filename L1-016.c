// L1-016 查验身份证
// Langauge: C(C99)

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int WEIGHTS[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char *M_VALUE[] = {"1", "0", "X", "9", "8", "7", "6", "5", "4", "3", "2"};

int calculate_Z_code(char *str){
    int sum = 0;
    for(int i = 0;i < 17;i++){
        sum += WEIGHTS[i] * (str[i] - '0');
    }
    sum %= 11;
    return sum;
}

int main(void){
    int kase;
    scanf("%d", &kase);

    bool all_valid = true;
    while(kase--){
        bool valid = true;
        char buffer[20];
        scanf("%s", buffer);

        for(int i = 0;i < 17;i++){
            char c = buffer[i];
            if(!isdigit(c)){
                all_valid = false;
                valid = false;
                printf("%s\n", buffer);
                break;
            }
        }
        if(!valid){
            continue;
        }

        int z_code = calculate_Z_code(buffer);
        char m_code = *M_VALUE[z_code];

        if(buffer[17] != m_code){
            all_valid = false;
            printf("%s\n", buffer);
        }
    }

    if(all_valid){
        printf("All passed\n");
    }

    return 0;
}
