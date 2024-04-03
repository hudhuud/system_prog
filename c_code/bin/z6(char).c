#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(FILE *file, long fsize, size_t line_size) {
    char *key = (char *)malloc(line_size);
    char *current = (char *)malloc(line_size);

    for (long i = 1; i < fsize; i++) {
        fseek(file, i * line_size, SEEK_SET);
        fread(key, 1, line_size - 1, file); // Читаем строку без символа конца строки
        key[line_size - 1] = '\0'; // Добавляем символ конца строки

        long j = i - 1;
        while (j >= 0) {
            fseek(file, j * line_size, SEEK_SET);
            fread(current, 1, line_size - 1, file); // Читаем строку без символа конца строки
            current[line_size - 1] = '\0'; // Добавляем символ конца строки

            if (strcmp(current, key) > 0) {
                fseek(file, (j + 1) * line_size, SEEK_SET);
                fwrite(current, 1, line_size - 1, file); // Записываем строку без символа конца строки
                fwrite("\n", 1, 1, file); // Записываем символ конца строки
                j--;
            } else {
                break;
            }
        }
        fseek(file, (j + 1) * line_size, SEEK_SET);
        fwrite(key, 1, line_size - 1, file); // Записываем строку без символа конца строки
        fwrite("\n", 1, 1, file); // Записываем символ конца строки
    }

    free(key);
    free(current);
}

int binarySearch(FILE *binary_file, long size, const char *target, size_t line_size) {
    printf("зашел в функцию поиска\n");
    char *mid_str = (char *)malloc(line_size);
    
    long low = 0, high = size - 1, mid;
    printf("перед циклом поиска\n");
    
    while (low <= high) {
        printf("зашел в цикл функцию поиска2\n");
        mid = (low + high) / 2;
        fseek(binary_file, mid * line_size, SEEK_SET);
        
        int index = 0;
        char ch;
        while ((ch = fgetc(binary_file)) != '\n' && ch != EOF && index < line_size - 1) {
            mid_str[index++] = ch;
        }
        mid_str[index] = '\0'; // Добавляем символ конца строки
        
        printf("зашел в цикл функцию поиска\n");
        int cmp = strcmp(mid_str, target);
        if (cmp == 0) {
            return 1; // Строка найдена
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
}


    free(mid_str);
    return 0; // Строка не найдена
}

int main() {
    const char *text_filename = "1.txt";
    const char *binary_filename = "1.dat";
    char target[100];

    printf("Введите строку для поиска: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\r\n")] = '\0'; // Убираем символы окончания строки

    FILE *text_file = fopen(text_filename, "r");
    if (text_file == NULL) {
        printf("Ошибка открытия текстового файла\n");
        return 1;
    }

    FILE *binary_file = fopen(binary_filename, "wb+");
    if (binary_file == NULL) {
        printf("Ошибка открытия/создания бинарного файла\n");
        fclose(text_file);
        return 1;
    }

    char *line = NULL;
    size_t line_size = 0;
    ssize_t read;

    while ((read = getline(&line, &line_size, text_file)) != -1) {
        fwrite(line, 1, read, binary_file);
    }

    fseek(binary_file, 0, SEEK_END);
    long fsize = ftell(binary_file) / line_size;

    insertionSort(binary_file, fsize, line_size);

    fseek(binary_file, 0, SEEK_SET);
    printf("Отсортированные строки в бинарном файле:\n");
    while ((read = getline(&line, &line_size, binary_file)) != -1) {
        printf("%s\n", line);
    }

    if (binarySearch(binary_file, fsize, target, line_size)) {
        printf("Строка найдена в файле.\n");
    } else {
        printf("Строка не найдена в файле.\n");
    }

    fclose(text_file);
    fclose(binary_file);
    if (line)
        free(line);

    return 0;
}
