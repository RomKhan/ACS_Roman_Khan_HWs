/* exceptions.h - содержит обьявления функций, оторые могут выдавать исключения.
 */
#ifndef __exceptions__
#define __exceptions__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool GetInt(FILE* inputFile, int *number);

void errMessage2();

void errMessage1();


#endif
