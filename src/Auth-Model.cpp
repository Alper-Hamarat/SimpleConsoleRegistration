#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <sstream>
#include <stdexcept>

#include "../include/Auth-Model.hpp"

using namespace std;

// fullPath is declared in the header file and defined here
string fullPath = filepath + filename;

array<string, 2> getLoginCredentials(string username)
{
    // ==============================
    // Open the user credentials file
    // ==============================
    ifstream loginFile(fullPath);  
    if (!loginFile.is_open()) {
        // If the file cannot be opened, throw an error
        throw runtime_error("Could not open file: " + fullPath);
    }

    // ==============================
    // Read the file line by line
    // ==============================
    string line;
    while (getline(loginFile, line)) {
        // Split the line into words
        // We assume the format: "username password"
        istringstream iss(line);
        string user, pass;

        // If parsing fails (e.g. empty or invalid line), skip this line
        if (!(iss >> user >> pass)) {
            continue; 
        }

        // =========================================
        // Check if the given username matches
        // =========================================
        if (user == username) {
            loginFile.close();
            // If yes: return username and password as array
            return {user, pass};
        }
    }

    // =========================================
    // If no matching username found, return an empty array
    // =========================================
    loginFile.close();
    return {"",""};
}


bool checkLoginCredentials(string username, string password)
{
    //Get Credentials from Username
    array<string, 2> credentials = getLoginCredentials(username);
    //Check if password matches username
    if(password == credentials[1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkUsernameExists(string username)
{
    //Get Credentials from Username
    array<string, 2> credentials = getLoginCredentials(username);
    //Check if password matches username
    if(username == credentials[0])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool addLoginCredentials(string username, string password)
{
    // ============================================
    // Open the file in append mode (add at the end)
    // ============================================
    ofstream loginFile(fullPath, ios::app);
    if (!loginFile.is_open()) {
        // Could not open file -> return false
        cerr << "Error: could not open " << fullPath << " for writing" << endl;
        return false;
    }

    // ============================================
    // Write "username password" into the file
    // ============================================
    loginFile << username << " " << password << "\n";

    // Close happens automatically via RAII, but we can be explicit
    loginFile.close();

    // ============================================
    // If we reach here, writing was successful
    // ============================================
    return true;
}