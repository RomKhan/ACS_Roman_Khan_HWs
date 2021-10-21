// Файл testGenerator.cpp содержит реализацию функци класса TestGenerator, который расположен в файле testGenerator.h

#include "../headers/testGenerator.h"

/**
 * Генерация рандомного теста с заданным количеством фигур и запиь его в файл.
 * @param size - количество фигур.
 */
void TestGenerator::generateTest(int size) {
    FILE *inputFile = fopen("testAutomaticGenerate.txt", "w");
    for (int i = 0; i < size; ++i) {
        int type = Random::next(1, 4);
        int color = Random::next(0, 7);

        fprintf(inputFile, "%d %d\n", type, color);
        switch (type) {
            case 1:
                int x1, y1, x2, y2;
                generateRectangleCoordinates(x1, y1, x2, y2);
                fprintf(inputFile, "%d %d %d %d\n", x1, y1, x2, y2);
                break;
            case 2:
                int x3, y3;
                generateTriangleCoordinates(x1, y1, x2, y2, x3, y3);
                fprintf(inputFile, "%d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3);
                break;
            case 3:
                int x, y, r;
                generateCircleCoordinates(x, y, r);
                fprintf(inputFile, "%d %d %d\n", x, y, r);
                break;
            default:
                continue;
        }
    }
}

/**
 * Генерация рандомных координат точек для прямоугольника.
 * @param x1 - x координата первой точки.
 * @param y1 - y координата первой точки.
 * @param x2 - x координата второй точки.
 * @param y2 - y координата второй точки.
 */
void TestGenerator::generateRectangleCoordinates(int &x1, int &y1, int &x2, int &y2) {
    do {
        x1 = Random::next(0, 1000);
        y1 = Random::next(0, 1000);
    } while (x1 == 999 || y1 == 0);

    do {
        x2 = Random::next(0, 1000);
        y2 = Random::next(0, 1000);
    } while (x2 <= x1 || y2 >= y1);
}

/**
 * Генерация рандомных координат точек для треугольника.
 * @param x1 - x координата первой точки.
 * @param y1 - y координата первой точки.
 * @param x2 - x координата второй точки.
 * @param y2 - y координата второй точки.
 * @param x3 - x координата третей точки.
 * @param y3 - y координата третей точки.
 */
void TestGenerator::generateTriangleCoordinates(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3) {
    x1 = Random::next(0, 1000);
    y1 = Random::next(0, 1000);

    do {
        x2 = Random::next(0, 1000);
        y2 = Random::next(0, 1000);
    } while (x1 == x2 && y1 == y2);

    do {
        x3 = Random::next(0, 1000);
        y3 = Random::next(0, 1000);
    } while (pow(x1 - x2, 2) + pow(y1 - y2, 2) >=
             pow(x3 - x2, 2) + pow(y3 - y2, 2) +
             pow(x1 - x3, 2) + pow(y1 - y3, 2));
}

/**
 * Генерация рандомных координат точек для круга.
 * @param x - x координата центра.
 * @param y - y координата центра.
 * @param r - радиус.
 */
void TestGenerator::generateCircleCoordinates(int &x, int &y, int &r) {
    x = Random::next(0, 1000);
    y = Random::next(0, 1000);
    r = Random::next(0, 100);
}
