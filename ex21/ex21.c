#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void bin(unsigned n) 
{ 
    /* step 1 */
    if (n > 1) 
        bin(n/2); 
  
    /* step 2 */
    printf("%d", n % 2); 
} 

int main(int argc, char *argv[])
{
	//types
	//SIGNED-------
	//8 bit int, ranging from -128 to 127
	int8_t eight_bit = 127;
	printf("8bit: %d\n", eight_bit);
	//16 bit int, ranging from -32768 to 32767
	int16_t sixteen_bit = 32767;
	printf("16bit: %d\n", sixteen_bit);
	//32 bit int, ranging from -2147483648 to 2147483647
	int32_t thirtytwo_bit = 2147483647;
	printf("32bit: %d\n", thirtytwo_bit);
	//64 bit int, ranging from -9223372036854775808 to 9223372036854775807
	int64_t sixtyfour_bit = 9223372036854775807;
	printf("64bit: %lld\n", sixtyfour_bit);
	//UNSIGNED--------
	//only positives, max values...
	uint8_t unsigned_eight_bit = 255;
	printf("u8bit: %u\n", unsigned_eight_bit);
	uint16_t unsigned_sixteen_bit = 65535;
	printf("u16bit: %u\n", unsigned_sixteen_bit);
	uint32_t unsigned_thirtytwo_bit = 4294967295;
	printf("u32bit: %u\n", unsigned_thirtytwo_bit);
	uint64_t unsigned_sixtyfour_bit = 18446744073709551615;
	printf("u64bit: %llu\n", unsigned_sixtyfour_bit);

	//printing out min and max values for each type...
	printf("INT8_MIN-INT8_MAX: %d to %d\n", INT8_MIN, INT8_MAX);
	printf("INT16_MIN-INT16_MAX: %d to %d\n", INT16_MIN, INT16_MAX);
	printf("INT32_MIN-INT32_MAX: %d to %d\n", INT32_MIN, INT32_MAX);
	printf("INT64_MIN-INT64_MAX: %lld to %lld\n", INT64_MIN, INT64_MAX);
	
	printf("UINT8_MAX: %u\n", UINT8_MAX);
	printf("UINT16_MAX: %u\n", UINT16_MAX);
	printf("UINT32_MAX: %u\n", UINT32_MAX);
	printf("UINT64_MAX: %llu\n", UINT64_MAX);
	
	return 0;
}