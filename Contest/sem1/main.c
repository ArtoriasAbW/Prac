#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    DIR *d = opendir(argv[1]);
    if (!d) {
        fprintf(stderr, "%s : %s\n", argv[1], strerror(errno));
        return 1;
    }
    struct dirent *dd;
    errno = 0;
    while ((dd = readdir(d)) != NULL) {
        printf("%lu %s\n", dd->d_ino, dd->d_name);
        struct stat sb;
        if (lstat(dd->d_name, &sb) < 0) {
            fprintf(stderr, "%s: read error: %s\n", dd->d_name, strerror(errno));
        } else {
            printf("dev, ino: %lx %ld\n",sb.st_dev , sb.st_ino);
        }

    }
    if (errno) {
        fprintf(stderr, "%s: read error: %s\n", argv[1], strerror(errno));
    }
    closedir(d);
    return 0;
}