/*  author: Di Li<dil1@andrew.cmu.edu>
 *          Minglei Chen<mingleic@andrew.cmu.edu>
 *          Zhe Shen<zshen@andrew.cmu.edu>
 */

#include "main.h"
#include <exports.h>
#include <bits/swi.h>
#define BADCODE 0xbadc0de

/*Given swi_num and arguments, decide which swi handler to choose */

unsigned long C_SWI_HANDLER(unsigned swi_num, void* regs) {
        unsigned long result = 0;
        /*Decide which swi to run based on swi number */
        switch(swi_num) {
                case EXIT_SWI:
                    /* call swi_exit */
                    result = swi_exit(*(int*)regs);
                    break;
                case READ_SWI:
                    /* call swi_read */
                    result = swi_read(regs);          
                    break;                            
                case WRITE_SWI:                           
                    /* call swi_write */
                    result = swi_write(regs);      
                    break;    
		case TIME_SWI:
		    /* call swi_time */
		    result = swi_time();
		    break;
		case SLEEP_SWI:
		    /*call swi_sleep */
		    swi_sleep(regs);
		    break;
                default:                           
                    /* return with status bad code */
                    swi_exit(BADCODE);                 
        }                                    

        return result;                       
}                     
