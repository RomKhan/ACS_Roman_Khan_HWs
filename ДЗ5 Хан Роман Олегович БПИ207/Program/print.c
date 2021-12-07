/**
 * Исполняемый файл с функцией вывода содержимого буфера в консоль.
 */
#include "print.h"

/**
 * Функция вывода содержимого буфера в консоль
 * @param buffer - буфер, из которого нужно вывести содержимое.
 * @param size - размерность склада / грузовика.
 */
void pringState(Buffer* buffer, size_t size) {
    printf("------------------------\n");
    printf("\tСклад:\n");
    for(int i = 0; i < size; ++i) {
        if (buffer->warehousI <= i) {
            printf("%d\n", 0);
        }
        else {
            printf("%ld\n", buffer->warehouse[i].price);
        }
    }
    printf("------------------------\n");
    printf("\tГрузовик:\n");
    for(int i = 0; i < size; ++i) {
        if (buffer->truckI <= i) {
            printf("%d\n", 0);
        }
        else {
            printf("%ld\n", buffer->truck[i].price);
        }
    }
}