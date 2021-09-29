#include "triangle.h"

// Ввод параметров треугольника из потока.
void InTriangle(struct triangle *t, FILE* inputFile) {
    bool aX = GetInt(inputFile, &t->a.x);
    bool aY = GetInt(inputFile, &t->a.y);
    bool bX = GetInt(inputFile, &t->b.x);
    bool bY = GetInt(inputFile, &t->b.y);
    bool cX = GetInt(inputFile, &t->c.x);
    bool cY = GetInt(inputFile, &t->c.y);
    if (!aX || !aY || !bX || !bY || !cX || !cY) {
        printf("Some values was incorrect, so they was changed to zero\n");
    }
}

// Рандомная генерация параметров треугольника.
void InRndTriangle(struct triangle *t) {
    t->a.x = Random();
    t->a.y = Random();

    do {
        t->b.x = Random();
        t->b.y = Random();
    } while (t->a.x != t->b.x && t->a.y != t->b.y);

    do {
        t->c.x = Random();
        t->c.y = Random();
    } while(pow(t->a.x-t->b.x, 2) + pow(t->a.y-t->b.y, 2) >=
            pow(t->c.x-t->b.x, 2) + pow(t->c.y-t->b.y, 2) +
            pow(t->a.x-t->c.x, 2) + pow(t->a.y-t->c.y, 2));
}

// Вывод данных треугольника в файл.
void OutTriangle(struct triangle *t, FILE* outputFile) {
    fprintf(outputFile, "It is Triangle:\n\ta = ");
    fprintf(outputFile, "%d %d,\n\t", t->a.x, t->a.y);
    fprintf(outputFile, "b = %d %d,\n\t", t->b.x, t->b.y);
    fprintf(outputFile, "c = %d %d,\n\t", t->c.x, t->c.y);
    fprintf(outputFile, "Perimeter = %f\n", PerimeterTriangle(t));
}

// Вычисление периметра треугольника.
double PerimeterTriangle(struct triangle *t) {
    return (double)(ceil(pow(t->a.x-t->b.x, 2) + pow(t->a.y-t->b.y, 2)) +
                    ceil(pow(t->c.x-t->b.x, 2) + pow(t->c.y-t->b.y, 2)) +
                    ceil(pow(t->a.x-t->c.x, 2) + pow(t->a.y-t->c.y, 2)));
}