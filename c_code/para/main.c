'''читать строки из файла в buf, если место в res есть то добавить в res, иначе сначала увеличить размер rts вдвое. выполнить лексикографиескую сортировку'''


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

#define max_len 100

int main() {
    FILE *file;
    char **res = NULL;
    char buf[max_len];
    int n = 0; // строки в res
    int siz = 1; // начальный размер
    int i;

    res = (char **)malloc(siz * sizeof(char *));
    if (res == NULL) {
        printf("ошибка при выделении памяти 2\n");
        return 1;
    }

    file = fopen("in.txt", "r");
    if (file == NULL) {
        printf("ошибка при открытии\n");
        return 1;
    }

    while (fgets(buf, max_len, file) != NULL) {
        buf[strcspn(buf, "\n")] = '\0';
        sort(&res, &n, &siz, buf);
    }

    fclose(file);

    qsort(res, n, sizeof(char *), compare);

    for (i = 0; i < n; i++) {
        printf("%s\n", res[i]);
        free(res[i]); //для каждой строки
    }
    free(res); //для массива

    return 0;
}
