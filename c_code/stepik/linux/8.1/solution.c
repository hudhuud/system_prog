#include <stdio.h>
#include <getopt.h>
#include <stdbool.h>

int main(int argc, char** args) {
	int opindex = 0, opchar = 0;
	bool isOk = true;
	
	opterr = 0;

	struct option opts[] = {
		{"query", required_argument, 0, 'q'},
		{"longinformationrequest", no_argument, 0, 'i'},
		{"version", no_argument, 0, 'v'},
		{0, 0, 0, 0},
	};

	while (-1 != (opchar = getopt_long(argc, args, "q:iv", opts, &opindex))) {
		if (opchar == '?') isOk = false;
	}
	
	if (isOk) printf("+\n");
	else printf("-\n");
}

Требуется написать программу solution, выполняющую разбор опций командной строки и выводящую в стандартный поток вывода символ '+', если набор корректен, или '-' в противном случае.

Описание возможных опций:

-q | --query (опциональный, но обязательно требует аргумента)
-i | --longinformationrequest (опциональный)
-v | --version (опциональный)


CC=gcc
CFLAGS=-Wall -std=c99

all: solution

solution: solution.o
	$(CC) $(CFLAGS) -o solution solution.o

solution.o: solution.c
	$(CC) $(CFLAGS) -c solution.c

clean:
	rm -f solution.o solution
