#include <stdio.h> 

int main(int argc, char *argv[])
{
	printf("\nIF STATEMENT\n\n");
	int x = 5;
	int y = 10;
	
	if(x == y) {
		printf("%d EQUALS %d\n", x, y);
	} else if (x > y) {
		printf("%d IS GREATER THAN %d\n", x, y);	
	} else {
		printf("%d IS LESS THAN %d\n", x, y);
	}
	
	printf("\nWHILE LOOP\n\n");
	int i = 0;
	while (i < 5) {
		printf("%d IS LESS THAN 5\n", i);
		i ++;
	}
	
	printf("\nWHILE-CONTINUE-LOOP\n\n");
	int z = 0;
	while (z < 10) {
		z++;
		if(z % 2 == 0) {
			continue;
		}
		printf("%d IS AN ODD NUMBER LESS THAN 10\n", z);
	}
	
	printf("\nWHILE-BREAK-LOOP\n\n");
	int n = 0;
	while (n < 1000) {
		n++;
		if (n > 15) {
			break;
		}
		printf("%d IS BREAKING BEFORE IT REACHES 16\n", n);
	}
	
	printf("\nDO-WHILE-LOOP\n\n");
	int b = 0;
	do {
		printf("%d IS LESS THAN 6\n", b);
		b++;
	} while (b < 6);
	
	return 0;
}