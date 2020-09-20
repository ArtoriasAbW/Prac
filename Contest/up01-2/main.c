#include <stdio.h>

int main(void) {
    int c, length = 0, max_length = 0;
    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z' && c != 'q') {
            length++;
        } else if (c == 'q') {
            length = 0;
            c = getchar();
            while (c >= 'a' && c <= 'z') {
                c = getchar();
            }
        } else {
            if (length > max_length) {
                max_length = length;
            }
            length = 0;
        }
    }
    if (length > max_length) {
        max_length = length;
    }
    printf("%d\n", max_length);
    return 0;
}