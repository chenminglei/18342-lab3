
#include "constant.h"
#include <arm/timer.h>
#include <exports.h>

extern volatile unsigned int cur_time;
extern volatile unsigned int cur_bias;
void swi_sleep(unsigned *reg) {
    unsigned long millis = (unsigned long)reg[0];
    unsigned long currenttime = cur_time;
    unsigned long bias = cur_bias / OSMR_ONE_SECOND;

    while (currenttime * TIME_RESOLUTION + millis + bias > cur_time * TIME_RESOLUTION + cur_bias / OSMR_ONE_SECOND) {
    };
}
