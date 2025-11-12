#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"
#include <iomanip> // Для использования setw

using namespace std;

void deleteBook() {
    // Открываем файл для чтения и записи
    fstream file("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\book.txt", ios::in | ios::out);

    if (!file.is_open()) {
        cout << "Не удалось открыть файл!" << endl;
        return;
    }

    // Проверяем, пуст ли файл
    file.seekg(0, ios::end);
    if (file.tellg() == 0) {
        cout << "Список книг пуст!" << endl;
        file.close();
        return;
    }
    file.seekg(0, ios::beg);

    cout << endl;
    // Выводим все книги, которые есть в файле
    cout << "----[Удаление книги]----" << endl;
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
    // Закрываем файл перед тем, как снова открыть его для записи
    file.close();

    // Пользователь выбирает, какую книгу удалить
    int regNumberToDelete;
    cout << "Введите номер регистрации книги, которую хотите удалить: ";
    cin >> regNumberToDelete;

    // Подтверждение удаления
    string confirmDelete;
    cout << "Вы действительно хотите удалить эту книгу? (yes/no): ";
    cin >> confirmDelete;

    if (confirmDelete != "yes" && confirmDelete != "YES") {
        cout << "Удаление отменено." << endl;
        return;
    }

    // Открываем файл заново, чтобы выполнить удаление
    file.open("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\book.txt", ios::in | ios::out);

    // Создаем временный файл, куда будем записывать книги, кроме той, которую нужно удалить
    ofstream tempFile("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\temp_book.txt");

    bool bookDeleted = false; // Флаг для отслеживания удаления книги

    while (file >> book.regNumber >> book.author >> book.title >> book.year
        >> book.publisher >> book.pageCount >> book.readerCardNumber >> book.isAvailable) {
        // Если номер регистрации не совпадает с тем, что нужно удалить, записываем во временный файл
        if (book.regNumber != regNumberToDelete) {
            tempFile << book.regNumber << " " << book.author << " " << book.title << " " << book.year
                << " " << book.publisher << " " << book.pageCount << " " << book.readerCardNumber
                << " " << book.isAvailable << endl;
        }
        else {
            bookDeleted = true; // Книга успешно удалена
        }
    }

    // Закрываем файлы
    file.close();
    tempFile.close();

    // Проверяем, была ли удалена книга
    if (!bookDeleted) {
        cout << "Книга с таким номером регистрации не найдена." << endl;
        return;
    }

    // Удаляем старый файл
    remove("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\book.txt");
    // Переименовываем временный файл
    rename("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\temp_book.txt",
        "C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\book.txt");

    cout << endl << "Книга успешно удалена!" << endl << endl;

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
