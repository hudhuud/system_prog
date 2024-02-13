Вводятся два слова (через пробел в одной строке). Длина первого слова меньше второго. Необходимо обрезать второе слово до длины первого и отобразить обрезанное слово на экране.

#include <stdio.h>
#include <string.h>

int main() {
    char word1[100], word2[100];

    scanf("%s %s", word1, word2);

    word2[strlen(word1)] = '\0';

    printf("%s", word2);

    return 0;
}
