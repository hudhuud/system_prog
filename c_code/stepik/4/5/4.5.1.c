Необходимо объявить указатель с именем ptr_var_d для работы с переменной var_d. Через указатель ptr_var_d изменить значение переменной var_d на -54.38.

P. S. В консоль ничего выводить не нужно. 
решила хоть немного усложнить код поэтому пусть будет с функцией

#include <stdio.h>

void changeVarD(double *ptr_var_d);

int main() {
    double var_d = 0.0;
    double *ptr_var_d = &var_d;

    changeVarD(ptr_var_d);

    __ASSERT_TESTS__
    return 0;
}

void changeVarD(double *ptr_var_d) {
    *ptr_var_d = -54.38;
}
