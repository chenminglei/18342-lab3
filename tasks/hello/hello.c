/**
 * hello.c: test sleep and time basic functions
 *
 * Authors: Di Li <dil1@andrew.cmu.edu>
 *          Zhe Shen <zshen@andrew.cmu.edu>
 *          Minglei Chen <mingleic@andrew.cmu.edu>
 * Date:    00:37 AM  Nov 3rd 2013
 */

#include <unistd.h>
#include <stdio.h>
int main(int argc, char** argv) {
	// sleep 30 milliseconds
	sleep(30);
	// get current time
	unsigned long t = time();
	return t;
}
