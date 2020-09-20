#include <stdint.h>

int32_t satsum(int32_t v1, int32_t v2) {
    int32_t res;
    uint32_t maxbit = 1, t = 0;
    if (__builtin_add_overflow(v1, v2, &res)) {
        while (maxbit) {
            t = maxbit;
            maxbit <<= 1u;
        }
        maxbit = t;
        if (v1 > 0 && v2 > 0) {
            return (int32_t) (~maxbit);
        } else {
            return (int32_t) maxbit;
        }
    }
    return res;
}
