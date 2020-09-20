#include <stdlib.h>

struct Pair
{
    int key;
    int value;
};

void process(struct Pair *data, size_t size) {
    if (size > 1) {
        process(data, size / 2);
        process(&data[size / 2], size / 2 + size % 2);
        size_t i = 0, j = 0;
        struct Pair *tmp = calloc(size / 2, sizeof(*tmp));
        if (tmp != NULL) {
            for (size_t l = 0; l < size / 2; ++l) {
                tmp[l].key = data[l].key;
                tmp[l].value = data[l].value;
            }
            for (size_t k = 0; k < size; ++k) {
                if (j >= size / 2 + size % 2 || (i < size / 2 && tmp[i].key <= data[size / 2 + j].key)) {
                    data[k].key = tmp[i].key;
                    data[k].value = tmp[i].value;
                    i++;
                } else {
                    data[k].key = data[size / 2 + j].key;
                    data[k].value = data[size / 2 + j].value;
                    j++;
                }
            }
            free(tmp);
        }
    }
}
