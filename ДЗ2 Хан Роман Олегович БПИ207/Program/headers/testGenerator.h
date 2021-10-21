#ifndef TASK1_TESTGENERATOR_H
#define TASK1_TESTGENERATOR_H

#include <cstdio>
#include "string.h"
#include "random.h"
#include "math.h"
#include "container.h"

/**
 * Класс генератора тестов.
 * В улосвии задания не сказано, что это нужно реализовать, поэтому можно считать данный класс доп функционалом.
 */
class TestGenerator {
private:
    /**
     * Генерация рандомных координат точек для прямоугольника.
     * @param x1 - x координата первой точки.
     * @param y1 - y координата первой точки.
     * @param x2 - x координата второй точки.
     * @param y2 - y координата второй точки.
     */
    static void generateRectangleCoordinates(int &x1, int &y1, int &x2, int &y2);

    /**
     * Генерация рандомных координат точек для треугольника.
     * @param x1 - x координата первой точки.
     * @param y1 - y координата первой точки.
     * @param x2 - x координата второй точки.
     * @param y2 - y координата второй точки.
     * @param x3 - x координата третей точки.
     * @param y3 - y координата третей точки.
     */
    static void generateTriangleCoordinates(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3);

    /**
     * Генерация рандомных координат точек для круга.
     * @param x - x координата центра.
     * @param y - y координата центра.
     * @param r - радиус.
     */
    static void generateCircleCoordinates(int &x, int &y, int &r);

public:
    /**
     * Генерация рандомного теста с заданным количеством фигур и запиь его в файл.
     * @param size - количество фигур.
     */
    static void generateTest(int size);
};


#endif //TASK1_TESTGENERATOR_H
