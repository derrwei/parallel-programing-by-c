#include<stdio.h>
#include"random.h"

//consistant define
#define NUM_VALUES 250
// global variables
int values[NUM_VALUES];

int main()
{
	// unsigned means no negative num
	unsigned int sum = 0;
	int min = 0;
	int max = 0;
	unsigned char i;
	init_random();

	for (i = 0; i < NUM_VALUES; i++)
	{
		values[i] = random_ushort();
		//printf("%hhu: %hu\n", i, values[i]);
		sum += values[i];
	}

	unsigned int average;
	average = sum / NUM_VALUES;
	for (i = 0; i < NUM_VALUES; i++) {
		values[i] -= average;
		min = (values[i] < min) ? values[i] : min;
		max = (values[i] > max) ? values[i] : max;
	}

	printf("Sum=%u\n", sum);
	printf("Average=%u\n", average);
	printf("Min=%d\n", min);
	printf("Max=%d\n", max);
	return 0;
}
