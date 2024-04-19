#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_descendants(int pid) {
    // Открытие файла /proc/<pid>/task/<pid>/children для чтения
    char filename[256];
    snprintf(filename, sizeof(filename), "/proc/%d/task/%d/children", pid, pid);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Ошибка при открытии файла /proc/%d/task/%d/children\n", pid, pid);
        return -1;
    }

    // Счетчик для хранения количества потомков
    int count = 0;
    // Переменная для считывания PID потомков
    int child_pid;

    // Пока есть PID потомка, увеличиваем счетчик
    while (fscanf(fp, "%d", &child_pid) != EOF) {
        count++;
        // Рекурсивный вызов для подсчета потомков потомка
        count += count_descendants(child_pid);
    }

    // Закрытие файла
    fclose(fp);

    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <pid>\n", argv[0]);
        return 1;
    }

    // Получение PID из аргумента командной строки
    int pid = atoi(argv[1]);

    // Подсчет процессов в поддереве
    int descendants_count = count_descendants(pid);

    if (descendants_count == -1) {
        // Ошибка при подсчете процессов
        return 1;
    }

    // Вывод количества процессов
    printf("%d\n", descendants_count + 1); // +1 для учета самого процесса с указанным PID

    return 0;
}
