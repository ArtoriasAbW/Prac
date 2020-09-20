#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>
#include <stdlib.h>

volatile sig_atomic_t flag;

void handler(int signal) {
    flag = 1;
}

void read_and_write(int num_of_proc, int maxval, int fd[2], sigset_t *ss)  {
    int x = 0;
    FILE *fr = fdopen(fd[0], "r");
    FILE *fw = fdopen(fd[1], "w");
    setbuf(stdout, NULL);
    setbuf(fr, NULL);
    setbuf(fw, NULL);
    while (1) {
        while (!flag) {
            sigsuspend(ss);
        }
        flag = 0;
        pid_t pid;
        if (fscanf(fr, "%d %d", &x, &pid) != 2) {
            fclose(fr);
            fclose(fw);
            break;
        }
        if (x == maxval) {
            fclose(fr);
            fclose(fw);
            break;
        }
        printf("%d %d\n", num_of_proc, x);
        ++x;
        if (x >= maxval) {
            fclose(fr);
            fclose(fw);
            break;
        }
        fprintf(fw, "%d %d ", x, getpid());
        kill(pid, SIGUSR1);
    }
    exit(0);
}


int main(int argc, char *argv[]) {
    int maxval = strtol(argv[1], NULL, 10);
    int fd[2];
    if (pipe(fd) != 0) {
        _exit(1);
    }
    sigset_t ss2;
    struct sigaction unit;
    unit.sa_handler = handler;
    unit.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &unit, NULL);
    pid_t pid1, pid2;
    pid1 = fork();
    if (pid1 < 0) {
        _exit(1);
    }
    if (pid1 == 0) {
        read_and_write(1, maxval, fd, &ss2);
    }
    pid2 = fork();
    if (pid2 < 0) {
        _exit(1);
    }
    if (pid2 == 0) {
        read_and_write(2, maxval, fd, &ss2);
    }
    FILE *f = fdopen(fd[1], "w");
    fprintf(f, "%d %d ", 1, pid2);
    fflush(f);
    close(fd[0]);
    kill(pid1, SIGUSR1);
    pid_t epid = wait(NULL);
    fprintf(f, "%d 0 ", maxval);
    if (epid != pid1) {
        kill(pid1, SIGUSR1);
    } else {
        kill(pid2, SIGUSR1);
    }
    fclose(f);
    wait(NULL);
    printf("Done\n");
    fflush(stdout);
    return 0;
}