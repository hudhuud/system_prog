'''
   Разработать программу solution, которая при запуске себя "демонизирует" и остается в  памяти. Перед закрытием стандартного потока вывода stdout унаследованного от родителя, программа должна вывести в него Pid процесса-демона.

Пример вызова


./solution
13221
   '''
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void daemonize() {
    // Создание нового процесса
    pid_t pid = fork();

    // В случае ошибки при создании процесса, завершаем программу
    if (pid < 0) {
        perror("Ошибка при создании процесса");
        exit(EXIT_FAILURE);
    }

    // Если это родительский процесс, завершаем его
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    // Установка нового SID для дочернего процесса
    if (setsid() < 0) {
        perror("Ошибка при установке нового SID");
        exit(EXIT_FAILURE);
    }

    // Изменение текущего рабочего каталога
    if (chdir("/") < 0) {
        perror("Ошибка при изменении текущего рабочего каталога");
        exit(EXIT_FAILURE);
    }

    // Закрытие дескрипторов стандартных потоков ввода-вывода-ошибок
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // Перенаправление стандартного вывода в /dev/null
    int fd = open("/dev/null", O_RDWR);
    if (fd < 0) {
        perror("Ошибка при открытии /dev/null");
        exit(EXIT_FAILURE);
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
}

int main() {
    // Демонизируем программу
    daemonize();

    // Получаем PID процесса
    pid_t pid = getpid();

    // Выводим PID процесса в стандартный поток вывода
    printf("%d\n", pid);

    // Закрываем стандартный поток вывода
    fclose(stdout);

    // Бесконечный цикл для демонизированной программы
    while (1) {
        // Можно добавить здесь код, который должен выполняться в демоне
        // Например, обработку входящих запросов или другие действия
        // Здесь просто оставляем пустой цикл
    }

    return 0;
}

//в комментариях предлагали сделать просто sleep(1000), но я решила делать через бесконечный цикл + обработку событий с например родительским процессом и закрытием потоков. так более правильно что ли и так он на лекциях объяснял.
