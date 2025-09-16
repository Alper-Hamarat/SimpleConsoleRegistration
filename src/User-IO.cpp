#include <iostream>

#include "../include/User-IO.hpp"

using namespace std;

void printMenu()
{
    cout << "Hello Would you like to login or register?" << endl;
    cout << "0: to registration" << endl;
    cout << "1: to login" << endl;
    cout << "9: to exit" << endl;
}

string getUserInput()
{
    string input;
    cout << "Please make an Input:" << endl;
    cin >> input;
    return input;
}
