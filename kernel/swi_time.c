#include <arm/timer.h>
#include <arm/reg.h>
#include <exports.h>
#include "constant.h"

extern unsigned int cur_time;
unsigned long swi_time() {

    printf("in swi_time \n");

    unsigned long oscr = reg_read(OSTMR_OSCR_ADDR);
    printf("oscr : %lu", oscr);
    unsigned long ret = cur_time*TIME_RESOLUTION + (oscr -  cur_time*OSMR_COUNT) / OSMR_ONE_SECOND;
    return ret;
}

