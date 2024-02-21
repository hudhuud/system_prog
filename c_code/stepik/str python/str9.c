Вводятся две строки (каждая с новой строчки). Из первой строки выделить все символы с четными индексами, а из второй - с нечетными. Объединить строки через пробел и вывести на экран.

#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], result[200];

    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    int j = 0;
    for (int i = 0; str1[i] != '\0'; i += 2) {
        result[j++] = str1[i];
    }
    
    result[j++]=' ';

    for (int i = 1; str2[i] != '\0'; i += 2) {
        result[j++] = str2[i];
    }

    result[j] = '\0';

    printf("%s", result);

    return 0;
}
