#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *clean_name(char *name, int length);

struct Person {
	char *name;
	int age, height;
};


struct Person Person_create(char *name, int age, int height) 
{	
	struct Person who;
	
	who.name = name;
	who.age = age;
	who.height = height;
	return who;
}

void Person_destroy(struct Person *who){
	who = NULL;
}

void Person_print(struct Person who){
	printf("Name: %s\n", who.name);
	printf("Age: %d\n", who.age);
	printf("Height: %d\n", who.height);
}

char *clean_name(char *name, int length)
{
	char *name_clean = malloc(length + 1);
	for(int i = 0; i < length; i++){
		if(i == length - 1){
			name_clean[i] = '\0';
		} else {
			name_clean[i] = name[i];
		}
	}
	return name_clean;
}

int main(int argc, char *argv[])
{
	//create a person
	char name[20];
	int age, height;
	printf("Please enter a name:\n");
	fgets(name,20,stdin);
	printf("Please enter an age:\n");
	scanf("%d", &age);
	printf("Please enter a height:\n");
	scanf("%d", &height);
	char *n = clean_name(name, strlen(name));
	struct Person input = Person_create(n, age, height);
	Person_print(input);
	Person_destroy(&input);
	
	return 0;
}