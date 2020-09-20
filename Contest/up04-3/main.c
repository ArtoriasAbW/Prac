#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

struct Node
{
    int32_t key;
    int32_t left_idx;
    int32_t right_idx;
};

void print_keys(int f, long off) {
    struct Node unit;
    lseek(f, off, SEEK_SET);
    ssize_t count_bytes = read(f, &unit, sizeof(unit));
    if (count_bytes != sizeof(unit)) {
        return;
    }
    if (unit.right_idx != 0) {
        print_keys(f, unit.right_idx * sizeof(unit));
    }
    printf("%d ", unit.key);
    if (unit.left_idx != 0) {
        print_keys(f, unit.left_idx * sizeof(unit));
    }
}

int main(int argc, char *argv[]) {
    int f = open(argv[1], O_RDONLY, 0777);
    if (f == -1) {
        return 1;
    }
    print_keys(f, 0);
    close(f);
    printf("\n");
    return 0;
}