#ifndef __rectangle__
#define __rectangle__

#include <stdio.h>
#include "random.h"
#include "point.h"
#include <stdbool.h>
#include "exceptions.h"


// Структура прямоугольника.
struct rectangle {
    struct point point1;
    struct point point2;
};

// Ввод параметров прямоугольника из файла.
void InRectangle(struct rectangle *r, FILE* inputFile);

// Рандомная генерация параметров прямоугольника.
void InRndRectangle(struct rectangle *r);

// Вывод данных прямоугольника в файл.
void OutRectangle(struct rectangle *r, FILE* outputFile);

// Вычисление периметра прямоугольника.
double PerimeterRectangle(struct rectangle *r);

#endif