#include <arm/reg.h>
#include <arm/timer.h>
#include <exports.h>
#include "constant.h"

extern volatile unsigned int cur_time;
extern volatile unsigned int cur_bias;
void C_IRQ_HANDLER() {

	cur_time++;

        volatile unsigned long oscr = reg_read(OSTMR_OSCR_ADDR);
        cur_bias += (oscr - OSMR_COUNT);
	reg_write(OSTMR_OSCR_ADDR, OSCR_CLEAR);

        if (cur_bias >= OSMR_COUNT) {
            cur_bias -= OSMR_COUNT;
            cur_time++;
        }    

	reg_set(OSTMR_OSSR_ADDR, OSTMR_OSSR_M0);
}
