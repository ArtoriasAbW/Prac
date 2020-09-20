#include <stdio.h>

int main(int argc, char *argv[]) {
    long long sum1 = 0, sum2 = 0;
    int num;
    for (int i = 1; i < argc; ++i) {
        sscanf(argv[i], "%d", &num);
        if (num > 0) {
            sum1 += num;
        } else {
            sum2 += num;
        }
    }
    printf("%lld\n%lld\n", sum1, sum2);
    return 0;
}