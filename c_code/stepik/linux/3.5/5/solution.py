import os
import sys
import signal

def daemonize():
    # Создание нового процесса
    pid = os.fork()

    # В случае ошибки при создании процесса, завершаем программу
    if pid < 0:
        sys.stderr.write("Ошибка при создании процесса\n")
        sys.exit(1)

    # Если это родительский процесс, завершаем его
    if pid > 0:
        sys.exit(0)

    # Установка нового SID для дочернего процесса
    os.setsid()

    # Изменение текущего рабочего каталога
    os.chdir("/")

    # Закрытие дескрипторов стандартных потоков ввода-вывода-ошибок
    sys.stdin.close()
    sys.stdout.close()
    sys.stderr.close()

    # Перенаправление стандартного вывода в /dev/null
    devnull = os.open(os.devnull, os.O_RDWR)
    os.dup2(devnull, sys.stdin.fileno())
    os.dup2(devnull, sys.stdout.fileno())
    os.dup2(devnull, sys.stderr.fileno())
    os.close(devnull)

def sigterm_handler(signum, frame):
    # Обработчик сигнала SIGTERM
    pid = os.getpid()
    print(pid)
    sys.stdout.flush()
    sys.exit(0)

def main():
    # Демонизируем программу
    daemonize()

    # Регистрируем обработчик сигнала SIGTERM
    signal.signal(signal.SIGTERM, sigterm_handler)

    # Бесконечный цикл для демонизированной программы
    while True:
        pass

if __name__ == "__main__":
    main()
