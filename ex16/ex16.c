#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
	char *hobbies[3];
};

struct Person *Person_create(char *name, int age, int height, int weight, char *hobbies[])
{
	//malloc allocates the requested memory and returns a pointer to it
	//*who is the pointer to the person being constructed
	struct Person *who = malloc(sizeof(struct Person));
	//assert evaluates an expression
	//if true, nothing will happen
	//if false, error will occur and the program will exit
	assert(who != NULL);
	
	//strdup returns a pointer to a null-terminated byte string 
	//and can be terminated using free
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;
	for(int i = 0; i < 3; i++) {
		who->hobbies[i] = strdup(hobbies[i]);
	}
	
	return who;
}

void Person_destroy(struct Person *who)
{
	assert(who != NULL);
	
	free(who->name);
	for(int i = 0; i < 3; i++) {
		free(who->hobbies[i]);
	}
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
	printf("\tHobbies: %s, %s, and %s\n", who->hobbies[0], who->hobbies[1], who->hobbies[2]);
}

void update_person(struct Person *who, char *name, int age, int height, int weight, char *hobbies[])
{
	assert(who != NULL);
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;
	for (int i = 0; i < 3; i ++) {
		who->hobbies[i] = strdup(hobbies[i]);
	}
}

int main(int argc, char *argv[])
{
	//make two people structures
	char *joe_hobbies[] = { "Hiking", "skiing", "cooking" };
	char *frank_hobbies[] = { "Reading", "coding", "math" };
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140, joe_hobbies);
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180, frank_hobbies);
	
	//print them out and where they are in memory
	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);
	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);
	
	//update people using update_person function
	joe_hobbies[0] = "Relaxing";
	joe_hobbies[1] = "drinking tea";
	update_person(joe, joe->name, 35, 64, 142, joe_hobbies);
	Person_print(joe);
	update_person(frank, "Frank New", 26, 74, 182, frank->hobbies);
	Person_print(frank);
	
	//destroy them both so we clean up
	Person_destroy(joe);
	Person_destroy(frank);
	
	return 0;
}