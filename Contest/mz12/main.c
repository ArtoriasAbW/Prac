#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>

typedef struct Data
{
    int value;
    int s_num;

} Data;

enum
{
    DEC_BASE = 10
};

void work(int semid, Data *ptr, int nproc, int maxval, int i) {
    int r, pnum;
    while (1) {
        struct sembuf o1[] =
                {
                        {.sem_num = i, -1},
                };
        r = semop(semid, o1, sizeof(o1) / sizeof(o1[0]));
        if (r < 0) {
            _exit(1);
        }
        printf("%d %d %d\n", i + 1, ptr->value, ptr->s_num + 1);
        fflush(stdout);
        if (ptr->value == maxval) {
            _exit(0);
        }
        ++ptr->value;
        ptr->s_num = i;
        pnum = ptr->value % nproc;
        pnum *= pnum;
        pnum %= nproc;
        pnum *= pnum;
        pnum %= nproc;
        struct sembuf o2[] =
                {
                        {.sem_num = pnum, 1},
                };
        r = semop(semid, o2, sizeof(o2) / sizeof(o2[0]));
        if (r < 0) {
            _exit(1);
        }
    }
}

int main(int argc, char *argv[]) {
    key_t key = strtol(argv[2], NULL, DEC_BASE);
    int nproc = strtol(argv[1], NULL, DEC_BASE);
    int maxval = strtol(argv[3], NULL, DEC_BASE);

    int semid = semget(key, nproc + 1, 0600 | IPC_CREAT | IPC_EXCL);
    if (semid < 0) {
        exit(1);
    }
    semctl(semid, 0, SETVAL, 1);
    Data *ptr = mmap(NULL, sizeof(*ptr), PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0);
    if (ptr == MAP_FAILED) {
        exit(1);
    }
    ptr->s_num = -1;
    for (int i = 0; i < nproc; ++i) {
        pid_t pid = fork();
        if (pid < 0) {
            semctl(semid, 0, IPC_RMID);
            munmap(ptr, sizeof(*ptr));
            exit(1);
        }
        if (pid == 0) {
            work(semid, ptr, nproc, maxval, i);
        }
    }
    wait(NULL);
    semctl(semid, 0, IPC_RMID);
    munmap(ptr, sizeof(*ptr));
    while (wait(NULL) > 0) {}
    exit(0);
}