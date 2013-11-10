/**
 * funtime.c: Horse Betting game
 *
 * Authors: Di Li <dil1@andrew.cmu.edu>
 *          Zhe Shen <zshen@andrew.cmu.edu>
 *          Minglei Chen <mingleic@andrew.cmu.edu>
 * Date:    00:37 AM  Nov 9th 2013
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define DISTANCE 15
#define STDIN  0
#define BUFFERSIZE 1

/*
 * Generate random steps for one horse
 */
int stepsGen(int* steps) {
	int count = 0;
	int num = 0;
	for (num = 0; count < DISTANCE; ++num) {
		int temp = rand() % 2 + 1;
		count += temp;
		if (num > 0) {
			temp += steps[num - 1];
		}
		steps[num] = temp;

	}
	return num - 1;
}

/*
 * get the minimal number of three numbers
 */
int minOfThree(int num1, int num2, int num3) {
	int result = 0;
	if (num1 < num2) {
		result = num1;
	} else {
		result = num2;
	}
	if (result < num3) {
		return result;
	}
	return num3;
}

/*
 * Simulate one horse's running
 */
void run(int line, int* steps, int min, int* curr) {
	if ((*curr) <= min && line == steps[*curr]) {
		printf("1");
		++(*curr);
	} else {
		printf(" ");
	}
}

/*
 * To know who win the game
 */
int getWinner(int min, int* num) {
	if (num[0] == min)
		return 1;
	if (num[1] == min)
		return 2;
	return 3;
}

int main(int argc, char** argv) {

	// random steps of three horse
	int steps[3][DISTANCE];
	// number of steps for each horse to pass the finishing line
	int num[3];
	// least number of steps to pass the finishing line
	int min = 0;
	// receive user's input
	char input[BUFFERSIZE] = { 0 };
	// for loop control variable
	int i = 0;

	while (1) {
		srand((unsigned int) time());
		for (i = 0; i < 3; ++i) {
			memset(steps[i], 0, sizeof(steps[i]));
		}
		memset(num, 0, sizeof(num));
		memset(input, 0, sizeof(input));
		// get and process user input
		while (input[0] - '0' < 1 || input[0] - '0' > 3) {
			printf("The number (1-3) of the horses you bet('q' to quit): \n");

			read(STDIN, input, 1);
			if (input[0] != '\n') {
				printf("\n");
			}

			if (input[0] - 'q' == 0)
				return 0;
		}
		// generate random and fair steps for three horses
		while ((steps[0][min] < DISTANCE + 1 && steps[1][min] < DISTANCE + 1
				&& steps[2][min] < DISTANCE + 1) || num[0] == num[1]
				|| num[0] == num[2] || num[1] == num[2]) {
			num[0] = stepsGen(steps[0]);
			num[1] = stepsGen(steps[1]);
			num[2] = stepsGen(steps[2]);
			min = minOfThree(num[0], num[1], num[2]);
		}
		// get winner
		int winner = getWinner(min, num);

		min = minOfThree(num[0], num[1], num[2]);
		int i = 0;
		int curr1 = 0, curr2 = 0, curr3 = 0;
		printf("Race start!\n 111\n---\n");
		// simulate the game
		for (i = 1; i <= DISTANCE + 1; ++i) {
			run(i, steps[0], min, &curr1);
			run(i, steps[1], min, &curr2);
			run(i, steps[2], min, &curr3);
			printf("\n");
			if (i == DISTANCE) {
				printf("---\n");
			}
			sleep(100);
		}
		// show result
		if (input[0] - '0' == winner) {
			printf("Win! Try it again!\n");
		} else {
			printf("Failed! How could you lose the game!\n");
		}
	}

	return 0;
}
