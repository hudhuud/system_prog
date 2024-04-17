'''Разработать программу solution, обеспечивающую загрузку динамической библиотеки в режиме исполнения. При запуске, программе передается имя динамической библиотеки, имя функции которая должна быть вызвана, и ее аргумент. Функция в библиотеке принимает на вход int и возвращает int. Результат, возвращаемый функцией должен быть выведен отдельной строкой (оканчиваться символом новой строки \n)  в stdout.

Пример вызова


./solution libShared.so someSecretFunctionPrototype 8
16

В примере, должна быть загружена библиотека libShared.so, в которой вызвана функция someSecretFunctionPrototype с аргументом 8. Результат (16) выведен в stdout.


Представление решения

Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается цель по умолчанию, которая приводит к сборке Вашего приложения.

Вывод

Программа выводит в стандартный поток вывода число, полученное после вызова функции, и символ новой строки \n.
'''
import sys
from ctypes import CDLL, c_int

def main():
    if len(sys.argv) != 4:
        print("Usage: ./solution <library_name> <function_name> <argument>")
        return

    library_name = sys.argv[1]
    function_name = sys.argv[2]
    argument = int(sys.argv[3])

    # Загрузка динамической библиотеки
    try:
        lib = CDLL(library_name)
    except OSError as e:
        print("Error:", e)
        return

    # Поиск функции в библиотеке
    try:
        function = getattr(lib, function_name)
    except AttributeError:
        print("Error: Function", function_name, "not found in the library")
        return

    # Вызов функции и вывод результата
    try:
        result = function(c_int(argument))
        print(result)
    except Exception as e:
        print("Error:", e)

if __name__ == "__main__":
    main()
