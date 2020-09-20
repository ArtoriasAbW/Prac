#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <values.h>

enum
{
    BUF_SIZE = 2,
};

int main(int argc, char *argv[]) {
    unsigned char buf[BUF_SIZE];
    unsigned short num, min = USHRT_MAX;
    int f = open(argv[1], O_RDONLY, 0777);
    if (f == -1) {
        return 1;
    }
    while (read(f, &buf, sizeof(buf)) == sizeof(buf)) {
        num = ((unsigned short)buf[0]) << CHAR_BIT | (buf[1]);
        if (num % 2 == 0 && num < min) {
            min = num;
        }
    }
    if (min % 2 == 0) {
        printf("%hu\n", min);
    }
    close(f);
    return 0;
}