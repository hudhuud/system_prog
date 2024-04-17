#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_len 100

void sort(char **arr, int n) {
    int i, j;
    char *mass;
    
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                mass = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = mass;
            }
        }
    }
}

int main() {
    FILE *file;
    char **arr;
    char line[max_len];
    int n, i;

    file = fopen("in.txt", "r");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }

    n = 0;
    while (fgets(line, max_len, file) != NULL) {
        n++;
    }

    fseek(file, 0, SEEK_SET);

    arr = (char **)malloc(n * sizeof(char *));
    if (arr == NULL) {
        printf("Ошибка при выделении памяти.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        arr[i] = (char *)malloc(max_len * sizeof(char));
        if (arr[i] == NULL) {
            printf("Ошибка при выделении памяти.\n");
            return 1;
        }
        fgets(arr[i], max_len, file);
    }

    fclose(file);

    sort(arr, n);

    for (i = 0; i < n; i++) {
        printf("%s", arr[i]);
        free(arr[i]);
    }
    free(arr);

    return 0;
}
