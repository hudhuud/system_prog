#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <hostname>\n", argv[0]);
        return 1;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        herror("Ошибка при вызове gethostbyname");
        return 1;
    }

    for (int i = 0; host->h_addr_list[i] != NULL; ++i) {
        struct in_addr addr;
        memcpy(&addr, host->h_addr_list[i], sizeof(struct in_addr));
        printf("%s\n", inet_ntoa(addr));
    }

    return 0;
}


/*Разработайте утилиту командной строки, принимающую на вход имя хоста и печатающую в стандартный поток вывода список IP-адресов, ассоциированных с данным именем.*/
//просто перепечатал урок из лекции, заработало

CC=gcc
CFLAGS=-Wall -std=c99

all: solution

solution: solution.o
	$(CC) $(CFLAGS) -o solution solution.o

solution.o: solution.c
	$(CC) $(CFLAGS) -c solution.c

clean:
	rm -f solution.o solution
