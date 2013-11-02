#include <arm/reg.h>
#include <arm/timer.h>
#include <arm/interrupt.h>
#include <exports.h>
#include "constant.h"


void timeSetup() {
    reg_clear(INT_ICLR_ADDR, 1 << INT_OSTMR_0);
    reg_write(INT_ICMR_ADDR, 1 << INT_OSTMR_0);

    reg_write(OSTMR_OSMR_ADDR(0), OSMR_COUNT);
    reg_write(OSTMR_OSCR_ADDR, 0);
    reg_set(OSTMR_OIER_ADDR, OSTMR_OIER_E0);
}

