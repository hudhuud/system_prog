#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_len 100

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

    //копирование строки
    (*res)[*n] = strdup(buf);
    (*n)++;
}

int main() {
    FILE *file;
    char **res = NULL;
    char buf[max_len];
    int n = 0; //строки в res
    int siz = 1; //начальный размер
    int i;
    
    //для qsort
    int compare(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strcmp(str1, str2);
    }
    
    //выделение памяти для res
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
