include <stdio.h>
 
int main(void)
{
    char * filename1 = "data1.txt";
    char * filename2 = "data2.txt";
    char buffer[256];
    FILE *f1 = fopen(filename1, "r");   // файл на чтение
    FILE *f2 = fopen(filename2, "w");   // файл на запись
    if(!f1 || !f2)
    {
        printf("Error occured while opening file\n");
    }
    else
    {
        // пока не дойдем до конца, считываем по 256 байт из файла f1
        while((fgets(buffer, 256, f1))!=NULL)
        {
            // записываем строку в файл f2
            fputs(buffer, f2);
            printf("%s", buffer);
        }
    }
     
    fclose(f1);
    fclose(f2);
     
    return 0;
}
//копирование файлов
