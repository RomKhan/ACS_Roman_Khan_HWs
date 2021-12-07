/**
 * Заголовочный файл с определением функциеи вывода содержимого буфера в консоль.
 */

#ifndef HW5_PRINT_H
#define HW5_PRINT_H

#include "stdlib.h"
#include "buffer.h"
#include <stdio.h>

typedef struct Buffer Buffer;

/**
 * Функция вывода содержимого буфера в консоль
 * @param buffer - буфер, из которого нужно вывести содержимое.
 * @param size - размерность склада / грузовика.
 */
void pringState();

#endif //HW5_PRINT_H
