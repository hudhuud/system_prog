#include <stdio.h>
  
int main(void)
{
    // файл чтения
    char * filename = "data.txt";
    // буфер для считавания данных из файла
    char buffer[256];
    // чтение из файла
    FILE *fp = fopen(filename, "r");
    if(fp)
    {
        // пока не дойдем до конца, считываем по 256 байт
        while((fgets(buffer, 256, fp))!=NULL)
        {
            printf("%s", buffer);
        }
        fclose(fp);
    } 
}
