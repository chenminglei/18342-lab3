/*
 * kernel.c: Kernel main (entry) function
 *
 * Author: Di Li   <dil1@andrew.cmu.edu>
 *         Zhe Shen <zshen@andrew.cmu.edu>
 *         Minglei Chen <mingleic@andrew.cmu.edu>
 * Date:   Oct 30th
 */

#include "main.h"
#include "constant.h"
#include <exports.h>
#include <arm/psr.h>                             
#include <arm/reg.h>                             
#include <arm/exception.h>                       
#include <arm/interrupt.h>                       
#include <arm/timer.h>                           
                                                 
uint32_t global_data;
/* Global variables */
unsigned int *jump_swi; // address of the s handler
unsigned int swi_instr1; // original content of the first instruction in swi handler
unsigned int swi_instr2; // original content of the second instruction in swi handler

unsigned int *jump_irq; // address of the s handler
unsigned int irq_instr1; // original content of the first instruction in swi handler
unsigned int irq_instr2; // original content of the second instruction in swi handler

unsigned int spaddr;     // original sp address
volatile unsigned int cur_time = 0;
volatile unsigned int cur_bias = 0;

unsigned int irq_stack[IRQ_STACK_SIZE];
unsigned long irq_stack_top;




int kmain(int argc, char** argv, uint32_t table) {
        irq_stack_top = (unsigned long)(irq_stack + IRQ_STACK_SIZE - 1);        

        global_data = table;        
        /*install SWI and IRQ handler */
        installHandler((unsigned int *)VEC_SWI, (unsigned int)S_Handler, 0);
        installHandler((unsigned int *)VEC_IRQ, (unsigned int)IRQ_Handler, 1);

	/*set up the IRQ stack */
        irqSetup();

	/*set up the time registers */
        timeSetup();

        /* Set up user program */     
        userSetup(argc, argv); 

	return -255;
}

