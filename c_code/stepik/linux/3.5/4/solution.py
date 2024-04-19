import os
import sys

def count_descendants(pid):
    # Счетчик для хранения количества потомков
    count = 1

    # Открываем файл с PID потомков для чтения
    try:
        with open(f"/proc/{pid}/task/{pid}/children", "r") as fp:
            # Читаем PID потомков и рекурсивно считаем их потомков
            for line in fp:
                child_pid = int(line.strip())
                count += count_descendants(child_pid)
    except FileNotFoundError:
        print(f"Ошибка при открытии файла /proc/{pid}/task/{pid}/children")
        return -1

    return count

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Использование:", sys.argv[0], "<pid>")
        sys.exit(1)

    # Получаем PID из аргумента командной строки
    pid = int(sys.argv[1])

    # Подсчет процессов в поддереве
    descendants_count = count_descendants(pid)

    if descendants_count == -1:
        # Ошибка при подсчете процессов
        sys.exit(1)

    # Вывод количества процессов
    print(descendants_count)
