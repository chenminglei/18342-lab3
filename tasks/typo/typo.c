/**
 * typo.c: Echo the input of the user and count the input time
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
#define BUFFERSIZE 30

int main(int argc, char** argv) {
	unsigned long start = 0;
	unsigned long end = 0;
	char buffer[BUFFERSIZE] = { 0 };
	int i = 0;
	int num = 0;
	while (1) {
		memset(buffer, 0, BUFFERSIZE);
		// print prompt
		printf(">");
		// record start time
		start = time();
		num = read(STDIN, buffer, BUFFERSIZE - 1);
		// record finish time
		end = time();
		// finish the input and also deal with the Ctrl+D
		if (num == BUFFERSIZE - 1) {
			buffer[BUFFERSIZE - 1] = '\n';
			printf("\n");
		} else if (buffer[num-1] != '\n'){
			buffer[num] = '\n';
			printf("\n");
		}

		// output the input characters
		i = 0;
		while (i < BUFFERSIZE && buffer[i] != '\0') {
			printf("%c", buffer[i]);
			++i;
		}
		// calculate the input time user used
		int diff = end - start;
		printf("%d.%ds\n", diff / 1000, (diff % 1000) / 100);
	}
	return 0;
}
