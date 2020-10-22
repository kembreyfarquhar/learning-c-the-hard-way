#include <stdio.h>
#include <string.h>
#include <strings.h>

int main(int argc, char *argv[])
{
	//removing first argument of ./ex8
	int x = 0;
	for (x = 0; x < argc-1; x++) {
		argv[x] = argv[x + 1];
	}
	argc = argc - 1;
	
	printf("Numer of arguments passed in is %d.\n", argc);
	
	int i = 0;
	if (argc ==1) {
		printf("You only have one argument. You suck.\n");
	} else if (argc > 1 && argc < 4) {
		printf("Here's your arguments:\n");
		
		for (i = 0; i < argc; i++) {
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else {
		printf("You have too many arguments. You suck.\n");
	}
	
	return 0;
}