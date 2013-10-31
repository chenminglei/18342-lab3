/* Author:    Zhe Shen<zshen@andrew.cmu.edu>
 *            Di Li <dil1@andrew.cmu.edu>
 *            Minglei Chen<mingleic@andrew.cmu.edu>
 */

#include "kernel.h"
#include<bits/errno.h>
#include<exports.h>


unsigned swi_write(unsigned* regs) {
    char c;
    unsigned num = 0;

    int fd = (int)(*regs); //get the first argument
    char* buf = (char*)(*(regs + 1));  //get the buffer
    size_t char_count = (size_t)(*(regs + 2));  //get the size of buffer
    if(fd == STDOUT) {
        while(num < char_count) {
            //check whether the addrss is legal
            if(((unsigned)buf + num) < 0xa0000000
                &&((unsigned)buf + num) > 0x00ffffff) {
                return -EFAULT;
            }
            else if((unsigned)buf + num > 0xa3ffffff) {
                return -EFAULT;                                         
            }                                                           
            //get the char from buffer                                  
            c = *((char*)buf + num);                   
            putc(c);                                   
            num ++;                                                     
            // if we met '\0', it ends                 
            if (c == '\0')                                              
                return num;                                             
        }                                              
    }                                                  
    else {                                       
        //if this is not STDOUT, we return with -EBADF 
        return -EBADF;                                 
    }                                                 
    return num;                                        
}                                

