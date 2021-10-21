#ifndef __random__
#define __random__

#include <stdlib.h>

// random.h - содерит спецификацию класса геренации
// случайных числе в диаопзоне от 1 до 20.

/**
 * Класс рандомной выдачи числа.
 */
class Random {
public:
    /**
     * Получить следующее(относительно заданного сида) рандомное число.
     * @return рандомное число.
     */
    static int next(int lower = 0, int upper = INT32_MAX);
};

#endif
