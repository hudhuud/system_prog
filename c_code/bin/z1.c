#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input_file = fopen("1.txt", "r");
    if (input_file == NULL) {
        printf("Ошибка открытия файла 1.txt\n");
        return 1;
    }

    FILE *output_file = fopen("1.dat", "wb+");
    if (output_file == NULL) {
        printf("Ошибка открытия/создания файла 1.dat\n");
        fclose(input_file);
        return 1;
    }

    int num;
    printf("Неотсортированные числа:\n");
    while (fscanf(input_file, "%d", &num) != EOF) {
        printf("%d ", num);
        fwrite(&num, sizeof(int), 1, output_file);
    }
    printf("\n");

    fclose(input_file);
    fclose(output_file);

    // Открываем файл для сортировки
    FILE *file_to_sort = fopen("1.dat", "rb+");
    if (file_to_sort == NULL) {
        printf("Ошибка открытия файла 1.dat\n");
        return 1;
    }

    // Определяем размер файла
    fseek(file_to_sort, 0, SEEK_END);
    long fsize = ftell(file_to_sort) / sizeof(int);

    // Сортировка пузырьком
    fseek(file_to_sort, 0, SEEK_SET);
    for (long i = 0; i < fsize - 1; i++) {
        for (long j = 0; j < fsize - i - 1; j++) {
            int current, next;
            fseek(file_to_sort, j * sizeof(int), SEEK_SET);
            fread(&current, sizeof(int), 1, file_to_sort);
            fseek(file_to_sort, (j + 1) * sizeof(int), SEEK_SET);
            fread(&next, sizeof(int), 1, file_to_sort);
            if (current > next) {
                fseek(file_to_sort, j * sizeof(int), SEEK_SET);
                fwrite(&next, sizeof(int), 1, file_to_sort);
                fseek(file_to_sort, (j + 1) * sizeof(int), SEEK_SET);
                fwrite(&current, sizeof(int), 1, file_to_sort);
            }
        }
    }

    // Вывод отсортированных чисел
    printf("Отсортированные числа:\n");
    fseek(file_to_sort, 0, SEEK_SET);
    for (long i = 0; i < fsize; i++) {
        fread(&num, sizeof(int), 1, file_to_sort);
        printf("%d ", num);
    }
    printf("\n");

    fclose(file_to_sort);
    return 0;
}
