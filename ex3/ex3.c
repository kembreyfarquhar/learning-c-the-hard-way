#include <stdio.h> 

int main(int argc, char *argv[])
{
	int age = 29;
	int height = 71;
	char * name = "Katie";
	double eggs = 1.5;
	
	//printf("%s", argv[5000]); create stack overflow error
	
	printf("I am %d years old.\n", age);
	printf("I am %d inches tall.\n", height);
	printf("My name is %s.\n", name);
	printf("I have %f eggs.\n", eggs);
	
	printf("Here we go...\n");
	
	printf("Alert \a\a\a\a\n");
	printf("My\t name\n is \t %s and I am \t %d years old.\n", name, age);
	
	printf("Vertical \v Tab.\n");
	//printf("Backspace\b\b\b\n"); //No idea
	printf("Carriage hello \r Return this line\n");
	printf("Formfeed \f\n");
	
	return 0;
}