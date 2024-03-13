#include <stdio.h>

int main(void)
{   
    // Имя файла для чтения данных
    char *filename = "users.dat";
    
    // Переменные для считывания имени и возраста
    char name[20];  
    int age;

    // Открытие файла для чтения
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        // Вывод сообщения об ошибке при открытии файла
        printf("Error occurred while opening file\n");
        return 1;
    }

    // Чтение данных из файла и вывод на экран
    while ((fscanf(fp, "%20s %d\n", name, &age)) != EOF)
    {
        printf("%s %d\n", name, age);
    }

    // Закрытие файла
    fclose(fp);

    return 0;
}
