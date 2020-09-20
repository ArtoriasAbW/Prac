#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    unsigned long long total = 0;
    char fn[PATH_MAX] = {};
    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        return 1;
    }
    struct dirent *unit;
    while ((unit = readdir(dir)) != NULL) {
        struct stat st = {};
        int path_len = snprintf(fn, sizeof(fn), "%s/%s", argv[1], unit->d_name);
        if (path_len < sizeof(fn)) {
            if (stat(fn, &st) >= 0) {
                unsigned char firstlet = unit->d_name[0];
                if (firstlet >= 'A' && firstlet <= 'Z' && S_ISREG(st.st_mode) && st.st_uid == getuid()) {
                    total += st.st_size;
                }
            }
        }
    }
    closedir(dir);
    printf("%llu\n", total);
    return 0;
}