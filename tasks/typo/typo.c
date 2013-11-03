#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define STDIN  0
#define STDOUT 1
#define BUFFERSIZE 30

int main(int argc, char** argv) {
	/* Add code here -- put your names at the top. */
	unsigned long start = 0;
	unsigned long end = 0;
	char buffer[BUFFERSIZE] = { 0 };
	int i = 0;
	int num = 0;
	while (1) {
		i = 0;
		printf(">");
		start = time();
		num = read(STDIN, buffer, BUFFERSIZE - 2);
		end = time();
		if (num == BUFFERSIZE - 2) {
			buffer[BUFFERSIZE - 2] = '\n';
			buffer[BUFFERSIZE - 1] = '\0';
			printf("\n");
		}

		while (i < BUFFERSIZE && buffer[i] != '\0') {
			printf("%c", buffer[i]);
			++i;
		}

		int diff = end - start;
		printf("%d.%ds\n", diff / 1000, (diff % 1000) / 100);
		memset(buffer,0,BUFFERSIZE);
	}
	return 0;
}

