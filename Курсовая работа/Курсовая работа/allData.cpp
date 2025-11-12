#include <iostream>
#include <fstream>
#include <iomanip> // Для использования setw
#include "Header.h"

using namespace std;

void allData() {

    // Открываем файл для чтения и записи
    fstream file("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\book.txt");

    if (!file.is_open()) {
        cout << "Не удалось открыть файл!" << endl;
        return;
    }

    cout << endl;
    cout << "----[Просмотр всех данных]----" << endl;
    // Выводим все книги, которые есть в файле
    cout << "Список книг:" << endl;
    Book book;
    cout << left << setw(20) << "Номер регистрации" << setw(20) << "Автор" << setw(30) << "Название"
        << setw(10) << "Год" << setw(20) << "Издатель" << setw(15) << "Страницы"
        << setw(25) << "Номер читат. билета" << setw(10) << "Доступна?" << endl;
    while (file >> book.regNumber >> book.author >> book.title >> book.year
        >> book.publisher >> book.pageCount >> book.readerCardNumber >> book.isAvailable) {
        cout << left << setw(20) << book.regNumber << setw(20) << book.author << setw(30) << book.title
            << setw(10) << book.year << setw(20) << book.publisher << setw(15) << book.pageCount
            << setw(25) << book.readerCardNumber << setw(10) << (book.isAvailable ? "да" : "нет") << endl;
    }

    cout << endl;

    // Закрываем файл
    file.close();

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
