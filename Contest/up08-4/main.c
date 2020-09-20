#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[]) {
    unsigned n;
    scanf("%u", &n);
    for (unsigned j = 0; j < n; ++j) {
        printf("%u", j + 1);
        if (j == n - 1) {
            printf("\n");
            break;
        } else {
            printf(" ");
            fflush(stdout);
        }
        pid_t pid = fork();
        if (pid == -1) {
            _exit(1);
        }
        if (pid > 0) {
            wait(NULL);
            break;
        }
    }
    return 0;
}