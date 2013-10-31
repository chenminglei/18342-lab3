/*  author: Di Li<dil1@andrew.cmu.edu>
 *          Minglei Chen<mingleic@andrew.cmu.edu>
 *          Zhe Shen<zshen@andrew.cmu.edu>
 */

#include "kernel.h"
#include <exports.h>

#define READ 0x900003
#define WRITE 0x900004
#define EXIT 0x900001
#define BADCODE 0xbadc0de

/*Given swi_num and arguments, decide which swi handler to choose */

unsigned C_SWI_HANDLER(unsigned swi_num, void* regs) {
        unsigned result = 0;

        /*Decide which swi to run based on swi number */
        switch(swi_num) {
                case EXIT:
                    /* call swi_exit */
                    result = swi_exit(*(int*)regs);
                    break;
                case READ:
                    /* call swi_read */
                    result = swi_read(regs);          
                    break;                            
                case WRITE:                           
                    /* call swi_write */
                    result = swi_write(regs);      
                    break;                         
                default:                           
                    /* return with status bad code */
                    swi_exit(BADCODE);                 
        }                                    

        return result;                       
}                     
