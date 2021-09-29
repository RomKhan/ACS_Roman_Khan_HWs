/* exceptions.c - содержит реализацию процедур, которые могут выдавать исключения,
 * и обрабатывает их.
 * */

#include "exceptions.h"

// Получение числа из файла.
bool GetInt(FILE* inputFile, int *number) {
    int count = fscanf(inputFile, "%d", number);
    if (count == EOF || count == 0) {
        number = 0;
        return false;
    }
    return true;
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}