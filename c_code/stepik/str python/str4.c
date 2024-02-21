Написать программу ввода строки и формирования новой строчки вида: "Строка: <введенная строка>. Длина: <длина строки>". Результат сформированной строки вывести на экран.

#include <stdio.h>
#include <string.h>

int main() {
    char inputString[100];

    fgets(inputString, sizeof(inputString), stdin);

    inputString[strcspn(inputString, "\n")] = '\0';

    int length = strlen(inputString);

    char result[200];
    sprintf(result, "Строка: %s. Длина: %d", inputString, length);

  
    printf("%s", result);

    return 0;
}
