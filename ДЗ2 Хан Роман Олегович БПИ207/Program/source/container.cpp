#include "../headers/container.h"


/**
 * Конструктор класса, создает коллекцию обобщенных фигур (10 тысяч ссылок).
 */
Container::Container() : len{0} {}

/**
 * Деструктор контейнера.
 * Очищает память также и от фигур внутри.
 */
Container::~Container() {
    Clear();
}

/**
 * Метод очистки контейнера от фигур.
 */
void Container::Clear() {
    for (int i = 0; i < len - 1; i++) {
        delete storage[i];
        storage[i] = nullptr;
    }
    storage[len - 1] = nullptr;
    len = 0;
}

/**
 * Ввод коллекции фигур из файла.
 * @param inputFile - файл, из которого присходит считывание.
 */
void Container::In(FILE *inputFile) {
    while ((storage[len] = Shape::StaticIn(inputFile)) != nullptr) {
        len++;
    }
    fclose(inputFile);
}

/**
 * Рандомная генерация содержимого контейнера
 * @param size - количество элементов в колекции, которые необходимо сгенерировать.
 */
void Container::InRnd(int size) {
    while (len < size) {
        if ((storage[len] = Shape::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

/**
* Вывод содержимого контейнера в файл.
* @param outputFile - файл, в который нужно вывести данные о фигурах.
*/
void Container::Out(FILE *outputFile) {
    fprintf(outputFile, "Container contains ");
    fprintf(outputFile, "%d", len);
    fprintf(outputFile, " elements.\n");
    for (int i = 0; i < len; i++) {
        fprintf(outputFile, "%d", i + 1);
        fprintf(outputFile, ": ");
        storage[i]->Out(outputFile);
    }
}

/**
 * Вычиление суммарного периметра всех фигур.
 * @return суммарный периметр.
 */
double Container::Perimeter() {
    double sum = 0.0;
    for (int i = 0; i < len; i++) {
        sum += storage[i]->Perimeter();
    }
    return sum;
}

/**
 * Получить средний периметр фигуры в колекции.
 * @return средний периметр.
 */
double Container::GetAvaragePerimetr() {
    return Perimeter() / len;
}

/**
 * Удаление всех фигур, периметр которых больше среднего.
 */
void Container::RemoveAlternativesWithBigPerimeter() {
    double average = Perimeter() / len;
    for (int i = 0; i < len; i++) {
        if (storage[i]->Perimeter() > average) {
            len--;
            for (int j = i; j < len - 1; j++) {
                storage[j] = storage[j + 1];
            }
            storage[len] = nullptr;
        }
    }
}

