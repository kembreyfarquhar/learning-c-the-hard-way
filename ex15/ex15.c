#include <stdio.h>

int function(int x, int y);
int more_math(int(*cb)(int, int));

int function(int x, int y)
{
	return x + y;
}

int more_math(int(*cb)(int, int)) {
	int result = (*cb)(5, 5);
	return result * 2;
}

int main(int argc, char *argv[])
{
	//create two arrays we care about
	int ages[] = { 23, 43, 12, 89, 2 };
	char *names[] = {
		"Alan", "Frank", "Mary", "John", "Lisa"
	};
	
	//safely get the size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;
	
	//first way using indexing
	for (i = 0; i < count; i++) {
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}
	
	printf("---------------\n");
	
	//set up the pointers to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;
	int(*fpointer)(int, int) = &function;
	
	printf("Address of ages: %p\n", ages);
	printf("Address of cur_age: %p\n", cur_age);
	
	printf("Address of names: %p\n", names);
	printf("Address of cur_name: %p\n", cur_name);
	
	printf("Address of function: %p\n", function);
	printf("Address of fpointer: %p\n", fpointer);
	printf("function: %d\n", function(5, 5));
	printf("fpointer: %d\n", (*fpointer)(5, 5));
	
	printf("---------------\n");
	
	//second way of using pointers
	for (i = 0; i < count; i++) {
		printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
	}
	
	printf("---------------\n");
	
	//third way, pointers are just arrays
	for (i = 0; i < count; i++) {
		printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
	}
	
	printf("---------------\n");
	
	//fourth way with pointers in a stupid complex way
	for(cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++) {
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}
	
	int result = more_math(fpointer);
	printf("MORE MATH: (5 + 5) * 2: %d\n", result);
	
	return 0;
}