В программе объявлен до функции main() массив с именем marks и типом элементов short. Этот массив скрыт в коде, но он существует. В функции main() вычислите длину массива marks (число его элементов) и размер массива (число байт, которые он занимает в памяти устройства). Выведите в консоль в одну строчку через пробел длину массива и его размер в байтах (именно в таком порядке) в виде целых чисел.

#include <stdio.h>

int main(void)
{
    int length = sizeof(marks) / sizeof(marks[0]);
    int size = sizeof(marks);

    printf("%d %d\n", length, size);


    return 0;
}
