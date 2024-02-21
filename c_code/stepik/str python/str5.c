Написать программу ввода двух слов (через пробел в одну строчку). Определить булевы значения для оператора in проверки вхождения первого слова во второе. А также для операторов ==, >, <. 
  Все булевы значения объединить в одну строку через пробел и вывести на экран.




#include <stdio.h>
#include <string.h>

int main() {
    char word1[50], word2[50];

    scanf("%s %s", word1, word2);

    int isIncluded = strstr(word2, word1) != NULL;

    int isEqual = strcmp(word1, word2) == 0;
    int isGreaterThan = strcmp(word1, word2) > 0;
    int isLessThan = strcmp(word1, word2) < 0;

    char result[100];
    sprintf(result, "%d %d %d %d", isIncluded, isEqual, isGreaterThan, isLessThan);

    printf("%s", result);

    return 0;
}
