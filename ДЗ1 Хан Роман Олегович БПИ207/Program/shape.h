#ifndef __shape__
#define __shape__

#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include <stdio.h>
#include "random.h"
#include <stdbool.h>
#include "exceptions.h"

// Структура обобщенной фигуры.
struct shape {
    // Значения цветов для каждой из фигур.
    enum color {RED, ORANGE, YELLOW, GREEN, LIGHTBLUE, BLUE, PURPLE, TRANSPARENT};
    enum color col;

    // Значения ключей для каждой из фигур.
    enum key {RECTANGLE, TRIANGLE, CIRCLE};
    enum key k;

    // используемые альтернативы
    union {
        struct rectangle r;
        struct triangle t;
        struct circle c;
    };
};

// Ввод обобщенной фигуры.
struct shape *InShape(FILE* inputFile);

// Рандомная генерация некой фигуры.
struct shape *InRndShape();

// Вывод информации о данной фигуре в файл.
void OutShape(struct shape *s, FILE* outputFile);

// Вычисление периметра обобщенной фигуры.
double PerimeterShape(struct shape *s);

#endif
