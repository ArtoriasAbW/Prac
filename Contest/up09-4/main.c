#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
    char fullname[PATH_MAX];
    const char *path = getenv("XDG_RUNTIME_DIR");
    int name = getpid();
    if (path == NULL) {
        path = getenv("TMPDIR");
        if (path == NULL) {
            path = "/tmp";
        }
    }
    snprintf(fullname, PATH_MAX, "%s/%d", path, name);
    FILE *f = fopen(fullname, "w");
    if (f == NULL) {
        exit(1);
    }
    fclose(f);
    if (chmod(fullname, 0711) == -1) {
        exit(1);
    }
    f = fopen(fullname, "w");
    if (f == NULL) {
        exit(1);
    }
    fprintf(f, "#!\npython -c \"print(");
    for (int i = 1; i < argc; i++) {
        fprintf(f, "%s*", argv[i]);
    }
    fprintf(f, "1)\" rm $0");
    fclose(f);
    execlp("bash", "bash", fullname, NULL);
    exit(1);
}