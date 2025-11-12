#include <iostream>
#include <fstream>
#include <algorithm> // Для функции sort
#include "Header.h"

using namespace std;

// Функция для сравнения двух книг по количеству страниц
bool sortByPage(const Book& book1, const Book& book2) {
    return book1.pageCount < book2.pageCount;
}

void sortByPageCount() {
    // Открываем файл для чтения
    ifstream file("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\book.txt");

    if (!file.is_open()) {
        cout << "Не удалось открыть файл!" << endl;
        return;
    }

    Book books[100]; // Предполагаем, что не более 100 книг
    int numBooks = 0;

    // Считываем книги из файла в массив
    while (file >> books[numBooks].regNumber >> books[numBooks].author >> books[numBooks].title >> books[numBooks].year
        >> books[numBooks].publisher >> books[numBooks].pageCount >> books[numBooks].readerCardNumber >> books[numBooks].isAvailable) {
        numBooks++;
    }

    file.close();

    // Сортируем массив книг по количеству страниц в порядке возрастания
    sort(books, books + numBooks, compareByPageCount);

    // Выводим отсортированный список книг
    cout << "Результаты поиска книг по количеству страниц в порядке возрастания:" << endl;
    for (int i = 0; i < numBooks; i++) {
        cout << "Номер регистрации: " << books[i].regNumber << endl;
        cout << "Автор: " << books[i].author << endl;
        cout << "Название: " << books[i].title << endl;
        cout << "Год издания: " << books[i].year << endl;
        cout << "Издатель: " << books[i].publisher << endl;
        cout << "Количество страниц: " << books[i].pageCount << endl;
        cout << "Номер читательского билета: " << books[i].readerCardNumber << endl;
        cout << "Доступна? " << (books[i].isAvailable ? "да" : "нет") << endl;
        cout << "==================================" << endl;
    }
}
