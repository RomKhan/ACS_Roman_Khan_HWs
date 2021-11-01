from extender import *


class Container:
    def __init__(self):
        self.store = []

    # Вывод информации о содержимом контейнера в консоль.
    def Print(self):
        print("Container is store", len(self.store), "shapes:")
        for shape in self.store:
            shape.Print()
        print("Summa of Perimeters  = ", self.Perimeter())
        pass

    # Вывод информации о содержимом контейнера в файл.
    def Write(self, ostream):
        ostream.write("Container is store {} shapes:\n".format(len(self.store)))
        for shape in self.store:
            shape.Write(ostream)
            ostream.write("\n")
        ostream.write("Summa of Perimeters  = {}\n".format(self.Perimeter()))
        pass

    # Подсчет суммы пермитрев всех фигур.
    def Perimeter(self):
        perim = 0.0
        for shape in self.store:
            perim += shape.Perimeter()
        return perim

    # Вычисление среднего периметра фигуры в контейнере.
    def GetAveragePerimeter(self) -> float:
        return self.Perimeter() / (len(self.store) if len(self.store) != 0 else 1)

    # Удаление всех фигур, периметр которых больше среднего.
    def RemoveAlternativesWithBigPerimeter(self):
        average = self.GetAveragePerimeter()

        index = 0
        for i in range(len(self.store)):
            if self.store[index].Perimeter() > average:
                self.store.remove(self.store[index])
                index -= 1
            index += 1
