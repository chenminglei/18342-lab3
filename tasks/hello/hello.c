/** @file hello.c
 *
 * @brief Prints out Hello world using the syscall interface.
 *
 * Links to libc.
 *
 * @author Kartik Subramanian <ksubrama@andrew.cmu.edu>
 * @date   2008-10-29
 */
#include <unistd.h>
#include <stdio.h>
int main(int argc, char** argv)
{
        sleep(30);
       // unsigned long t = time();
	//printf("rest\n");
	//printf("rest\n");
//	sleep(70); 
	unsigned long t = time();
	return t;
}
