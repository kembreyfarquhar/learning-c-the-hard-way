#include <stdio.h>

int main(int argc, char* argv[])
{
	int distance = 100;
	float power = 2.345f;
	double super_power = 56789.4532;
	char initial = 'A';
	char first_name[] = "Zed";
	char last_name[] = "Shaw";
	
	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome super powers.\n", super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have a first name %s.\n", first_name);
	printf("I have a last name %s.\n", last_name);
	printf("My whole name is %s %c. %s.\n", first_name, initial, last_name);
	
	int bugs = 100;
	double bug_rate = 1.2;
	
	printf("You have %d bugs at the imaginary rate of %f.\n", bugs, bug_rate);
	
	long universe_of_defects = 1L * 1024L * 1024L * 1024L;
	unsigned long long big_num = 9999999999999999999;
	int universe_defect_size = sizeof(universe_of_defects);
	int big_num_size = sizeof(big_num);
	printf("Big num is %lld.\n", big_num); //Big num is -8446744073709551617.
	printf("Big num size is %d bytes.\n", big_num_size);
	printf("Universe bugs size is %d bytes.\n", universe_defect_size);
	printf("The universe has %ld bugs.\n", universe_of_defects);
	
	double expected_bugs = bugs * bug_rate;
	printf("You are expected to have %f bugs.\n", expected_bugs);
	
	double part_of_universe = expected_bugs / universe_of_defects;
	printf("That is only a %e portion of the universe.\n", part_of_universe); 
	
	//this makes no sense, just a demo of something weird
	char nul_byte = '\0';
	int care_percentage = bugs * nul_byte;
	int size = sizeof(nul_byte);
	printf("Null byte is %d.\n", size);
	printf("Which means you should care %d%%.\n", care_percentage);
	
	return 0;
}