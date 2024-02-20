Продолжите программу. Необходимо после первого элемента со значением 5 массива digs вставить новое значение -5. Обратите внимание, что при вставке нового значения, последний элемент массива digs может теряться (если длина массива не позволяет хранить все значения). Также следует учитывать, что элемент со значением 5 может отсутствовать в массиве digs (тогда ничего вставлять не нужно). Выведите в консоль по порядку значения всех прочитанных + добавленных элементов массива digs в одну строчку через пробел.

#include <stdio.h>
#define TOTAL     10

int main(void)
{
    int digs[TOTAL] = {0};
    size_t count = 0;
    size_t sz_ar = sizeof(digs) / sizeof(*digs);

    while(count < sz_ar && scanf("%d", &digs[count]) == 1)
        count++;

    int found = 0;
    for (size_t i = 0; i < count; i++) {
        if (digs[i] == 5) {
            found = 1;
          if (count == TOTAL) {
                count--;
            }
            for (size_t j = count; j > i + 1; j--) { //оч странный момент, на котором я долго сидела. если написать j>i++, то шестерка в выводе задвоится
                digs[j] = digs[j - 1];
            }
            digs[i + 1] = -5;
            count++;
            break;
        }
    }

    for (size_t i = 0; i < count; i++) {
        printf("%d ", digs[i]);
    }
    printf("\n");

    return 0;
}
