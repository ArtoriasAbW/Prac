#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

unsigned long long hash_function(unsigned long long );

int main(int argc, char *argv[]) {
    int f;
    if (argc < 4) {
        return 2;
    }
    f = open(argv[1], O_CREAT | O_WRONLY, 0660);
    if (f == -1) {
        return 1;
    }
    unsigned long long h, count;
    sscanf(argv[2], "%llx", &h);
    sscanf(argv[3], "%llu", &count);
    if (count < 0) {
        close(f);
        return 4;
    }
    long offset = lseek(f, 0, SEEK_END);
    for (unsigned long long k = 0; k < count; ++k) {
        lseek(f, offset + sizeof(count) * (count - 1 - k), SEEK_SET);
        ssize_t count_bytes = write(f, &h, sizeof(h));
        if (count_bytes != sizeof(h)) {
            close(f);
            return 3;
        }
        h = hash_function(h);
    }
    close(f);
    return 0;
}