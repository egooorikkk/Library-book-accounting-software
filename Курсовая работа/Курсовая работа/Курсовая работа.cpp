#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // Для цвета консоли
#include "Header.h"

using namespace std; 

int main() {
    system("color F0"); 


    setlocale(LC_ALL, "Russian");

    bool isAdmin = false;
    bool isLoggedIn = false;

    cout << "----[ДОБРО ПОЖАЛОВАТЬ]----" << endl;
    cout << "Выберите тип пользователя:" << endl;
    cout << "1. Пользователь" << endl;
    cout << "2. Администратор" << endl;
    cout << "Введите соответствующий номер: ";
    int userType;
    cin >> userType;

    switch (userType) {
    case 1:
        isLoggedIn = userLogin();
        break;
    case 2:
        isLoggedIn = adminLogin();
        isAdmin = true;
        break;
    default:
        cout << "Неверный выбор типа пользователя." << endl;
        return 1;
    }

    if (!isLoggedIn) {
        cout << "Неверный логин или пароль. Вход запрещен." << endl;
        return 1;
    }

    if (isAdmin) {
        // Код для администратора
        while (true) {
            ifstream file("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\book.txt");
            if (!file.is_open()) {
                cout << "Не удалось открыть файл!" << endl;
                return 1;
            }

            // Создаем структуру, в которую будем считывать данные о книгах
            Book book;

            // Считываем данные о книге из файла
            file >> book.regNumber >> book.author >> book.title >> book.year
                >> book.publisher >> book.pageCount >> book.readerCardNumber
                >> book.isAvailable;


            // Закрываем файл
            file.close();

            cout << "-----------------------------------------" << endl;
            cout << "           Меню библиотекаря             " << endl;
            cout << "-----------------------------------------" << endl;
            cout << "1. Добавить книгу" << endl;
            cout << "2. Удалить книгу" << endl;
            cout << "3. Просмотр всех данных" << endl;
            cout << "4. Редактирование данных" << endl;
            cout << "5. Поиск книги по названию" << endl;
            cout << "6. Поиск книги по автору" << endl;
            cout << "7. Сортировка книг по количеству страниц" << endl;
            cout << "8. Список книг, находящихся у читателей" << endl;
            cout << "9. Список книг с фамилиями авторов в алфавитном порядке, изданных после определенного года" << endl;
            cout << "10. Выход из программы" << endl;
            cout << "-----------------------------------------" << endl;

            int choice;
            cout << "Введите номер пункта: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                deleteBook();
                break;
            case 3:
                allData();
                break;
            case 4:
                dataEditing();
                break;
            case 5:
                searchByTitle();
                break;
            case 7:
                sortByPages();
                break;
            case 6:
                searchByAuthor();
                break;
            case 8:
                booksFromTheReader();
                break;
            case 9:
                sortByYear();
                break;
            case 10:
                exit();
                break;
            default:
                // Если выбран неверный пункт меню, выдаем сообщение об ошибке
                cout << "Ошибка: Неправильный выбор. Пожалуйста, выберите существующий пункт меню." << endl;
                break;
            }
        }
        return 0;
    }
    else {
        // Код для пользователя
        while (true) {
            ifstream file("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\book.txt");
            if (!file.is_open()) {
                cout << "Не удалось открыть файл!" << endl;
                return 1;
            }

            // Создаем структуру, в которую будем считывать данные о книгах
            Book book;

            // Считываем данные о книге из файла
            file >> book.regNumber >> book.author >> book.title >> book.year
                >> book.publisher >> book.pageCount >> book.readerCardNumber
                >> book.isAvailable;


            // Закрываем файл
            file.close();

            cout << "-----------------------------------------" << endl;
            cout << "           Меню пользователя            " << endl;
            cout << "-----------------------------------------" << endl;
            cout << "1. Просмотр всех данных" << endl;
            cout << "2. Поиск книги по названию" << endl;
            cout << "3. Поиск книги по автору" << endl;
            cout << "4. Сортировка книг количеству страниц" << endl;
            cout << "5. Список книг, находящихся у читателей" << endl;
            cout << "6. Список книг с фамилиями авторов в алфавитном порядке, изданных после определенного года" << endl;
            cout << "7. Выход из программы" << endl;
            cout << "-----------------------------------------" << endl;

            int choice;
            cout << "Введите номер пункта: ";
            cin >> choice;
            switch (choice) {
            case 1:
                allData();
                break;
            case 2:
                searchByTitle();
                break;
            case 3:
                searchByAuthor();
                break;
            case 4:
                sortByPages();
                break;
            case 5:
                booksFromTheReader();
                break;
            case 6:
                sortByYear();
                break;
            case 7:
                exit();
                break;
            default:
                // Если выбран неверный пункт меню, выдаем сообщение об ошибке
                cout << "Ошибка: Неправильный выбор. Пожалуйста, выберите существующий пункт меню." << endl;
                break;
            }
        }
    }

    return 0;
}