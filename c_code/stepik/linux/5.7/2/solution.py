import socket
import sys

# Проверяем количество аргументов командной строки
if len(sys.argv) != 2:
    print("Использование: {} <порт>".format(sys.argv[0]))
    sys.exit(1)

# Создаем UDP сокет
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Получаем порт из аргументов командной строки
port = int(sys.argv[1])

# Привязываем сокет к локальному адресу и порту
s.bind(('127.0.0.1', port))

# Получаем сообщения и выводим их
while True:
    data, addr = s.recvfrom(1024)  # Принимаем сообщение размером не более 1024 байт
    message = data.decode('utf-8')  # Декодируем байты в строку
    print(message.rstrip())         # Выводим сообщение без символа перевода строки

    # Проверяем, завершено ли выполнение
    if message.rstrip() == "OFF":
        break

# Закрываем сокет
s.close()
