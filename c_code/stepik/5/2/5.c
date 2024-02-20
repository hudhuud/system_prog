В программе до функции main() объявлен массив с именем marks и типом элементов short. Этот массив скрыт в коде, но он существует. В функции main() вычислите среднее арифметическое значений элементов этого массива и выведите в консоль полученное значение с точностью до сотых.

#include <stdio.h>

int main(void)
{
    int length = sizeof(marks) / sizeof(marks[0]);
    int sum = 0;

    for (int i = 0; i < length; i++) {
        sum += marks[i];
    }

    float mean = (float)sum / length;

    printf("%.2f\n", mean);

    return 0;
}
