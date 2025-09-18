#include <array>
#include <iostream>
#include <string>
#include <cstdlib>

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
            //Get Username input of User
            cout << "Please input an username" << endl;
            string username = getUserInput();
            //Check if username exists
            if(checkUsernameExists(username))
            {
                cout << "Username already exists " << endl;
            }
            else
            {
                //Get Password of user
                cout << "Please input your password" << endl;
                string password = getUserInput();
                cout << "Credentials were added: " << addLoginCredentials(username, password) << endl;
            }


        }
        //login
        else if(input == "1")
        {
            //Get Username input of User
            cout << "Please input your username" << endl;
            string username = getUserInput();
            //Get Password of user
            cout << "Please input your password" << endl;
            string password = getUserInput();
            //Check if password matches 
            if (checkLoginCredentials(username, password))
            {
                cout << "Password matches" << endl;
                cout << "Your are now logged in" << endl;
                system("PAUSE");
                exit(0);
            }
            cout << "Password does not match" << endl;
        }

    }
    return 0;
}