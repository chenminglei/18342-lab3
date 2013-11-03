/*                                                                              
 * swi_sleep.c: handling sleep of swi interrupt                                       
 *                                                                              
 * Authors: Di Li <dil1@andrew.cmu.edu>                                      
 *          Zhe Shen <zshen@andrew.cmu.edu>
 *          Minglei Chen <mingleic@andrew.cmu.edu>                                      
 * Date:    7:47 PM  Nov 3rd 2013                                             
 */ 

#include "constant.h"
#include <arm/timer.h>
#include <exports.h>

extern volatile unsigned int cur_time;
extern volatile unsigned int cur_bias;

void swi_sleep(unsigned *reg) {
    /* Get the time requested by the user program */
    unsigned long millis = (unsigned long)reg[0];
    /* Get current time */
    unsigned long currenttime = cur_time;
    /* Get the cumulated bias for oscr */
    unsigned long bias = cur_bias / OSMR_ONE_SECOND;

    /* Break until sleep enough */
    while (currenttime * TIME_RESOLUTION + millis + bias > cur_time * TIME_RESOLUTION + cur_bias / OSMR_ONE_SECOND) {
    };
}
