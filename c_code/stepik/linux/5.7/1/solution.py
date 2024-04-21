import socket
import sys

def main():
    if len(sys.argv) != 2:
        print("Использование: {} <hostname>".format(sys.argv[0]))
        return

    hostname = sys.argv[1]
    try:
        ip_addresses = socket.gethostbyname_ex(hostname)[-1]
        for ip in ip_addresses:
            print(ip)
    except socket.gaierror as e:
        print("Ошибка при вызове gethostbyname_ex:", e)

if __name__ == "__main__":
    main()
