#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

void addBook() {

    setlocale(LC_ALL, "Russian");

    // Открываем файл для чтения и записи
    fstream file("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\book.txt", ios::in | ios::out | ios::app);

    if (!file.is_open()) {
        cout << "Не удалось открыть файл!" << endl;
        return;
    }

    // Устанавливаем позицию чтения в конец файла, чтобы добавить новую запись
    file.seekg(0, ios::end);

    // Создаем структуру, в которую будем считывать данные о книгах
    Book book;

    // Получаем позицию, на которой находится указатель на конец файла
    streampos filePos = file.tellg();

    // Если файл не пустой, переходим на новую строку
    if (filePos != 0) {
        file << endl;
    }

    cout << endl; 
    // Добавляем новую запись
    cout << "----[Добавление новой книги]----" << endl;
    cout << "Введите данные для новой книги:" << endl;
    cout << "Номер регистрации: ";
    cin >> book.regNumber;
    cout << "Автор: ";
    cin >> book.author;
    cout << "Название: ";
    cin >> book.title;
    cout << "Год издания: ";
    cin >> book.year;
    cout << "Издатель: ";
    cin >> book.publisher;
    cout << "Количество страниц: ";
    cin >> book.pageCount;
    cout << "Номер читательского билета: ";
    cin >> book.readerCardNumber;
    cout << "Доступна? (1 - да, 0 - нет): ";
    cin >> book.isAvailable;

    // Записываем новую запись в файл
    file << book.regNumber << " " << book.author << " " << book.title << " " << book.year
        << " " << book.publisher << " " << book.pageCount << " " << book.readerCardNumber
        << " " << book.isAvailable;

    // Закрываем файл
    file.close();

    cout << endl << "Новая книга успешно добавлена в файл!" << endl << endl;

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
