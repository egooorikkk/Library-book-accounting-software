#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

using namespace std;

void searchByAuthor() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string bookAuthor;

    cout << endl;
    cout << "----[Поиск книги по автору]----" << endl;
    cout << "Введите автора: ";
    cin >> bookAuthor; // Запрашиваем название книги у пользователя
    cout << endl; 

    // Открываем файл для чтения
    ifstream file("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\book.txt");

    if (!file.is_open()) {
        cout << "Не удалось открыть файл!" << endl;
        return;
    }

    Book book;
    bool found = false;

    cout << "Результаты поиска книг по названию \"" << bookAuthor << "\":" << endl;

    // Пока есть книги в файле, читаем их и проверяем соответствие названию
    while (file >> book.regNumber >> book.author >> book.title >> book.year
        >> book.publisher >> book.pageCount >> book.readerCardNumber >> book.isAvailable) {
        if (book.author == bookAuthor) {
            // Если найдена книга с указанным названием, выводим ее данные
            cout << "Номер регистрации: " << book.regNumber << endl;
            cout << "Автор: " << book.author << endl;
            cout << "Название: " << book.title << endl;
            cout << "Год издания: " << book.year << endl;
            cout << "Издатель: " << book.publisher << endl;
            cout << "Количество страниц: " << book.pageCount << endl;
            cout << "Номер читательского билета: " << book.readerCardNumber << endl;
            cout << "Доступна? " << (book.isAvailable ? "да" : "нет") << endl;
            cout << "==================================" << endl << endl;
            found = true;
        }
    }

    file.close();

    if (!found) {
        cout << "Книги с таким автором не найдены." << endl << endl;
    }
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
