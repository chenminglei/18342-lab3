#include <arm/reg.h>
#include <arm/timer.h>
#include "constant.h"

extern unsigned int cur_time;

void C_IRQ_HANDLER() {
	reg_set(OSTMR_OSSR_ADDR, OSTMR_OSSR_M0);
	reg_write(OSTMR_OSCR_ADDR, 0x0);
	cur_time = cur_time + 1;
}
