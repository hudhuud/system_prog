Разработайте TCP сервер, предназначенный для сортировки символов в строке. Сервер получает на вход строки, оканчивающиеся символом '\0', сортирует в них символы в порядке убывания ASCII-кодов и отсылает обратно на клиент, в виде строки заканчивающейся '\0'. Завершение работы сервера происходит после получения строки, содержащей только 'OFF'. 

При старте сервер получает на вход номер порта в качестве параметра командной строки. bind производится на адресе 127.0.0.1



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_MESSAGE_SIZE 512
#define SERVER_IP "127.0.0.1"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void sort_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] < str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <порт>\n", argv[0]);
        exit(1);
    }

    int portno = atoi(argv[1]);
    if (portno < 0 || portno > 65535) {
        fprintf(stderr, "Порт должен быть числом от 0 до 65535\n");
        exit(1);
    }

    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[MAX_MESSAGE_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Ошибка открытия сокета");
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Ошибка привязки сокета");
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            error("Ошибка при принятии соединения");
        }

        while (1) {
            int n = read(newsockfd, buffer, MAX_MESSAGE_SIZE - 1);
            if (n < 0) {
                error("Ошибка при чтении сокета");
            }
            if (n == 0 || strncmp("OFF", buffer, 3) == 0) {
                break;
            }

            sort_string(buffer);
            int len = strlen(buffer);
            buffer[len] = '\0';
            strcat(buffer, "\n");

            n = write(newsockfd, buffer, strlen(buffer));
            if (n < 0) {
                error("Ошибка при записи в сокет");
            }
        }

        close(newsockfd);
        if (strncmp("OFF", buffer, 3) == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}
аааа сложнооо....

CC=gcc
CFLAGS=-Wall -std=c99

all: solution

solution: solution.o
	$(CC) $(CFLAGS) -o solution solution.o

solution.o: solution.c
	$(CC) $(CFLAGS) -c solution.c

clean:
	rm -f solution.o solution
