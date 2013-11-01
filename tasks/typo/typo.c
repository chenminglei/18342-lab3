/** @file typo.c
 *
 * @brief Echos characters back with timing data.
 *
 * Links to libc.
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define BUFFERSIZE 100
int main(int argc, char** argv)
{
	/* Add code here -- put your names at the top. */
	unsigned long start;
	unsigned long end;
	int i;
	char buffer[BUFFERSIZE] = {0};
	i = 0;
	while(1) {
	    printf(">");
	    start = time();
	    sscanf("%s", buffer);
	    while(i < BUFFERSIZE && buffer[i] != '\0') {
		printf("%c", buffer[i]);
	        i ++;
	    }
	    end = time();
	    printf("%.1fs\n", (double)(end - start)/1000);
	    for(i = 0;i < BUFFERSIZE;i ++) {
		buffer[i] = 0;
	    }
	    i = 0;
	}	
	return 0;
}
