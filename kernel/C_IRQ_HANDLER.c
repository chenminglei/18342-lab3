#include <arm/reg.h>
#include <arm/timer.h>
#include <exports.h>
#include "constant.h"

extern volatile unsigned int cur_time;
void C_IRQ_HANDLER() {
	cur_time ++;
	reg_write(OSTMR_OSCR_ADDR, 0x0);
	reg_set(OSTMR_OSSR_ADDR, OSTMR_OSSR_M0);
}
