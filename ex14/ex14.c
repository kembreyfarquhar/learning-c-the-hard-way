#include <stdio.h>
#include <ctype.h>
#include <string.h>

//forward declarations
int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[])
{
	int i = 0;
	
	//loops through all strings passed as arguments
	for (i = 0; i < argc; i++) {
		print_letters(argv[i]);
	}
}

void print_letters(char arg[])
{
	int i = 0;
	//loops through each string for chars that are not null
	for (i = 0; i < strlen(arg); i++) {
		char ch = arg[i];
		
		if (can_print_it(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}
	
	printf("\n");
}
	
int can_print_it(char ch)
{
	//isalpha() returns 1 if char is alpha char
	//isblank() returns 1 if char is space or tab char
	return isalpha(ch) || isblank(ch);
}
	
//MAIN FUNCTION, SENDS ARGC & ARGV TO PRINT_ARGUMENTS	
int main(int argc, char *argv[])
{
	char space = ' ';
	char tab = '	';
	printf("IS BLANK SPACE: %d\n", isblank(space));
	printf("IS BLANK TAB: %d\n", isblank(tab));
	print_arguments(argc, argv);
	return 0;
}
