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
unsigned int cur_time = 0;

unsigned int irq_stack[IRQ_STACK_SIZE];
unsigned long irq_stack_top;


//void installHandler(unsigned int * vec_address, unsigned int new_address, unsigned int type);


int kmain(int argc, char** argv, uint32_t table) {
        irq_stack_top = (unsigned long)(irq_stack + IRQ_STACK_SIZE - 1);        

        global_data = table;        

        installHandler((unsigned int *)VEC_SWI, (unsigned int)S_Handler, 0);
        installHandler((unsigned int *)VEC_IRQ, (unsigned int)IRQ_Handler, 1);

        printf("before irqsetup\n");

        irqSetup();

        printf("after irqsetup\n");

        timeSetup();

        /* Set up user program */     
        userSetup(argc, argv); 

	return -255;
}

/*void installHandler(unsigned int * vec_address, unsigned int new_address, unsigned int type) {

        unsigned int vec_instr = *vec_address;
        unsigned int * jump_handler;
*/
        /* Check the ldr instruction */
/*        if ((vec_instr & 0xfffff000) != LDR_CHECK) {
            printf("info : instruction in vector table incorrect!\n");
            swi_exit(vec_instr);
        }      
*/
        /* Get the address of the original swi handler */
 /*       jump_handler = (unsigned int *)((0x00000fff & vec_instr) + (unsigned int)vec_address + 0x08);
        jump_handler = (unsigned int *)(*jump_handler); 

        if (type == 0) {
            jump_swi = jump_handler;
            swi_instr1 = *jump_swi;
            swi_instr2 = *(jump_swi + 1);
        }
        else {
            jump_irq = jump_handler;
            irq_instr1 = *jump_irq;
            irq_instr2 = *(jump_irq + 1);
        }
*/
        /* Change the original instructions */
/*        *jump_handler = (unsigned int)LDR_INSTR;
        *(jump_handler + 1) = (unsigned int)new_address;
}
*/

