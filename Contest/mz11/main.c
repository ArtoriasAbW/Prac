#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <wait.h>

int main(int argc, char *argv[]) {
    int n, status, i;
    char name[PATH_MAX];
    FILE *f;
    pid_t pid;
    sscanf(argv[1], "%d", &n);
    long count = 0;
    for (i = 2; i < argc; ++i) {
        pid = fork();
        if (pid < 0) {
            exit(1);
        }
        if (pid == 0) {
            f = fopen(argv[i], "r");
            fscanf(f, "%s", name);
            fclose(f);
            execlp(name, name, NULL);
            _exit(1);
        }
        for (int k = 0; k < n; ++k) {
            wait(&status);
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                ++count;
            }
        }
    }
    for (int j = i; j < argc; ++j) {
        pid = fork();
        if (pid == 0) {
            f = fopen(argv[i], "r");
            fscanf(f, "%s", name);
            fclose(f);
            execlp(name, name, NULL);
            _exit(1);
        }
        if (pid > 0) {
            wait(NULL);
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                ++count;
            }
        }

    }
    printf("%ld\n", count);
    exit(0);
}