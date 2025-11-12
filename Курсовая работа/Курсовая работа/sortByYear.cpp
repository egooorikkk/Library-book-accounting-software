#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Header.h"

using namespace std;

// Функция для сравнения книг по фамилии автора (используется при сортировке)
bool compareBooks(const Book& book1, const Book& book2) {
    return book1.author < book2.author;
}

void sortByYear() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Открываем файл с данными о книгах для чтения
    ifstream inputFile("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\book.txt");
    if (!inputFile) {
        cout << "Ошибка открытия файла." << endl;
        return;
    }
    cout << endl; 
    cout << "----[Сортировка списка книг с фамилиями авторов в алфавитном порядке, изданных после заданного года]----" << endl;

    vector<Book> books; // Вектор для хранения книг

    // Читаем данные о книгах из файла
    Book book;
    while (inputFile >> book.regNumber >> book.author >> book.title >> book.year >> book.publisher >> book.pageCount >> book.readerCardNumber >> book.isAvailable) {
        books.push_back(book);
    }

    inputFile.close(); // Закрываем файл после чтения

    int targetYear;
    cout << "Введите год для фильтрации: ";
    cin >> targetYear;
    cout << endl; 

    // Фильтрация книг по году издания и сортировка по фамилии автора
    vector<Book> filteredBooks;
    for (const auto& book : books) {
        if (book.year > targetYear) {
            filteredBooks.push_back(book);
        }
    }
    sort(filteredBooks.begin(), filteredBooks.end(), compareBooks); // Сортировка

    // Вывод отфильтрованного и отсортированного списка книг
    cout << "Список книг по алфавиту фамилий авторов, изданных после " << targetYear << " года:" << endl;
    for (const auto& book : filteredBooks) {
        cout << book.title << " (" << book.author << "), " << book.year << endl;
    }
    cout << "==================================" << endl<<endl ;

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
