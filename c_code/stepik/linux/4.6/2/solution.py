import os
import select

def main():
    # Открываем каналы на чтение
    in1 = os.open("in1", os.O_RDONLY | os.O_NONBLOCK)
    in2 = os.open("in2", os.O_RDONLY | os.O_NONBLOCK)

    # Список каналов для select
    inputs = [in1, in2]
    sum = 0

    while inputs:
        # Вызываем select для ожидания готовности каналов
        readable, _, _ = select.select(inputs, [], [])

        for fd in readable:
            # Считываем данные из канала
            data = os.read(fd, 32)
            if not data:
                # Если данные не прочитаны, закрываем канал
                os.close(fd)
                inputs.remove(fd)
            else:
                # Парсим данные и прибавляем к сумме
                sum += int(data)

    # Выводим окончательную сумму
    print(sum)

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
