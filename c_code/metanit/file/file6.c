#include <stdio.h>
 
struct person
{
    char name[20];
    int age;
};
 
void save(char*);
void read_by_age(char*, int);
 
int main() {
    char * filename = "people.bin";
    save(filename);
    read_by_age(filename, 22);   // находим пользователей, которым 22 года
}
 
// записываем данные
void save(char* filename)
{
    struct person people[] = { {"Tom", 22}, {"Bob", 33}, {"Kate", 33 }, {"Alice", 22}};
    int size = sizeof(people[0]);              // размер всего массива
    int count = sizeof(people)  / size;         // количество структур 
 
    FILE *fp = fopen(filename, "w");
    size_t written = fwrite(people, size, count, fp); 
    printf("wrote %zu elements out of %d\n", written, count);
    fclose(fp);
}
// выводим данные на консоль для возраста age
void read_by_age(char* filename, int age)
{
    struct person p;  // структур для считывания файла
    FILE* fp = fopen(filename, "r");
    while(fread(&p, sizeof(p), 1, fp) == 1)
    {
        if(p.age == age)    // если пользователь имеет определенный возраст
        {
            printf("Name: %s \t Age: %d \n", p.name, p.age);
        }
    }
    fclose(fp);
}
