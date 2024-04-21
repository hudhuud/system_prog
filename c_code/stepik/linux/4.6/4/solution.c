/*Задача -- снабдить демон обработчиком сигнала SIGURG, по приходу которого демон должен завершать свою работу.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>

void sigurg_handler(int signum) {
    printf("Received SIGURG signal. Exiting...\n");
    exit(0);
}

void daemonize() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid > 0) {
        // Родительский процесс завершает свою работу
        exit(0);
    }

    // Новый сеанс
    if (setsid() < 0) {
        perror("setsid");
        exit(1);
    }

    // Изменение текущего рабочего каталога
    if (chdir("/") < 0) {
        perror("chdir");
        exit(1);
    }

    // Закрываем стандартные потоки ввода/вывода/ошибок
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // Открытие лог-файла для записи
    open("/dev/null", O_RDONLY);
    open("/dev/null", O_RDWR);
    open("/dev/null", O_RDWR);
}

int main() {
    daemonize();

    // Установка обработчика сигнала SIGURG
    struct sigaction sa;
    sa.sa_handler = sigurg_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGURG, &sa, NULL);

    // Получение PID и его вывод
    pid_t pid = getpid();
    printf("%d\n", pid);

    // Бесконечный цикл ожидания сигналов
    while (1) {
        pause(); // Приостанавливаем выполнение процесса до прихода сигнала
    }

    return 0;
}

#makefile
CC=gcc
CFLAGS=-Wall

all: solution

solution: solution.o
	$(CC) $(CFLAGS) -o solution solution.o

solution.o: solution.c
	$(CC) $(CFLAGS) -c solution.c

clean:
	rm -f solution.o solution
