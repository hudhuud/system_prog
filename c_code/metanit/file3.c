#include <stdio.h>

int main() {
    // Задаем размер буфера
    int N = 20;
    char str[N];   // Определяем буфер достаточной длины

    // Открываем файл для чтения
    FILE *fp = fopen("data.txt", "r");

    // Чтение данных из файла и получение количества прочитанных элементов
    int count = fread(str, sizeof str[0], N, fp);

    // Проверка успешности чтения
    if (count == N) {
        // Вывод содержимого строки
        printf("%s \n", str);
    } else {
        // Проверка причины ошибки
        if (feof(fp)) {
            // Если достигнут конец файла
            printf("Unexpected end of file\n");
            printf("Available: %s", str);
        } else if (ferror(fp)) {
            // Если произошла ошибка ввода/вывода
            perror("Error while reading file\n");
        }
    }

    // Закрываем файл
    fclose(fp);
}
