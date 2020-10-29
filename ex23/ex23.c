#include <stdio.h>
#include <string.h>
#include "../dbg.h"

int normal_copy(char *from, char *to, int count)
{
	int i = 0;
	
	//copying all contents of *from arr over to *to arr
	for(i=0; i < count; i++) {
		to[i] = from[i];
	}
	
	//i will be whatever int count has been passed in as, due to increment in for loop
	return i;
}

int duffs_device(char *from, char *to, int count)
{
	{
	//this code chunks the loop into 8 pieces
		//125.875 in this case 
		int n = (count + 7) / 8;
		//zero, so it will go to case 0
		switch (count % 8) {
			case 0:
				//start the do-while loop
				do {
					*to++ = *from++;
					case 7:
					*to++ = *from++;
					case 6:
					*to++ = *from++;
					case 5:
					*to++ = *from++;
					case 4:
					*to++ = *from++;
					case 3:
					*to++ = *from++;
					case 2:
					*to++ = *from++;
					case 1:
					*to++ = *from++;
				//decrement n, then check if greater than 0
				//in this case, will loop 125 times
				} while (--n > 0);
		}
	}
	
	//count remains unchanged
	return count;
}

int zeds_device(char *from, char *to, int count)
{
	{
		int n = (count + 7) / 8;
		
		switch (count % 8) {
			case 0:
again:	*to++ = *from++;

			case 7:
		*to++ = *from++;
			case 6:
		*to++ = *from++;
			case 5:
		*to++ = *from++;
			case 4:
		*to++ = *from++;
			case 3:
		*to++ = *from++;
			case 2:
		*to++ = *from++;
			case 1:
		*to++ = *from++;
		if (--n > 0)
			goto again;
		}
	}
	
	//count remains unchanged 
	return count;
}

int valid_copy(char *data, int count, char expects)
{
	//checking whether the contents of *data arr are the expected char
	int i = 0;
	for(i=0; i < count; i++) {
		if (data[i] != expects) {
			log_err("[%d] %c != %c", i, data[i], expects);
			return 0;
		}
	}
	
	return 1;
}

int main(int argc, char *argv[])
{
	char from[1000] = { 'a' };
	char to[1000] = { 'c' };
	int rc = 0;
	
	//set up the from to have some stuff
	memset(from, 'x', 1000);
	//set it to a failure mode
	memset(to, 'y', 1000);
	check(valid_copy(to, 1000, 'y'), "Not initialized right.");
	
	//use normal copy to
	rc = normal_copy(from, to, 1000);
	check(rc == 1000, "Normal copy failed: %d", rc);
	check(valid_copy(to, 1000, 'x'), "Normal copy failed.");
	
	//reset
	memset(to, 'y', 1000);
	
	//duffs version
	rc = duffs_device(from, to, 1000);
	check(rc == 1000, "Duff's device failed: %d", rc);
	check(valid_copy(to, 1000, 'x'), "Duffs device failed copy.");
	
	//reset
	memset(to, 'y', 1000);
	
	//zeds version
	rc = zeds_device(from, to, 1000);
	check(rc == 1000, "Zed's device failed: %d", rc);
	check(valid_copy(to, 1000, 'x'), "Zed's device failed copy.");
	
	return 0;
error:
	return 1;
}
