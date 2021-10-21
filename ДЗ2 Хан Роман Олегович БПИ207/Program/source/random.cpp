#include "../headers/random.h"

// Реализация метода класса генерации рандомного числа в диапозоне от 1 до 20.

/**
 * Получить следующее(относительно заданного сида) рандомное число.
 * @return рандомное число.
 */
int Random::next(int lower, int upper) {
    if (lower < upper) {
        return rand() % (upper - lower) + lower;
    }
    return 0;
}
