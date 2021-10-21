// shape.cpp - исходный файл, содержащий в себе реализацию методов класса Shape,
// который находится в файле shape.h.
// Данные методы содержат логику обработки обобщенной фигуры и создания специфических.

#include "../headers/triangle.h"
#include "../headers/circle.h"
#include "../headers/rectangle.h"

/**
 * Было решено отнести метод написания цвета в файл также к абстрактному классу.
 * Это помогает не копировать один и тот же функционал в различные различных альтернатив.
 * @param outFile
 */
void Shape::WriteColorInFile(FILE *outFile) {
    switch (color) {
        case RED:
            fprintf(outFile, "\tColor: RED\n");
            break;
        case ORANGE:
            fprintf(outFile, "\tColor: ORANGE\n");
            break;
        case YELLOW:
            fprintf(outFile, "\tColor: YELLOW\n");
            break;
        case GREEN:
            fprintf(outFile, "\tColor: GREEN\n");
            break;
        case LIGHTBLUE:
            fprintf(outFile, "\tColor: LIGHTBLUE\n");
            break;
        case BLUE:
            fprintf(outFile, "\tColor: BLUE\n");
            break;
        case PURPLE:
            fprintf(outFile, "\tColor: PURPLE\n");
            break;
        default:
            fprintf(outFile, "\tColor: TRANSPARENT\n");
            break;
    }
}

/**
 * Геттер для инкапсулированного поля цвета фигуры.
 * Реализация данного метода прописана в файле shape.cpp - это означает,
 * что данный метод напрямую можно вызывать от ссылки асбтрактного класса.
 * @return возвращает цвет данной фигуры.
 */
Colors Shape::GetColor() {
    return color;
}

/**
 * Сеттер цвета данной фигуры.
 * Данный метод также принадлежит обьекту асбтрактного класса.
 * Он позволяет установить цвет фигуры.
 * @param color - цвет, который нужно установить.
 */
void Shape::SetColor(Colors newColor) {
    color = newColor;
}

/**
 * Статический ввод фигуры.
 * На основе полученных данных из файла программа генерирует одну из альтернатив.
 * @param inputFile - файл, из которого происходит чтение.
 * @return Возвращает обобщенный экземпляр фигуры.
 */
Shape *Shape::StaticIn(FILE *inputFile) {
    int k;
    bool checkType = ProgramException::GetInt(inputFile, &k);

    int colorType;
    bool checkColor = ProgramException::GetInt(inputFile, &colorType);
    if (!checkType || !checkColor)
        return nullptr;
    Shape *sp = nullptr;
    switch (k) {
        case 1:
            sp = new Rectangle;
            break;
        case 2:
            sp = new Triangle;
            break;
        case 3:
            sp = new Circle;
            break;
        default:
            "Incorrect random value";
    }
    int *x = new int;
    sp->SetColor(Colors(colorType));
    sp->In(inputFile);

    delete x;
    return sp;
}

/**
 * Статический метод генерации рандомной алтернативы с рандомными параметрами.
 * Гарантируется, что какая бы алтернатива не была сгенерирована,
 * ее параметры будут отвечать математическим правилам.
 * @return Возвращает сгенерированный обобщенный экземпляр фигуры.
 */
Shape *Shape::StaticInRnd() {
    auto k = Random::next(1, 4);
    Shape *sp = nullptr;
    switch (k) {
        case 1:
            sp = new Rectangle;
            break;
        case 2:
            sp = new Triangle;
            break;
        case 3:
            sp = new Circle;
            break;
        default:
            "Incorrect random value";
    }
    sp->SetColor(Colors(Random::next(0, 7)));
    sp->InRnd();
    return sp;
}