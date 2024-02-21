В программе ниже выполняется считывание целочисленных значений из входного потока с их последовательной записью в массив vls размерностью 3 x 5 (3 строки и 5 столбцов). Необходимо объявить еще один массив с именем mean типа double и размерностью 3 элемента. 
В элементы массива mean следует записать среднее арифметическое каждой строки массива vls. Выведите в консоль значения элементов массива mean (по порядку) в одну строчку через пробел с точностью до сотых.

#include <stdio.h>

#define ROWS    3
#define COLS    5

int main(void)
{
    short vls[ROWS][COLS] = {0};
    short *ptr_vls = &vls[0][0];

    short x;
    for (int i = 0; i < ROWS * COLS && scanf("%hd", &x) == 1; ++i)
        *ptr_vls++ = x;

    double mean[ROWS];
    
    for (int i = 0; i < ROWS; i++) {
        mean[i] = 0.0;
        for (int j = 0; j < COLS; j++) {
            mean[i] += vls[i][j];
        }
        mean[i] /= COLS;
    }

    for (int i = 0; i < ROWS; i++) {
        printf("%.2f", mean[i]);

        if (i < ROWS - 1) {
            printf(" ");
        }
    }
    __ASSERT_TESTS__
    return 0;
}
