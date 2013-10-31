/*
 * kernel.c: Kernel main (entry) function
 *
 * Author: Di Li   <dil1@andrew.cmu.edu>
 *         Zhe Shen <zshen@andrew.cmu.edu>
 *         Minglei Chen <mingleic@andrew.cmu.edu>
 * Date:   Oct 30th
 */

#include "main.h"
#include <exports.h>
#include <arm/psr.h>                             
#include <arm/exception.h>                       
#include <arm/interrupt.h>                       
#include <arm/timer.h>                           
                                                 
uint32_t global_data;

#define VEC_SWI   0x08
#define LDR_INSTR 0xe51ff004

/* Global variables */
unsigned int * jump_swi; // address of the s handler
unsigned int swi_instr1; // original content of the first instruction in swi handler
unsigned int swi_instr2; // original content of the second instruction in swi handler
unsigned int spaddr;     // original sp address

int kmain(int argc, char** argv, uint32_t table) {
        /* Get the instruction in the swi entry of vector table */
        unsigned int vec_swi_instr = *((unsigned int *)VEC_SWI);
       
        /* Check the ldr instruction */
        if ((vec_swi_instr & 0xfffff000) != 0xe59ff000) {
            printf("info : instruction in vector table incorrect!\n");
            swi_exit(vec_swi_instr);
        }      
 
        /* Get the address of the original swi handler */
        jump_swi = (unsigned int *)((0x00000fff & vec_swi_instr) + VEC_SWI + 0x08);
        jump_swi = (unsigned int *)(*jump_swi); 

        /* Get the original instructions in the handler */
        swi_instr1 = *jump_swi;
        swi_instr2 = *(jump_swi + 1);
        /* Change the original instructions */
        *jump_swi = (unsigned int)LDR_INSTR;
        *(jump_swi + 1) = (unsigned int)S_Handler;
       
        /* Set up user program */     
        userSetup(argc, argv); 

	return -255;
}

