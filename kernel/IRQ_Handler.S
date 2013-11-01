@ IRQ_Handler.S: Customized IRQ handler
@
@ Author: Di Li <dil1@andrew.cmu.edu>
@         Zhe Shen <zshen@andrew.cmu.edu>
@         Minglei Chen <mingleic@andrew.cmu.edu>
@ Date:   Oct 18th 2013

        .file   "IRQ_Handler.S"
        .text
        .global IRQ_Handler
        .extern C_IRQ_HANDLER

IRQ_Handler:
        LDR    sp, =0xa3edf010 
        SUB    sp, sp, #4                                                      
        STMFD  sp!, {r0-r12, lr}      @ store registers into stack             
        MRS    r2, spsr               @ store spsr into stack
        STR    r2, [sp, #14*4]                                                 
        
        BL     C_IRQ_HANDLER          @ jump to C swi handler

        LDR    r2, [sp, #14*4]                                     
        MSR    spsr, r2               @ restore spsr
        ADD    sp, sp, #4                                      
        LDMFD  sp!, {r1-r12, lr}      @ restore registers except r0
        ADD    sp, sp, #4                                          
        MOVS   pc, lr                 @ go back to user program
