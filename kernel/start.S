/**
 * @file  start.S
 *
 * @brief Kernel startup routine
 *
 * @author Mike Kasick <mkasick@andrew.cmu.edu>
 * @date   Tue, 23 Oct 2007 11:20:33 -0400
 *
 * @author Kartik Subramanian <ksubrama@andrew.cmu.edu>
 * @date   2008-07-06
 */

#include <asm.h>

	.file   "start.S"

FUNC(_start)
	/*
	 * Branch immediately to main without altering the execution environment.
	 * This indirection is needed to guarantee that the program entry point is
	 * LOAD_ADDR (probably 0xa3000000) without placing strict
	 * requirements on the layout of kernel.c.  Bit first, provide main with the
	 * jump table address as one of its arguments.
	 */
        
        sub sp, sp, #8          @leave space for spsr and cpsr                  
        stmfd sp!, {r1-r12, lr} @store r1 to r12 and lr                         
        mrs r2, spsr            @get the value of spsr                          
        str r2, [sp, #14 * 4]   @store spsr to the right place                  
        mrs r2, cpsr            @get the value of cpsr          
        str r2, [sp, #13 * 4]   @store cpsr to the right place
        ldr r2, [sp, #4]        @restore the value of r2      
                                                              
        ldr r1, =spaddr         @get the address of var spaddr
        str sp, [r1]            @store sp to this variable    
        ldr r1, [sp]            @changed                                 
       
        mov r2, r8                                                       
        b       kmain            

