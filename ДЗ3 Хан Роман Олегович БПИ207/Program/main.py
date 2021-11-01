import os.path
import sys
from extender import *

'''
Домашнаяя работа студента Хан Роман.
'''


# Метод с основной логикой работы программы.
def StartBaseLogic():
    print('==> Start')

    container = Container()
    # Проверка на корректность считывания фигур из массива.
    is_correct = GeneratorAndWriter.ReadStrArray(container, strArray)
    if not is_correct:
        print('==> Finish')
        sys.exit()

    # Вывод информации о содержимом контейнера до применения функции в консоль.
    print("\tBefore function")
    print("<----------------------->")
    container.Print()
    print(f"Average perimeter: {container.GetAveragePerimeter()}")
    print("<----------------------->")

    ofile = open(outputFileName, 'w')

    # Вывод информации о содержимом контейнера до применения функции в файл.
    ofile.write("\tBefore function\n")
    ofile.write("<----------------------->\n")
    container.Write(ofile)
    ofile.write(f"Average perimeter: {container.GetAveragePerimeter()}\n")
    ofile.write("<----------------------->\n")

    # Удаление всех фигур, периметры которых больше среднего периметра.
    container.RemoveAlternativesWithBigPerimeter()

    # Вывод информации о содержимом контейнера после применения функции в консоль.
    print("\n\tAfter function")
    print("<----------------------->")
    container.Print()
    print("<----------------------->")

    # Вывод информации о содержимом контейнера после применения функции в файл.
    ofile.write("\n\tAfter function\n")
    ofile.write("<----------------------->\n")
    container.Write(ofile)
    ofile.write("<----------------------->\n")
    ofile.close()

    print('==> Finish')


# Точка входа в программу.
# Здесь происходит валидация введенных аргументов и загрузка данных из файл в массив
# (если указан соответвующий ключ).
if __name__ == '__main__':
    if len(sys.argv) < 2 or len(sys.argv) > 4:
        Exceptions.incorrectArguments()
    if sys.argv[1] == "-f":
        if len(sys.argv) == 4:
            inputFileName = sys.argv[2]
            outputFileName = sys.argv[3]
        elif len(sys.argv) == 3:
            inputFileName = sys.argv[2]
            outputFileName = "output.txt"
        else:
            inputFileName = "No file"

        # Чтение исходного файла, содержащего данные, разделенные пробелами и переводами строки
        if not os.path.isfile(inputFileName):
            print(f"File with name '{inputFileName}' not found")
            sys.exit(1)
        ifile = open(inputFileName)
        str = ifile.read()
        ifile.close()

        # Формирование массива строк, содержащего чистые данные в виде массива строк символов.
        strArray = [x for x in str.replace("\n", " ").split(" ") if x != ""]
        StartBaseLogic()
    elif sys.argv[1] == "-n":
        count = -1
        if len(sys.argv) == 4:
            count = int(sys.argv[2])
            outputFileName = sys.argv[3]
        elif len(sys.argv) == 3:
            count = int(sys.argv[2])
            outputFileName = "output.txt"

        # Формирование массива строк, содержащего чистые данные в виде массива строк символов
        if not Exceptions.incorrectCount(count):
            strArray = GeneratorAndWriter.RndGenerateArr(count)
            StartBaseLogic()
    elif sys.argv[1] == "-g":
        if len(sys.argv) < 3:
            Exceptions.incorrectArguments()

        if not sys.argv[2].isdigit():
            Exceptions.incorrectArguments()
            sys.exit(1)
        count = int(sys.argv[2])
        # Запуск генератора, если введенно корректное количество фигур.
        if not Exceptions.incorrectCount(count):
            GeneratorAndWriter.WriteTest(count)
            print("Test generated successfully")
    else:
        Exceptions.incorrectArguments()
