#ifndef __rectangle__
#define __rectangle__

#include <stdio.h>
#include "random.h"
#include "point.h"
#include <stdbool.h>
#include "exceptions.h"
#include "shape.h"

/**
 * Класс прямоугольника (наследуется от Shape)
 */
class Rectangle : public Shape {
public:
    /**
     * Деструктор прямоугольника.
     */
    virtual ~Rectangle() {}

    /**
     * Ввод параметров прямоугольника из файла
     * @param inputFile - входной поток байтов.
     */
    virtual void In(FILE *outputFile);

    /**
     * Случайна генерация прямоугольника.
     * При этом гарантируется, что сгенерированный прямоугольник соответсвует математическим требованиям.
     */
    virtual void InRnd();

    /**
     * Вывод информации о прямоугольнике в файл.
     * @param outputFile - файл, в который нужно вывести информацию.
     */
    virtual void Out(FILE *outputFile);

    /**
     * Вычисление периметра прямоугольнике.
     * @return Результатом является периметр (вещественное число).
     */
    virtual double Perimeter();

private:
    // Точки, которые отвечают за верхний левый и правый нижний углы прямоугольника соответсвенно.
    Point point1, point2;
};

#endif