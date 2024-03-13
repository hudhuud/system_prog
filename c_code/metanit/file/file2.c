#include <stdio.h>

int main() {
    // Задаем размер буфера
    int N = 20;
    char str[N];   // Определяем буфер достаточной длины

    // Открываем файл для чтения
    FILE *fp = fopen("data.txt", "r");

    // Чтение данных из файла и получение количества прочитанных элементов
    size_t count = fread(str, sizeof str[0], N, fp);

    // Вывод информации о количестве прочитанных элементов
    printf("read %zu elements out of %d\n", count, N);

    // Вывод содержимого строки
    printf(str);

    // Закрываем файл
    fclose(fp);
}
