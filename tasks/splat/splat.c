/** @file splat.c
 *
 * @brief Displays a spinning cursor.
 *
 * Links to libc.
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv)
{
	
	/* Add code here -- put your names at the top. */
	while(1) {
	    printf("\b|");
	    sleep(200);
	    printf("\b/");
	    sleep(200);
	    printf("\b-");
	    sleep(200);
	    printf("\b\\");
	    sleep(200);
	}
	return 0;
}
