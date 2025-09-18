#include <iostream>
#include <string>

#include "../include/User-IO.hpp"

using namespace std;

int main()
{
    printMenu();
    string input = getUserInput();
    cout << "Your Input: " << input;
    return 0;
}