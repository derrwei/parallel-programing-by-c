#include <stdio.h>

#include "random.h"

#define NUM_VALUES 250
signed long long int values[NUM_VALUES];

int main()
{

	float sum = 0;		// sum is a an unsigned long long int as it adds only positive integer values
	float average;			// average is unsigned as all random numbers are positive. It does not need to be 64bit as the value can not exceed the range.
	float min = 0;			// can be signed as we normalise so the range can not be exceeded
	float max = 0;			// can be signed as we normalise so the range can not be exceeded

	unsigned char i;				// unsigned to ensure that we can hold the full range of 0-255

	init_random();

	for (i = 0; i < NUM_VALUES; i++) {

		values[i] = random_uint();		// values is 64 bit signed so it will not overflow holding a 32 bit unsigned number

		sum += values[i];				// sum will not overflow as it is 64bit
		//printf("value = %u, sum = %llu\n", values[i], sum);
	}

	average = (float)(sum / NUM_VALUES);	// once sum is divided by NUM_VALUES ist will be in 32 bit unsigned range (it can not be larger than the largest unsigned int returned from random_uint())

	for (i = 0; i < NUM_VALUES; i++) {
		values[i] -= average;										// values is signed so it can hold the normalised values
		min = (values[i] < min) ? values[i] : min;
		max = (values[i] > max) ? values[i] : max;
	}

	printf("Sum is %.0f\n", sum);
	printf("Average is %.0f\n", average);
	printf("Min is %.0f\n", min);
	printf("Max is %.0f\n", max);
	return 0;
}