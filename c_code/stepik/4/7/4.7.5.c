Напишите программу, которая читает из входного потока целое число в переменную count типа int. В каждом байте переменной count нужно выключить 7-й, 6-й и 1-й биты (нумерация бит в байте: 7, 6, 5, 4, 3, 2, 1, 0). Вывести в консоль полученное значение count в виде одного целого числа.

#include <stdio.h>

int main(void) {
    int count;

    scanf("%d", &count);

    for (int i = 0; i < sizeof(int); i++) {
        unsigned char *byte_ptr = ((unsigned char *)&count) + i; // Pointer to the i-th byte
        *byte_ptr &= ~(1 << 7); 
        *byte_ptr &= ~(1 << 6); 
        *byte_ptr &= ~(1 << 1); 
    }

    printf("%d\n", count);

    return 0;
}

