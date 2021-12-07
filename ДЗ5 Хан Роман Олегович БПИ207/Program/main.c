#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "buffer.h"
#include "print.h"

// Мьютикс обьект.
// Присутсвует для того, чтобы корректно обрабатывать доступ к различным ресурсам.
pthread_mutex_t mutex;

// Размер склада.
size_t size;

// Буфер.
struct Buffer buffer;

/**
 * Функция для потока Иванова.
 * В модели иванов выступает потребителем для буфера склада
 * и производителем для буфера его рук.
 *
 * Иванов забирает данные из буфера склада и кладет их в буфер своих рук.
 * @param arg - аргументы потока.
 * @return
 */
void* ivanov(void* arg) {
    while(buffer.warehousI != 0) {
        pthread_mutex_lock(&mutex);
        if (buffer.ivansHandsI < size && buffer.warehousI > 0) {
            buffer.warehousI -= 1;
            printf("Иванов взял товар со склада на сумму %ld.\n", buffer.warehouse[buffer.warehousI].price);
            buffer.ivansHands[buffer.ivansHandsI] = buffer.warehouse[buffer.warehousI];
            buffer.ivansHandsI += 1;
        }
        pthread_mutex_unlock(&mutex);
        usleep(1);
    }
    return NULL;
}

/**
 * Функция для потока Петрова.
 * В модели Петров выступает в роли потребителя для буфера рук Иванова
 * и производителем для буфера грузовика.
 *
 * Петров забирает из рук Иванова имущество и грузит его в грузовик.
 * @param arg - аргументы потока.
 * @return
 */
void* petrov(void* arg) {
    while(buffer.warehousI != 0 || (buffer.truckI < size && buffer.ivansHandsI > 0)) {
        pthread_mutex_lock(&mutex);
        if (buffer.truckI < size && buffer.ivansHandsI > 0) {
            buffer.ivansHandsI -= 1;
            printf("Петров положил имущество в машину на сумму %ld.\n", buffer.ivansHands[buffer.ivansHandsI].price);
            buffer.truck[buffer.truckI] = buffer.ivansHands[buffer.ivansHandsI];
            buffer.truckI += 1;
        }
        pthread_mutex_unlock(&mutex);
        usleep(1);
    }
    return NULL;
}

/**
 * Функция для потока Нечепорчука.
 * В модели Нечепорчук выступает в роли потребителя для буфера грузовика.
 *
 * Нечепорчука добавляет в свой подсчет цены всех элементов,
 * которые еще не были учтены и которые находятся в грузовике.
 * @param arg - аргументы потока.
 * @return
 */
void* nechiporchuk(void* arg) {
    long sum = 0;
    int last_used_index = 0;
    do {
        pthread_mutex_lock(&mutex);
        if (last_used_index != buffer.truckI) {
            printf("Нечепорчук посчитал рыночную стоимость.\n");
            for(int i = last_used_index; i < buffer.truckI; ++i) {
                sum += buffer.truck[i].price;
            }
            printf("%ld\n", sum);
            last_used_index = (int)buffer.truckI;
        }
        pthread_mutex_unlock(&mutex);
    } while (buffer.truckI != size || last_used_index != buffer.truckI);
    return NULL;
}

// Главная функция прогармы.
int main(int k, char** args) {
    // Проверка на корректное количество элементов.
    if (k < 3) {
        printf("Недостаточно аргументов!");
        return 1;
    }

    // В зависимости от флага происходит генерация склада или ввод из параметров.
    // Если флаг неверный, то пользователю будет выведено сообщение об ошибке.
    if (strcmp(args[1], "-f") == 0) {
        buffer.warehousI = k - 2;
        size = buffer.warehousI;
        for (int i = 2; i < k; ++i) {
            long price = strtol(args[i], &args[i], 0);
            buffer.warehouse[i - 2].price = price;
        }
    }
    else if (strcmp(args[1], "-n") == 0) {
        buffer.warehousI =  strtol(args[2], &args[2], 0);
        size = buffer.warehousI;
        if((buffer.warehousI < 1) || (buffer.warehousI > 10000)) {
            printf("incorrect number of figures = %ld. Set 0 < number <= 10000\n", buffer.warehousI);
            return 3;
        }

        for (int i = 0; i < buffer.warehousI; ++i) {
            buffer.warehouse[i].price = rand() % 100;
        }
    }
    else {
        printf("Неверный флаг! Флаг может быть только '-f' или '-n'\n"
               "'-f' - ввод цен на имущество на складе из парметров\n"
               "'-n' - рандомная генеарция цен на имущество");
        return 1;
    }

    printf("До изменения ситуация такая:\n");
    pringState(&buffer, size);

    printf("---------START---------\n");

    pthread_mutex_init(&mutex,NULL);
    pthread_t ivanov_thread, petrov_thread, nechiporchuk_thread;

    // Создание потоков.
    pthread_create(&nechiporchuk_thread, NULL, nechiporchuk, NULL);
    pthread_create(&petrov_thread, NULL, petrov, NULL);
    pthread_create(&ivanov_thread, NULL, ivanov, NULL);

    // Ждем, пока все потоки закончат свою работу.
    pthread_join(ivanov_thread, NULL);
    pthread_join(petrov_thread, NULL);
    pthread_join(nechiporchuk_thread, NULL);
    printf("---------END---------\n");

    printf("После изменения ситуация такаия\n");
    pringState(&buffer, size);
    return 0;
}