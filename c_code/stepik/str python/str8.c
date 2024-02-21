Напишите программу отображения первых четырех символов из введенной строки. Будем полагать, что строка гарантированно длиной не менее четырех символов.
#include <stdio.h>
#include <string.h>

int main() {
    char inputString[100];

    fgets(inputString, sizeof(inputString), stdin);

    inputString[strcspn(inputString, "\n")] = '\0';
    printf("%.4s", inputString);

    return 0;
}
