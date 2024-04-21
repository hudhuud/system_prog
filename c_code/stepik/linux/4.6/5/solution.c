/*В системе существуют 2 региона разделяемой памяти, заполненной некоторыми числами (типа int). Каждый из регионов имеет размер 1000 байт. Вам требуется разработать приложение, которое попарно суммирует первые 100 чисел в этих регионах и помещает суммы в новый (созданный вашим приложением) регион памяти размером 1000 байт. Таким образом, после завершения работы Вашего приложения в памяти должен существовать регион разделяемой памяти размером 1000 байт, содержащий в начале 100 сумм. Перед завершением работы приложение выводит в стандартный поток ввода-вывода ключ созданного региона, завершающийся символом конца строки. На вход ваше приложение принимает ключи существующих регионов памяти.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1000

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "%s key1 key2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    key_t key1 = atoi(argv[1]);
    key_t key2 = atoi(argv[2]);
    key_t new_key;

    // Получаем идентификаторы разделяемых сегментов памяти
    int shmid1 = shmget(key1, SHM_SIZE, 0666);
    int shmid2 = shmget(key2, SHM_SIZE, 0666);

    if (shmid1 == -1 || shmid2 == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Получаем указатели на разделяемые сегменты памяти
    int *shm1 = (int *) shmat(shmid1, NULL, 0);
    int *shm2 = (int *) shmat(shmid2, NULL, 0);
    int *new_shm;

    if (shm1 == (int *) -1 || shm2 == (int *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Создаем новый разделяемый сегмент памяти
    new_key = ftok(".", 'B');
    int new_shmid = shmget(new_key, SHM_SIZE, IPC_CREAT | 0666);

    if (new_shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Получаем указатель на новый разделяемый сегмент памяти
    new_shm = (int *) shmat(new_shmid, NULL, 0);

    if (new_shm == (int *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Выполняем суммирование и записываем результат в новый разделяемый сегмент
    for (int i = 0; i < 100; i++) {
        new_shm[i] = shm1[i] + shm2[i];
    }

    // Отсоединяем разделяемые сегменты памяти
    shmdt(shm1);
    shmdt(shm2);
    shmdt(new_shm);

    // Выводим ключ созданного региона памяти
    printf("%d\n", new_key);

    return 0;
}

makefile
CC=gcc
CFLAGS=-Wall -std=c99 -D_SVID_SOURCE

all: solution

solution: solution.o
	$(CC) $(CFLAGS) -o solution solution.o

solution.o: solution.c
	$(CC) $(CFLAGS) -c solution.c

clean:
	rm -f solution.o solution

