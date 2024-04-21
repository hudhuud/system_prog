import sys
import multiprocessing.shared_memory as sm

def main():
    if len(sys.argv) != 3:
        print(f"{sys.argv[0]} key1 key2")
        sys.exit(1)

    key1 = int(sys.argv[1])
    key2 = int(sys.argv[2])

    try:
        # Открываем разделяемые сегменты памяти
        shm1 = sm.SharedMemory(key1)
        shm2 = sm.SharedMemory(key2)

        # Создаем новый разделяемый сегмент памяти для сумм
        new_shm = sm.SharedMemory(create=True, size=shm1.size)

        # Получаем данные из разделяемых сегментов
        data1 = shm1.buf[:shm1.size].cast("i")
        data2 = shm2.buf[:shm2.size].cast("i")
        new_data = new_shm.buf[:new_shm.size].cast("i")

        # Выполняем суммирование и записываем результат в новый разделяемый сегмент
        for i in range(100):
            new_data[i] = data1[i] + data2[i]

        # Выводим ключ нового разделяемого сегмента памяти
        print(new_shm.name)

    except FileNotFoundError:
        sys.exit(1)

if __name__ == "__main__":
    main()
