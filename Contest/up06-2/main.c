#include <stdio.h>
#include <time.h>
#include <string.h>
enum
{
    NEW_FIRST_DAY = 7,
    NEW_FIRST_MONTH = 10,
    NEW_FIRST_YEAR = 1925,
    YEAR_OFFSET = 1900,
    NUM_ARGS = 3,
    SEC_IN_DAY = 86400,
    DAYS_IN_MOUTH = 30,
    MOUTHS_IN_YEAR = 12
};

int main(void) {
    int year, month, day;
    struct tm newTime;
    memset(&newTime, 0, sizeof(newTime));
    newTime.tm_mday = NEW_FIRST_DAY;
    newTime.tm_mon = NEW_FIRST_MONTH - 1;
    newTime.tm_year = NEW_FIRST_YEAR - YEAR_OFFSET;
    long long newNumTime = timegm(&newTime);
    while (scanf("%d %d %d", &year, &month, &day) == NUM_ARGS) {
        struct tm inTime;
        int outYear, outMonth, outDay;
        memset(&inTime, 0, sizeof(inTime));
        inTime.tm_isdst = -1;
        inTime.tm_mday = day;
        inTime.tm_mon = month - 1;
        inTime.tm_year = year - YEAR_OFFSET;
        long long outNumTime = timegm(&inTime) - newNumTime;
        outDay = outNumTime / SEC_IN_DAY % DAYS_IN_MOUTH + 1;
        outMonth = outNumTime / (SEC_IN_DAY * DAYS_IN_MOUTH) % MOUTHS_IN_YEAR + 1;
        outYear = outNumTime / (SEC_IN_DAY * DAYS_IN_MOUTH * MOUTHS_IN_YEAR) + 1;
        printf("%d %d %d\n", outYear, outMonth, outDay);
    }
    return 0;
}