#ifndef __triangle__
#define __triangle__

#include <stdio.h>
#include <math.h>
#include "random.h"
#include "point.h"
#include <stdbool.h>
#include "exceptions.h"

// Структура треугольника.
struct triangle {
    struct point a, b, c;
};

// Ввод параметров треугольника из файла.
void InTriangle(struct triangle *t, FILE* inputFile);

// Рандомная генерация параметров треугольника.
void InRndTriangle(struct triangle *e);

// Вывод данных треугольника в файл.
void OutTriangle(struct triangle *t, FILE* outputFile);

// Вычисление периметра треугольника.
double PerimeterTriangle(struct triangle *t);

#endif