#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void) {
    uint32_t n;
    int32_t w;
    int32_t sign = 1;
    scanf("%"PRIo32"%"PRIo32, &n, &w);
    uint32_t e = 1u << n;
    for (uint32_t i = 0; i < e; ++i) {
        if (i > e >> 1u) {
            sign = -1;
        }
        printf("|%*"PRIo32"|%*" PRIu32"|%*"PRId32"|\n", (int) w, i, (int) w, i, (int) w, sign * (i % (e >> 1u)));
    }
    return 0;
}