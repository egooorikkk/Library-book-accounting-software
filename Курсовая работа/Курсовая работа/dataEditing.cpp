#include <iostream>
#include <fstream>
#include "Header.h"
#include <iomanip>

using namespace std;

void dataEditing() {
    fstream file("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\book.txt", ios::in | ios::out);

    if (!file.is_open()) {
        cout << "Не удалось открыть файл!" << endl;
        return;
    }
    cout << endl;
    cout << "-----------------[Редактирование данных]-----------------" << endl;

    cout << "Список книг:" << endl;
    Book book;
    cout << left << setw(20) << "Номер регистрации" << setw(20) << "Автор" << setw(30) << "Название"
        << setw(10) << "Год" << setw(20) << "Издатель" << setw(15) << "Страницы"
        << setw(25) << "Номер читат. билета" << setw(10) << "Доступна?" << endl;

    // Вернуть курсор в начало файла
    file.clear();
    file.seekg(0, ios::beg);

    while (file >> book.regNumber >> book.author >> book.title >> book.year
        >> book.publisher >> book.pageCount >> book.readerCardNumber >> book.isAvailable) {
        cout << left << setw(20) << book.regNumber << setw(20) << book.author << setw(30) << book.title
            << setw(10) << book.year << setw(20) << book.publisher << setw(15) << book.pageCount
            << setw(25) << book.readerCardNumber << setw(10) << (book.isAvailable ? "да" : "нет") << endl << endl;
    }

    int regNumberToEdit;
    cout << "Введите номер регистрации книги, данные которой хотите отредактировать: ";
    cin >> regNumberToEdit;

    // Создаем временный файл, куда будем записывать измененные данные
    ofstream tempFile("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\temp_book.txt");

    bool found = false;
    cout << endl;

    // Вернуть курсор в начало файла
    file.clear();
    file.seekg(0, ios::beg);

    while (file >> book.regNumber >> book.author >> book.title >> book.year
        >> book.publisher >> book.pageCount >> book.readerCardNumber >> book.isAvailable) {
        if (book.regNumber == regNumberToEdit) {
            cout << "Новые данные для книги с номером регистрации " << regNumberToEdit << ":" << endl;
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
            found = true;
        }
        tempFile << book.regNumber << " " << book.author << " " << book.title << " " << book.year
            << " " << book.publisher << " " << book.pageCount << " " << book.readerCardNumber
            << " " << book.isAvailable << endl;
    }

    file.close();
    tempFile.close();

    if (found) {
        remove("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\book.txt");
        rename("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\temp_book.txt",
            "C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\book.txt");
        cout << "Данные о книге успешно отредактированы!" << endl << endl;
    }
    else {
        cout << "Книга с указанным номером регистрации не найдена!" << endl << endl;
    }
    cout << "Хотите продолжить? (1 - да, 2 - нет): ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        system("cls");
    }
    else {
        exit();
    }
}
