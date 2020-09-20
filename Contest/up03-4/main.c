#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

enum
{
    SIZE_BUF = 16,
    DEC = 10
};

int main(void) {
    char buf[SIZE_BUF], sign = 0;
    ssize_t rv;
    unsigned long long sum = 0, num = 0;
    while ((rv = read(STDIN_FILENO, &buf, sizeof(buf)))) {
        if (rv == -1) {
            return 1;
        }
        for (ssize_t i = 0; i < rv; ++i) {
            if (buf[i] == '-') {
                sign = 1;
            } else if (buf[i] == '+') {
                sign = 0;
            } else if (isspace((unsigned char) buf[i])) {
                if (sign) {
                    sum -= num;
                } else {
                    sum += num;
                }
                sign = 0;
                num = 0;
            } else {
                num = num * DEC + (buf[i] - '0');
            }
        }
    }
    printf("%lld\n", (long long) sum);
    return 0;
}
