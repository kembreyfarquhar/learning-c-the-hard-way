#include <stdio.h>

int main(int argc, char *argv[])
{

	for (int y = argc-1; y > 0; y--) {
		char letter = argv[y][0];
		
		switch (letter) {
			case 'a':
			case 'A':
				printf("%d: 'A'\n", y);
				break;
				
			case 'e':
			case 'E':
				printf("%d: 'E'\n", y);
				break;
				
			case 'i':
			case 'I':
				printf("%d: 'I'\n", y);
				break;
				
			case 'o':
			case 'O':
				printf("%d: 'O'\n", y);
				break;
				
			case 'u':
			case 'U':
				printf("%d: 'U'\n", y);
				break;
				
			case 'y':
			case 'Y':
				if (y > 2) {
					//it's only sometimes y
					printf("%d: 'Y'\n", y);
				}
				break;
				
			default:
				printf("%d: %c is not a vowel\n", y, letter);
		}
	}

	int i = 0;
	
	//go through each string in argv
	//Why am I skipping argv[0]?
	for (i = 1; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}
	
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