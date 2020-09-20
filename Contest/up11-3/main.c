#include <stdio.h>
#include <unistd.h>
#include <wait.h>

volatile int count = 0;
int prime_num;

void handler(int signal) {
    if (signal == SIGTERM || (signal == SIGINT && count >= 3)) {
        _exit(0);
    }
    count++;
    printf("%d\n", prime_num);
}

int is_prime(int num) {
    for (int i = 2; i < num; ++i) {
        if (num < 2 || num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    setbuf(stdout, NULL);
    int low, high;
    pid_t pid = getppid();
    struct sigaction unit;
    unit.sa_handler = handler;
    unit.sa_flags = SA_RESTART;
    scanf("%d %d", &low, &high);
    printf("%d\n", pid);
    sigaction(SIGINT, &unit, NULL);
    sigaction(SIGTERM, &unit, NULL);
    for (int i = low; i < high; ++i) {
        if (is_prime(i)) {
            prime_num = i;
        }
    }
    printf("-1\n");
    return 0;
}