#include <fcntl.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int fd[2];
    if (pipe(fd) != 0) {
        exit(1);
    }
    pid_t pid1 = fork();
    if (pid1 < 0) {
        exit(1);
    }
    if (pid1 == 0) {
        if (dup2(fd[1], 1) == -1) {
            exit(1);
        }
        close(fd[1]);
        close(fd[0]);
        int fd2 = open(argv[4], O_RDONLY | O_CREAT, 0666);
        if (fd2 == -1) {
            exit(1);
        }
        if (dup2(fd2, 0) == -1) {
            exit(1);
        }
        close(fd2);
        execlp(argv[1], argv[1], NULL);
        _exit(1);
    }
    pid_t pid2 = fork();
    if (pid2 < 0) {
        exit(1);
    }
    if (pid2 == 0) {
        if (dup2(fd[0], 0) == -1) {
            exit(1);
        }
        int fd1 = open(argv[5], O_CREAT | O_APPEND | O_WRONLY, 0640);
        if (fd1 == -1) {
            exit(1);
        }
        if (dup2(fd1, 1) == -1) {
            exit(1);
        }
        close(fd[0]);
        close(fd[1]);
        close(fd1);
        pid_t pid3 = fork();
        if (pid3 < 0) {
            exit(1);
        }
        if (pid3 > 0) {
            execlp(argv[2], argv[2], NULL);
            _exit(1);
        }
        if (pid3 == 0) {
            execlp(argv[3], argv[3], NULL);
            _exit(1);
        }
    }
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);
    return 0;
}