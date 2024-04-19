'''Некоторая утилита генерирует довольно большой вывод, а вам требуется всего-лишь посчитать количество символов '0' в этом выводе. Утилита при запуске принимает 1 параметр. Вам требуется разработать программу, которая вызывает указанную утилиту, с заданным параметром и подсчитывает количество символов '0' в ее выводе. Ваша программа принимает на вход 2 параметра -- имя утилиты, в текущем каталоге и ее параметр. Ваша программа должна после подсчета вывести найденное число '0' в отдельной строке, заканчивающейся символом конца строки.

Пример вызова


./solution someprog param
234222'''


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    // Проверка наличия двух аргументов (имени утилиты и ее параметра)
    if (argc != 3) {
        fprintf(stderr, "Использование: %s <имя_утилиты> <параметр>\n", argv[0]);
        return 1;
    }

    // Создание канала для связи с дочерним процессом
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Ошибка при создании канала");
        return 1;
    }

    // Создание дочернего процесса
    pid_t pid = fork();

    if (pid == -1) {
        perror("Ошибка при создании процесса");
        return 1;
    } else if (pid == 0) { // Код дочернего процесса
        // Перенаправление стандартного вывода в канал
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);

        // Запуск указанной утилиты с заданным параметром
        execlp(argv[1], argv[1], argv[2], NULL);

        // В случае ошибки при выполнении утилиты
        perror("Ошибка при запуске утилиты");
        exit(1);
    } else { // Код родительского процесса
        close(pipefd[1]); // Закрываем конец записи канала, используем только чтение

        // Счетчик для подсчета символов '0'
        int count = 0;
        char buffer[BUFSIZ];
        ssize_t bytes_read;

        // Чтение данных из канала и подсчет символов '0'
        while ((bytes_read = read(pipefd[0], buffer, BUFSIZ)) > 0) {
            for (ssize_t i = 0; i < bytes_read; i++) {
                if (buffer[i] == '0') {
                    count++;
                }
            }
        }

        // Вывод количества символов '0'
        printf("%d\n", count);

        // Закрытие конечного чтения канала
        close(pipefd[0]);
    }

    return 0;
}


makefile:
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99

all: solution

solution: solution.o
	$(CC) $(CFLAGS) -o solution solution.o

solution.o: solution.c
	$(CC) $(CFLAGS) -c solution.c

clean:
	rm -f solution solution.o


пришлось указывать c99 тк степик не принимал for с объявлением переменных в нем 
