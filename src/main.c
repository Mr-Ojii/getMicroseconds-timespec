#include <stdio.h>
#include <time.h>
#include <stdint.h>

uint64_t getNowMicroseconds() {
    struct timespec ts;
    if (timespec_get(&ts, TIME_UTC) == 0)
    {
        fprintf(stderr, "Failed to get the current time.");
        return 0;
    }

    uint64_t nanos = ts.tv_nsec;
    uint64_t micros = (1000*1000*1000 * ts.tv_sec + nanos)/(1000);
    return micros;
}
