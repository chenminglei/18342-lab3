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
