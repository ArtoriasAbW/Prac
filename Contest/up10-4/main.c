#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

enum
{
    START_SIZE = 64
};

void terminate(int size, pid_t *pids) {
    for (int j = 0; j < size; ++j) {
        kill(pids[j], SIGKILL);
    }
    while (wait(NULL) != -1) {}
    free(pids);
    exit(1);
}

int main(int argc, char *argv[]) {
    int cur_size = 0, max_size = START_SIZE, rfd = -1;
    pid_t pid;
    pid_t *pids = calloc(max_size, sizeof(*pids));
    if (pids == NULL) {
        exit(1);
    }
    for (int i = 1; i < argc; ++i) {
        int fd[2];
        if (pipe(fd) != 0) {
            terminate(cur_size, pids);
        }
        pid = fork();
        if (pid < 0) {
            terminate(cur_size, pids);
        } else if (pid > 0) {
            pids[cur_size] = pid;
            ++cur_size;
            if (cur_size >= max_size - 1) {
                max_size *= 2;
                pid_t *new = realloc(pids, max_size * sizeof(*new));
                if (new == NULL) {
                    terminate(cur_size, pids);
                }
                pids = new;
            }
            if (i != 1) {
                close(rfd);
            }
            if (i == argc - 1) {
                close(fd[0]);
            } else {
                rfd = fd[0];
            }
            close(fd[1]);
        } else {
            if (i != argc - 1) {
                if (dup2(fd[1], 1) == -1) {
                    exit(1);
                }
            }
            if (i != 1) {
                if (dup2(rfd, 0) == -1) {
                    exit(1);
                }
            }
            close(fd[0]);
            execlp(argv[i], argv[i], NULL);
            _exit(1);
        }
    }
    while (wait(NULL) != -1) {}
    free(pids);
    exit(0);
}