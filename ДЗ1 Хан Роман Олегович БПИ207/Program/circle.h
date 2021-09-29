#ifndef __circle__
#define __circle__

#include <stdio.h>
#include "random.h"
#include "point.h"
#include "exceptions.h"
#include <stdbool.h>

// Структура круга.
struct circle {
    // Радиус.
    int r;
    // Центр.
    struct point center;
};

// Ввод параметров круга из файла.
void InCircle(struct circle *circle, FILE* inputFile);

// Рандомная генерация параметров круга.
void InRndCircle(struct circle *circle);

// Вывод данных круга в файл.
void OutCircle(struct circle *circle, FILE* outputFile);

// Вычисление длины окружности круга.
double PerimeterCircle(struct circle *circle);

#endif
