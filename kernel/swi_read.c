/*Author: Minglei Chen<mingleic@andrew.cmu.edu>                                 
 *        Di Li<dil1@andrew.cmu.edu>                                            
 *        Zhe Shen<zshen@andrew.cmu.edu>                                        
 */ 

#include "kernel.h"
#include <bits/errno.h>
#include <exports.h>

unsigned swi_read(unsigned *regs) {

	// get the parameters
	int fd = (int) (*regs);
	char *buf = (char*) regs[1];
	size_t count = (size_t) (*(regs + 2));

	int tmp;
	size_t i = 0;

	// if file descriptor does not match stdin return error
	if (fd != STDIN) {
		return -EBADF;
	}
	// if the memory range specified exceeds the size of SDRAM, return error
	if ((unsigned)buf < 0xa0000000
			|| (unsigned)(buf + count) > 0xa3ffffff) {
		return -EFAULT;
	}
	while (i < count) {
		tmp = getc();

		// ctrl + d
		if (tmp == 4) {
			return i;
		}
		// backspace or delete
		else if (tmp == 8 || tmp == 127) {
			putc(8);
			putc(' ');
			putc(8);
			if (i > 0) {
				((char*) buf)[i]  = '\0';
				i--;
			}
		}
		// newline
		else if (tmp == 10 || tmp == 13) {
			((char*) buf)[i]  = '\n';
			putc('\n');
			return ++i;
		}
		else {
			buf[i]  = tmp;
			putc(tmp);
			i++;
		}
	}
	return i;
}

