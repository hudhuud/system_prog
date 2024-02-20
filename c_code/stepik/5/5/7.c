Продолжите программу. Выполните сортировку массива ws по возрастанию (неубыванию), используя метод сортировки выбором. Сортировать нужно только первые count элементов. Выведите в консоль значения отсортированного массива ws (первые count элементов) в одну строчку через пробел с точностью до сотых.

#include <stdio.h>

#define TOTAL 20

void selectionSort(float arr[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        float temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main(void) {
    float ws[TOTAL] = {0.0f};
    size_t count = 0;
    size_t sz_ar = sizeof(ws) / sizeof(*ws);

    while (count < sz_ar && scanf("%f", &ws[count]) == 1)
        count++;

    selectionSort(ws, count);

    for (size_t i = 0; i < count; i++) {
        printf("%.2f ", ws[i]);
    }
    printf("\n");

    return 0;
}
