#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int mysys(const char *str) {
    int status;
    pid_t pid = fork();
    if (pid == -1) {
        return -1;
    }
    if (!pid) {
        execl("/bin/sh", "sh", "-c", str, NULL);
        _exit(127);
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else if (WIFSIGNALED(status)) {
            return WTERMSIG(status) + 128;
        }
    }
    return 0;
}