#include <stdio.h>
#include <unistd.h>
#include <wait.h>

enum { BUF_SIZE = 9 };

int main(int argc, char *argv[]) {
    char buf[BUF_SIZE];
    int stat1, stat2, stat3, x;
    pid_t pid = fork();
    if (pid < 0) {
        _exit(1);
    }
    if (!pid) {
        read(STDIN_FILENO, &buf, BUF_SIZE - 1);
        buf[8] = '\0';
        sscanf(buf, "%d", &x);
        printf("%d 1\n", x * x);
        return 0;
    } else {
        pid = fork();
        if (pid < 0) {
            _exit(1);
        }
        if (!pid) {
            read(STDIN_FILENO, &buf, BUF_SIZE - 1);
            buf[8] = '\0';
            sscanf(buf, "%d", &x);
            printf("%d 2\n", x * x);
            return 0;
        } else {
            pid = fork();
            if (pid < 0) {
                _exit(1);
            }
            if (!pid) {
                read(STDIN_FILENO, &buf,  BUF_SIZE - 1);
                buf[8] = '\0';
                sscanf(buf, "%d", &x);
                printf("%d 3\n", x * x);
                return 0;
            } else {
                wait(&stat1);
                wait(&stat2);
                wait(&stat3);
            }
        }
    }
    return 0;
}