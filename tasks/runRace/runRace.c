/**
 * runRace.c: a micro timer to get the times for several runners
 *
 * Authors: Di Li <dil1@andrew.cmu.edu>
 *          Zhe Shen <zshen@andrew.cmu.edu>
 *          Minglei Chen <mingleic@andrew.cmu.edu>
 * Date:    00:37 AM  Nov 3rd 2013
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


#define STDIN  0
#define STDOUT 1

int main(int argc, char** argv) {
	unsigned long start = 0;
	unsigned long buffer[5] = { 0 };
	char i = '0';
	char num = '0';
        char key = 0;
    
       /* Get valid number of runners */
        while (num <= '0' || num > '5') {
            printf("Please input the number of runners(Max 5):");
            read(STDIN, &num, 1);
            printf("\n");
        }

        /* Start to time */
        printf("Press any key to start:");
        read(STDIN, &key, 1);
        printf("\n");
        start = time();
	while (i < num) {
                read(STDIN, &key, 1);
		buffer[(size_t)(i-'0')] = time();
                i++;
	}

        /* Output the results of several runners */
        printf("result:\n");
        for (i = '0'; i < num; i++) {
		unsigned long diff = buffer[(size_t)(i-'0')] - start;
		printf("%lu.%lus\n", diff / 1000, (diff % 1000) / 100);
        } 
	return 0;
}
