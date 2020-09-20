#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    long long num;
    int sum = 0;
    for (int i = 1; i < argc; ++i) {
        sscanf(argv[argc - i], "%lld", &num);
        pid_t pid = fork();
        if (pid == 0) {
            while (num) {
                sum += num & 1;
                num >>= 1;
                exit(sum);
            }
        }
    }
    return 0;
}