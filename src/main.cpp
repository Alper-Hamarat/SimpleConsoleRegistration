#include <array>
#include <iostream>
#include <string>

#include "../include/User-IO.hpp"
#include "../include/Auth-Model.hpp"

using namespace std;

/**
 * Main Program structure calls the Menu and redirects user to the Registration and Login Menu.
 */
int main()
{
    //Set the input to an unused value
    string input = "-1";

    //Run the program until user input "9"
    while (input != "9")
    {

        printMenu();
        input = getUserInput();
        //Check which option the user has detected
        //register
        if(input == "0")
        {

        }
        //login
        else if(input == "1")
        {
            cout << "Please input your username" << endl;
            string username = getUserInput();
            array<string, 2> credentials = getLoginCredentials(username);
            cout << credentials[0] << " " << credentials[1] << endl;
        }

    }
    return 0;
}