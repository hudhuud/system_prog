Продолжите программу. Объявите указатель ptr_a на переменную a и указатель ptr_b на переменную b. Поменяйте адреса указателей ptr_a и ptr_b между собой, используя третий вспомогательный указатель с обобщенным типом void*. Выведите в консоль в одну строчку через пробел целочисленные значения, на которые ссылаются указатели ptr_a и ptr_b именно в таком порядке:

<значение для ptr_a> <значение для ptr_b>

#include <stdio.h>

void swapAddresses(void **ptr_a, void **ptr_b);

int main(void) {
    short a, b;
    scanf("%hd, %hd", &a, &b);

    short *ptr_a = &a;
    short *ptr_b = &b;

    void *aux_ptr = NULL;

    swapAddresses((void**)&ptr_a, (void**)&ptr_b);

    printf("%d %d", *((short*)ptr_a), *((short*)ptr_b));

    __ASSERT_TESTS__
        
    return 0;
}

void swapAddresses(void **ptr_a, void **ptr_b) {
    void *temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;
}
