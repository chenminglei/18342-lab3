#include <exports.h>
#include "main.h"
#include "constant.h"


extern unsigned int *jump_swi;
extern unsigned int *jump_irq;

extern unsigned int swi_instr1;
extern unsigned int swi_instr2;

extern unsigned int irq_instr1;
extern unsigned int irq_instr2;


void installHandler(unsigned int * vec_address, unsigned int new_address, unsigned int type) {

        unsigned int vec_instr = *vec_address;
        unsigned int * jump_handler;

        /* Check the ldr instruction */
        if ((vec_instr & 0xfffff000) != LDR_CHECK) {
            printf("info : instruction in vector table incorrect!\n");
            swi_exit(vec_instr);
        }

        /* Get the address of the original swi handler */
        jump_handler = (unsigned int *)((0x00000fff & vec_instr) + (unsigned int)vec_address + 0x08);
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
        /* Change the original instructions */
        *jump_handler = (unsigned int)LDR_INSTR;
        *(jump_handler + 1) = (unsigned int)new_address;
}

