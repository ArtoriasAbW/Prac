#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int transform(unsigned char buf[4]) {
    return (unsigned)buf[0] << 24 | (unsigned)buf[1] << 16 | (unsigned)buf[2] << 8 | (unsigned)buf[3];
}

int main(int argc, char **argv) {
    int key = strtol(argv[2], NULL, 10);
    int cur_key, value;
    unsigned char buf[4], val_buf[4];
    int fd = open(argv[1], O_RDONLY);
    read(fd, &buf, sizeof(buf));
    read(fd, &val_buf, sizeof(val_buf));
    cur_key = transform(buf);
    while (cur_key != key && read(fd, &buf, sizeof(buf)) > 0) {
        cur_key = transform(buf);
        read(fd, &val_buf, sizeof(val_buf));
    }
    if (cur_key == key) {
        value = transform(val_buf);
        printf("1 %d\n", value);
    } else {
        printf("0 0\n");
    }
    close(fd);
    return 0;
}