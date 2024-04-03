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

int binarySearch(FILE *binary_file, long size, int target) {
    long low = 0, high = size - 1, mid;
    int mid_num;

    while (low <= high) {
        mid = (low + high) / 2;
        fseek(binary_file, mid * sizeof(int), SEEK_SET);
        fread(&mid_num, sizeof(int), 1, binary_file);

        if (mid_num == target) {
            return 1; // Число найдено
        } else if (mid_num < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return 0; // Число не найдено
}

int main() {
    const char *text_filename = "1.txt";
    const char *binary_filename = "1.dat";
    int target;

    printf("Введите число для поиска: ");
    scanf("%d", &target);

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

    int num;
    while (fscanf(text_file, "%d", &num) == 1) {
        fwrite(&num, sizeof(int), 1, binary_file);
    }

    fseek(binary_file, 0, SEEK_END);
    long fsize = ftell(binary_file) / sizeof(int);

    insertionSort(binary_file, fsize);

    if (binarySearch(binary_file, fsize, target)) {
        printf("Число найдено в файле.\n");
    } else {
        printf("Число не найдено в файле.\n");
    }

    fclose(text_file);
    fclose(binary_file);

    return 0;
}
