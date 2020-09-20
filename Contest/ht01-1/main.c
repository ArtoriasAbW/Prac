#include <stdio.h>
#include <stdlib.h>

enum { START_BUF_SIZE = 16 };

char *getline2(FILE *f) {
    size_t max_size = START_BUF_SIZE, size = 0;
    int c;
    char *buf = (char *) calloc(START_BUF_SIZE, sizeof(*buf));
    if (buf == NULL) {
        return NULL;
    }
    while ((c = getc(f)) != EOF) {
        buf[size] = (char) c;
        size++;
        if (c == '\n') {
            break;
        }
        if (max_size == size) {
            max_size *= 2;
            char *new = realloc(buf, max_size * sizeof(*new));
            if (new == NULL) {
                free(buf);
                return NULL;
            }
            buf = new;
        }
    }
    if (size == 0) {
        free(buf);
        return NULL;
    }
    char *new = realloc(buf, (size + 1) * sizeof(*new));
    if (new == NULL) {
        free(buf);
        return NULL;
    }
    new[size] = '\0';
    buf = new;
    return buf;
}
