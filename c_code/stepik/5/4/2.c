Необходимо из входного потока читать целые числа (по одному), пока не встретится число 78. Все прочитанные числа по порядку заносить в массив ar, используя указатель ptr_ar (кроме последнего числа 78). Вывести в консоль прочитанные значения из массива ar в одну строчку через пробел в порядке их чтения.

#include <stdio.h>

int main(void) {
    int ar[100];
    int *const ptr_ar = ar;

    int num;
    int *ptr = ptr_ar;

    while (scanf("%d", &num) == 1 && num != 78) {
        *ptr++ = num;
    }

    for (int *print_ptr = ptr_ar; print_ptr < ptr; print_ptr++) {
        printf("%d ", *print_ptr);
    }

    return 0;
}
