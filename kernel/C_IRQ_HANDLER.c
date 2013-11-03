#include <arm/reg.h>
#include <arm/timer.h>
#include <exports.h>
#include "constant.h"

extern volatile unsigned int cur_time;
void C_IRQ_HANDLER() {
       // printf("C_IRQ_Handler\n");
        volatile unsigned long osmr = reg_read(OSTMR_OSMR_ADDR(0));
	reg_write(OSTMR_OSMR_ADDR(0), osmr + OSMR_COUNT);
	cur_time = cur_time + 1;;
	reg_set(OSTMR_OSSR_ADDR, OSTMR_OSSR_M0);
}
