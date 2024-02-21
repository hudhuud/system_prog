Напишите программу, которая читает из входного потока целое число в переменную count типа int. В каждом байте переменной count нужно включить 3-й и 0-й биты (нумерация бит в байте: 7, 6, 5, 4, 3, 2, 1, 0). Вывести в консоль полученное значение count в виде одного целого числа.

#include <stdio.h>

int main(void) {
    int count;

    scanf("%d", &count);

    for (int i = 0; i < sizeof(int); i++) {
        unsigned char *byte_ptr = ((unsigned char *)&count) + i; 
        *byte_ptr |= (1 << 3); 
        *byte_ptr |= 1;
    }

    printf("%d\n", count);

    return 0;
}
