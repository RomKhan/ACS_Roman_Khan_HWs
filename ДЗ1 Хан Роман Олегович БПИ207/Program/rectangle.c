#include "rectangle.h"

// Ввод параметров прямоугольника из файла.
void InRectangle(struct rectangle *r, FILE* inputFile) {
    bool p1X = GetInt(inputFile, &r->point1.x);
    bool p1Y= GetInt(inputFile,  &r->point1.y);
    bool p2X = GetInt(inputFile, &r->point2.x);
    bool p2Y = GetInt(inputFile, &r->point2.y);
    if (!p1X || !p1Y || !p2X || !p2Y) {
        printf("Some values was incorrect, so they was changed to zero\n");
    }
}

// Рандомная генерация параметров прямоугольника.
void InRndRectangle(struct rectangle *r) {
    r->point1.x = Random();
    r->point1.y = Random();

    do {
        r->point2.x = Random();
        r->point2.y = Random();
    } while(r->point2.x <= r->point1.x || r->point2.y >= r->point1.y);
}

// Вывод данных прямоугольника в файл.
void OutRectangle(struct rectangle *r, FILE* outputFile) {
    fprintf(outputFile, "It is Rectangle:\n\t");
    fprintf(outputFile, "point1: %d %d\n\t", r->point1.x, r->point1.y);
    fprintf(outputFile, "point2: %d %d\n\t", r->point2.x, r->point2.y);
    fprintf(outputFile, "Perimeter = %f\n", PerimeterRectangle(r));
}

// Вычисление периметра прямоугольника.
double PerimeterRectangle(struct rectangle *r) {
    return 2.0 * (abs(r->point2.x-r->point1.x) + abs(r->point1.y-r->point2.y));
}