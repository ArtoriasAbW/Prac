#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <values.h>

enum
{
    BUF_SIZE = 16
};

int main(int argc, char *argv[]) {
    int f;
    char buf[BUF_SIZE];
    int price, max1 = INT_MIN, max2 = INT_MIN, ft_flag = 1, st_flag = 1;
    for (int i = 1; i < argc; ++i) {
        f = open(argv[i], O_RDONLY);
        if (f != -1) {
            while (read(f, &buf, sizeof(buf)) == sizeof(buf)) {
                if (read(f, &price, sizeof(price)) == sizeof(price)) {
                    if (price == max1) {
                        ft_flag = 0;
                    } else if (price > max1) {
                        if (!ft_flag) {
                            max2 = max1;
                            st_flag = 0;
                        }
                        ft_flag = 0;
                        max1 = price;
                    } else if (price > max2 && price != max1) {
                        max2 = price;
                        st_flag = 0;
                    } else if (price == max2 && price != max1) {
                        st_flag = 0;
                    }
                }
            }
        }
        close(f);
    }
    if (!st_flag) {
        printf("%.2lf\n", max2 / 100.0);
    }
    return 0;
}