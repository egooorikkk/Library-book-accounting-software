#include <iostream>
#include <fstream>
#include "Header.h"
#include <iomanip> // Для использования setw

using namespace std;

void booksFromTheReader() {
    // Открываем файл для чтения
    ifstream file("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\book.txt");

    if (!file.is_open()) {
        cout << "Не удалось открыть файл!" << endl;
        return;
    }

    Book book;
    bool found = false;

    cout << endl;
    cout << "----[Список книг которые находятся у читателя]----" << endl;
    cout << "Книги, находящиеся у читателей:" << endl << endl;

    
    // Читаем книги из файла и выводим информацию о книгах, которые находятся у читателей
    cout << left << setw(20) << "Номер регистрации" << setw(20) << "Автор" << setw(20) << "Название"
        << setw(10) << "Год" << setw(20) << "Издатель" << setw(15) << "Страницы"
        << setw(25) << "Номер читат. билета" << setw(10) << "Доступна?" << endl;
    while (file >> book.regNumber >> book.author >> book.title >> book.year
        >> book.publisher >> book.pageCount >> book.readerCardNumber >> book.isAvailable) {
        if (!book.isAvailable) {
            // Если книга находится у читателя, выводим ее данные
            cout << left << setw(20) << book.regNumber << setw(20) << book.author << setw(20) << book.title
                << setw(10) << book.year << setw(20) << book.publisher << setw(15) << book.pageCount
                << setw(25) << book.readerCardNumber << setw(10) << (book.isAvailable ? "да" : "нет") << endl;
            found = true;
        }
    }

    file.close();

    if (!found) {
        cout << "Книги, находящиеся у читателей, не найдены." << endl << endl; 
    }
    cout << endl; 
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
