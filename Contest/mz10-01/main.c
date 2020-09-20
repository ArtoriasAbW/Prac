#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

enum { YEAR_OFFSET = 1900, NUM_OF_PROC = 3 };

int main(void) {
    int fd[2];
    if (pipe(fd) == -1) {
        exit(1);
    }
    pid_t pid;
    for (int i = 0; i < NUM_OF_PROC; ++i) {
        pid = fork();
        if (pid < 0) {
            exit(1);
        }
        if (!pid) {
            if (i == 2) { // правнук
                close(fd[0]);
                time_t t = time(NULL);
                write(fd[1], &t, sizeof(t));
                write(fd[1], &t, sizeof(t));
                write(fd[1], &t, sizeof(t));
                close(fd[1]);
                exit(0);
            }
        } else if (pid > 0) {
            wait(NULL);
            close(fd[1]);
            time_t t;
            read(fd[0], &t, sizeof(t));
            close(fd[0]);
            struct tm *tm = localtime(&t);
            if (i == 0) { // отец
                long long y = tm->tm_year + YEAR_OFFSET;
                printf("Y:%04lld\n", y);
            } else if (i == 1) { // сын
                long long m = tm->tm_mon + 1;
                printf("M:%02lld\n", m);
            } else if (i == 2) { // внук
                long long d = tm->tm_mday;
                printf("D:%02lld\n", d);
            }
            fflush(stdout);
            exit(0);
        }
    }
    exit(0);
}