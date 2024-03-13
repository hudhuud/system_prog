#include <stdio.h>
 
struct person
{
    char name[20];
    int age;
};
 
int main() {
    // запись файла
    struct person tom = {"Tom", 22}; // структура для записи
    int size = sizeof(struct person);
    FILE *fp = fopen("person.bin", "w");
    // записываем одну структуру
    size_t count = fwrite(&tom, size, 1, fp); 
    printf("wrote %zu elements out of %d\n", count,  1);
    fclose(fp);
 
    // считывание структуры
    struct person unknown;  // структура для чтения
    fp = fopen("person.bin", "r");
    // считываем одну структуру
    count = fread(&unknown, size, 1, fp); 
    if(count == 1)
    {  
        printf("Name: %s \n", unknown.name);
        printf("Age: %d \n", unknown.age);
    }
    fclose(fp);
}
