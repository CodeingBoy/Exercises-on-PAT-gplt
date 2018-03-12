// L1-026 I Love GPLT
// Language: C(C99)

#include <stdio.h>

const char output[] = "I Love GPLT";

void print(const char c){
    putchar(c);
    putchar('\n');
}

int main(void){
    const char *c = output;
    while(*c != '\0'){
        print(*c);
        c++;
    }

    return 0;
}
