#include <stdio.h>

void insertionSort(FILE *file, long fsize) {
    for (long i = 1; i < fsize; i++) {
        fseek(file, i * sizeof(int), SEEK_SET);
        int key;
        fread(&key, sizeof(int), 1, file);

        long j = i - 1;
        while (j >= 0) {
            int current;
            fseek(file, j * sizeof(int), SEEK_SET);
            fread(&current, sizeof(int), 1, file);
            if (current > key) {
                fseek(file, (j + 1) * sizeof(int), SEEK_SET);
                fwrite(&current, sizeof(int), 1, file);
                j--;
            } else {
                break;
            }
        }
        fseek(file, (j + 1) * sizeof(int), SEEK_SET);
        fwrite(&key, sizeof(int), 1, file);
    }
}

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

    // Определяем размер файла
    fseek(output_file, 0, SEEK_END);
    long fsize = ftell(output_file) / sizeof(int);

    // Выполняем сортировку вставками
    insertionSort(output_file, fsize);

    // Вывод отсортированных чисел
    printf("Отсортированныеa числа:\n");
    fseek(output_file, 0, SEEK_SET);
    for (long i = 0; i < fsize; i++) {
        fread(&num, sizeof(int), 1, output_file);
        printf("%d ", num);
    }
    printf("\n");

    fclose(output_file);
    return 0;
}
