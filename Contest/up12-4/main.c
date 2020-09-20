#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

enum { DEC_BASE = 10, KEY = 45476592 };

void work(int semid, int pnum, int count) {
    int r, x;
    while (1) {
        struct sembuf o1[] =
                {
                        {.sem_num = pnum, -1}
                };
        r = semop(semid, o1, sizeof(o1) / sizeof(o1[0]));
        if (r < 0) {
            _exit(1);
        }
        if (scanf("%d", &x) != 1) {
            exit(0);
        }
        printf("%d %d\n", pnum, x);
        if (x >= 0) {
            pnum = x % count;
        } else {
            pnum = (x % count + count) % count;
        }
        struct sembuf o2[] =
                {
                        {.sem_num = pnum, 1}
                };
        r = semop(semid, o2, sizeof(o2) / sizeof(o2[0]));
        if (r < 0) {
            exit(1);
        }
    }
}

int main(int argc, char *argv[]) {
    int count = strtol(argv[1], NULL, DEC_BASE);
    pid_t pid;
    int semid = semget(KEY, count, 0600 | IPC_CREAT | IPC_EXCL);
    if (semid < 0) {
        exit(1);
    }
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    for (int i = 0; i < count; ++i) {
        pid = fork();
        if (pid < 0) {
            semctl(semid, 0, IPC_RMID);
            exit(1);
        }
        if (pid == 0) {
            work(semid, i, count);
        }
    }
    semctl(semid, 0, SETVAL, 1);
    wait(NULL);
    semctl(semid, 0, IPC_RMID);
    return 0;
}