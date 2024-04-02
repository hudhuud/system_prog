#include <stdio.h>
#include <stdlib.h>

void selectionSort(FILE *file, long fsize) {
    int temp1, temp2;
    for (long i = 0; i < fsize - 1; i++) {
        fseek(file, i * sizeof(int), SEEK_SET);
        fread(&temp1, sizeof(int), 1, file);
        for (long j = i + 1; j < fsize; j++) {
            fseek(file, j * sizeof(int), SEEK_SET);
            fread(&temp2, sizeof(int), 1, file);
            if (temp2 < temp1) {
                fseek(file, j * sizeof(int), SEEK_SET);
                fwrite(&temp1, sizeof(int), 1, file);
                fseek(file, i * sizeof(int), SEEK_SET);
                fwrite(&temp2, sizeof(int), 1, file);
                temp1 = temp2;
            }
        }
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
    // Читаем числа из текстового файла и записываем в бинарный
    while (fscanf(input_file, "%d", &num) == 1) {
        fwrite(&num, sizeof(int), 1, output_file);
    }

    fclose(input_file);

    // Определяем размер файла
    fseek(output_file, 0, SEEK_END);
    long fsize = ftell(output_file) / sizeof(int);

    // Выполняем сортировку выбором
    selectionSort(output_file, fsize);

    // Выводим отсортированные числа из бинарного файла
    printf("Отсортированные числа:\n");
    rewind(output_file);
    while (fread(&num, sizeof(int), 1, output_file) == 1) {
        printf("%d ", num);
    }
    printf("\n");

    fclose(output_file);

    return 0;
}
