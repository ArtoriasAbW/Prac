#include <stdio.h>
#include <string.h>
#include <limits.h>

enum
{
    NUMBER_OF_DIGITS = 10,
    SIZE_BUF = 4096
};

int main(void) {
    char buf[SIZE_BUF];
    unsigned long long digits[NUMBER_OF_DIGITS];
    memset(digits, 0, NUMBER_OF_DIGITS * sizeof(*digits));
    char name[PATH_MAX];
    char *flag = fgets(name, sizeof(name), stdin);
    if (flag != NULL) {
        size_t name_len = strlen(name);
        if (name_len > 2 && name[name_len - 2] == '\r') {
            name[name_len - 2] = '\0';
        } else if (name[name_len - 1] == '\n' || name[name_len - 1] == '\r') {
            name[name_len - 1] = '\0';
        }
        FILE *f = fopen(name, "r");
        if (f != NULL) {
            while ((fgets(buf, sizeof(buf), f)) != NULL) {
                size_t buf_len = strlen(buf);
                for (size_t i = 0; i < buf_len; ++i) {
                    if (buf[i] >= '0' && buf[i] <= '9') {
                        digits[buf[i] - '0']++;
                    }
                }
            }
            fclose(f);
        }
    }
    for (int i = 0; i < NUMBER_OF_DIGITS; ++i) {
        printf("%d %llu\n", i, digits[i]);
    }
    return 0;
}