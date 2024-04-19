'''
  В текущем каталоге есть 2 канала in1 in2, в которые в случайном порядке поступают числа, которые необходимо просуммировать и вывести окончательную сумму на экран. Сумма выводится в отдельной строке, завершающейся символом конца строки. Признаком окончания подачи символов в каналы является закрытие этих каналов посылающей стороной.

Подсказка: для неблокирующего чтения использовать select.
Замечание: ﻿протокол обмена по каналу текстовый, то есть числа представлены строками
Пример вызова


./solution 
795
  '''

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <fcntl.h>

#define BUF_SIZE 32

int main() {
    int in1 = open("in1", O_RDONLY | O_NONBLOCK);
    int in2 = open("in2", O_RDONLY | O_NONBLOCK);

    if (in1 == -1 || in2 == -1) {
        perror("Ошибка при открытии каналов");
        return 1;
    }

    int sum = 0;
    char buf[BUF_SIZE];
    fd_set fds;
    int maxfd = (in1 > in2) ? in1 : in2;
    maxfd++;

    while (1) {
        FD_ZERO(&fds);
        FD_SET(in1, &fds);
        FD_SET(in2, &fds);

        if (select(maxfd, &fds, NULL, NULL, NULL) == -1) {
            perror("Ошибка при использовании select");
            return 1;
        }

        if (FD_ISSET(in1, &fds)) {
            ssize_t bytes_read = read(in1, buf, BUF_SIZE);
            if (bytes_read == -1) {
                perror("Ошибка при чтении из in1");
                return 1;
            } else if (bytes_read == 0) {
                close(in1);
                FD_CLR(in1, &fds);
            } else {
                sum += atoi(buf);
            }
        }

        if (FD_ISSET(in2, &fds)) {
            ssize_t bytes_read = read(in2, buf, BUF_SIZE);
            if (bytes_read == -1) {
                perror("Ошибка при чтении из in2");
                return 1;
            } else if (bytes_read == 0) {
                close(in2);
                FD_CLR(in2, &fds);
            } else {
                sum += atoi(buf);
            }
        }

        if (FD_ISSET(in1, &fds) == 0 && FD_ISSET(in2, &fds) == 0) {
            break;
        }
    }

    printf("%d\n", sum);

    return 0;
}

makefile:
.PHONY: all clean

CFLAGS = -Wall -Wextra -Werror -std=c99

all: solution

solution: solution.c
	gcc $(CFLAGS) -o solution solution.c

clean:
	rm -f solution
