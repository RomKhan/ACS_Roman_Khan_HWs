/* shape.c - исходный файл, содержащий в себе процедуры
 * обработки обобщенной фигуры и создания специфических.
 * */

#include "shape.h"

typedef struct shape shape;

// Отдельная процедура установки цвета обобщенной фигуры.
void SetColor(struct shape *shape, int colorType) {
    switch (colorType) {
        case 1:
            shape->col = RED;
            break;
        case 2:
            shape->col = ORANGE;
            break;
        case 3:
            shape->col = YELLOW;
            break;
        case 4:
            shape->col = GREEN;
            break;
        case 5:
            shape->col = LIGHTBLUE;
            break;
        case 6:
            shape->col = BLUE;
            break;
        case 7:
            shape->col = PURPLE;
            break;
        default:
            shape->col = TRANSPARENT;
            break;
    }
}

// Вывод информации о цвете обобщенной фигуры в файл.
void OutColor(struct shape *shape, FILE* outFile) {
    switch (shape->col) {
        case RED:
            fprintf(outFile, "\tColor: RED\n");
            break;
        case ORANGE:
            fprintf(outFile, "\tColor: ORANGE\n");
            break;
        case YELLOW:
            fprintf(outFile, "\tColor: YELLOW\n");
            break;
        case GREEN:
            fprintf(outFile, "\tColor: GREEN\n");
            break;
        case LIGHTBLUE:
            fprintf(outFile, "\tColor: LIGHTBLUE\n");
            break;
        case BLUE:
            fprintf(outFile, "\tColor: BLUE\n");
            break;
        case PURPLE:
            fprintf(outFile, "\tColor: PURPLE\n");
            break;
        default:
            fprintf(outFile, "\tColor: TRANSPARENT\n");
            break;
    }
}

// Ввод параметров обобщенной фигуры из файла.
shape* InShape(FILE* inputFile) {

    shape *sp;
    int k;
    bool checkType = GetInt(inputFile, &k);
    sp = (shape*)malloc(sizeof(shape));

    int colorType;
    bool checkColor = GetInt(inputFile, &colorType);
    if (!checkType || !checkColor)
        return NULL;
    SetColor(sp, colorType);

    switch(k) {
        case 1:
            sp->k = RECTANGLE;
            InRectangle(&(sp->r), inputFile);
            return sp;
        case 2:
            sp->k = TRIANGLE;
            InTriangle(&(sp->t), inputFile);
            return sp;
        case 3:
            sp->k = CIRCLE;
            InCircle(&(sp->c), inputFile);
            return sp;
        default:
            return 0;
    }
}

// Рандомная генерация некой фигуры.
shape *InRndShape() {
    shape *sp;
    int colorType = Random() % 7 + 1;
    sp = (shape*)malloc(sizeof(shape));
    SetColor(sp, colorType);
    int k = Random() % 3 + 1;
    switch(k) {
        case 1:
            sp->k = RECTANGLE;
            InRndRectangle(&(sp->r));
            return sp;
        case 2:
            sp->k = TRIANGLE;
            InRndTriangle(&(sp->t));
            return sp;
        case 3:
            sp->k = CIRCLE;
            InRndCircle(&(sp->c));
            return sp;
        default:
            return 0;
    }
}

// Вывод информации о данной фигуре в файл.
void OutShape(struct shape *s, FILE* outputFile) {
    switch(s->k) {
        case RECTANGLE:
            OutRectangle(&(s->r), outputFile);
            OutColor(s, outputFile);
            break;
        case TRIANGLE:
            OutTriangle(&(s->t), outputFile);
            OutColor(s, outputFile);
            break;
        case CIRCLE:
            OutCircle(&(s->c), outputFile);
            OutColor(s, outputFile);
            break;
        default:
            fprintf(outputFile, "Incorrect figure!\n");
    }
}

// Вычисление периметра фигуры.
double PerimeterShape(struct shape *s) {
    switch(s->k) {
        case RECTANGLE:
            return PerimeterRectangle(&(s->r));
        case TRIANGLE:
            return PerimeterTriangle(&(s->t));
        case CIRCLE:
            return PerimeterCircle(&(s->c));
        default:
            return 0.0;
    }
}