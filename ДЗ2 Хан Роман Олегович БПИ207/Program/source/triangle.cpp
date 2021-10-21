// Файл triangle.cpp содержит реализацию функци класса Triangle, который расположен в файле triangle.h

#include "../headers/triangle.h"

/**
 * Ввод параметров треугольника из файла
 * @param inputFile - входной поток байтов.
 */
void Triangle::In(FILE *inputFile) {
    bool aX = ProgramException::GetInt(inputFile, &a.x);
    bool aY = ProgramException::GetInt(inputFile, &a.y);
    bool bX = ProgramException::GetInt(inputFile, &b.x);
    bool bY = ProgramException::GetInt(inputFile, &b.y);
    bool cX = ProgramException::GetInt(inputFile, &c.x);
    bool cY = ProgramException::GetInt(inputFile, &c.y);
    if (!aX || !aY || !bX || !bY || !cX || !cY) {
        printf("Some values was incorrect, so they was changed to zero\n");
    }
}

/**
 * Случайна генерация треугольника.
 * При этом гарантируется, что сгенерированный треугольник соответсвует математическим требованиям.
 */
void Triangle::InRnd() {
    a.x = Random::next(0, 1000);
    a.y = Random::next(0, 1000);

    do {
        b.x = Random::next(0, 1000);
        b.y = Random::next(0, 1000);
    } while (a.x == b.x && a.y == b.y);

    do {
        c.x = Random::next(0, 1000);
        c.y = Random::next(0, 1000);
    } while (pow(a.x - b.x, 2) + pow(a.y - b.y, 2) >=
             pow(c.x - b.x, 2) + pow(c.y - b.y, 2) +
             pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
}

/**
 * Вывод информации о треугольнике в файл.
 * @param outputFile - файл, в который нужно вывести информацию.
 */
void Triangle::Out(FILE *outputFile) {
    fprintf(outputFile, "It is Triangle:\n\ta = ");
    fprintf(outputFile, "%d %d,\n\t", a.x, a.y);
    fprintf(outputFile, "b = %d %d,\n\t", b.x, b.y);
    fprintf(outputFile, "c = %d %d,\n\t", c.x, c.y);
    fprintf(outputFile, "Perimeter = %f\n", Perimeter());
    WriteColorInFile(outputFile);
}

/**
 * Вычисление периметра треугольника.
 * @return Результатом является периметр (вещественное число).
 */
double Triangle::Perimeter() {
    return (double) (ceil(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)) +
                     ceil(pow(c.x - b.x, 2) + pow(c.y - b.y, 2)) +
                     ceil(pow(a.x - c.x, 2) + pow(a.y - c.y, 2)));
}