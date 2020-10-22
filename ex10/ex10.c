#include <stdio.h>
#include <ctype.h>

int convert_upper_to_lower(char letter)
{
	return tolower(letter);
}

int main(int argc, char *argv[])
{

	printf("\nSWITCH CASE CHECKING FOR VOWELS:\n");
	for (int y = argc-1; y > 0; y--) {
		char letter = argv[y][0];
		letter = convert_upper_to_lower(letter);
		
		switch (letter) {
			case 'a':
				printf("%d: 'A'\n", y);
				break;
				
			case 'e':
				printf("%d: 'E'\n", y);
				break;
				
			case 'i':
				printf("%d: 'I'\n", y);
				break;
				
			case 'o':
				printf("%d: 'O'\n", y);
				break;
				
			case 'u':
				printf("%d: 'U'\n", y);
				break;
				
			case 'y':
				if (y > 2) {
					//it's only sometimes y
					printf("%d: 'Y'\n", y);
				}
				break;
				
			default:
				printf("%d: %c is not a vowel\n", y, letter);
		}
	}
	
	
	printf("\nLOOP TO DISPLAY ALL ARGUMENTS:\n");
	int i = 0;
	
	//go through each string in argv
	//Why am I skipping argv[0]?
	for (i = 1; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}
	
	printf("\nLOOP DISPLAYING ALL STATES IN THE STATES ARR:\n");
	//let's make our own array of strings
	char *states[] = {
		"California", "Oregon", "Washington", "Texas"
	};
	
	int num_states = 4;
	int x = 0;
	for (x = 0; x < num_states; x++) {
		printf("state %d: %s\n", x, states[x]);
	}
	
	return 0;
}