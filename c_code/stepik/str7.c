Напишите программу ввода строки и отображения на экране ее первого и последнего символа в виде одной строки.

#include <stdio.h>
#include <string.h>

int main() {
    char inputString[100];

    fgets(inputString, sizeof(inputString), stdin);

    inputString[strcspn(inputString, "\n")] = '\0';

    int length = strlen(inputString);

    if (length > 0) {
        printf("%c%c", inputString[0], inputString[length - 1]);
    } 
    else {
        printf("Строка пуста.\n");
    }

    return 0;
}
