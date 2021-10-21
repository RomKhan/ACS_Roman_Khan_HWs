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
 *
 * В приложении реализован доп функционал - генерация тестов (для этого нужно пользоваться -g).
 * Пример:
 * -g 10
 * Создат файл-тест в папке bin, в котором будут 10 рандомно сгенерирвоанных фигур.
 *
 * ВАЖНО!
 * Стоит отметить, что все файлы, которые програма выдает и принимает будут и должны находиться в папке bin.
 */

// Домашнаяя работа студента Хан Роман.
#include <string.h>
#include "../headers/container.h"
#include "time.h"
#include "../headers/exceptions.h"
#include "../headers/testGenerator.h"

/**
 * Основной метод программы.
 * @param argc число переданных оргументов.
 * @param argv массив аргументов.
 * @return код завершения программы.
 */
int main(int argc, char *argv[]) {
    if (argc == 3 && !strcmp(argv[1], "-g")) {
        int size = strtol(argv[2], &argv[2], 0);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect number of figures = %d. Set 0 < number <= 10000\n", size);
            return 4;
        }
        TestGenerator::generateTest(size);
        printf("Test generated successful!\n");
        return 5;
    }

    clock_t time_start = clock();

    // Обработка некорректного количества аргументов.
    if (argc != 5) {
        ProgramException::errMessage1();
        return 1;
    }

    printf("Start\n");
    Container c;


    if (!strcmp(argv[1], "-f")) {
        FILE *inputFile = fopen(argv[2], "r");
        c.In(inputFile);
    } else if (!strcmp(argv[1], "-n")) {
        int size = strtol(argv[2], &argv[2], 0);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect number of figures = %d. Set 0 < number <= 10000\n", size);
            return 3;
        }


        srand(time(NULL));
        // Заполнение контейнера генератором случайных чисел
        c.InRnd(size);
    } else {
        ProgramException::errMessage2();
        return 2;
    }


    // Открытие первого файла для записи.
    FILE *outputFile1;
    if (!(outputFile1 = fopen(argv[3], "w+"))) {
        perror("Невозможно открыть файл");
        exit(EXIT_FAILURE);
    }

    // Вывод содержимого контейнера в файл
    fprintf(outputFile1, "Filled container:\n");
    c.Out(outputFile1);
    fclose(outputFile1);

    // Открытие второго файла для записи.
    FILE *outputFile2;
    if (!(outputFile2 = fopen(argv[4], "w+"))) {
        perror("Невозможно открыть файл");
        exit(EXIT_FAILURE);
    }

    // Вывод результатов выполнения дополнительной функции и содержимого измененного контейнера в файл.
    fprintf(outputFile2, "Perimeter sum = %f\n", c.Perimeter());
    fprintf(outputFile2, "Perimeter average = %f\n", c.GetAvaragePerimetr());
    fprintf(outputFile2, "Changed container:\n");
    c.RemoveAlternativesWithBigPerimeter();
    c.Out(outputFile2);
    fclose(outputFile2);

    printf("Stop\n");
    printf("Seconds: %f\n", ((double) (clock() - time_start)) / CLOCKS_PER_SEC);
    return 0;
}
