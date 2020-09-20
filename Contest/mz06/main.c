#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    unsigned long long total = 0;
    struct stat unit;
    for (int j = 1; j < argc; ++j) {
        if (lstat(argv[j], &unit) == 0 && S_ISREG(unit.st_mode) && unit.st_nlink == 1) {
            total += unit.st_size;
        }
    }
    printf("%llu\n", total);
    return 0;
}