#include <stdio.h>
#include <stdlib.h>

void createBinaryFile(const char *text_filename, const char *binary_filename) {
    FILE *text_file = fopen(text_filename, "r");
    if (text_file == NULL) {
        printf("Ошибка открытия текстового файла\n");
        exit(1);
    }

    FILE *binary_file = fopen(binary_filename, "wb+");
    if (binary_file == NULL) {
        printf("Ошибка открытия/создания бинарного файла\n");
        fclose(text_file);
        exit(1);
    }

    int num;
    while (fscanf(text_file, "%d", &num) == 1) {
        fwrite(&num, sizeof(int), 1, binary_file);
    }

    fclose(text_file);
    fclose(binary_file);
}

int linearSearch(const char *binary_filename, int target) {
    FILE *binary_file = fopen(binary_filename, "rb");
    if (binary_file == NULL) {
        printf("Ошибка открытия бинарного файла\n");
        exit(1);
    }

    int num;
    rewind(binary_file);

    while (fread(&num, sizeof(int), 1, binary_file) == 1) {
        if (num == target) {
            fclose(binary_file);
            return 1; // Число найдено
        }
    }

    fclose(binary_file);
    return 0; // Число не найдено
}

int main() {
    const char *text_filename = "1.txt";
    const char *binary_filename = "1.dat";
    int target;

    printf("Введите число для поиска: ");
    scanf("%d", &target);

    createBinaryFile(text_filename, binary_filename);

    if (linearSearch(binary_filename, target)) {
        printf("Число найдено в файле.\n");
    } else {
        printf("Число не найдено в файле.\n");
    }

    return 0;
}
