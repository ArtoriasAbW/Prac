#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[]) {
    pid_t pid[argc - 1];
    long long x;
    int status;
    for (int i = 0; i < argc - 1; ++i) {
        pid[i] = fork();
        if (pid[i] < 0) {
            exit(1);
        }
        if (pid[i] == 0) {
            sscanf(argv[i + 1], "%lld", &x);
            int count = 0;
            while (x > 0) {
                count += x & 1;
                x >>= 1;
            }
            exit(count);
        }
    }
    int res[argc - 1];
    for (int i = 0; i < argc- 1; ++i) {
        pid_t p = wait(&status);
        int j;
        for (j = 0; pid[j] != p; ++j);
        res[j] = WEXITSTATUS(status);
    }
    for (int i = 0; i < argc - 1; ++i) {
        printf("%d\n", res[i]);
    }
    return 0;
}