#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

bool userLogin() {
    cout << endl;
    cout << "----[Авторизация в режим пользователя]----" << endl;
    string username, password;
    cout << "Введите логин: ";
    cin >> username;
    cout << "Введите пароль: ";
    cin >> password;
    
    system("cls");

    ifstream loginFile("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\login.txt");
    ifstream passwordFile("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\password.txt");

    string storedUsername, storedPassword;
    bool loggedIn = false;

    while (loginFile >> storedUsername && passwordFile >> storedPassword) {
        if (username == storedUsername && password == storedPassword) {
            loggedIn = true;
            break;
        }
    }

    loginFile.close();
    passwordFile.close();

    return loggedIn;
}