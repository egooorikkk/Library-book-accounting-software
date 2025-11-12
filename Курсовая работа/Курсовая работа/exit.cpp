#include <iostream>
#include <cstdlib> // Для функции exit()

using namespace std;

void exit() {
    cout << endl; 
    cout << "Выход из программы." << endl;
    exit(0); // Завершаем выполнение программы с кодом 0
}