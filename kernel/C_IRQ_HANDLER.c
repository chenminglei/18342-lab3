#include <arm/reg.h>
#include <arm/timer.h>
#include <exports.h>
#include "constant.h"

extern unsigned int cur_time;

void C_IRQ_HANDLER() {
        printf("C_IRQ_HANDLER\n");
        volatile unsigned long osmr = reg_read(OSTMR_OSMR_ADDR(0));
	reg_write(OSTMR_OSMR_ADDR(0), osmr + OSMR_COUNT);
	cur_time++;
	reg_set(OSTMR_OSSR_ADDR, OSTMR_OSSR_M0);
}
