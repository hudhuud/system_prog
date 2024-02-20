Продолжите программу. Из массива pows необходимо удалить элемент с первым найденным четным значением. Если такой элемент не был найден, то, соответственно, ничего удалять не нужно. Выведите в консоль по порядку в одну строчку через пробел полученные значения оставшихся элементов массива pows.

  #include <stdio.h>

#define TOTAL 20

int main(void)
{
    short pows[TOTAL] = {0};
    size_t count = 0;
    size_t arraySize = sizeof(pows) / sizeof(*pows);

    while (count < arraySize && scanf("%hd", &pows[count]) == 1)
        count++;

    int firstEvenIndex = -1;
    for (size_t i = 0; i < count; i++) {
        if (pows[i] % 2 == 0) {
            firstEvenIndex = i;
            break;
        }
    }

    if (firstEvenIndex != -1) {
        for (size_t i = firstEvenIndex; i < count - 1; i++) {
            pows[i] = pows[i + 1];
        }
        count--;
    }

    for (size_t i = 0; i < count; i++) {
        printf("%hd ", pows[i]);
    }
    printf("\n");

    return 0;
}
