#include "../headers/rectangle.h"

/**
 * Ввод параметров прямоугольника из файла
 * @param inputFile - входной поток байтов.
 */
void Rectangle::In(FILE *inputFile) {
    bool p1X = ProgramException::GetInt(inputFile, &point1.x);
    bool p1Y = ProgramException::GetInt(inputFile, &point1.y);
    bool p2X = ProgramException::GetInt(inputFile, &point2.x);
    bool p2Y = ProgramException::GetInt(inputFile, &point2.y);
    if (!p1X || !p1Y || !p2X || !p2Y) {
        printf("Some values was incorrect, so they was changed to zero\n");
    }
}

/**
 * Случайна генерация прямоугольника.
 * При этом гарантируется, что сгенерированный прямоугольник соответсвует математическим требованиям.
 */
void Rectangle::InRnd() {
    do {
        point1.x = Random::next(0, 1000);
        point1.y = Random::next(0, 1000);
    } while (point1.x == 999 || point1.y == 0);

    do {
        point2.x = Random::next(0, 1000);
        point2.y = Random::next(0, 1000);
    } while (point2.x <= point1.x || point2.y >= point1.y);
}

/**
 * Вывод информации о прямоугольнике в файл.
 * @param outputFile - файл, в который нужно вывести информацию.
 */
void Rectangle::Out(FILE *outputFile) {
    fprintf(outputFile, "It is Rectangle:\n\t");
    fprintf(outputFile, "point1: %d %d\n\t", point1.x, point1.y);
    fprintf(outputFile, "point2: %d %d\n\t", point2.x, point2.y);
    fprintf(outputFile, "Perimeter = %f\n", Perimeter());
    WriteColorInFile(outputFile);
}

/**
 * Вычисление периметра прямоугольнике.
 * @return Результатом является периметр (вещественное число).
 */
double Rectangle::Perimeter() {
    return 2.0 * (abs(point2.x - point1.x) + abs(point1.y - point2.y));
}