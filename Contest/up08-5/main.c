#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>


int main(int argc, char *argv[]) {
    int x, status;
    pid_t pid = fork();
    if (pid == -1) {
        printf("-1");
        return 0;
    }
    if (pid > 0) {
        wait(&status);
    } else if (pid == 0) {
        while (scanf("%d", &x) == 1) {
            if (x == 0) {
                break;
            }
            pid = fork();
            if (pid > 0) {
                wait(&status);
                if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                    printf("%d\n", x);
                    exit(0);
                }
                exit(1);
            } else if (pid == -1) {
                printf("-1");
                exit(1);
            }
        }
    }
    exit(0);
}