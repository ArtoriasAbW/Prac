#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int check(char *cmd) {
    int status;
    pid_t pid = fork();
    if (pid < 0) {
        return 0;
    }
    if (!pid) {
        execlp(cmd, cmd, NULL);
        return 0;
    }
    if (pid > 0) {
        wait(&status);
        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        exit(1);
    }
    if ((check(argv[1]) || check(argv[2])) && check(argv[3])) {
        return 0;
    }
    return 1;
}