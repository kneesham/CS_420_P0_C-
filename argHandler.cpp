#include <stdio.h>
#include <stdlib.h>

int hasProperArgs(int argc) {
	// Function just checking the arguments passed through the command line.

	int doesHaveArg = 0; 
	// return value for function representing true or false...

	if(argc == 1) {
		// printf("no command line arguments found\n");
		doesHaveArg = 0;
	} else if(argc == 2) {
		// printf("1 command line argument found\n");
		doesHaveArg = 1;
	} else {
		printf("ERROR: There were more command line arguments found than expected.\n");
		exit(0);
	}

	return doesHaveArg;
}
