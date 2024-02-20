 В программе объявлен до функции main() массив с именем pows и типом элементов float. Этот массив скрыт в коде, но он существует. В функции main() выведите в консоль в одну строчку через пробел значения его элементов в обратном порядке с точностью до десятых.

#include <stdio.h>

int main(void)
{
    int length = sizeof(pows) / sizeof(pows[0]);

    for (int i = length - 1; i >= 0; i--) {
        printf("%.1f ", pows[i]);
    }

    return 0;
}