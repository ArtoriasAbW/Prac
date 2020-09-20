#include <stdio.h>
#include <limits.h>

struct RoundResult
{
    long long value;
    int status;
};
struct RoundResult iround(long long value, int prec){
    long long mod = 1, sign = 1;
    if (value < 0) {
        sign = -1;
    }
    for (int i = 0; i < prec; ++i) {
        mod *= 10;
    }
    struct RoundResult u;
    u.status = 0;
    if ((value % mod + mod) % mod >= mod / 2) { // round to +-inf
        if (sign > 0 && (LLONG_MAX - mod + (value % mod + mod) % mod) < value) { // positive overflow
            u.status = 1;
            u.value = 0;
        } else {
            u.value = mod - (value % mod + mod) % mod + value;
        }
    } else { // round to 0
        if (sign < 0 && (LLONG_MIN + (value % mod + mod) % mod > value)) { // negative overflow
            u.status = -1;
            u.value = 0;
        } else {
            u.value = value - (value % mod + mod) % mod;
        }
    }
    return u;
}

int main() {
    struct RoundResult u = iround(670, 3);
    printf("%lld %d\n", u.value, u.status);
    return 0;
}