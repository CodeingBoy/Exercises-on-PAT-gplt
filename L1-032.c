// L1-032 Left-pad
// Language: C

#include <stdio.h>
#include <string.h>

int main(void){
    int expected_len;
    char pad_char;
    char input[100000+1];
    char *output = input;

    scanf("%d", &expected_len);
    getchar();
    pad_char = getchar();
    while(getchar() != '\n')
        ;
    fgets(input, 100000+1, stdin);

    int cur_len = strlen(input) - 1; // \n

    if(expected_len < cur_len){
        output = input + cur_len - expected_len;
    }
    int pad_len = expected_len - cur_len;
#ifdef DEBUG
    printf("%d, %d\n", cur_len, pad_len);
#endif
    while(pad_len-- > 0){
        putchar(pad_char);
    }
    printf("%s", output);

    return 0;
}
