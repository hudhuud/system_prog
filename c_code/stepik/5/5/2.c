Продолжите программу. Необходимо в массиве buffer поменять местами первую половину прочитанных данных со второй половиной. Обратите внимание, что число прочитанных данных определяется переменной count. Причем, если count четное, то первая половина меняется со второй целиком, а если count нечетное, то центральный элемент должен оставаться на своем месте без изменений. Выведите в консоль в одну строчку через пробел первые count элементов полученного массива buffer.

P. S. Дополнительных массивов в программе не создавать.

#include <stdio.h>

#define SIZE_BUFFER 128

int main(void) {
    int buffer[SIZE_BUFFER];
    size_t count = 0;
    size_t sz_ar = sizeof(buffer) / sizeof(*buffer);

    while (count < sz_ar && scanf("%d", &buffer[count]) == 1)
        count++;

    size_t half_count = count / 2;

    for (size_t i = 0; i < half_count; i++) {
        int temp = buffer[i];
        buffer[i] = buffer[half_count + i + count % 2];
        buffer[half_count + i + count % 2] = temp;
    }

    for (size_t i = 0; i < count; i++) {
        printf("%d ", buffer[i]);
    }

    return 0;
}
