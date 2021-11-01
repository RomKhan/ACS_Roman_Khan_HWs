# Класс со статическими методами ошибок.
class Exceptions:
    # Метод, который выводит информацию о том,
    # что формат введенных аргументов неккоректен.
    # При этом, пользователь информируется о том, какой формат является правельным.
    @staticmethod
    def incorrectArguments():
        print("Incorrect arguments!\n"
              "Available format:\n"
              "\t-f input.txt output.txt\n"
              "\t-n countOfFigures output.txt\n"
              "\t-g countOfFiguresInRandomTest")

    # Метод проверяет переданное число на попадание в промежуток.
    # Если происходит выход из допустимого промежутка, то выводится информация об ошибке.
    @staticmethod
    def incorrectCount(count) -> bool:
        if count > 10000 or count < 0:
            print(f"incorrect number of figures = {count}. Set 0 < number <= 10000")
            return True
        return False

    # Во входном файле присутсвуте неккоректный формат.
    # Например, вместо числа введеная строка или для фигуры нет достаточного количества аргументов.
    @staticmethod
    def incorrectFileInput():
        print("Program was closed with exception - Incorrect file input!\n"
              "Please fix the file input arguments and try again")
