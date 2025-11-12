#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Header.h"

using namespace std;


// Функция для сравнения книг по количеству страниц
bool compareByPageCount(const Book& book1, const Book& book2) {
    return book1.pageCount < book2.pageCount;
}

void sortByPages() {
    // Открытие файла с данными
    ifstream inputFile("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\book.txt");
    if (!inputFile) {
        cout << "Ошибка открытия файла." << endl;
        return;
    }

    cout << endl; 
    cout << "----[Сортировка по количеству страниц]----" << endl;

    vector<Book> books;

    // Чтение данных из файла
    Book tempBook;
    while (inputFile >> tempBook.regNumber >> tempBook.author >> tempBook.title >> tempBook.year >> tempBook.publisher >> tempBook.pageCount >> tempBook.readerCardNumber >> tempBook.isAvailable) {
        books.push_back(tempBook);
    }

    // Сортировка книг по количеству страниц
    sort(books.begin(), books.end(), compareByPageCount);

    // Вывод отсортированных книг
    for (const auto& book : books) {
        cout << "Название: " << book.title << ", Кол-во страниц: " << book.pageCount << endl;
    }
    cout << "==================================" << endl;

    // Спрашиваем пользователя, хочет ли он продолжить
    cout << "Хотите продолжить? (1 - да, 2 - нет): ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        // Очищаем консоль и возвращаем true
        system("cls");

    }
    else {
        // Возвращаем false
        exit();
    }
}