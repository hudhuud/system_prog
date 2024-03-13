#include <stdio.h>

// Определение структуры для представления данных о человеке
struct person
{
    char name[20];
    int age;
};

int main(void)
{
    // Имя файла для записи данных
    char *filename = "users.dat";

    // Массив структур с информацией о людях
    struct person people[] = {{"Tom", 23}, {"Alice", 27}, {"Bob", 31}, {"Kate", 29}};

    // Количество записываемых структур
    int n = sizeof(people) / sizeof(people[0]);

    // Открытие файла для записи
    FILE *fp = fopen(filename, "w");
    if (!fp)
    {
        // Вывод сообщения об ошибке при открытии файла
        printf("Error occurred while opening file\n");
        return 1;
    }

    // Запись данных в файл
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%s  %d\n", people[i].name, people[i].age);
    }

    // Закрытие файла
    fclose(fp);

    // Вывод сообщения об успешной записи данных в файл
    printf("File has been written\n");

    return 0;
}

