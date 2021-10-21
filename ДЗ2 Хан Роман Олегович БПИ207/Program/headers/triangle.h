#ifndef __triangle__
#define __triangle__

#include <stdio.h>
#include <math.h>
#include "random.h"
#include "point.h"
#include <stdbool.h>
#include "exceptions.h"
#include "shape.h"

/**
 * Класс треугольника (наследуется от Shape)
 */
class Triangle : public Shape {
public:
    /**
     * Деструктор теугольника.
     */
    virtual ~Triangle() {}

    /**
     * Ввод параметров треугольника из файла
     * @param inputFile - входной поток байтов.
     */
    virtual void In(FILE *inputFile);

    /**
     * Случайна генерация треугольника.
     * При этом гарантируется, что сгенерированный треугольник соответсвует математическим требованиям.
     */
    virtual void InRnd();

    /**
     * Вывод информации о треугольнике в файл.
     * @param outputFile - файл, в который нужно вывести информацию.
     */
    virtual void Out(FILE *outputFile);

    /**
     * Вычисление периметра треугольника.
     * @return Результатом является периметр (вещественное число).
     */
    virtual double Perimeter();

private:
    // Крайние точки треугольника.
    Point a, b, c;
};

#endif