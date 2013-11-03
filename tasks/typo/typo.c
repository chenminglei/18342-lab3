/** @file typo.c
 *
 * @brief Echos characters back with timing data.
 *
 * Links to libc.
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define STDIN  0
#define STDOUT 1
#define BUFFERSIZE 1000

int main(int argc, char** argv) {
	/* Add code here -- put your names at the top. */
	unsigned long start = 0;
	unsigned long end = 0;
	char buffer[BUFFERSIZE] = { 0 };
	int i = 0;
	while (1) {
		i = 0;
		printf(">");
		start = time();
		read(STDIN, buffer, 1000);
		while (i < BUFFERSIZE && buffer[i] != '\0') {
			printf("%c", buffer[i]);
			++i;
		}
		end = time();
		printf("%d\n", (int)start);
		printf("%d\n", (int)end);
		printf("%d\n", (int) ((end - start) / 1000));
	}
	return 0;
}

