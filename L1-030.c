// L1-030 一帮一
// Language: C(C99)

#include <stdio.h>
#include <stdbool.h>

int main(void){
    int count;
    scanf("%d", &count);

    char students_names[50][10];
    int students_gender[50];
    bool paired[50] = {false};

    for(int i = 0;i < count;i++){
        int gender;
        scanf("%d %s", &students_gender[i], students_names[i]);
    }

    int front = 0;
    while(front < count){
        if(!paired[front]){
            printf("%s ", students_names[front]);
            paired[front] = true;
            for(int j = count - 1;j >= 0;j--){
                if(paired[j]){
                    continue;
                }

                if(students_gender[front] + students_gender[j] == 1){
                    printf("%s\n", students_names[j]);
                    paired[j] = true;
                    break;
                }
            }
        }
        front++;
    }


    return 0;
}
