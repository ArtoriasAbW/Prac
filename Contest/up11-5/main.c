#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <math.h>


volatile int count = 0;
int prime_num = 0;

void handler(int signal) {
    if (signal == SIGTERM || (signal == SIGINT && count >= 3)) {
        _exit(0);
    }
    count++;
    printf("%d\n", prime_num);
    fflush(stdout);
}

int is_prime(int num) {
    int flag = 1;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(void) {
    int low, high;
    pid_t pid = getpid();
    struct sigaction unit;
    unit.sa_handler = handler;
    unit.sa_flags = SA_RESTART;
    scanf("%d%d", &low, &high);
    printf("%d\n", pid);
    fflush(stdout);
    sigaction(SIGINT, &unit, NULL);
    sigaction(SIGTERM, &unit, NULL);
    for (int i = low; i < high; ++i) {
        if (is_prime(i)) {
            prime_num = i;
        }
    }
    printf("-1\n");
    fflush(stdout);
    return 0;
}