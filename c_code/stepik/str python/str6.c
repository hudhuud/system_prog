С клавиатуры вводятся две буквы (в одну строку через пробел). Вывести на экран следующую строку:

"Коды: <буква1> = <код буквы1>, <буква2> = <код буквы2>"

#include <stdio.h>

int main() {
    char letter1, letter2;

    scanf("%c %c", &letter1, &letter2);

    int code1 = (int)letter1;
    int code2 = (int)letter2;

    printf("Коды: %c = %d, %c = %d", letter1, code1, letter2, code2);

    return 0;
}
