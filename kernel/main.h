/*
 * kernel.h: Kernel header file
 *
 * Author: Di Li   <dil1@andrew.cmu.edu>
 *         Zhe Shen <zshen@andrew.cmu.edu>
 *         Minglei Chen <mingleic@andrew.cmu.edu>
 * Date:   Oct 18th
 */
#define STDIN 0
#define STDOUT 1

// swi read 
unsigned swi_read(unsigned* regs);
// swi write
unsigned swi_write(unsigned* regs);
// swi exit
unsigned swi_exit(unsigned staus);
// user set up
void userSetup(int argc, char *argv[]);
// new swi handler
unsigned S_Handler();