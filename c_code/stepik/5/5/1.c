 Продолжите программу. Необходимо из массива ar в обратном порядке (идя от последнего записанного значения к первому) скопировать прочитанные данные в массив marks (копирование выполнять от первого элемента к последнему), не выходя за пределы массива marks. То есть, в случае достижения последнего элемента массива marks, останавливать процедуру копирования. Вывести в консоль значения массива marks (от первого до последнего скопированного элемента) в одну строчку через пробел.

#include <stdio.h>

int main(void) {
    short ar[10], marks[5];
    size_t count = 0;
    size_t sz_ar = sizeof(ar) / sizeof(*ar);

    while (count < sz_ar && scanf("%hd", &ar[count]) == 1)
        count++;
    size_t i;
    size_t marks_count = 0;

    for (i = count; i > 0 && marks_count < sizeof(marks) / sizeof(*marks); i--, marks_count++) {
        marks[marks_count] = ar[i - 1];
    }

    for (size_t j = 0; j < marks_count; j++) {
        printf("%hd ", marks[j]);
    }

    return 0;
}
