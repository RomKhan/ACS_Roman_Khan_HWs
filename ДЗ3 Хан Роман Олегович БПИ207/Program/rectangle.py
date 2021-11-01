from shape import *
from point import *

# Класс прямоугольника (наследуется от Shape).
class Rectangle(Shape):
    def __init__(self):
        self.point1 = Point()
        self.point2 = Point()

    # Создание прямоугольника по данным из общего массива.
    def ReadStrArray(self, strArray, i):
        # Проверка на то,
        # что в массиве будет достаточно элементов уже производится в методе ReadStrArray.
        self.point1.x = int(strArray[i])
        self.point1.y = int(strArray[i + 1])
        self.point2.x = int(strArray[i + 2])
        self.point2.y = int(strArray[i + 3])
        i += 4
        return i

    # Вывод данных о прямоугольнике в консоль.
    def Print(self):
        print(f"It is a Rectangle:\n"
              f"\tcolor - {self.GetColorString()}\n"
              f"\tfirstPoint = {self.point1.x} {self.point1.y}\n"
              f"\tsecondPoint = {self.point2.x} {self.point2.y}\n"
              f"\tPerimeter = {self.Perimeter()}")
        pass

    # Вывод данных о прямоугольнике в файл.
    def Write(self, ostream):
        ostream.write(f"It is a Rectangle:\n"
                      f"\tcolor - {self.GetColorString()}\n"
                      f"\tfirstPoint = {self.point1.x} {self.point1.y}\n"
                      f"\tsecondPoint = {self.point2.x} {self.point2.y}\n"
                      f"\tPerimeter = {self.Perimeter()}")
        pass

    # Вычисление периметра прямоугольника.
    def Perimeter(self):
        return 2.0 * (abs(self.point2.x - self.point1.x) + abs(self.point1.y - self.point2.y))
        pass
