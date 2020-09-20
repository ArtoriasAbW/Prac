#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fd[2], status;
    pipe(fd);
    pid_t pid1, pid2, pid3;
    pid1 = fork();
    if (pid1 == -1) {
        exit(1);
    }
    if (pid1 == 0) {
        if (dup2(fd[1], STDOUT_FILENO) < 0) {
            _exit(1);
        }
        close(fd[0]);
        close(fd[1]);
        pid2 = fork();
        if (pid2 == -1) {
            exit(1);
        }
        if (pid2 == 0) {
            int fd1 = open(argv[4], O_CREAT | O_RDONLY, 0777);
            if (dup2(fd1, STDIN_FILENO) < 0) {
                _exit(1);
            }
            execlp(argv[1], argv[1], NULL);
            _exit(1);
        } else {
            wait(&status);
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                execlp(argv[2], argv[2], NULL);
                _exit(1);
            }
            exit(0);
        }
    }
    pid3 = fork();
    if (pid3 == -1) {
        exit(1);
    }
    if (pid3 == 0) {
        close(fd[1]);
        int fd2 = open(argv[5], O_WRONLY | O_CREAT | O_APPEND, 0777);
        if (dup2(fd2, STDOUT_FILENO) < 0 || dup2(fd[0], STDIN_FILENO) < 0) {
            _exit(1);
        }
        close(fd[0]);
        execlp(argv[3], argv[3], NULL);
        _exit(1);
    }
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
    exit(0);
}