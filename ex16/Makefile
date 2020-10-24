CFLAGS=-Wall -g

all: 
	cc -Wall -g ex16.c -o ex16 -fsanitize=address
	cc -Wall -g book_ex16.c -o bookex16
	cc -Wall -g extracredit.c -o credit -fsanitize=address
	
clean:
	rm -f ex16
	rm -f bookex16
	rm -f credit