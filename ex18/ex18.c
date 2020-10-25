#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die from ex17. */
void die(const char *message)
{
	if(errno){
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	exit(1);
}

//a typedef creates a fake type, in this
//case for a function pointer
typedef int (*compare_cb)(int a, int b);

int sorted_order(int a, int b)
{
	return a - b;
}

int reverse_order(int a, int b)
{
	return b - a;
}

int strange_order(int a, int b)
{
	if(a == 0 || b == 0) {
		return 0;
	} else {
		return a % b;
	}
}

char *fname(int (*compare_cb)(int, int)) {
	if (compare_cb == sorted_order) return "sorted_order";
	if (compare_cb == reverse_order) return "reverse_order";
	if (compare_cb == strange_order) return "strange_order";
	return "unknown";
}

/* 
A classic bubble sort function that uses the 
compare_cb to do the sorting.
*/
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
	int temp = 0;
	int i = 0;
	int j = 0;
	//target is an array, allocated with the amount
	//of elements equal to count (* sizeof(int) due to byte size)
	int *target = malloc(count * sizeof(int));
	
	if(!target)
		die("Memory error.");
		
	memcpy(target, numbers, count * sizeof(int));
	
	for(i = 0; i < count; i++) {
		for(j = 0; j < count - 1; j++) {
			if(cmp(target[j], target[j + 1]) > 0) {
				temp = target[j + 1];
				target[j + 1] = target[j];
				target[j] = temp;
			}
		}
	}
	return target;
}

/* 
Used to test that we are sorting things correctly
by doing the sort and printing it out.
*/

void test_sorting(int *numbers, int count, compare_cb cmp)
{
	printf("\n");
	
	int i = 0;
	int *sorted = bubble_sort(numbers, count, cmp);
	
	if(!sorted)
		die("Failed to sort as requested.");
		
	printf("\n\n");

	for(i = 0; i < count; i++) {
		printf("%d ", sorted[i]);
	}
	
	printf("\n");
	
	printf("CMP POINTER FOR %s:\n", fname(cmp));
	unsigned char *data = (unsigned char *)cmp;
	
	for(i=0;i<25;i++){
		printf("%02x:", data[i]);
	}
	
	printf("\n");
	
	free(sorted);
}

int main(int argc, char *argv[])
{
	if(argc < 2) die("USAGE: ex18 4 3 1 5 6");
	
	int count = argc - 1;
	int i = 0;
	char **inputs = argv + 1;
	int *numbers = malloc(count * sizeof(int));
	if(!numbers) die("Memory error.");
	
	printf("\n\nINPUT:\n");
	for (i = 0; i < count; i++) {
		numbers[i] = atoi(inputs[i]);
		printf("%s ", inputs[i]);
	}
	
	printf("\n");
	
	test_sorting(numbers, count, sorted_order);
	printf("POINTER FOR %s:\n", "sorted_order");
	unsigned char *data1 = (unsigned char *)sorted_order;
	for(i=0;i<25;i++){
		printf("%02x:", data1[i]);
	}
	test_sorting(numbers, count, reverse_order);
	printf("POINTER FOR %s:\n", "reverse_order");
	unsigned char *data2 = (unsigned char *)reverse_order;
	for(i=0;i<25;i++){
		printf("%02x:", data2[i]);
	}
	test_sorting(numbers, count, strange_order);
	printf("POINTER FOR %s:\n", "strange_order");
	unsigned char *data3 = (unsigned char *)strange_order;
	for(i=0;i<25;i++){
		printf("%02x:", data3[i]);
	}
	free(numbers);
	
	return 0;
}
