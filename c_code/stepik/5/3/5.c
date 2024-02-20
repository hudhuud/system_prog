Прочитайте из входного потока целые числа в переменные var_1, var_2 и var_3, записанные в одну строчку через запятую. Побайтно занесите их значения в массив типа char (в порядке var_1, var_2, var_3). Выведите в одну строчку по порядку значения массива в виде беззнаковых десятичных чисел.

#include <stdio.h>

int main(void)
{
    short var_1;
    int var_2;
    long long var_3;

    scanf("%hd, %d, %lld", &var_1, &var_2, &var_3);

    char bytes[sizeof(short) + sizeof(int) + sizeof(long long)];
    for (int i = 0; i < sizeof(short); ++i) {
        bytes[i] = *((char*)&var_1 + i);
    }
    for (int i = 0; i < sizeof(int); ++i) {
        bytes[sizeof(short) + i] = *((char*)&var_2 + i);
    }
    for (int i = 0; i < sizeof(long long); ++i) {
        bytes[sizeof(short) + sizeof(int) + i] = *((char*)&var_3 + i);
    }

    for (int i = 0; i < sizeof(bytes); ++i) {
        printf("%u ", (unsigned char)bytes[i]);
    }
    printf("\n");

    return 0;
}
