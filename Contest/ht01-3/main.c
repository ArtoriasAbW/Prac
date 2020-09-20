#include<stdio.h>

enum { FLOAT_MANTISSA_BYTES = 23u };

int testFloatPresice(unsigned unum) {
    unsigned mask = (1u << (FLOAT_MANTISSA_BYTES + 1u)) - 1;
    return (unum & ~((-unum & unum) * mask)) == 0;
}

int main(void) {
    unsigned num;
    while ((scanf("%u", &num) == 1)) {
        printf("%d\n", testFloatPresice(num));
    }
    return 0;
}