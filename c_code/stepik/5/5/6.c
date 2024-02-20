Продолжите программу. Из массива pows необходимо удалить все элементы кратные 3 (делятся нацело на 3). Если таких элементов нет, то ничего удалять не нужно. Выведите в консоль по порядку в одну строчку через пробел полученные значения оставшихся элементов массива pows.

  #include <stdio.h>

#define TOTAL 20

int main(void)
{
    short pows[TOTAL] = {0};
    size_t count = 0;
    size_t arraySize = sizeof(pows) / sizeof(*pows);

    while (count < arraySize && scanf("%hd", &pows[count]) == 1)
        count++;

    size_t writeIndex = 0;
    for (size_t i = 0; i < count; i++) {
        if (pows[i] % 3 != 0) {
            pows[writeIndex++] = pows[i];
        }
    }
    count = writeIndex;

    for (size_t i = 0; i < count; i++) {
        printf("%hd ", pows[i]);
    }
    printf("\n");

    return 0;
}
