#include <stdio.h>
#include <stdlib.h>

enum { MAX_N = 1999 };
int main(void) {
    int n, k = 1;
    scanf("%d", &n);
    if (n > MAX_N || n < 2) {
        return 1;
    }
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            return 1;
        }
    }
    int *b = calloc(n, sizeof(*b));
    if (b == NULL) {
        return 1;
    }
    for (int i = 1; i < n; ++i) {
        while (i * k % n != 1) {
            k++;
        }
        b[i] = k;
        k = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            printf("%d ", i * b[j] % n);
        }
        printf("\n");
    }
    free(b);
    return 0;
}
