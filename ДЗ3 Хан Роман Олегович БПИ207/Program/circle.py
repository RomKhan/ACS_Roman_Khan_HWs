from shape import *
from point import *
import math


# Класс круга (наследуется от Shape).
class Circle(Shape):
    def __init__(self):
        self.r = 0
        self.center = Point()

    # Создание круга по данным из общего массива.
    def ReadStrArray(self, strArray, i):
        # Проверка на то,
        # что в массиве будет достаточно элементов уже производится в методе ReadStrArray.
        self.center.x = int(strArray[i])
        self.center.y = int(strArray[i + 1])
        self.r = int(strArray[i + 2])
        i += 3
        return i

    # Вывод данных о круге в консоль.
    def Print(self):
        print(f"It is a Circle:\n"
              f"\tcolor - {self.GetColorString()}\n"
              f"\tcenter = {self.center.x} {self.center.y}\n"
              f"\tr = {self.r}\n"
              f"\tPerimeter = {self.Perimeter()}")
        pass

    # Вывод данных о круге в файл.
    def Write(self, ostream):
        ostream.write(f"It is a Circle:\n"
                      f"\tcolor - {self.GetColorString()}\n"
                      f"\tcenter = {self.center.x} {self.center.y}\n"
                      f"\tr = {self.r}\n"
                      f"\tPerimeter = {self.Perimeter()}")
        pass

    # Вычисление периметра круга.
    def Perimeter(self):
        return float(2 * math.pi * self.r)
        pass
