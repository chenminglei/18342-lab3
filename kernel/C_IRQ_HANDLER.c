#include <arm/reg.h>
#include <arm/timer.h>
#include "constant.h"

extern unsigned int cur_time;

unsigned IRQ_Handler(unsigned num, void* regs) {
	unsigned long cur_ossr = reg_read(OSTMR_OSSR_ADDR);
	reg_write(OSTMR_OSSR_ADDR, cur_ossr & 0xffffffffe);
	reg_write(OSTMR_OSCR_ADDR, 0x0);
	cur_time = cur_time + 1;
}
