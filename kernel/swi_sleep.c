
#include "constant.h"
#include <arm/timer.h>

extern unsigned int cur_time;
void swi_sleep(unsigned *reg) {

    unsigned long millis = (unsigned long)reg[0];
    unsigned long currenttime = cur_time;
    while (currenttime * TIME_RESOLUTION + millis < cur_time * TIME_RESOLUTION);
}
