В программе ниже объявите массив с именем buffer длиной 1024 элементов типа short. Присвойте первому элементу (первому по счету) значение 13.

P. S. В консоль ничего выводить не нужно.

#include <stdio.h>

int main(void)
{
    short buffer[1024];

    buffer[0] = 13;

    __ASSERT_TESTS__ 
    return 0;
}
