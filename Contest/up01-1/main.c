#include <stdio.h>
#include <limits.h>


long long absolute(long long x) {
    if (x >= 0) {
        return x;
    } else {
        return -x;
    }
}

int main(void) {
    long long a, b, c;
    scanf("%lld%lld", &a, &b);
    c = a % b;
    if (c > 0) {
        if (c >= b - c && a - c + b <= INT_MAX) {
            a = a - c + b;
        } else {
            a -= c;
        }
    } else if (c <= 0) {
        if (absolute(c) > absolute(b + c) && a - b - c > INT_MIN && a - b - c < INT_MAX) {
            a = a - b - c;
        } else {
            a -= c;
        }
    }
    printf("%lld\n", a);
    return 0;
}