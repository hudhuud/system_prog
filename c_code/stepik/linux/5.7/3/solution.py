import socket
import sys

def sort_string(s):
    return ''.join(sorted(s, reverse=True))

def main():
    if len(sys.argv) != 2:
        print("Использование: {} <порт>".format(sys.argv[0]))
        return

    port = int(sys.argv[1])
    if port < 0 or port > 65535:
        print("Порт должен быть числом от 0 до 65535")
        return

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('127.0.0.1', port))
    server_socket.listen(5)

    print("Сервер запущен. Ожидание подключений...")

    while True:
        client_socket, addr = server_socket.accept()
        print("Подключение от {}".format(addr))

        while True:
            data = client_socket.recv(1024)
            if not data or data.strip() == b'OFF':
                break

            sorted_data = sort_string(data.decode()).encode() + b'\n'
            client_socket.sendall(sorted_data)

        client_socket.close()
        if data and data.strip() == b'OFF':
            break

    server_socket.close()

if __name__ == "__main__":
    main()
