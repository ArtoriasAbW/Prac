#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <wait.h>

typedef struct
{
    long mtype;
    long long msgtext[2];
} Data;

enum
{
    DEC_BASE = 10
};

void work(int qd, int numproc, long long maxval, int i) {
    setbuf(stdout, NULL);
    Data m;
    while (1) {
        if (msgrcv(qd, &m, sizeof(m) - sizeof(m.mtype), i + 1, 0) < 0) {
            _exit(1);
        }
        printf("%d %lld\n", i, m.msgtext[0] + m.msgtext[1]);
        m.msgtext[0] += m.msgtext[1];
        long long tmp = m.msgtext[1];
        m.msgtext[1] = m.msgtext[0];
        m.msgtext[0] = tmp;
        if (llabs(m.msgtext[1]) > maxval) {
            _exit(0);
        }
        m.mtype = (m.msgtext[1] % numproc) + 1;
        if (msgsnd(qd, &m, sizeof(m) - sizeof(m.mtype), 0) < 0) {
            _exit(1);
        }
    }
}

void terminate(int qd, int n) {
    signal(SIGTERM, SIG_IGN);
    msgctl(qd, IPC_RMID, NULL);
    kill(0, SIGTERM);
    while (wait(NULL) > 0) {}
    exit(1);
}

int main(int argc, char *argv[]) {
    key_t key = strtol(argv[1], NULL, DEC_BASE);
    int n = strtol(argv[2], NULL, DEC_BASE);
    long long value1 = strtol(argv[3], NULL, DEC_BASE);
    long long value2 = strtoll(argv[4], NULL, DEC_BASE);
    long long maxval = strtoll(argv[5], NULL, DEC_BASE);
    int qd = msgget(key, 0600 | IPC_CREAT | IPC_EXCL);
    if (qd < 0) {
        exit(1);
    }
    pid_t pid;
    for (int i = 0; i < n; ++i) {
        pid = fork();
        if (pid < 0) {
            terminate(qd, n);
        }
        if (pid == 0) {
            work(qd, n, maxval, i);
        }
    }
    Data m = {.mtype = 1, .msgtext[0] = value1, .msgtext[1] = value2};
    msgsnd(qd, &m, sizeof(m) - sizeof(m.mtype), 0);
    wait(NULL);
    msgctl(qd, IPC_RMID, NULL);
    for (int i = 0; i < n - 1; ++i) {
        wait(NULL);
    }
    return 0;
}