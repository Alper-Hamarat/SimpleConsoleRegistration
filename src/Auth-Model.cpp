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
            // If yes: return username and password as array
            return {user, pass};
        }
    }

    // =========================================
    // If no matching username found, return an empty array
    // =========================================
    return {"",""};
}