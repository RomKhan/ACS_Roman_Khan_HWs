/* main.c - исходный файл, из которого стартует программа.
 * Здесь описан полный жизненный цикл программы.
 *
 * Формат входных данных в файле следующий:
 * Сначало на одной строке идет номер фигуры ее цвета.
 * Затем на следующей строке идут параметры специфичной фигуры.
 * Пример:
 * 1 3
 * 2 3 4 5
 * Будет создана сущность - прямоугольник желтого цвета.
 * Первая точка имеет координаты (2,3), вторая - (4,5).
 */

// Домашнаяя работа студента Хан Роман.
#include <stdio.h>
#include <string.h>
#include "container.h"
#include "time.h"
#include "exceptions.h"
typedef struct container container;

int main(int argc, char* argv[]) {

    clock_t time_start = clock();

    // Обработка некорректного количества аргументов.
    if(argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    container c;

    // Создание контейнера.
    Init(&c);

    if(!strcmp(argv[1], "-f")) {
        FILE *inputFile = fopen(argv[2], "a+");
        In(&c, inputFile);
    }
    else if(!strcmp(argv[1], "-n")) {
        long size =  strtol(argv[2], &argv[2], 0);
        if((size < 1) || (size > 10000)) {
            printf("incorrect number of figures = %d. Set 0 < number <= 10000\n", size);
            return 3;
        }


        srand(time(NULL));
        // Заполнение контейнера генератором случайных чисел
        InRnd(&c, (int)size);
    }
    else {
        errMessage2();
        return 2;
    }


    // Открытие первого файла для записи.
    FILE *outputFile1;
    if(!(outputFile1 = fopen(argv[3], "w+"))) {
        perror("Невозможно открыть файл");
        exit(EXIT_FAILURE);
    }

    // Вывод содержимого контейнера в файл
    fprintf(outputFile1, "Filled container:\n");
    Out(&c, outputFile1);
    fclose(outputFile1);

    // Открытие второго файла для записи.
    FILE *outputFile2;
    if(!(outputFile2 = fopen(argv[4], "w+"))) {
        perror("Невозможно открыть файл");
        exit(EXIT_FAILURE);
    }

    // Вывод результатов выполнения дополнительной функции и содержимого измененного контейнера в файл.
    fprintf(outputFile2, "Perimeter sum = %f\n", PerimeterSum(&c));
    fprintf(outputFile2, "Perimeter average = %f\n", PerimeterSum(&c) / c.len);
    fprintf(outputFile2, "Changed container:\n");
    RemoveAlternativesWithBigPerimeter(&c);
    Out(&c, outputFile2);
    fclose(outputFile2);

    // Очистка контейнера.
    Clear(&c);

    printf("Stop\n");
    printf("Seconds: %f\n", ((double)(clock() - time_start)) / CLOCKS_PER_SEC);
    return 0;
}
