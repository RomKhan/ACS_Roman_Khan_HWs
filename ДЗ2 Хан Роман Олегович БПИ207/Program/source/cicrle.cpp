#include "../headers/circle.h"

// Константное задание числа PI.
#define PI 3.1415926

/**
 * Ввод параметров круга из файла
 * @param inputFile - входной поток байтов.
 */
void Circle::In(FILE *inputFile) {
    bool centerX = ProgramException::GetInt(inputFile, &center.x);
    bool centerY = ProgramException::GetInt(inputFile, &center.y);
    bool radiusBool = ProgramException::GetInt(inputFile, &radius);
    if (!centerX || !centerY || !radiusBool) {
        printf("Some values was incorrect, so they was changed to zero\n");
    }
}

/**
 * Случайна генерация круга.
 * При этом гарантируется, что сгенерированный круг соответсвует математическим требованиям.
 */
void Circle::InRnd() {
    center.x = Random::next(0, 1000);
    center.y = Random::next(0, 1000);
    radius = Random::next(0, 100);
}

/**
 * Вывод информации о круге в файл.
 * @param outputFile - файл, в который нужно вывести информацию.
 */
void Circle::Out(FILE *outputFile) {
    fprintf(outputFile, "It is Circle:\n\t");
    fprintf(outputFile, "x = %d,\n\t", center.x);
    fprintf(outputFile, "y = %d,\n\t", center.y);
    fprintf(outputFile, "r = %d,\n\t", radius);
    fprintf(outputFile, "Perimeter = %f\n", Perimeter());
    WriteColorInFile(outputFile);
}

/**
 * Вычисление периметра круга.
 * @return Результатом является периметр (вещественное число).
 */
double Circle::Perimeter() {
    return 2.0 * PI * radius;
}