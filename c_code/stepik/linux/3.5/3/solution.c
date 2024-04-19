#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_process_path(int pid) {
    // Выводим текущий PID
    printf("%d\n", pid);

    // Если PID равен 1, завершаем функцию
    if (pid == 1) {
        return;
    }

    // Открытие файла /proc/<pid>/status для чтения
    char filename[256];
    snprintf(filename, sizeof(filename), "/proc/%d/status", pid);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Ошибка при открытии файла /proc/%d/status\n", pid);
        return;
    }

    // Поиск строки с информацией о родительском PID
    char line[256];
    int parent_pid = -1;
    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "PPid:", 5) == 0) {
            sscanf(line, "PPid:\t%d", &parent_pid);
            break;
        }
    }

    // Закрытие файла
    fclose(fp);

    // Рекурсивный вызов для родительского процесса
    print_process_path(parent_pid);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <pid>\n", argv[0]);
        return 1;
    }

    // Получение PID из аргумента командной строки
    int pid = atoi(argv[1]);

    // Печать пути в дереве процессов
    print_process_path(pid);

    return 0;
}


//просто код из первой задачи с рекурсией
какие ошибки возникали:
не выводилась единица
вывод наоборот из за рекурсии
