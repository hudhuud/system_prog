#include <stdio.h>
  
int main(void)
{
    // строка для записи
    char * message = "Hello METANIT.COM!\nAn apple a day keeps the doctor away";
    // файл для записи
    char * filename = "data.txt";
    // запись в файл
    FILE *fp = fopen(filename, "w");
    if(fp)
    {
        // записываем строку
        fputs(message, fp);
        fclose(fp);
        printf("File has been written\n");
    }
}

//это задачи на чтение и запись файла без fwrite и freaad
