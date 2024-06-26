Разработайте UDP сервер для логирования (сбора и записи) сообщений. Сервер при запуске принимает параметр -- номер порта, на котором будут приниматься запросы. Каждый запрос приходящий к серверу - строка, не превышающая размер 5K.  Задача сервера -- выводить приходящие строки в стандартный поток ввода-вывода, завершающиеся символом конца строки.

Сервер завершает работу, когда получает строку содержащую только текст 'OFF', и заканчивающуюся символом перевода строки '\n'. 

Сервер использует локальный адрес 127.0.0.1

#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

struct sockaddr_in local;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Format %s port \n", argv[0]);
        return 1;
    }

    (void) argv;

    int s = socket(AF_INET, SOCK_DGRAM, 0);
    // printf("%d\n", s);

    inet_aton("127.0.0.1", &local.sin_addr);
    int port = atoi(argv[1]);
    // printf("port: %d\n", port);

    local.sin_port   = htons(port);
    local.sin_family = AF_INET;

    int result = bind(s, (struct sockaddr*) &local, sizeof(local));
    // printf("result: %d\n", result);

    char buffer[BUFSIZ];


    const char* text = "OFF\n";
    while (true)
    {
        ssize_t length = read(s, buffer, BUFSIZ);
        buffer[length] = 0;
        if (strncmp(buffer, text, sizeof(text)) == 0)
            break;

        printf("%s\n", buffer);
    }

    return 0;

CC=gcc
CFLAGS=-Wall -std=c99

all: solution

solution: solution.o
	$(CC) $(CFLAGS) -o solution solution.o

solution.o: solution.c
	$(CC) $(CFLAGS) -c solution.c

clean:
	rm -f solution.o solution

}
