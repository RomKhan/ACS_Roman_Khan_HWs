#ifndef __circle__
#define __circle__

#include <stdio.h>
#include "random.h"
#include "point.h"
#include "exceptions.h"
#include "shape.h"
#include <stdbool.h>

/**
 * Класс круга (наследуется от Shape)
 */
class Circle : public Shape {
public:
    /**
     * Деструктор круга.
     */
    virtual ~Circle() {}

    /**
     * Ввод параметров круга из файла
     * @param inputFile - входной поток байтов.
     */
    virtual void In(FILE *inputFile);

    /**
     * Случайна генерация круга.
     * При этом гарантируется, что сгенерированный круг соответсвует математическим требованиям.
     */
    virtual void InRnd();

    /**
     * Вывод информации о круге в файл.
     * @param outputFile - файл, в который нужно вывести информацию.
     */
    virtual void Out(FILE *outputFile);

    /**
     * Вычисление периметра круга.
     * @return Результатом является периметр (вещественное число).
     */
    virtual double Perimeter();

private:
    // Точка центра круга.
    Point center;
    // Числовое значение радиуса круга.
    int radius;
};

#endif
