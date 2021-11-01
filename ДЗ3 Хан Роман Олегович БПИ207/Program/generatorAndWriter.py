import random
import sys
from extender import *


class GeneratorAndWriter:
    # Генерация массива с информаице о рандомных фигурах в соответсвии с форматов входных данных.
    # Всего в генерируемом массиве содержится ровно count фигур.
    @staticmethod
    def RndGenerateArr(count) -> []:
        arr = []
        for i in range(count):
            key = random.randint(1, 3)
            color = random.randint(1, 7)
            arr.append(key)
            arr.append(color)
            if key == 1:
                arr += GeneratorAndWriter.getCordsForRectangle()
            elif key == 2:
                arr += GeneratorAndWriter.getCordsForTriangle()
            elif key == 3:
                arr += GeneratorAndWriter.getCordsForCircle()
        return [str(x) for x in arr]

    # Генерация рандомных координат точек для треугольника.
    @staticmethod
    def getCordsForTriangle() -> []:
        x1 = random.randint(1, 1000)
        y1 = random.randint(1, 1000)
        x2 = random.randint(1, 1000)
        y2 = random.randint(1, 1000)
        x3 = random.randint(1, 1000)
        y3 = random.randint(1, 1000)

        while x1 == x2 and y1 == y2:
            x2 = random.randint(1, 1000)
            y2 = random.randint(1, 1000)
        while (math.pow(x1 - x2, 2) + math.pow(y1 - y2, 2) >=
               math.pow(x3 - x2, 2) + math.pow(y3 - y2, 2) +
               math.pow(x1 - x3, 2) + math.pow(y1 - y3, 2)):
            x3 = random.randint(1, 1000)
            y3 = random.randint(1, 1000)
        return [x1, y1, x2, y2, x3, y3]

    # Генерация рандомных координат точек для прямоугольника.
    @staticmethod
    def getCordsForRectangle() -> []:
        x1 = random.randint(1, 1000)
        y1 = random.randint(1, 1000)
        x2 = random.randint(1, 1000)
        y2 = random.randint(1, 1000)

        while x1 == 1000 or y1 == 1:
            x1 = random.randint(1, 1000)
            y1 = random.randint(1, 1000)

        while x2 <= x1 or y2 >= y1:
            x2 = random.randint(1, 1000)
            y2 = random.randint(1, 1000)

        return [x1, y1, x2, y2]

    # Генерация рандомных координат точек для круга.
    @staticmethod
    def getCordsForCircle() -> []:
        r = random.randint(1, 1000)
        x = random.randint(1, 1000)
        y = random.randint(1, 1000)
        return [r, x, y]

    # Метод, который проверяет на возможность дальнешего считывания массива (вместе со смещением).
    # Если в массиве присутвуют строки,
    # которые не могут быть преобразованы в число или массив имеет недостаточную длину,
    # то пользователю выводится сообщение об ошибке, а приложение прекращает работу.
    @staticmethod
    def ConinueOrExit(start_index, count_of_offset, array):
        if start_index + count_of_offset > len(array):
            Exceptions.incorrectFileInput()
            sys.exit()
        for i in range(count_of_offset):
            if not array[start_index + i].isdigit():
                Exceptions.incorrectFileInput()
                sys.exit()

    @staticmethod
    def ReadStrArray(container, strArray) -> bool:
        array_len = len(strArray)
        # Индекс, задающий текущую строку в массиве.
        i = 0
        while i < array_len:
            GeneratorAndWriter.ConinueOrExit(i, 2, strArray)

            # Парсинг отличительного признака фигуры.
            key = int(strArray[i])
            # Парсинг цвета фигуры.
            color = int(strArray[i + 1])
            i += 2

            # Признак прямоугольника - 1, треугольика - 2, круга - 3.
            if key == 1:
                GeneratorAndWriter.ConinueOrExit(i, 4, strArray)
                shape = Rectangle()
                # Чтение прямоугольника с возвратом позиции за ним.
                i = shape.ReadStrArray(strArray, i)
            elif key == 2:
                GeneratorAndWriter.ConinueOrExit(i, 6, strArray)
                shape = Triangle()
                # Чтение треугольника с возвратом позиции за ним.
                i = shape.ReadStrArray(strArray, i)
            elif key == 3:
                GeneratorAndWriter.ConinueOrExit(i, 3, strArray)
                shape = Circle()
                # Чтение круга с возвратом позиции за ним.
                i = shape.ReadStrArray(strArray, i)
            else:
                # Если что-то пошло не так, вывод сообщения и выход из функции.
                print("Something went wrong!")
                return False
            shape.SetColor(color)
            container.store.append(shape)
        return True

    # Генерация рандомного теста с заданным количеством фигур
    # и запись полученного массива данных в файл.
    @staticmethod
    def WriteTest(count):
        str_arr = GeneratorAndWriter.RndGenerateArr(count)
        file = open("autoGenerateRandomTest.txt", 'w')
        i = 0
        while i < len(str_arr):
            key = int(str_arr[i])
            color = int(str_arr[i + 1])
            i += 2
            file.write(f"{key} {color}\n")
            if key == 1:
                file.write(f"{str_arr[i]} {str_arr[i + 1]} {str_arr[i + 2]} {str_arr[i + 3]}\n")
                i += 4
            elif key == 2:
                file.write(f"{str_arr[i]} {str_arr[i + 1]} {str_arr[i + 2]} "
                           f"{str_arr[i + 3]} {str_arr[i + 4]} {str_arr[i + 5]}\n")
                i += 6
            elif key == 3:
                file.write(f"{str_arr[i]} {str_arr[i + 1]} {str_arr[i + 2]}\n")
                i += 3
        file.close()
