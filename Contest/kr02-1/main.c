#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

enum { DEC_BASE = 10, ARG_NUM = 2 };

void print_nums(long max_d, long cd, long num) {
    if (cd == max_d) {
        printf("%ld\n", num);
        fflush(stdout);
        exit(0);
    }
    long left_num = 2 * num + 1;
    long right_num = 2 * num + 2;
    pid_t pid = fork();
    if (pid == 0) {
        print_nums(max_d, cd + 1, left_num);
    } else {
        wait(NULL);
        printf("%ld\n", num);
        fflush(stdout);
        pid = fork();
        if (pid == 0) {
            print_nums(max_d, cd + 1, right_num);
        } else {
            wait(NULL);
            exit(0);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < ARG_NUM) {
        exit(0);
    }
    long max_d;
    char * c;
    max_d = strtol(argv[1], &c, DEC_BASE);
    print_nums(max_d, 0, 0);
    exit(0);
}