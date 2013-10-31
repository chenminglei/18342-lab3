/*  author: Di Li<dil1@andrew.cmu.edu>
 *          Minglei Chen<mingleic@andrew.cmu.edu>
 *          Zhe Shen<zshen@andrew.cmu.edu>
 */

#include "main.h"
#include <exports.h>
#include <bits/swi.h>
//#define READ 0x900003
//#define WRITE 0x900004
//#define EXIT 0x900001
//#define TIME 0x900006
//#define SLEEP 0x900007
#define BADCODE 0xbadc0de

/*Given swi_num and arguments, decide which swi handler to choose */

unsigned C_SWI_HANDLER(unsigned swi_num, void* regs) {
        unsigned result = 0;

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
		    result = swi_time(regs);
		    break;
		case SLEEP_SWI:
		    /*call swi_sleep */
		    result = swi_sleep(regs);     
		    break;                
                default:                           
                    /* return with status bad code */
                    swi_exit(BADCODE);                 
        }                                    

        return result;                       
}                     
