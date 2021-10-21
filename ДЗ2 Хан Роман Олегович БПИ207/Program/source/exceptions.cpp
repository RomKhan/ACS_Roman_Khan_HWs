// exceptions.c - содержит реализацию методов класса ProgramException,
// которые могут выдавать исключения, и обрабатывает их.

#include "../headers/exceptions.h"

/**
 * Метод пытается считать число из файла.
 * Притом, если считать число возможно - считывает это число.
 * @param inputFile - файл, из которого нужно считать число.
 * @param number - интовая переменная, в которую надо записать числовое значение.
 * @return результатом явялется успешность считывания числа (true - счтиать число получилось, false - нет).
 */
bool ProgramException::GetInt(FILE *inputFile, int *number) {
    int count = fscanf(inputFile, "%d", number);
    if (count == EOF || count == 0) {
        number = 0;
        return false;
    }
    return true;
}

/**
 * Вывод сообщения об ошибке 1 (неккоректное количество аргументов) в консоль.
 */
void ProgramException::errMessage2() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

/**
 * Вывод сообщения об ошибке 2 (неккоректное ключ) в консоль.
 */
void ProgramException::errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}