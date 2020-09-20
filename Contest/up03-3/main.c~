#include <stdio.h>
#include <math.h>

enum {ROUND = 10000};

int main(int argc, char *argv[]) {
    double result, change;
    sscanf(argv[1], "%lf", &result);
    for (int i = 2; i < argc; ++i) {
        sscanf(argv[i], "%lf", &change);
        result += result * change / 100;
        result *= ROUND;
        result = round(result);
        result /= ROUND;
    }
    printf("%.4lf\n", result);
    return 0;
}  
