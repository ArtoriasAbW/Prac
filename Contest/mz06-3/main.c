#include <string.h>
#include <stdio.h>
const char template[] = "rwxrwxrwx";

enum {TEMPLATE_LEN = sizeof(template) - 1};

int parse_rwx_permissions(const char *str) {
    int res = 0;
    if (str == NULL) {
        return -1;
    }
    size_t len = strlen(str);
    if (len != TEMPLATE_LEN) {
        return -1;
    }
    for (size_t j = 0; j < len; ++ j) {
        if (str[j] == '-') {
            res <<= 1;
        } else if (str[j] == template[j]) {
            res <<= 1;
            res++;
        } else {
            return -1;
        }
    }
    return res;
}

int main(void) {
     printf("%o", parse_rwx_permissions("rwx--x--x"));
}
