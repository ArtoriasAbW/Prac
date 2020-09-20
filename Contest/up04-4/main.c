#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int f = open(argv[1], O_RDWR);
    if (f == -1) {
        return 1;
    }
    long long num, min = LLONG_MAX;
    int empty = 1;
    long offset = 0, offset_min = 0;
    while (read(f, &num, sizeof(num)) == sizeof(num)) {
        empty = 0;
        if (min > num) {
            min = num;
            offset_min = offset;
        }
        offset += sizeof(num);
    }
    if (empty || min == LLONG_MIN) {
        close(f);
        return 0;
    }
    offset = lseek(f, offset_min, SEEK_SET);
    if (offset == -1) {
        return 3;
    }
    min = -min;
    if (write(f, &min, sizeof(min)) != sizeof(num)) {
        close(f);
        return 2;
    }
    close(f);
    return 0;
}