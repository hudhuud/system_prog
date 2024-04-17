#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

void sort(char ***res, int *n, int *siz, char *buf) {
    //есть ли место в res
    if (*n >= *siz) {
        //увеличение вдвое
        *siz *= 2;
        *res = realloc(*res, (*siz) * sizeof(char *));
        if (*res == NULL) {
            printf("ошибка при выделении памяти 1\n");
            exit(1);
        }
    }

    // Копирование строки
    (*res)[*n] = strdup(buf);
    (*n)++;
}

//для qsort
int compareStrings(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strcmp(str1, str2);
}
