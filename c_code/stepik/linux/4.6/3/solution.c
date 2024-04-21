/*Разработать приложение, умеющее обрабатывать сигналы SIGUSR1 ,SIGUSR2, SIGTERM. После старта Ваше приложение должно по приходу одного из сигналов SIGUSR1,  SIGUSR2 выполнять суммирование числа срабатываний каждого из сигналов, а после прихода сигнала SIGTERM, требуется вывести в стандартный поток вывода 2 числа, разделенных пробелом, соответствующих количеству обработанных сигналов SIGUSR1, SIGUSR2, и завершить программу. Вывод оканчивается символом конца строки.*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

volatile int sigusr1_count = 0;
volatile int sigusr2_count = 0;

void sigusr1_handler(int signum) {
    sigusr1_count++;
}

void sigusr2_handler(int signum) {
    sigusr2_count++;
}

void sigterm_handler(int signum) {
    printf("%d %d\n", sigusr1_count, sigusr2_count);
    exit(0);
}

int main() {
    // Установка обработчиков сигналов
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);
    signal(SIGTERM, sigterm_handler);

    // Бесконечный цикл ожидания сигналов
    while (1) {
        pause(); // Приостанавливаем выполнение процесса до прихода сигнала
    }

    return 0;
}

# Makefile

CC=gcc
CFLAGS=-Wall

all: solution

solution: solution.o
	$(CC) $(CFLAGS) -o solution solution.o

solution.o: solution.c
	$(CC) $(CFLAGS) -c solution.c

clean:
	rm -f solution.o solution
