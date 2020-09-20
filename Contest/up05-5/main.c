#include <stdio.h>
#include <time.h>

enum
{
    NUM_ARGS = 6,
    YEAR_OFFSET = 1900
};

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        return 1;
    }
    time_t t1 = 0, t2 = 0;
    int year, mon, day, hour, min, sec, flag = 0;
    while (fscanf(f, "%d/%d/%d %d:%d:%d", &year, &mon, &day, &hour, &min, &sec) == NUM_ARGS) {
        struct tm time;
        time.tm_sec = sec;
        time.tm_min = min;
        time.tm_hour = hour;
        time.tm_mday = day;
        time.tm_mon = mon - 1;
        time.tm_year = year - YEAR_OFFSET;
        time.tm_isdst = -1;
        t2 = mktime(&time);
        if (flag) {
            printf("%ld\n", t2 - t1);
        }
        t1 = t2;
        flag = 1;
    }
    fclose(f);
    return 0;
}