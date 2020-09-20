#include <stdio.h>
#include <string.h>

const char template[] = "rwxrwxrwx";

enum { TEMPLATE_LEN = sizeof(template) - 1 };

int main(int argc, char* argv[]) {
    int x;
    char output[TEMPLATE_LEN + 1];
    output[TEMPLATE_LEN] = '\0';
    unsigned mask;
    for (int i = 1; i < argc; ++i) {
        sscanf(argv[i], "%o", &x);
        mask = 1u << (TEMPLATE_LEN - 1);
        for (size_t k = 0; k < TEMPLATE_LEN; ++k) {
            if (mask & x) {
                output[k] = template[k];
            } else {
                output[k] = '-';
            }
            mask >>= 1u;
        }
        printf("%9s\n", output);
    }
    return 0;
}