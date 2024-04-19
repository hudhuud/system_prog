import os
import sys

def print_process_path(pid):
    # Выводим текущий PID
    print(pid)

    # Если PID равен 1, завершаем функцию
    if pid == 1:
        return

    # Получаем информацию о родительском процессе
    try:
        with open(f"/proc/{pid}/status", "r") as fp:
            for line in fp:
                if line.startswith("PPid:"):
                    parent_pid = int(line.split()[1])
                    break
    except FileNotFoundError:
        print(f"Ошибка при открытии файла /proc/{pid}/status")
        return

    # Рекурсивный вызов для родительского процесса
    print_process_path(parent_pid)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Использование:", sys.argv[0], "<pid>")
        sys.exit(1)

    # Получение PID из аргумента командной строки
    pid = int(sys.argv[1])

    # Печать пути в дереве процессов
    print_process_path(pid)
