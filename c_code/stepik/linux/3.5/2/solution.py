import os

def count_processes_with_name(name):
    result_count = 0

    # Перебираем все директории в /proc
    for pid in os.listdir("/proc"):
        # Проверяем, является ли имя директории числом (это может быть PID процесса)
        if pid.isdigit():
            # Формируем путь к файлу status для текущего процесса
            status_path = os.path.join("/proc", pid, "status")
            
            try:
                with open(status_path, "r") as f:
                    # Считываем имя процесса из файла status
                    for line in f:
                        if line.startswith("Name:"):
                            # Извлекаем имя процесса
                            _, process_name = line.split(":", 1)
                            process_name = process_name.strip()
                            
                            # Проверяем, совпадает ли имя процесса с искомым именем
                            if process_name == name:
                                result_count += 1
                            break
            except FileNotFoundError:
                pass

    return result_count

def main():
    name = "genenv"
    result_count = count_processes_with_name(name)
    print(result_count)

if __name__ == "__main__":
    main()
