#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *sep = argv[1];
    pid_t pid;
    int status, end = argc - 1;
    for (int j = argc - 1; j > 0; --j) {
        if (strcmp(sep, argv[j]) == 0) {
            for (int k = j; k < end; ++k) {
                argv[k] = argv[k + 1];
            }
            pid = fork();
            if (pid < 0) {
                exit(1);
            }
            if (pid == 0) {
                argv[end] = NULL;
                execvp(argv[j], &argv[j]);
                _exit(1);
            } else {
                wait(&status);
                if (WIFEXITED(status) == 0 || WEXITSTATUS(status)) {
                    exit(1);
                }
            }
            if (j != 1) {
                end = j - 1;
            }
        }
    }
    return 0;
}