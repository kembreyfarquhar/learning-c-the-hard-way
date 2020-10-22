#include <stdio.h>

/* This is a comment. */
int main(int argc, char *argv[])
{
	printf("%d\n", argc);
	for(int i = 0; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
	
	printf("%s", argv[5000]);
	//Segmentation fault: 11-- surpassed memory limit
	
	//printf("You are %ld miles away.\n", distance);
	
	return 0;
}

//to make an executable, run `make filename` 
//to execute, run `./executable` 

/* 
REMOVING THE * BEFORE ARGV[]

ex1.c:4:5: error: second parameter of 'main' (argument array) must be of
      type 'char **'
int main(int argc, char argv[])
    ^
1 error generated.
make: *** [ex1] Error 1
*/

/* 
RETURN ANY INT OTHER THAN 0
REMOVE RETURN STATEMENT

program still works ???????
*/