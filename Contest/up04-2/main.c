#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <values.h>

enum
{
    BUF_SIZE = 2
};

int main(int argc, char *argv[]) {
    unsigned short num;
    unsigned char buf[BUF_SIZE];
    int file = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0600);
    while (scanf("%hu", &num) == 1) {
        buf[0] = num >> CHAR_BIT;
        buf[1] = (num << CHAR_BIT) >> CHAR_BIT;
        write(file, &buf, sizeof(buf));
    }
    close(file);
    return 0;
}