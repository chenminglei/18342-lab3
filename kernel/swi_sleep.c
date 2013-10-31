#include <arm/reg.h>
#include <arm/timer.h>
#include "constant.h"

extern unsigned int cur_time;
void sleep(unsigned long millis) {

    unsigned long currenttime = cur_time;
    while (currenttime + millis < cur_time);
}
