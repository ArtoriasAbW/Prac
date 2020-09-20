#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <wait.h>

enum
{
    DEC_BASE = 10,
    OFFSET = 5,
    RANGE = 10
};

void operation(int *data, int ind1, int ind2, int value);

void work(int semid, int *data, int iter_count, char *argv[], int count, int i) {
    int idx1, idx2, val, r;
    unsigned seed;
    sscanf(argv[i + OFFSET], "%u", &seed);
    srand(seed);
    for (int j = 0; j < iter_count; ++j) {
        val = rand() % RANGE;
        idx1 = rand() % count;
        idx2 = rand() % count;
        if (idx1 != idx2) {
            struct sembuf o1[] =
                    {
                            {.sem_num = idx1, -1},
                            {.sem_num = idx2, -1}
                    };
            r = semop(semid, o1, sizeof(o1) / sizeof(o1[0]));
            if (r < 0) {
                _exit(1);
            }
            operation(data, idx1, idx2, val);
            struct sembuf o2[] =
                    {
                            {.sem_num = idx1, 1},
                            {.sem_num = idx2, 1}
                    };
            r = semop(semid, o2, sizeof(o2) / sizeof(o2[0]));
            if (r < 0) {
                _exit(1);
            }
        }
    }
    exit(0);
}

int main(int argc, char *argv[]) {
    pid_t pid;
    int count = strtol(argv[1], NULL, DEC_BASE);
    key_t key = strtol(argv[2], NULL, DEC_BASE);
    int nproc = strtol(argv[3], NULL, DEC_BASE);
    int iter_count = strtol(argv[4], NULL, DEC_BASE);
    int *arr = mmap(NULL, count * sizeof(*arr), PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0);
    if (arr == MAP_FAILED) {
        exit(1);
    }
    int semid = semget(key, count, 0600 | IPC_CREAT | IPC_EXCL);
    if (semid < 0) {
        exit(1);
    }
    for (int i = 0; i < count; ++i) {
        scanf("%d", &arr[i]);
        semctl(semid, i, SETVAL, 1);
    }
    for (int i = 0; i < nproc; ++i) {
        pid = fork();
        if (pid < 0) {
            exit(1);
        }
        if (pid == 0) {
            work(semid, arr, iter_count, argv, count, i);
        }
    }
    for (int i = 0; i < nproc; ++i) {
        wait(NULL);
    }
    for (int i = 0; i < count; ++i) {
        printf("%d\n", arr[i]);
    }
    semctl(semid, 0, IPC_RMID);
    munmap(arr, count * sizeof(*arr));
    return 0;
}