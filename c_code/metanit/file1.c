#include <stdio.h>

int main() {
    // Инициализация строки
    char str[] = "Hello METANIT.COM";
    
    // Получение размера строки в байтах
    size_t N = sizeof(str);

    // Открытие файла для записи
    FILE *fp = fopen("data.txt", "w");

    // Запись данных в файл и получение количества записанных элементов
    size_t count = fwrite(str, sizeof str[0], N, fp);

    // Вывод информации о количестве записанных элементов
    printf("wrote %zu elements out of %zu\n", count,  N);

    // Закрытие файла
    fclose(fp);
}
