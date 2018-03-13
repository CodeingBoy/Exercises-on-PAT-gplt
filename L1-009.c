// L1-009 N个数求和
// Langauge: C(C99)

#include <stdio.h>

long calcGCD(long a, long b){
    if(b == 0){
        return a;
    }
    long rest = a % b;
    return calcGCD(b, rest);
}

void reduction(long *a, long *b){
    long gcd = calcGCD(*a, *b);
    *a /= gcd;
    *b /= gcd;
}

long calcLCM(long a, long b){
    return a / calcGCD(a, b) * b;
}

void add(long a1, long b1, long a2, long b2,
        long *result_a, long *result_b){
    long lcm = calcLCM(b1, b2);
#ifdef DEBUG
    printf("lcm: %ld\n", lcm);
#endif
    long multiple_1 = lcm / b1, multiple_2 = lcm / b2;
    a1 *= multiple_1;
    a2 *= multiple_2;
    *result_a = a1 + a2;
    *result_b = lcm;
}

long get_integer(long *a, const long b){
    long result = *a / b;
    *a = *a % b;
    return result;
}

int main(void){
    int row_count;
    scanf("%d", &row_count);

    long integer = 0;
    long result_a = 0, result_b = 1;
    while(row_count--){
        long a, b;
        scanf("%ld/%ld", &a, &b);

        if(b == 0){
            continue;
        }

        integer += get_integer(&a, b);
        add(result_a, result_b, a, b, &result_a, &result_b);
        reduction(&result_a, &result_b);
        if(result_a == 0){
            result_b = 1;
        }
#ifdef DEBUG
        printf("Integer: %ld, ", integer);
        printf("%ld/%ld\n", result_a, result_b);
#endif
    }

    integer += get_integer(&result_a, result_b);
    reduction(&result_a, &result_b);

    if(integer != 0){
        printf("%ld", integer);
        if(result_a != 0){
            putchar(' ');
        }
    }
    if(result_a != 0){
        printf("%ld/%ld", result_a, result_b);
    }

    if(integer == 0 && result_a == 0){
        printf("0");
    }

    return 0;
}
