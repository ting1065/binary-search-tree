# for the convenience of compiling and running the tests

all : bst_tests.c my_bst.c
	gcc -Wall -g -o tests bst_tests.c my_bst.c

clean :
	rm tests