Продолжите программу. Выполните сортировку второй половины массива ws по убыванию (невозрастанию), используя метод сортировки выбором. То есть, сортировать нужно элементы с индексами от count/2 до count-1 включительно. Выведите в консоль все полученные значения массива ws (первые count элементов) в одну строчку через пробел с точностью до сотых.

#include <stdio.h>

#define TOTAL 20

void sort(float arr[], size_t start, size_t end) {
    for (size_t i = start; i < end - 1; i++) {
        size_t maxIndex = i;
        for (size_t j = i + 1; j < end; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        float temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;
    }
}

int main(void) {
    float ws[TOTAL] = {0.0f};
    size_t count = 0;
    size_t sz_ar = sizeof(ws) / sizeof(*ws);

    while (count < sz_ar && scanf("%f", &ws[count]) == 1)
        count++;
    size_t start = count / 2;
    size_t end = count;
    sort(ws, start, end);

    for (size_t i = 0; i < count; i++) {
        printf("%.2f ", ws[i]);
    }
    printf("\n");

    return 0;
}
