#include <arm/timer.h>
#include <arm/reg.h>
#include <exports.h>
#include "constant.h"

extern volatile unsigned int cur_time;
extern volatile unsigned int cur_bias;
unsigned long swi_time() {
    /*read the current value of OSCR */
    volatile unsigned long oscr = reg_read(OSTMR_OSCR_ADDR);
    /*get the current time */
    unsigned long ret = cur_time*TIME_RESOLUTION + (oscr + cur_bias)/OSMR_ONE_SECOND;
    return ret;
}

