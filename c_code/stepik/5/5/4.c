Продолжите программу. Необходимо после каждого элемента со значением 5 массива digs вставлять новые элементы со значениями: -1 - после первой найденной пятерки; -2 - после второй пятерки и т.д. Обратите внимание, что при вставке новых значений, последние элементы массива digs могут теряться. Также следует учитывать, что элемент со значением 5 может отсутствовать в массиве digs (тогда ничего вставлять не нужно). Выведите в консоль по порядку значения всех прочитанных + добавленных элементов массива digs в одну строчку через пробел.

  #include <stdio.h>

#define TOTAL 10

int main(void)
{
    int numbers[TOTAL] = {0};
    size_t currentCount = 0;
    size_t arraySize = sizeof(numbers) / sizeof(*numbers);

    while (currentCount < arraySize && scanf("%d", &numbers[currentCount]) == 1)
        currentCount++;

    int countFives = 0;

    for (size_t i = 0; i < currentCount; i++) {
        if (numbers[i] == 5) {
            countFives++;
            int newValue = -countFives;

            for (size_t j = currentCount; j > i + 1; j--) {
                numbers[j] = numbers[j - 1];
            }

            numbers[i + 1] = newValue;
            currentCount++;

            if (currentCount == TOTAL + 1) {
                currentCount--;
            }
        }
    }

    for (size_t i = 0; i < currentCount; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
