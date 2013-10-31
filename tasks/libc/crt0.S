/** @file crt0.S
 *
 * @brief Execution startup routine
 *
 * @author Mike Kasick <mkasick@andrew.cmu.edu>
 * @date   Sun, 07 Oct 2007 01:51:29 -0400
 */

#include <asm.h>
#include<bits/swi.h>

	.file "crt0.S"

FUNC(_start)
	@ needs code.  Put your names at the top.
        ldr r0, [sp], #4 @move content in address sp to r0 and modify sp
        mov r1, sp       @move sp + 4 to r1
        bl main          @call main function
        swi EXIT_SWI     @use exit interrupt to exit

