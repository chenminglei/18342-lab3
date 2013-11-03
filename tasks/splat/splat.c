/**
 * splat.c: Display a spinning cursor
 *
 * Authors: Di Li <dil1@andrew.cmu.edu>
 *          Zhe Shen <zshen@andrew.cmu.edu>
 *          Minglei Chen <mingleic@andrew.cmu.edu>
 * Date:    00:37 AM  Nov 3rd 2013
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv) {
	while (1) {
		printf("|");
		sleep(200);
		printf("\b");
		printf("/");
		sleep(200);
		printf("\b");
		printf("-");
		sleep(200);
		printf("\b");
		printf("\\");
		sleep(200);
		printf("\b");
	}
	return 0;
}
