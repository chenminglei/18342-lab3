@ swi_exit.S: swi exit handler                 
@                                       
@ Author: Di Li<dil1@andrew.cmu.edu>                         
@         Minglei Chen<mingleic@andrew.cmu.edu>              
@         Zhe Shen<zshen@andrew.cmu.edu>                             
@ Date:   Sun, 18 Oct 2013                                           
                                                                     
        .file   "swi_exit.S"                          
        .text                                                        
        .global swi_exit                                     
        .extern jump_swi                                    
        .extern swi_instr1                                           
        .extern swi_instr2                                   

        .extern jump_irq                                    
        .extern irq_instr1                                           
        .extern irq_instr2                                   

        .extern spaddr                                      
swi_exit:                                                            
        stmfd sp!, {r1, r2}  @save r1 and r2's original value
                                                                     
        ldr  r1, =jump_swi   @get the address of jump swi instruction
        ldr  r2, =swi_instr1 @get the swi instruction       
        str  r2, [r1]        @restore this instruction 
        ldr  r2, =swi_instr2 @get the second swi instruction
        str  r2, [r1, #4]    @restore it                                                                      

        ldr  r1, =jump_irq   @get the address of jump swi instruction
        ldr  r2, =irq_instr1 @get the swi instruction       
        str  r2, [r1]        @restore this instruction 
        ldr  r2, =irq_instr2 @get the second swi instruction
        str  r2, [r1, #4]    @restore it                                                                      

        ldmfd sp!, {r1, r2}  @restore the value in r1 and r2         
                                                             
        ldr  sp, =spaddr     @get the sp address                     
        ldr  sp, [sp]                                                
        ldr  r2, [sp, #14*4] @move the correct location              
        msr  spsr, r2        @restore spsr                           
        ldr  r2, [sp, #13*4]                                         
        msr  cpsr, r2        @restore cpsr                  
                                                            
        ldmfd sp!, {r1-r12, lr} @restore r1 to r12          
        add   sp, sp, #8        @restore the location of sp 
        mov   pc, lr            @restore pc from lr         


