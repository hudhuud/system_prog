В программе ниже объявите константную целочисленную переменную с именем total и начальным значением 5. Прочитайте из входного потока total целых чисел, записанных в одну строчку через пробел, в массив целых чисел с именем marks и длиной 100 элементов. Выведите в консоль прочитанные значения в обратном порядке в одну строчку через пробел.

#include <stdio.h>

int main(void)
{
    const int total = 5;
    int marks[100];

    for (int i = 0; i < total; i++) {
        scanf("%d", &marks[i]);
    }

    for (int i = total - 1; i >= 0; i--) {
        printf("%d ", marks[i]);
    }


    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}