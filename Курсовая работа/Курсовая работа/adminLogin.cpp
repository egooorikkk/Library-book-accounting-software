#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

bool adminLogin() {
    cout << endl; 
    cout << "----[Авторизация в режим администратора]----" << endl;
    string username, password;
    cout << "Введите логин администратора: ";
    cin >> username;
    cout << "Введите пароль администратора: ";
    cin >> password;
    system("cls");

    ifstream loginFile("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\admin_login.txt");
    ifstream passwordFile("C:\\Users\\egors\\OneDrive\\Рабочий стол\\Курсовая работа\\admin_password.txt");

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
