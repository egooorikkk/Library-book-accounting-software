#ifndef HEADER_H
#define HEADER_H


#include <string> // Включаем заголовочный файл для типа std::string

using namespace std;



struct Book {
    int regNumber;
    string author;
    string title;
    int year;
    string publisher;
    int pageCount;
    int readerCardNumber;
    bool isAvailable;
};

// Объявление функций
bool userLogin();
bool adminLogin();
void addBook();
void deleteBook();
void allData(); 
void dataEditing();
void searchByTitle(); 
void searchByAuthor();
void booksFromTheReader();
void exit();
void sortByYear();
void sortByPages();

#endif