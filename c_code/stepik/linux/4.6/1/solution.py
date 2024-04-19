import subprocess
import sys

def count_zeros(command, param):
    try:
        # Запуск утилиты и захват её вывода
        output = subprocess.check_output([command, param])
        # Подсчет символов '0' в выводе
        zeros_count = output.count(b'0')
        return zeros_count
    except subprocess.CalledProcessError:
        print("Ошибка при выполнении утилиты.")
        sys.exit(1)

def main():
    # Проверка наличия двух аргументов (имени утилиты и её параметра)
    if len(sys.argv) != 3:
        print("Использование: {} <имя_утилиты> <параметр>".format(sys.argv[0]))
        sys.exit(1)
    
    # Получение имени утилиты и её параметра из аргументов командной строки
    command = sys.argv[1]
    param = sys.argv[2]

    # Подсчет символов '0' и вывод результата
    zeros_count = count_zeros(command, param)
    print(zeros_count)

if __name__ == "__main__":
    main()


makefile:
.PHONY: all clean

all: solution

solution: solution.py
	chmod +x solution.py
	@echo "Скрипт готов к использованию"

clean:
	@echo "Удаление временных файлов"
