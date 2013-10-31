#include <arm/reg.h>
#include <arm/timer.h>
#include "constant.h"

extern unsigned int cur_time;
void sleep(unsigned long millis) {

    unsigned long currenttime = cur_time;
    while (currenttime * TIME_RESOLUTION + millis < cur_time * TIME_RESOLUTION);
}
