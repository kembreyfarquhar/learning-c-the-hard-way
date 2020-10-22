#include <stdio.h>

int main(int argc, char *argv[])
{
	//loop through backwards, printing each argument
	int i = argc - 1;
	while (i >= 0) {
		printf("%d: %s\n", i, argv[i]);
		i--;
	}
	
	return 0;
}