#include "container.h"


// Инициализация контейнера.
void Init(struct container *c) {
    c->len = 0;
}

// Очистка контейнера от элементов (освобождение памяти).
void Clear(struct container *c) {
    for(int i = 0; i < (*c).len; i++) {
        free(c->cont[i]);
    }
    c->len = 0;
}

// Ввод содержимого контейнера из указанного потока.
void In(struct container *c, FILE* inputFile) {
    while((c->cont[c->len] = InShape(inputFile)) != NULL) {
            c->len++;
    }
    fclose(inputFile);
}

// Рандомная генерация содержимого контейнера.
void InRnd(struct container *c, int size) {
    while(c->len < size) {
        if((c->cont[c->len] = InRndShape()) != 0) {
            c->len++;
        }
    }
}

// Вывод содержимого контейнера в указанный поток.
void Out(struct container *c, FILE* outputFile) {
    fprintf(outputFile,"Container contains ");
    fprintf(outputFile, "%d", c->len);
    fprintf(outputFile," elements.\n");
    for(int i = 0; i < c->len; i++) {
        fprintf(outputFile,"%d", i+1);
        fprintf(outputFile,": ");
        OutShape(c->cont[i], outputFile);
    }
}

// Вычисление суммы периметров всех фигур в контейнере.
double PerimeterSum(struct container *c) {
    double sum = 0.0;
    for(int i = 0; i < c->len; i++) {
        sum += PerimeterShape(c->cont[i]);
    }
    return sum;
}

// Удаление из контейнера всех фигур, периметр которых больше среднего.
void RemoveAlternativesWithBigPerimeter(struct container *c) {
    double average = PerimeterSum(c) / c->len;
    for (int i = 0; i < c->len; i++) {
        if (PerimeterShape(c->cont[i]) > average) {
            c->len--;
            for(int j = i; j < c->len; j++) {
                c->cont[j] = c->cont[j+1];
            }
            c->cont[c->len] = NULL;
        }
    }
}

