#include <stdio.h>
// another lib
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define _CRT_SECURE_NO_WARNINGS

#define BUFFER_SIZE 32

int readLine(char buffer[]);

int main()
{
	float in_value, sum;
	char buffer[BUFFER_SIZE];
	char command[4];
	sum = 0;

	printf("Welcome to basic COM4521 calculator\nEnter command: ");

	while (readLine(buffer)) {

		// Ex 4.5, Check the value of the first 4 elements of the buffer
		// isalpha() is a utility function found in the system header ctype.h, which returns true if the passed character is alphabetic
		// See documentation: https://www.cplusplus.com/reference/cctype/isalpha/
		if (!(isalpha(buffer[0]) && isalpha(buffer[1]) && isalpha(buffer[2]) && buffer[3] == ' ')) {
			fprintf(stderr, "Incorrect command format\n");
			continue;
		}

		// Ex 4.6, sscanf() reads in data according to a specified format
		// The format strings use the same format specifiers as printf()
		// The return values are provided to the trailing arguments, the pointer to these variables must be passed
		// So `&in_value` is used to get the address in memory where the variable in_value resides.
		// This allows sscanf() to write to the in_value
		// See documentation: https://www.cplusplus.com/reference/cstdio/sscanf/
		sscanf(buffer, "%s %f", command, &in_value);
		// Ex 4.7 & 4.8, strcmp() is used to provide more comparisons
		// Note, here strcmp() is used, rather than strncmp()
		// The difference is that strncmp() requires a length to be specified
		// In contrast, strncmp() looks for the null terminating character to assume length
		// See documentation: https://www.cplusplus.com/reference/cstring/strcmp/
		if (strcmp(command, "add") == 0) {
			sum += in_value;
		}
		else if (strcmp(command, "sub") == 0) {
			sum -= in_value;
		}
		else if (strcmp(command, "div") == 0) {
			sum /= in_value;
		}
		else if (strcmp(command, "mul") == 0) {
			sum *= in_value;
		}
		// Ex 4.9, Further comparisons using strncmp()
		else if (strncmp(command, "ad", 2) == 0) {
			printf("Did you mean add?\n");
			continue;
		}
		else if (strncmp(command, "su", 2) == 0) {
			printf("Did you mean sub?\n");
			continue;
		}
		else if (strncmp(command, "mu", 2) == 0) {
			printf("Did you mean mul?\n");
			continue;
		}
		else if (strncmp(command, "di", 2) == 0) {
			printf("Did you mean div?\n");
			continue;
		}

		else {
			fprintf(stderr, "Unknown command!\n");
			continue;
		}

		printf("\tSum is %f\n", sum);
		printf("Enter command: ");
	}

	return 0;
}

int readLine(char buffer[]) {
	int i = 0;
	char c;
	while ((c = getchar()) != '\n'){
		buffer[i++] = c;

		if (i == BUFFER_SIZE) {
			fprintf(stderr, "Buffer size is too small\n");
			exit(0);
		}
	}
	buffer[i] = '\0';
	if (strncmp(buffer, "exit", 4))
		return 0;
	else
		return 1;
}