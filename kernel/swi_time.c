#include <arm/reg.h>
#include <arm/timer.h>
#include "constant.h"

extern unsigned int cur_time;
unsigned long time() {

    unsigned long oscr = reg_read(OSTMR_OSCR_ADDR);
    unsigned long ret = cur_time * TIME_RESOLUTION + oscr / (OSCR_COUNT / 10);
    return ret;
}

