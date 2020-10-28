#include "ex22.h"
#include "../dbg.h"

const char *MY_NAME = "Katie Embrey-Farquhar";

void increment_count(int *count, int amount)
{
	*count += amount;
}

void decrement_count(int *count, int amount)
{
	*count -= amount;
}

void scope_demo(int count)
{
	log_info("count is: %d", count);
	
	if(count > 10) {
		int count = 100; //BAD! BUGS!
		
		log_info("count in this scope is %d", count);
	}
	
	log_info("count is at exit: %d", count);
	
	count = 3000;
	
	log_info("count after assign: %d", count);
}

int main(int argc, char *argv[])
{
	//test out THE_AGE accessors
	log_info("My name: %s, age: %d", MY_NAME, get_age());
	
	set_age(100);
	
	log_info("My age is now: %d", get_age());
	
	//test out THE_SIZE extern
	log_info("THE_SIZE is: %d", THE_SIZE);
	print_size();
	
	THE_SIZE = 9;
	
	log_info("THE_SIZE is now: %d", THE_SIZE);
	print_size();
	
	//test out the ratio function static
	log_info("Ratio at first: %f", update_ratio(2.0));
	log_info("Ratio again: %f", update_ratio(10.0));
	log_info("Ratio once more: %f", update_ratio(300.0));
	
	//setting up variable count, as well as a pointer to it
	int count = 4;
	int *count_pointer;
	count_pointer = &count;
	
	//test the scope demo - this is passing by value, nothing will affect the 
	//count variable created here by doing it this way
	scope_demo(count);
	scope_demo(count * 20);
	log_info("count after calling scope_demo: %d", count);
	
	//increment_count and decrement_count use passing by reference (a pointer)
	//this allows the functions to change the value stored in the specified address
	printf("count: %d\n", count);
	increment_count(count_pointer, 10);
	printf("count after incrementing 10: %d\n", count);
	decrement_count(count_pointer, 20);
	printf("count after decrementing 20: %d\n", count);
	
	
	return 0;
}