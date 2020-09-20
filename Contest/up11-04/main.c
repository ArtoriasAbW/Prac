#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signal) {

}

int main(int argc, char *argv[]) {
    int fd[2], x = 1, n;
    sscanf(argv[1], "%d", &n);
    if (pipe(fd) != 0) {
        exit(1);
    }
    FILE *f = fdopen(fd[1], "w");
    fprintf(f, "%d", x);
    fclose(f);
    if (n <= 1) {
        printf("Done\n");
        fflush(stdout);
        exit(0);
    }
    struct sigaction unit;
    unit.sa_handler = handler;
    unit.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &unit, NULL);

    return 0;
}